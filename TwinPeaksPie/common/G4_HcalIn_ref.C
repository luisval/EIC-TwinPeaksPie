//Inner HCal reconstruction macro
#ifndef MACRO_G4HCALINREF_C
#define MACRO_G4HCALINREF_C

#include <GlobalVariables.C>
#include <QA.C>

#include <g4calo/HcalRawTowerBuilder.h>
#include <g4calo/RawTowerDigitizer.h>

#include <g4detectors/PHG4CylinderSubsystem.h>
#include <g4detectors/PHG4HcalCellReco.h>
#include <g4detectors/PHG4InnerHcalSubsystem.h>

#include <g4eval/CaloEvaluator.h>

#include <g4main/PHG4Reco.h>

#include <eiccaloreco/RawClusterBuilderkV3.h>
#include <eiccaloreco/RawClusterBuilderHelper.h>

#include <caloreco/RawClusterBuilderGraph.h>
#include <caloreco/RawClusterBuilderTemplate.h>
#include <caloreco/RawTowerCalibration.h>
#include <qa_modules/QAG4SimulationCalorimeter.h>

#include <fun4all/Fun4AllServer.h>

R__LOAD_LIBRARY(libcalo_reco.so)
R__LOAD_LIBRARY(libg4calo.so)
R__LOAD_LIBRARY(libg4detectors.so)
R__LOAD_LIBRARY(libg4eval.so)
R__LOAD_LIBRARY(libqa_modules.so)

void HCalInner_SupportRing(PHG4Reco *g4Reco);

namespace Enable
{
  bool HCALIN = false;
  bool HCALIN_ABSORBER = false;
  bool HCALIN_OVERLAPCHECK = false;
  bool HCALIN_CELL = false;
  bool HCALIN_TOWER = false;
  bool HCALIN_CLUSTER = false;
  bool HCALIN_EVAL = false;
  bool HCALIN_QA = false;
  int HCALIN_VERBOSITY = 0;
}  // namespace Enable

namespace G4HCALIN
{
  double support_ring_outer_radius = 178.0 - 0.001;
  double support_ring_z_ring2 = (2150 + 2175) / 2. / 10.;
  double dz = 25. / 10.;

  //Inner HCal absorber material selector:
  //false - old version, absorber material is SS310
  //true - default Choose if you want Aluminum
  bool inner_hcal_material_Al = true;

  int inner_hcal_eic = 1;

  // Digitization (default photon digi):
  RawTowerDigitizer::enu_digi_algorithm TowerDigi = RawTowerDigitizer::kSimple_photon_digitization;
  // directly pass the energy of sim tower to digitized tower
  // kNo_digitization
  // simple digitization with photon statistics, single amplitude ADC conversion and pedestal
  // kSimple_photon_digitization
  // digitization with photon statistics on SiPM with an effective pixel N, ADC conversion and pedestal
  // kSiPM_photon_digitization

  enum enu_HCalIn_clusterizer
  {
    kHCalInGraphClusterizer,

    kHCalInTemplateClusterizer
  };

  //! template clusterizer, RawClusterBuilderTemplate, as developed by Sasha Bazilevsky
  enu_HCalIn_clusterizer HCalIn_clusterizer = kHCalInTemplateClusterizer;
  //! graph clusterizer, RawClusterBuilderGraph
  //enu_HCalIn_clusterizer HCalIn_clusterizer = kHCalInGraphClusterizer;
}  // namespace G4HCALIN

// Init is called by G4Setup.C
void HCalInnerInit(const int iflag = 0)
{
  BlackHoleGeometry::max_radius = std::max(BlackHoleGeometry::max_radius, G4HCALIN::support_ring_outer_radius);
  BlackHoleGeometry::max_z = std::max(BlackHoleGeometry::max_z, G4HCALIN::support_ring_z_ring2 + G4HCALIN::dz / 2.);
  BlackHoleGeometry::min_z = std::min(BlackHoleGeometry::min_z, -G4HCALIN::support_ring_z_ring2 - G4HCALIN::dz / 2.);
  if (iflag == 1)
  {
    G4HCALIN::inner_hcal_eic = 1;
    // ECCE version is stainless steel
    G4HCALIN::inner_hcal_material_Al = false;
  }
}

