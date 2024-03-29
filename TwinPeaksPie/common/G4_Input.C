#ifndef MACRO_G4INPUT_C
#define MACRO_G4INPUT_C

#include <GlobalVariables.C>

#include <phpythia6/PHPythia6.h>

#include <phpythia8/PHPythia8.h>

#include <g4main/HepMCNodeReader.h>
#include <g4main/PHG4IonGun.h>
#include <g4main/PHG4ParticleGenerator.h>
#include <g4main/PHG4ParticleGeneratorD0.h>
#include <g4main/PHG4ParticleGeneratorVectorMeson.h>
#include <g4main/PHG4ParticleGun.h>
#include <g4main/PHG4SimpleEventGenerator.h>
#include <g4main/ReadEICFiles.h>

#include <fermimotionafterburner/FermimotionAfterburner.h>

#include <phhepmc/Fun4AllHepMCInputManager.h>
#include <phhepmc/Fun4AllHepMCPileupInputManager.h>
#include <phhepmc/HepMCFlowAfterBurner.h>
#include <phhepmc/PHHepMCGenHelper.h>

#include <phsartre/PHSartre.h>
#include <phsartre/PHSartreParticleTrigger.h>

#include <fun4all/Fun4AllDstInputManager.h>
#include <fun4all/Fun4AllDummyInputManager.h>
#include <fun4all/Fun4AllInputManager.h>
#include <fun4all/Fun4AllNoSyncDstInputManager.h>
#include <fun4all/Fun4AllServer.h>

#include <set>

R__LOAD_LIBRARY(libfun4all.so)
R__LOAD_LIBRARY(libg4testbench.so)
R__LOAD_LIBRARY(libPHPythia6.so)
R__LOAD_LIBRARY(libPHPythia8.so)
R__LOAD_LIBRARY(libPHSartre.so)
R__LOAD_LIBRARY(libFermimotionAfterburner.so)

namespace Input
{
  // Real Event generators
  bool PYTHIA6 = false;
  int PYTHIA6_EmbedId = 0;

  bool PYTHIA8 = false;
  int PYTHIA8_EmbedId = 0;

  bool SARTRE = false;
  int SARTRE_EmbedId = 0;

  // Single/multiple particle generators
  bool DZERO = false;
  int DZERO_NUMBER = 1;
  int DZERO_VERBOSITY = 0;
  std::set<int> DZERO_EmbedIds;

  bool GUN = false;
  int GUN_NUMBER = 1;
  int GUN_VERBOSITY = 0;
  std::set<int> GUN_EmbedIds;

  bool IONGUN = false;
  int IONGUN_NUMBER = 1;
  int IONGUN_VERBOSITY = 0;
  std::set<int> IONGUN_EmbedIds;

  bool PGEN = false;
  int PGEN_NUMBER = 1;
  int PGEN_VERBOSITY = 0;
  std::set<int> PGEN_EmbedIds;

  bool SIMPLE = false;
  int SIMPLE_NUMBER = 1;
  int SIMPLE_VERBOSITY = 0;

  int UPSILON_NUMBER = 1;
  int UPSILON_VERBOSITY = 0;
  // other UPSILON settings which are also used elsewhere are in GlobalVariables.C

  double PILEUPRATE = 0.;
  bool READHITS = false;
  int VERBOSITY = 0;
  int EmbedId = 1;

