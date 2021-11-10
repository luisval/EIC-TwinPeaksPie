void ana_run(){
gROOT->Reset();


std::cout << "Processing data..." << std::endl;   

gROOT->ProcessLine("TChain * chain_dat = new TChain(\"tracktree\")");

gROOT->ProcessLine("chain_dat->Add(\"/home/luis/software/nuclearexp/condor/EICDetector/*calData.root\") ");


gROOT->ProcessLine(".L Matching.C");
gROOT->ProcessLine("Matching m");
gROOT->ProcessLine("m.Init(chain_dat)");
gROOT->ProcessLine("m.Loop()");


}