double HCalInner(PHG4Reco *g4Reco,
                 double radius,
                 const int crossings)
{
  bool AbsorberActive = Enable::ABSORBER || Enable::HCALIN_ABSORBER;
  bool OverlapCheck = Enable::OVERLAPCHECK || Enable::HCALIN_OVERLAPCHECK;
  int verbosity = std::max(Enable::VERBOSITY, Enable::HCALIN_VERBOSITY);

  // all sizes are in cm!
  PHG4InnerHcalSubsystem *hcal = new PHG4InnerHcalSubsystem("HCALIN");
  // these are the parameters you can change with their default settings
  // hcal->set_string_param("material","SS310");
  if (G4HCALIN::inner_hcal_material_Al)
  {
    if (verbosity > 0)
    {
      cout << "HCalInner - construct inner HCal absorber with G4_Al" << endl;
    }
    hcal->set_string_param("material", "G4_Al");
  }
  else
  {
    if (verbosity > 0)
    {
      cout << "HCalInner - construct inner HCal absorber with SS310" << endl;
    }
    hcal->set_string_param("material", "SS310");
  }

  // ECCE Inner HCAL paremeters
  
  double z_end = G4HCALIN::support_ring_z_ring2 - 12.5 + (G4HCALIN::dz/2.0);
  double z_start = -287; // DIRC prizm end
  double length = z_end - z_start;
  double z_shift = 0.5 * (z_end + z_start);

  hcal->set_double_param("outer_radius", 138.5);
  hcal->set_double_param("scinti_outer_radius", 138.0);
  hcal->set_double_param("inner_radius", 135.0);
  hcal->set_double_param("tilt_angle", 36.15);
  hcal->set_double_param("size_z", length);
  hcal->set_int_param("n_scinti_tiles", 0);
  hcal->set_int_param("n_scinti_tiles_pos", 12);
  hcal->set_int_param("n_scinti_tiles_neg", 15);
  hcal->set_double_param("place_z", z_shift);
  hcal->set_double_param("scinti_eta_coverage", 0.0);
  hcal->set_double_param("scinti_eta_coverage_pos", 1.15);
  hcal->set_double_param("scinti_eta_coverage_neg", 1.45);

  // hcal->set_double_param("inner_radius", 117.27);
  //-----------------------------------------
  // the light correction can be set in a single call
  // hcal->set_double_param("light_balance_inner_corr", NAN);
  // hcal->set_double_param("light_balance_inner_radius", NAN);
  // hcal->set_double_param("light_balance_outer_corr", NAN);
  // hcal->set_double_param("light_balance_outer_radius", NAN);
  // hcal->SetLightCorrection(NAN,NAN,NAN,NAN);
  //-----------------------------------------
  // hcal->set_double_param("outer_radius", 134.42);
  // hcal->set_double_param("place_x", 0.);
  // hcal->set_double_param("place_y", 0.);
  // hcal->set_double_param("place_z", 0.);
  // hcal->set_double_param("rot_x", 0.);
  // hcal->set_double_param("rot_y", 0.);
  // hcal->set_double_param("rot_z", 0.);
  
  // If scinti_eta_coverage>0 it will take precdence. 
  // Set to 0 (or <0) to use pos/neg values
  // hcal->set_double_param("scinti_eta_coverage", 1.1);
  // hcal->set_double_param("scinti_eta_coverage_pos", 1.1);
  // hcal->set_double_param("scinti_eta_coverage_neg", 1.1);

  // hcal->set_double_param("scinti_gap_neighbor", 0.1);
  // hcal->set_double_param("scinti_inner_gap", 0.85);
  // hcal->set_double_param("scinti_outer_gap", 1.22 * (5.0 / 4.0));
  // hcal->set_double_param("scinti_outer_radius", 133.3);
  // hcal->set_double_param("scinti_tile_thickness", 0.7);
  // hcal->set_double_param("size_z", 175.94 * 2);
  // hcal->set_double_param("steplimits", NAN);
  // hcal->set_double_param("tilt_angle", 36.15);
  // hcal->set_int_param("light_scint_model", 1);
  // hcal->set_int_param("ncross", 0);
  // hcal->set_int_param("n_towers", 64);
  // hcal->set_int_param("n_scinti_plates_per_tower", 4);
  //
  // If n_scinti_tiles>0 it will take precdence. 
  // Set to 0 (or <0) to use pos/neg values
  // hcal->set_int_param("n_scinti_tiles", 12);
  // hcal->set_int_param("n_scinti_tiles_pos", 12);
  // hcal->set_int_param("n_scinti_tiles_neg", 12);

  // hcal->set_string_param("material", "SS310");

  hcal->SetActive();
  hcal->SuperDetector("HCALIN");
  if (AbsorberActive)
  {
    hcal->SetAbsorberActive();
  }
  hcal->OverlapCheck(OverlapCheck);

  g4Reco->registerSubsystem(hcal);

  radius = hcal->get_double_param("outer_radius");

   HCalInner_SupportRing(g4Reco);

  radius += no_overlapp;
  return radius;
}