  //! apply sPHENIX nominal beam parameter with 2mrad crossing as defined in sPH-TRG-2020-001
  //! \param[in] HepMCGen any HepMC generator, e.g. Fun4AllHepMCInputManager, Fun4AllHepMCPileupInputManager, PHPythia8, PHPythia6, PHSartre, ReadEICFiles
  void ApplysPHENIXBeamParameter(PHHepMCGenHelper *HepMCGen)
  {
    if (HepMCGen == nullptr)
    {
      std::cout << "ApplysPHENIXBeamParameter(): Fatal Error - null input pointer HepMCGen" << std::endl;
      exit(1);
    }
    HepMCGen->set_beam_direction_theta_phi(1e-3, 0, M_PI - 1e-3, 0);  //2mrad x-ing of sPHENIX per sPH-TRG-2020-001

    HepMCGen->set_vertex_distribution_width(
        100e-4,         // approximation from past RICH data
        100e-4,         // approximation from past RICH data
        7,              // sPH-TRG-2020-001. Fig 3.2
        20 / 29.9792);  // 20cm collision length / speed of light in cm/ns
    HepMCGen->set_vertex_distribution_function(
        PHHepMCGenHelper::Gaus,
        PHHepMCGenHelper::Gaus,
        PHHepMCGenHelper::Gaus,
        PHHepMCGenHelper::Gaus);
  }

  //! apply EIC beam parameter to any HepMC generator following EIC CDR,
  //! including in-time collision's space time shift, beam crossing angle and angular divergence
  //! \param[in] HepMCGen any HepMC generator, e.g. Fun4AllHepMCInputManager, Fun4AllHepMCPileupInputManager, PHPythia8, PHPythia6, PHSartre, ReadEICFiles
  void ApplyEICIP6BeamParameter(PHHepMCGenHelper *HepMCGen)
  {
    if (HepMCGen == nullptr)
    {
      std::cout << "ApplyEICIP6BeamParameter(): Fatal Error - null input pointer HepMCGen" << std::endl;
      exit(1);
    }

    HepMCGen->PHHepMCGenHelper_Verbosity(VERBOSITY);

    //25mrad x-ing as in EIC CDR
    const double EIC_hadron_crossing_angle = 25e-3;
    // beta* for 275*x18 collisions
    // Table 4 of
    // https://github.com/eic/documents/blob/master/reports/general/Note-Simulations-BeamEffects.pdf
    const double beta_star_p_h = 80;
    const double beta_star_p_v = 7.1;
    const double beta_star_e_h = 59;
    const double beta_star_e_v = 5.7;
    // Table 1-2 of
    // https://github.com/eic/documents/blob/master/reports/general/Note-Simulations-BeamEffects.pdf
    const double beta_crab_p = 1300e2;
    const double beta_crab_e = 150e2;

    HepMCGen->set_beam_direction_theta_phi(
        EIC_hadron_crossing_angle,  // beamA_theta
        M_PI,                       // beamA_phi
        M_PI,                       // beamB_theta
        0                           // beamB_phi
    );
    // Table 4 of
    // https://github.com/eic/documents/blob/master/reports/general/Note-Simulations-BeamEffects.pdf
    HepMCGen->set_beam_angular_divergence_hv(
        150e-6, 150e-6,  // proton beam divergence horizontal & vertical
        202e-6, 187e-6   // electron beam divergence horizontal & vertical
    );

    // vertex shape from beam_bunch_sim
    HepMCGen->use_beam_bunch_sim(true);

    // angular kick within a bunch as result of crab cavity
    // Eq 5 of
    // https://github.com/eic/documents/blob/master/reports/general/Note-Simulations-BeamEffects.pdf
    HepMCGen->set_beam_angular_z_coefficient_hv(
        -EIC_hadron_crossing_angle / 2. / sqrt(beta_star_p_h * beta_crab_p), 0,
        -EIC_hadron_crossing_angle / 2. / sqrt(beta_star_e_h * beta_crab_e), 0);

    // Table 4 of
    // https://github.com/eic/documents/blob/master/reports/general/Note-Simulations-BeamEffects.pdf
    const double sigma_p_h = sqrt(beta_star_p_h * 18e-7);
    const double sigma_p_v = sqrt(beta_star_p_v * 1.6e-7);
    const double sigma_p_l = 6;
    const double sigma_e_h = sqrt(beta_star_e_h * 24e-7);
    const double sigma_e_v = sqrt(beta_star_e_v * 2.0e-7);
    const double sigma_e_l = 0.9;

    HepMCGen->set_beam_bunch_width(
        std::vector<double>{sigma_p_h, sigma_p_v, sigma_p_l},
        std::vector<double>{sigma_e_h, sigma_e_v, sigma_e_l});
  }

