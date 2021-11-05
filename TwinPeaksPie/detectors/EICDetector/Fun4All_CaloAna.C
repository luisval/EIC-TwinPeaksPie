#pragma once
#if ROOT_VERSION_CODE >= ROOT_VERSION(6,00,0)
#include <fun4all/SubsysReco.h>
#include <fun4all/Fun4AllServer.h>
#include <fun4all/Fun4AllInputManager.h>
#include <fun4all/Fun4AllDstInputManager.h>

#include </home/luis/software/nuclearexp/EIC/clean/July2021Concept/src/install/include/caldata/CalData.h>

R__LOAD_LIBRARY(libfun4all.so)
R__LOAD_LIBRARY(/home/luis/software/nuclearexp/EIC/clean/July2021Concept/src/install/lib/libcaldata.so)
#endif

void Fun4All_CaloAna(){

  gSystem->Load("libg4dst");
 // gSystem->Load("libcaloana");
  Fun4AllServer *se = Fun4AllServer::instance();
  
  ////////////CalData////////////////////////////////////////////////////////////
  CalData *calData = new CalData("calData","DISepcalData_JulyConcept_test.root");
  calData->setMinJetPt(3.);
  calData->Verbosity(0);
  calData->analyzeTracks(true);
  calData->analyzeClusters(true);
  calData->analyzeJets(true);
  calData->analyzeTruth(false);
  se->registerSubsystem(calData);
  //////////////////////////////////////////////////////////////////////////////

  Fun4AllInputManager *in = new Fun4AllDstInputManager("DSTin");
 // in->AddListFile("fileList_dst.txt");
  in->AddListFile("fileList-few.txt");
  se->registerInputManager(in);
  se->run();
  se->End();

}