//! A rough version of the inner HCal support ring, from Richie's CAD drawing. - Jin
void HCalInner_SupportRing(PHG4Reco *g4Reco)
{
  bool AbsorberActive = Enable::ABSORBER || Enable::HCALIN_ABSORBER;

  const double z_ring1 = (2025 + 2050) / 2. / 10.;
  const double innerradius_sphenix = 138.6;
  const double innerradius_ephenix_hadronside = 138.6;
  const double z_rings[] =
      {-G4HCALIN::support_ring_z_ring2, -z_ring1, z_ring1 - 12.5, G4HCALIN::support_ring_z_ring2 - 12.5};

  PHG4CylinderSubsystem *cyl;

  for (int i = 0; i < 4; i++)
  {
    double innerradius = innerradius_sphenix;
    if (z_rings[i] > 0 && G4HCALIN::inner_hcal_eic == 1)
    {
      //continue; // skip positive support rings for now
      innerradius = innerradius_ephenix_hadronside;
    }
    cyl = new PHG4CylinderSubsystem("HCALIN_SPT_N1", i);
    cyl->set_double_param("place_z", z_rings[i]);
    cyl->SuperDetector("HCALIN_SPT");
    cyl->set_double_param("radius", innerradius);
    cyl->set_int_param("lengthviarapidity", 0);
    cyl->set_double_param("length", G4HCALIN::dz);
    cyl->set_string_param("material", "SS310");
    cyl->set_double_param("thickness", G4HCALIN::support_ring_outer_radius - innerradius);
    if (AbsorberActive)
    {
      cyl->SetActive();
    }
    g4Reco->registerSubsystem(cyl);
  }

  return;
}

void HCALInner_Cells()
{
  int verbosity = std::max(Enable::VERBOSITY, Enable::HCALIN_VERBOSITY);

  Fun4AllServer *se = Fun4AllServer::instance();

  PHG4HcalCellReco *hc = new PHG4HcalCellReco("HCALIN_CELLRECO");
  hc->Detector("HCALIN");
  //  hc->Verbosity(2);
  // check for energy conservation - needs modified "infinite" timing cuts
  // 0-999999999
  //  hc->checkenergy();
  // timing cuts with their default settings
  // hc->set_double_param("tmin",0.);
  // hc->set_double_param("tmax",60.0);
  // or all at once:
  // hc->set_timing_window(0.0,60.0);
  se->registerSubsystem(hc);

  return;
}