  //! apply EIC beam parameter to any HepMC generator following EIC CDR,
  //! including in-time collision's space time shift, beam crossing angle and angular divergence
  //! \param[in] HepMCGen any HepMC generator, e.g. Fun4AllHepMCInputManager, Fun4AllHepMCPileupInputManager, PHPythia8, PHPythia6, PHSartre, ReadEICFiles
  void ApplyEICIP8BeamParameter(PHHepMCGenHelper *HepMCGen)
  {
    if (HepMCGen == nullptr)
    {
      std::cout << "ApplyEICIP8BeamParameter(): Fatal Error - null input pointer HepMCGen" << std::endl;
      exit(1);
    }

    //25mrad x-ing as in EIC CDR
    const double EIC_hadron_crossing_angle = 35e-3;

    HepMCGen->set_beam_direction_theta_phi(
        EIC_hadron_crossing_angle,  // beamA_theta
        0,                          // beamA_phi
        M_PI,                       // beamB_theta
        0                           // beamB_phi
    );
    HepMCGen->set_beam_angular_divergence_hv(
        119e-6, 119e-6,  // proton beam divergence horizontal & vertical, as in EIC CDR Table 1.1
        211e-6, 152e-6   // electron beam divergence horizontal & vertical, as in EIC CDR Table 1.1
    );

    // angular kick within a bunch as result of crab cavity
    // using an naive assumption of transfer matrix from the cavity to IP,
    // which is NOT yet validated with accelerator optics simulations!
    const double z_hadron_cavity = 52e2;  // CDR Fig 3.3
    const double z_e_cavity = 38e2;       // CDR Fig 3.2
    HepMCGen->set_beam_angular_z_coefficient_hv(
        -EIC_hadron_crossing_angle / 2. / z_hadron_cavity, 0,
        -EIC_hadron_crossing_angle / 2. / z_e_cavity, 0);

    // calculate beam sigma width at IP  as in EIC CDR table 1.1
    const double sigma_p_h = sqrt(80 * 11.3e-7);
    const double sigma_p_v = sqrt(7.2 * 1.0e-7);
    const double sigma_p_l = 6;
    const double sigma_e_h = sqrt(45 * 20.0e-7);
    const double sigma_e_v = sqrt(5.6 * 1.3e-7);
    const double sigma_e_l = 2;

    // combine two beam gives the collision sigma in z
    const double collision_sigma_z = sqrt(sigma_p_l * sigma_p_l + sigma_e_l * sigma_e_l) / 2;
    const double collision_sigma_t = collision_sigma_z / 29.9792;  // speed of light in cm/ns

    HepMCGen->set_vertex_distribution_width(
        sigma_p_h * sigma_e_h / sqrt(sigma_p_h * sigma_p_h + sigma_e_h * sigma_e_h),  //x
        sigma_p_v * sigma_e_v / sqrt(sigma_p_v * sigma_p_v + sigma_e_v * sigma_e_v),  //y
        collision_sigma_z,                                                            //z
        collision_sigma_t);                                                           //t
    HepMCGen->set_vertex_distribution_function(
        PHHepMCGenHelper::Gaus,   //x
        PHHepMCGenHelper::Gaus,   //y
        PHHepMCGenHelper::Gaus,   //z
        PHHepMCGenHelper::Gaus);  //t
  }

