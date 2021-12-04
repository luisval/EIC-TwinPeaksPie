// Description:
//       Analysis macro: this macro estimates the pion's rejection coefficient and it plots the coefficient 
//       as a function of the momentum.// Environment:
//      ROOT
//
// Author List:
//       Luis Valenzuela Cazares          (original author)
//   
//-----------------------------------------------------------
////////////////////////////////////////////////////////////////

Int_t PirejectionHCal()
{
  
TFile *file0 = TFile::Open("HETow_cut_revisited_hq2_pi_1-20GeV.root");
TFile *file1 = TFile::Open("HETow_cut_revisited_hq2_pi_1-3GeV.root");
TFile *file2 = TFile::Open("HETow_cut_revisited_hq2_pi_3-5GeV.root");
TFile *file3 = TFile::Open("HETow_cut_revisited_hq2_pi_5-7.5GeV.root");
TFile *file4 = TFile::Open("HETow_cut_revisited_hq2_pi_7.5-10GeV.root");
TFile *file5 = TFile::Open("HETow_cut_revisited_hq2_pi_10-12.5GeV.root");
TFile *file6 = TFile::Open("HETow_cut_revisited_hq2_pi_12.5-15GeV.root");
TFile *file7 = TFile::Open("HETow_cut_revisited_hq2_pi_15-17.5GeV.root");
TFile *file8 = TFile::Open("HETow_cut_revisited_hq2_pi_17.5-20GeV.root");

/*
TFile *file1 = TFile::Open("G4EICDetector_out_pi_1-5GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_pi_5-10GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_pi_10-20GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_pi_1-20GeV.root");
*/
/*
TFile *file1 = TFile::Open("Epcut_G4EICDetector_out_hq2_pi_0.5-1GeV.root");
TFile *file2 = TFile::Open("Epcut_G4EICDetector_out_hq2_pi_1-2GeV.root");
TFile *file3 = TFile::Open("Epcut_G4EICDetector_out_hq2_pi_2-5GeV.root");
TFile *file4 = TFile::Open("Epcut_G4EICDetector_out_hq2_pi_5-10GeV.root"); 
*/
/*
TFile *file1 = TFile::Open("G4EICDetector_out_low_pi_1-5GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_low_pi_5-10GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_low_pi_10-20GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_low_pi_1-20GeV.root"); 
*/
       if (file1 && file2 && file3 &&file4->IsZombie()) { cout << "Error opening a file" << endl;
              exit(-1);} 
       else {cout << "Files are okay" << endl;}
 
//  gStyle->SetOptTitle(0); //No title for histograms
 // gStyle->SetOptStat(0);
  
  TH1F *h1_tow_E = (TH1F*)file1->Get("h_tow_E");
        h1_tow_E->GetXaxis()->SetTitle("Tower E (GeV)");
        h1_tow_E->GetYaxis()->SetTitle("Counts");
        h1_tow_E->SetFillColor(0); 
        h1_tow_E->SetLineColor(1);
        h1_tow_E->SetLineWidth(6);  

  TH1F *h2_tow_E = (TH1F*)file2->Get("h_tow_E");
        h2_tow_E->GetXaxis()->SetTitle("Tower E (GeV)");
        h2_tow_E->GetYaxis()->SetTitle("Counts");
        h2_tow_E->SetFillColor(0); 
        h2_tow_E->SetLineColor(1);
        h2_tow_E->SetLineWidth(6);  

  TH1F *h3_tow_E = (TH1F*)file3->Get("h_tow_E");
        h3_tow_E->GetXaxis()->SetTitle("Tower E (GeV)");
        h3_tow_E->GetYaxis()->SetTitle("Counts");
        h3_tow_E->SetFillColor(0); 
        h3_tow_E->SetLineColor(1);
        h3_tow_E->SetLineWidth(6);  
     
  TH1F *h4_tow_E = (TH1F*)file4->Get("h_tow_E");
        h4_tow_E->GetXaxis()->SetTitle("Tower E (GeV)");
        h4_tow_E->GetYaxis()->SetTitle("Counts");
        h4_tow_E->SetFillColor(0); 
        h4_tow_E->SetLineColor(1);
        h4_tow_E->SetLineWidth(6);  

  TH1F *h5_tow_E = (TH1F*)file5->Get("h_tow_E");
        h5_tow_E->GetXaxis()->SetTitle("Tower E (GeV)");
        h5_tow_E->GetYaxis()->SetTitle("Counts");
        h5_tow_E->SetFillColor(0); 
        h5_tow_E->SetLineColor(1);
        h5_tow_E->SetLineWidth(6);  

  TH1F *h6_tow_E = (TH1F*)file6->Get("h_tow_E");
        h6_tow_E->GetXaxis()->SetTitle("Tower E (GeV)");
        h6_tow_E->GetYaxis()->SetTitle("Counts");
        h6_tow_E->SetFillColor(0); 
        h6_tow_E->SetLineColor(1);
        h6_tow_E->SetLineWidth(6);  

  TH1F *h7_tow_E = (TH1F*)file7->Get("h_tow_E");
        h7_tow_E->GetXaxis()->SetTitle("Tower E (GeV)");
        h7_tow_E->GetYaxis()->SetTitle("Counts");
        h7_tow_E->SetFillColor(0); 
        h7_tow_E->SetLineColor(1);
        h7_tow_E->SetLineWidth(6);  

  TH1F *h8_tow_E = (TH1F*)file8->Get("h_tow_E");
        h8_tow_E->GetXaxis()->SetTitle("Tower E (GeV)");
        h8_tow_E->GetYaxis()->SetTitle("Counts");
        h8_tow_E->SetFillColor(0); 
        h8_tow_E->SetLineColor(1);
        h8_tow_E->SetLineWidth(6);  

////////////Total pions (or kaons)////////////////////////////////////// 
  TH1F *h1_track_p_all = (TH1F*)file1->Get("h_track_p_all");
        h1_track_p_all->GetXaxis()->SetTitle("track p");
        h1_track_p_all->GetYaxis()->SetTitle("Counts");
        h1_track_p_all->SetFillColor(0); 
        h1_track_p_all->SetLineColor(1);
        h1_track_p_all->SetLineWidth(6);  

  TH1F *h2_track_p_all = (TH1F*)file2->Get("h_track_p_all");
        h2_track_p_all->GetXaxis()->SetTitle("track p");
        h2_track_p_all->GetYaxis()->SetTitle("Counts");
        h2_track_p_all->SetFillColor(0); 
        h2_track_p_all->SetLineColor(1);
        h2_track_p_all->SetLineWidth(6);  

  TH1F *h3_track_p_all = (TH1F*)file3->Get("h_track_p_all");
        h3_track_p_all->GetXaxis()->SetTitle("track p");
        h3_track_p_all->GetYaxis()->SetTitle("Counts");
        h3_track_p_all->SetFillColor(0); 
        h3_track_p_all->SetLineColor(1);
        h3_track_p_all->SetLineWidth(6);  

  TH1F *h4_track_p_all = (TH1F*)file4->Get("h_track_p_all");
        h4_track_p_all->GetXaxis()->SetTitle("track p");
        h4_track_p_all->GetYaxis()->SetTitle("Counts");
        h4_track_p_all->SetFillColor(0); 
        h4_track_p_all->SetLineColor(1);
        h4_track_p_all->SetLineWidth(6);


  TH1F *h5_track_p_all = (TH1F*)file5->Get("h_track_p_all");
        h5_track_p_all->GetXaxis()->SetTitle("track p");
        h5_track_p_all->GetYaxis()->SetTitle("Counts");
        h5_track_p_all->SetFillColor(0); 
        h5_track_p_all->SetLineColor(1);
        h5_track_p_all->SetLineWidth(6);


  TH1F *h6_track_p_all = (TH1F*)file6->Get("h_track_p_all");
        h6_track_p_all->GetXaxis()->SetTitle("track p");
        h6_track_p_all->GetYaxis()->SetTitle("Counts");
        h6_track_p_all->SetFillColor(0); 
        h6_track_p_all->SetLineColor(1);
        h6_track_p_all->SetLineWidth(6);

  TH1F *h7_track_p_all = (TH1F*)file7->Get("h_track_p_all");
        h7_track_p_all->GetXaxis()->SetTitle("track p");
        h7_track_p_all->GetYaxis()->SetTitle("Counts");
        h7_track_p_all->SetFillColor(0); 
        h7_track_p_all->SetLineColor(1);
        h7_track_p_all->SetLineWidth(6);

  TH1F *h8_track_p_all = (TH1F*)file8->Get("h_track_p_all");
        h8_track_p_all->GetXaxis()->SetTitle("track p");
        h8_track_p_all->GetYaxis()->SetTitle("Counts");
        h8_track_p_all->SetFillColor(0); 
        h8_track_p_all->SetLineColor(1);
        h8_track_p_all->SetLineWidth(6);   

/////////////////////////////////////////////////////
        Int_t nbinsh1 = h1_tow_E->Integral();
        Int_t nbinsh2 = h2_tow_E->Integral();
        Int_t nbinsh3 = h3_tow_E->Integral();
        Int_t nbinsh4 = h4_tow_E->Integral();

      //h1_tow_E->Scale(1./(h1_tow_E)->Integral());
 
        float totalIntegral_pi1 = h1_track_p_all->Integral(h1_track_p_all->FindFixBin(0), h1_track_p_all->FindFixBin(20));
        float totalIntegral_pi2 = h2_track_p_all->Integral(h2_track_p_all->FindFixBin(0), h2_track_p_all->FindFixBin(20));
        float totalIntegral_pi3 = h3_track_p_all->Integral(h3_track_p_all->FindFixBin(0), h3_track_p_all->FindFixBin(20));
        float totalIntegral_pi4 = h4_track_p_all->Integral(h4_track_p_all->FindFixBin(0), h4_track_p_all->FindFixBin(20));
        float totalIntegral_pi5 = h5_track_p_all->Integral(h5_track_p_all->FindFixBin(0), h5_track_p_all->FindFixBin(20));
        float totalIntegral_pi6 = h6_track_p_all->Integral(h6_track_p_all->FindFixBin(0), h6_track_p_all->FindFixBin(20));
        float totalIntegral_pi7 = h7_track_p_all->Integral(h7_track_p_all->FindFixBin(0), h7_track_p_all->FindFixBin(20));
        float totalIntegral_pi8 = h8_track_p_all->Integral(h8_track_p_all->FindFixBin(0), h8_track_p_all->FindFixBin(20));


       float pi_cut1 = h1_tow_E->Integral(h1_tow_E->FindFixBin(0), h1_tow_E->FindFixBin(1));
       float pi_cut2 = h2_tow_E->Integral(h2_tow_E->FindFixBin(0), h2_tow_E->FindFixBin(1));
       float pi_cut3 = h3_tow_E->Integral(h3_tow_E->FindFixBin(0), h3_tow_E->FindFixBin(1));
       float pi_cut4 = h4_tow_E->Integral(h4_tow_E->FindFixBin(0), h4_tow_E->FindFixBin(1));
       float pi_cut5 = h5_tow_E->Integral(h5_tow_E->FindFixBin(0), h5_tow_E->FindFixBin(1));
       float pi_cut6 = h6_tow_E->Integral(h6_tow_E->FindFixBin(0), h6_tow_E->FindFixBin(1));
       float pi_cut7 = h7_tow_E->Integral(h7_tow_E->FindFixBin(0), h7_tow_E->FindFixBin(1));
       float pi_cut8 = h8_tow_E->Integral(h8_tow_E->FindFixBin(0), h8_tow_E->FindFixBin(1));


        float rej1_pi= totalIntegral_pi1/pi_cut1; 
        float rej2_pi= totalIntegral_pi2/pi_cut2; 
        float rej3_pi= totalIntegral_pi3/pi_cut3; 
        float rej4_pi= totalIntegral_pi4/pi_cut4; 
        float rej5_pi= totalIntegral_pi5/pi_cut5; 
        float rej6_pi= totalIntegral_pi6/pi_cut6; 
        float rej7_pi= totalIntegral_pi7/pi_cut7; 
        float rej8_pi= totalIntegral_pi8/pi_cut8; 

        
        cout <<"Total pions: " << totalIntegral_pi1 << endl;
        cout <<"Total pions: " << totalIntegral_pi2 << endl;
        cout <<"Total pions: " << totalIntegral_pi3 << endl;
        cout <<"Total pions: " << totalIntegral_pi4 << endl;
        cout <<"Total pions: " << totalIntegral_pi5 << endl;
        cout <<"Total pions: " << totalIntegral_pi6 << endl;
        cout <<"Total pions: " << totalIntegral_pi7 << endl;
        cout <<"Total pions: " << totalIntegral_pi8 << endl;


        cout <<"Pions cut: " << pi_cut1 << endl;
        cout <<"Pions cut: " << pi_cut2 << endl;
        cout <<"Pions cut: " << pi_cut3 << endl;
        cout <<"Pions cut: " << pi_cut4 << endl;
        cout <<"Pions cut: " << pi_cut5 << endl;
        cout <<"Pions cut: " << pi_cut6 << endl;
        cout <<"Pions cut: " << pi_cut7 << endl;
        cout <<"Pions cut: " << pi_cut8 << endl;

        cout <<"rej1_pi: " << rej1_pi << endl;
        cout <<"rej2_pi: " << rej2_pi << endl;
        cout <<"rej3_pi: " << rej3_pi << endl;
        cout <<"rej4_pi: " << rej4_pi << endl;
        cout <<"rej5_pi: " << rej5_pi << endl;
        cout <<"rej6_pi: " << rej6_pi << endl;
        cout <<"rej7_pi: " << rej7_pi << endl;
        cout <<"rej8_pi: " << rej8_pi << endl;


  // h1_tow_E->Scale(1./(nbintstotal));

 TCanvas *c2 = new TCanvas("c2","#pi^{-} rejection ",200,10,500,300);
  TGraph* gr1 = new TGraph();
  TGraph* gr2 = new TGraph();
  TGraph* gr3 = new TGraph();
  TGraph* gr4 = new TGraph();
  TGraph* gr5 = new TGraph();
  TGraph* gr6 = new TGraph();
  TGraph* gr7 = new TGraph();
//  TGraph* gr8 = new TGraph();


  TMultiGraph *mg = new TMultiGraph();
      mg->SetTitle("#pi^{-} rejection;p_{max}(GeV); #pi^{-} rejection");
      mg->GetXaxis()->SetLimits(0.1, 1.02);
      mg->GetXaxis()->SetTitleOffset(1.2);
      mg->GetYaxis()->SetTitleOffset(1.2);
      mg->GetXaxis()->CenterTitle();
      mg->GetYaxis()->CenterTitle();      

   TAxis *axis1 = gr1->GetXaxis();
   axis1->SetLimits(0.2,21.0); // along X
  
   mg->Add(gr1,"");
   // mg->Add(gr1,"ALP");
    mg->Add(gr2,"");
    mg->Add(gr3,"");
    mg->Add(gr4,"");
    mg->Add(gr5,"");
    mg->Add(gr6,"");
    mg->Add(gr7,"");
   // mg->Add(gr8,"");
    mg->Draw("ap");
     
   gr1->SetName("gr1");
   gr1->SetTitle("1-3 GeV");
   gr1->SetMarkerStyle(21);
   gr1->SetMarkerSize(2);
  // gr1->SetLineColor(1);
  // gr1->SetLineWidth(4);
   gr1->SetFillStyle(0);
 
   gr2->SetName("gr2");
   gr2->SetTitle("3-5 GeV");
   gr2->SetMarkerStyle(22);
   gr2->SetMarkerColor(41);
   gr2->SetMarkerSize(2);
  // gr2->SetLineColor(41);
  // gr2->SetLineWidth(4);
   gr2->SetFillStyle(0);

   gr3->SetName("gr3");
   gr3->SetTitle("5-7.5 GeV");
   gr3->SetMarkerStyle(23);
   gr3->SetMarkerColor(46);
   gr3->SetMarkerSize(2);
  // gr3->SetLineColor(46);
  // gr3->SetLineWidth(4);
   gr3->SetFillStyle(0);

   gr4->SetName("gr4");
   gr4->SetTitle("7.5-10 GeV");
   gr4->SetMarkerStyle(20);
   gr4->SetMarkerColor(47);
   gr4->SetMarkerSize(2);
  // gr4->SetLineColor(49);
  // gr4->SetLineWidth(4);
   gr4->SetFillStyle(0);

   gr5->SetName("gr5");
   gr5->SetTitle("10-12.5 GeV");
   gr5->SetMarkerStyle(24);
   gr5->SetMarkerColor(48);
   gr5->SetMarkerSize(2);
  // gr5->SetLineColor(49);
  // gr5->SetLineWidth(4);
   gr5->SetFillStyle(0);

  gr6->SetName("gr6");
   gr6->SetTitle("12.5-15 GeV");
   gr6->SetMarkerStyle(25);
   gr6->SetMarkerColor(49);
   gr6->SetMarkerSize(2);
  // gr6->SetLineColor(49);
  // gr6->SetLineWidth(4);
   gr6->SetFillStyle(0);


  gr7->SetName("gr7");
   gr7->SetTitle("15-17.5 GeV");
   gr7->SetMarkerStyle(26);
   gr7->SetMarkerColor(50);
   gr7->SetMarkerSize(2);
  // gr7->SetLineColor(49);
  // gr7->SetLineWidth(4);
   gr7->SetFillStyle(0);

/*
  gr8->SetName("gr8");
   gr8->SetTitle("17.5-20 GeV");
   gr8->SetMarkerStyle(27);
   gr8->SetMarkerColor(48);
   gr8->SetMarkerSize(2);
  // gr8->SetLineColor(49);
  // gr8->SetLineWidth(4);
   gr8->SetFillStyle(0);
*/

/*
  gr1->SetPoint(1,5.0,rej1_pi);
  gr2->SetPoint(2,10.0,rej2_pi);
  gr3->SetPoint(3,20.0,rej3_pi);
  gr4->SetPoint(4,20.0,rej4_pi);
*/
  gr1->SetPoint(1,3.0,rej1_pi);
  gr2->SetPoint(2,5.0,rej2_pi);
  gr3->SetPoint(3,7.5,rej3_pi);
  gr4->SetPoint(4,10.0,rej4_pi);
  gr5->SetPoint(3,12.5,rej5_pi);
  gr6->SetPoint(3,15.0,rej6_pi);
  gr7->SetPoint(3,17.5,rej7_pi);
 // gr8->SetPoint(3,20.0,rej8_pi);


  c2->BuildLegend();

  c2->SaveAs("Rej.gif");

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  cout<<"End of the program. Gracias"<<endl;
  return 0;  
}