void HCALInner_Towers()
{
  int verbosity = std::max(Enable::VERBOSITY, Enable::HCALIN_VERBOSITY);
  Fun4AllServer *se = Fun4AllServer::instance();

  HcalRawTowerBuilder *TowerBuilder = new HcalRawTowerBuilder("HcalInRawTowerBuilder");
  TowerBuilder->Detector("HCALIN");
  TowerBuilder->set_sim_tower_node_prefix("SIM");
  TowerBuilder->Verbosity(verbosity);
  se->registerSubsystem(TowerBuilder);

  // From 2016 Test beam sim
  RawTowerDigitizer *TowerDigitizer = new RawTowerDigitizer("HcalInRawTowerDigitizer");
  TowerDigitizer->Detector("HCALIN");
  //  TowerDigitizer->set_raw_tower_node_prefix("RAW_LG");
  TowerDigitizer->set_digi_algorithm(G4HCALIN::TowerDigi);
  TowerDigitizer->set_pedstal_central_ADC(0);
  TowerDigitizer->set_pedstal_width_ADC(1);  // From Jin's guess. No EMCal High Gain data yet! TODO: update
  TowerDigitizer->set_photonelec_ADC(32. / 5.);
  TowerDigitizer->set_photonelec_yield_visible_GeV(32. / 5 / (0.4e-3));
  TowerDigitizer->set_zero_suppression_ADC(-0);  // no-zero suppression
  se->registerSubsystem(TowerDigitizer);

  //Default sampling fraction for SS310
  double visible_sample_fraction_HCALIN = 0.0631283;  //, /gpfs/mnt/gpfs04/sphenix/user/jinhuang/prod_analysis/hadron_shower_res_nightly/./G4Hits_sPHENIX_pi-_eta0_16GeV-0000.root_qa.rootQA_Draw_HCALIN_G4Hit.pdf

  if (G4HCALIN::inner_hcal_material_Al) visible_sample_fraction_HCALIN = 0.162166;  //for "G4_Al", Abhisek Sen <sen.abhisek@gmail.com>

  RawTowerCalibration *TowerCalibration = new RawTowerCalibration("HcalInRawTowerCalibration");
  TowerCalibration->Detector("HCALIN");
  //  TowerCalibration->set_raw_tower_node_prefix("RAW_LG");
  //  TowerCalibration->set_calib_tower_node_prefix("CALIB_LG");
  TowerCalibration->set_calib_algorithm(RawTowerCalibration::kSimple_linear_calibration);
  if (G4HCALIN::TowerDigi == RawTowerDigitizer::kNo_digitization)
  {
    TowerCalibration->set_calib_const_GeV_ADC(1. / visible_sample_fraction_HCALIN);
  }
  else
  {
    TowerCalibration->set_calib_const_GeV_ADC(0.4e-3 / visible_sample_fraction_HCALIN);
  }
  TowerCalibration->set_pedstal_ADC(0);
  se->registerSubsystem(TowerCalibration);

  return;
}

void HCALInner_Clusters()
{
  int verbosity = std::max(Enable::VERBOSITY, Enable::HCALIN_VERBOSITY);

  Fun4AllServer *se = Fun4AllServer::instance();

  if (G4HCALIN::HCalIn_clusterizer == G4HCALIN::kHCalInTemplateClusterizer)
  {
    RawClusterBuilderHelper *ClusterBuilder = new RawClusterBuilderkV3("HcalInRawClusterBuilderkV3");
    ClusterBuilder->Detector("HCALIN");
    ClusterBuilder->set_seed_e(0.5);
    ClusterBuilder->set_agg_e(0.1);
    se->registerSubsystem(ClusterBuilder);
    /*
    RawClusterBuilderTemplate *ClusterBuilder = new RawClusterBuilderTemplate("HcalInRawClusterBuilderTemplate");
    ClusterBuilder->Detector("HCALIN");
    ClusterBuilder->SetCylindricalGeometry();  // has to be called after Detector()
    ClusterBuilder->Verbosity(verbosity);
    se->registerSubsystem(ClusterBuilder);
    */
  }
  else if (G4HCALIN::HCalIn_clusterizer == G4HCALIN::kHCalInGraphClusterizer)
  {
    RawClusterBuilderGraph *ClusterBuilder = new RawClusterBuilderGraph("HcalInRawClusterBuilderGraph");
    ClusterBuilder->Detector("HCALIN");
    ClusterBuilder->Verbosity(verbosity);
    se->registerSubsystem(ClusterBuilder);
  }
  else
  {
    cout << "HCalIn_Clusters - unknown clusterizer setting!" << endl;
    exit(1);
  }
  return;
}

void HCALInner_Eval(const std::string &outputfile)
{
  int verbosity = std::max(Enable::VERBOSITY, Enable::HCALIN_VERBOSITY);
  Fun4AllServer *se = Fun4AllServer::instance();

  CaloEvaluator *eval = new CaloEvaluator("HCALINEVALUATOR", "HCALIN", outputfile);
  eval->Verbosity(verbosity);
  se->registerSubsystem(eval);

  return;
}

void HCALInner_QA()
{
  int verbosity = std::max(Enable::QA_VERBOSITY, Enable::HCALIN_VERBOSITY);

  Fun4AllServer *se = Fun4AllServer::instance();
  QAG4SimulationCalorimeter *qa = new QAG4SimulationCalorimeter("HCALIN");
  qa->Verbosity(verbosity);
  se->registerSubsystem(qa);

  return;
}

#endif