  //! apply EIC beam parameter to any HepMC generator following EIC CDR,
  //! including in-time collision's space time shift, beam crossing angle and angular divergence
  //! \param[in] HepMCGen any HepMC generator, e.g. Fun4AllHepMCInputManager, Fun4AllHepMCPileupInputManager, PHPythia8, PHPythia6, PHSartre, ReadEICFiles
  void ApplyEICBeamParameter(PHHepMCGenHelper *HepMCGen)
  {
    if (HepMCGen == nullptr)
    {
      std::cout << "ApplyEICBeamParameter(): Fatal Error - null input pointer HepMCGen" << std::endl;
      exit(1);
    }

    if (Enable::IP6 and Enable::IP8)
    {
      cout << "Can not enable Enable::IP6 and Enable::IP8 at the same time!" << endl;
      gSystem->Exit(1);
    }
    if (Enable::IP6 == false and Enable::IP8 == false)
    {
      cout << "None of the possible EIC IPs were selected: Enable::IP6 and Enable::IP8 !" << endl;
      gSystem->Exit(1);
    }

    if (Enable::IP6)
    {
      ApplyEICIP6BeamParameter(HepMCGen);
    }
    else if (Enable::IP8)
    {
      ApplyEICIP8BeamParameter(HepMCGen);
    }
    else
      // logically impossible
      exit(1);
  }

}  // namespace Input

namespace INPUTHEPMC
{
  string filename;
  string listfile;
  bool FLOW = false;
  int FLOW_VERBOSITY = 0;
  bool FERMIMOTION = false;

}  // namespace INPUTHEPMC

namespace INPUTREADEIC
{
  string filename;
}  // namespace INPUTREADEIC

namespace INPUTREADHITS
{
  map<unsigned int, std::string> filename;
  map<unsigned int, std::string> listfile;
}  // namespace INPUTREADHITS

namespace INPUTEMBED
{
  map<unsigned int, std::string> filename;
  map<unsigned int, std::string> listfile;
}  // namespace INPUTEMBED

namespace PYTHIA6
{
  string config_file = string(getenv("CALIBRATIONROOT")) + "/Generators/phpythia6_e18p275_MinPartonP10GeV.cfg";
}

namespace PYTHIA8
{
  string config_file = string(getenv("CALIBRATIONROOT")) + "/Generators/phpythia8.cfg";
}

namespace SARTRE
{
  string config_file = string(getenv("CALIBRATIONROOT")) + "/Generators/sartre.cfg";
}

namespace PILEUP
{
  string pileupfile = "/sphenix/sim/sim01/sphnxpro/MDC1/sHijing_HepMC/data/sHijing_0_20fm-0000000001-00000.dat";
  double TpcDriftVelocity = 8.0 / 1000.0;
}  // namespace PILEUP

// collection of pointers to particle generators we can grab in the Fun4All macro
namespace INPUTGENERATOR
{
  std::vector<PHG4IonGun *> IonGun;
  std::vector<PHG4ParticleGenerator *> ParticleGenerator;
  std::vector<PHG4ParticleGeneratorD0 *> DZeroMesonGenerator;
  std::vector<PHG4ParticleGeneratorVectorMeson *> VectorMesonGenerator;
  std::vector<PHG4SimpleEventGenerator *> SimpleEventGenerator;
  std::vector<PHG4ParticleGun *> Gun;
  PHPythia6 *Pythia6 = nullptr;
  PHPythia8 *Pythia8 = nullptr;
  PHSartre *Sartre = nullptr;
  PHSartreParticleTrigger *SartreTrigger = nullptr;
  ReadEICFiles *EICFileReader = nullptr;
}  // namespace INPUTGENERATOR

namespace INPUTMANAGER
{
  Fun4AllHepMCInputManager *HepMCInputManager = nullptr;
  Fun4AllHepMCPileupInputManager *HepMCPileupInputManager = nullptr;
}  // namespace INPUTMANAGER

void InputInit()
{
  // first consistency checks - not all input generators play nice
  // with each other
  if (Input::READHITS && Input::EMBED)
  {
    cout << "Reading Hits and Embedding into background at the same time is not supported" << endl;
    gSystem->Exit(1);
  }
  if (Input::READHITS && (Input::PYTHIA6 || Input::PYTHIA8 || Input::SARTRE || Input::SIMPLE || Input::GUN || Input::UPSILON || Input::HEPMC))
  {
    cout << "Reading Hits and running G4 simultanously is not supported" << endl;
    gSystem->Exit(1);
  }
  if (Input::PYTHIA6 && Input::PYTHIA8)
  {
    cout << "Pythia6 and Pythia8 cannot be run together - might be possible but needs R&D" << endl;
    gSystem->Exit(1);
  }

  if (INPUTHEPMC::FLOW && Input::PILEUPRATE > 0)
  {
    cout << "Flow Afterburner and Pileup cannot be run simultanously" << endl;
    gSystem->Exit(1);
  }
  // done with consistency checks, create generators in no specific order

  Fun4AllServer *se = Fun4AllServer::instance();
  if (Input::PYTHIA6)
  {
    INPUTGENERATOR::Pythia6 = new PHPythia6();
    INPUTGENERATOR::Pythia6->set_config_file(PYTHIA6::config_file);

    INPUTGENERATOR::Pythia6->set_embedding_id(Input::EmbedId);
    Input::PYTHIA6_EmbedId = Input::EmbedId;
    Input::EmbedId++;
  }
  if (Input::PYTHIA8)
  {
    INPUTGENERATOR::Pythia8 = new PHPythia8();
    // see coresoftware/generators/PHPythia8 for example config
    INPUTGENERATOR::Pythia8->set_config_file(PYTHIA8::config_file);

    INPUTGENERATOR::Pythia8->set_embedding_id(Input::EmbedId);
    Input::PYTHIA8_EmbedId = Input::EmbedId;
    Input::EmbedId++;
  }
  if (Input::SARTRE)
  {
    gSystem->Load("libPHSartre.so");
    INPUTGENERATOR::Sartre = new PHSartre();
    INPUTGENERATOR::Sartre->set_config_file(SARTRE::config_file);
    // particle trigger to enhance forward J/Psi -> ee
    INPUTGENERATOR::SartreTrigger = new PHSartreParticleTrigger("MySartreTrigger");
    INPUTGENERATOR::SartreTrigger->AddParticles(-11);
    //INPUTGENERATOR::SartreTrigger->SetEtaHighLow(4.0,1.4);
    INPUTGENERATOR::SartreTrigger->SetEtaHighLow(1.0, -1.1);  // central arm
    INPUTGENERATOR::SartreTrigger->PrintConfig();

    INPUTGENERATOR::Sartre->set_embedding_id(Input::EmbedId);
    Input::SARTRE_EmbedId = Input::EmbedId;
    Input::EmbedId++;
  }
  // single particle generators
  if (Input::DZERO)
  {
    for (int i = 0; i < Input::DZERO_NUMBER; ++i)
    {
      std::string name = "DZERO_" + std::to_string(i);
      PHG4ParticleGeneratorD0 *dzero = new PHG4ParticleGeneratorD0(name);
      dzero->Embed(Input::EmbedId);
      Input::DZERO_EmbedIds.insert(Input::EmbedId);
      Input::EmbedId++;
      INPUTGENERATOR::DZeroMesonGenerator.push_back(dzero);
    }
  }
  if (Input::GUN)
  {
    for (int i = 0; i < Input::GUN_NUMBER; ++i)
    {
      std::string name = "GUN_" + std::to_string(i);
      PHG4ParticleGun *gun = new PHG4ParticleGun(name);
      gun->Embed(Input::EmbedId);
      Input::GUN_EmbedIds.insert(Input::EmbedId);
      Input::EmbedId++;
      INPUTGENERATOR::Gun.push_back(gun);
    }
  }
  if (Input::IONGUN)
  {
    for (int i = 0; i < Input::IONGUN_NUMBER; ++i)
    {
      std::string name = "IONGUN_" + std::to_string(i);
      PHG4IonGun *iongun = new PHG4IonGun(name);
      iongun->Embed(Input::EmbedId);
      Input::IONGUN_EmbedIds.insert(Input::EmbedId);
      Input::EmbedId++;
      INPUTGENERATOR::IonGun.push_back(iongun);
    }
  }
  if (Input::PGEN)
  {
    for (int i = 0; i < Input::PGEN_NUMBER; ++i)
    {
      std::string name = "PGEN_" + std::to_string(i);
      PHG4ParticleGenerator *pgen = new PHG4ParticleGenerator(name);
      pgen->Embed(Input::EmbedId);
      Input::PGEN_EmbedIds.insert(Input::EmbedId);
      Input::EmbedId++;
      INPUTGENERATOR::ParticleGenerator.push_back(pgen);
    }
  }
  if (Input::SIMPLE)
  {
    for (int i = 0; i < Input::SIMPLE_NUMBER; ++i)
    {
      std::string name = "EVTGENERATOR_" + std::to_string(i);
      PHG4SimpleEventGenerator *simple = new PHG4SimpleEventGenerator(name);
      simple->Embed(Input::EmbedId);
      Input::PGEN_EmbedIds.insert(Input::EmbedId);
      Input::EmbedId++;
      INPUTGENERATOR::SimpleEventGenerator.push_back(simple);
    }
  }
  if (Input::UPSILON)
  {
    for (int i = 0; i < Input::UPSILON_NUMBER; ++i)
    {
      std::string name = "UPSILON_" + std::to_string(i);
      PHG4ParticleGeneratorVectorMeson *upsilon = new PHG4ParticleGeneratorVectorMeson(name);
      upsilon->Embed(Input::EmbedId);
      Input::UPSILON_EmbedIds.insert(Input::EmbedId);
      Input::EmbedId++;
      INPUTGENERATOR::VectorMesonGenerator.push_back(upsilon);
    }
  }

  // input managers for which we might need to set options
  if (Input::HEPMC)
  {
    INPUTMANAGER::HepMCInputManager = new Fun4AllHepMCInputManager("HEPMCin");
  }
  if (Input::PILEUPRATE > 0)
  {
    INPUTMANAGER::HepMCPileupInputManager = new Fun4AllHepMCPileupInputManager("HepMCPileupInput");
  }
}

void InputRegister()
{
  Fun4AllServer *se = Fun4AllServer::instance();
  if (Input::PYTHIA6)
  {
    se->registerSubsystem(INPUTGENERATOR::Pythia6);
  }
  if (Input::PYTHIA8)
  {
    se->registerSubsystem(INPUTGENERATOR::Pythia8);
  }
  if (Input::SARTRE)
  {
    INPUTGENERATOR::Sartre->register_trigger((PHSartreGenTrigger *) INPUTGENERATOR::SartreTrigger);
    se->registerSubsystem(INPUTGENERATOR::Sartre);
  }
  if (Input::DZERO)
  {
    int verbosity = max(Input::DZERO_VERBOSITY, Input::VERBOSITY);
    for (size_t icnt = 0; icnt < INPUTGENERATOR::DZeroMesonGenerator.size(); ++icnt)
    {
      INPUTGENERATOR::DZeroMesonGenerator[icnt]->Verbosity(verbosity);
      se->registerSubsystem(INPUTGENERATOR::DZeroMesonGenerator[icnt]);
    }
  }
  if (Input::GUN)
  {
    int verbosity = max(Input::GUN_VERBOSITY, Input::VERBOSITY);
    for (size_t icnt = 0; icnt < INPUTGENERATOR::Gun.size(); ++icnt)
    {
      INPUTGENERATOR::Gun[icnt]->Verbosity(verbosity);
      se->registerSubsystem(INPUTGENERATOR::Gun[icnt]);
    }
  }
  if (Input::IONGUN)
  {
    int verbosity = max(Input::IONGUN_VERBOSITY, Input::VERBOSITY);
    for (size_t icnt = 0; icnt < INPUTGENERATOR::IonGun.size(); ++icnt)
    {
      INPUTGENERATOR::IonGun[icnt]->Verbosity(verbosity);
      se->registerSubsystem(INPUTGENERATOR::IonGun[icnt]);
    }
  }
  if (Input::PGEN)
  {
    int verbosity = max(Input::PGEN_VERBOSITY, Input::VERBOSITY);
    for (size_t icnt = 0; icnt < INPUTGENERATOR::ParticleGenerator.size(); ++icnt)
    {
      INPUTGENERATOR::ParticleGenerator[icnt]->Verbosity(verbosity);
      se->registerSubsystem(INPUTGENERATOR::ParticleGenerator[icnt]);
    }
  }
  if (Input::SIMPLE)
  {
    int verbosity = max(Input::SIMPLE_VERBOSITY, Input::VERBOSITY);
    for (size_t icnt = 0; icnt < INPUTGENERATOR::SimpleEventGenerator.size(); ++icnt)
    {
      INPUTGENERATOR::SimpleEventGenerator[icnt]->Verbosity(verbosity);
      se->registerSubsystem(INPUTGENERATOR::SimpleEventGenerator[icnt]);
    }
  }
  if (Input::UPSILON)
  {
    for (size_t icnt = 0; icnt < INPUTGENERATOR::VectorMesonGenerator.size(); ++icnt)
    {
      int verbosity = max(Input::UPSILON_VERBOSITY, Input::VERBOSITY);
      if (Input::HEPMC || Input::SIMPLE)
      {
        INPUTGENERATOR::VectorMesonGenerator[icnt]->set_reuse_existing_vertex(true);
      }
      INPUTGENERATOR::VectorMesonGenerator[icnt]->Verbosity(verbosity);
      se->registerSubsystem(INPUTGENERATOR::VectorMesonGenerator[icnt]);
    }
  }
  if (Input::READEIC)
  {
    INPUTGENERATOR::EICFileReader = new ReadEICFiles();
    INPUTGENERATOR::EICFileReader->OpenInputFile(INPUTREADEIC::filename);
    INPUTGENERATOR::EICFileReader->Verbosity(Input::VERBOSITY);
    se->registerSubsystem(INPUTGENERATOR::EICFileReader);
  }
  // here are the various utility modules which read particles and
  // put them onto the G4 particle stack
  if (Input::HEPMC or Input::PYTHIA8 or Input::PYTHIA6 or Input::READEIC)
  {
    if (Input::HEPMC)
    {
      // these need to be applied before the HepMCNodeReader since they
      // work on the hepmc records
      if (INPUTHEPMC::FLOW)
      {
        HepMCFlowAfterBurner *burn = new HepMCFlowAfterBurner();
        burn->Verbosity(INPUTHEPMC::FLOW_VERBOSITY);
        se->registerSubsystem(burn);
      }
      if (INPUTHEPMC::FERMIMOTION)
      {
        FermimotionAfterburner *fermi = new FermimotionAfterburner();
        se->registerSubsystem(fermi);
      }
    }
    // copy HepMC records into G4
    HepMCNodeReader *hr = new HepMCNodeReader();
    se->registerSubsystem(hr);
  }
}

void InputManagers()
{
  Fun4AllServer *se = Fun4AllServer::instance();
  if (Input::EMBED)
  {
    gSystem->Load("libg4dst.so");
    if (!INPUTEMBED::filename.empty() && !INPUTEMBED::listfile.empty())
    {
      cout << "only filenames or filelists are supported, not mixtures" << endl;
      gSystem->Exit(1);
    }
    if (INPUTEMBED::filename.empty() && INPUTEMBED::listfile.empty())
    {
      cout << "you need to give an input filenames or filelist" << endl;
      gSystem->Exit(1);
    }
    for (auto iter = INPUTEMBED::filename.begin(); iter != INPUTEMBED::filename.end(); ++iter)
    {
      string mgrname = "DSTin" + to_string(iter->first);
      Fun4AllInputManager *hitsin = new Fun4AllDstInputManager(mgrname);
      hitsin->fileopen(iter->second);
      hitsin->Verbosity(Input::VERBOSITY);
      hitsin->Repeat();
      se->registerInputManager(hitsin);
    }
    for (auto iter = INPUTEMBED::listfile.begin(); iter != INPUTEMBED::listfile.end(); ++iter)
    {
      string mgrname = "DSTin" + to_string(iter->first);
      Fun4AllInputManager *hitsin = new Fun4AllDstInputManager(mgrname);
      hitsin->AddListFile(iter->second);
      hitsin->Verbosity(Input::VERBOSITY);
      hitsin->Repeat();
      se->registerInputManager(hitsin);
    }
  }
  if (Input::HEPMC)
  {
    INPUTMANAGER::HepMCInputManager->Verbosity(Input::VERBOSITY);
    se->registerInputManager(INPUTMANAGER::HepMCInputManager);
    if (!INPUTHEPMC::filename.empty() && INPUTHEPMC::listfile.empty())
    {
      INPUTMANAGER::HepMCInputManager->fileopen(INPUTHEPMC::filename);
    }
    else if (!INPUTHEPMC::listfile.empty())
    {
      INPUTMANAGER::HepMCInputManager->AddListFile(INPUTHEPMC::listfile);
    }
    else
    {
      cout << "no filename INPUTHEPMC::filename or listfile INPUTHEPMC::listfile given" << endl;
      gSystem->Exit(1);
    }
  }
  else if (Input::READHITS)
  {
    gSystem->Load("libg4dst.so");
    if (!INPUTREADHITS::filename.empty() && !INPUTREADHITS::listfile.empty())
    {
      cout << "only filenames or filelists are supported, not mixtures" << endl;
      gSystem->Exit(1);
    }
    if (INPUTREADHITS::filename.empty() && INPUTREADHITS::listfile.empty())
    {
      cout << "you need to give an input filenames or filelist" << endl;
      gSystem->Exit(1);
    }
    for (auto iter = INPUTREADHITS::filename.begin(); iter != INPUTREADHITS::filename.end(); ++iter)
    {
      string mgrname = "DSTin" + to_string(iter->first);
      Fun4AllInputManager *hitsin = new Fun4AllDstInputManager(mgrname);
      hitsin->fileopen(iter->second);
      hitsin->Verbosity(Input::VERBOSITY);
      se->registerInputManager(hitsin);
    }
    for (auto iter = INPUTREADHITS::listfile.begin(); iter != INPUTREADHITS::listfile.end(); ++iter)
    {
      string mgrname = "DSTin" + to_string(iter->first);
      Fun4AllInputManager *hitsin = new Fun4AllDstInputManager(mgrname);
      hitsin->AddListFile(iter->second);
      hitsin->Verbosity(Input::VERBOSITY);
      se->registerInputManager(hitsin);
    }
  }
  else
  {
    Fun4AllInputManager *in = new Fun4AllDummyInputManager("JADE");
    in->Verbosity(Input::VERBOSITY);
    se->registerInputManager(in);
  }
  if (Input::PILEUPRATE > 0)
  {
    INPUTMANAGER::HepMCPileupInputManager->SignalInputManager(INPUTMANAGER::HepMCInputManager);
    INPUTMANAGER::HepMCPileupInputManager->Verbosity(Input::VERBOSITY);
    INPUTMANAGER::HepMCPileupInputManager->AddFile(PILEUP::pileupfile);
    INPUTMANAGER::HepMCPileupInputManager->set_collision_rate(Input::PILEUPRATE);
    double time_window = 105.5 / PILEUP::TpcDriftVelocity;
    INPUTMANAGER::HepMCPileupInputManager->set_time_window(-time_window, time_window);
    se->registerInputManager(INPUTMANAGER::HepMCPileupInputManager);
  }
}
#endif
