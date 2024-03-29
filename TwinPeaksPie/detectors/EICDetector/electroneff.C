// Description:
//      
//       Analysis macro: this macro plots the coefficient of Energy/momentum distributions 
//       of both electrons and pions.
// Environment:
//      ROOT
//
// Author List:
//       Luis Valenzuela Cazares          (original author)
//   
//-----------------------------------------------------------
////////////////////////////////////////////////////////////////

Int_t electroneff()
{


TFile *file1 = TFile::Open("G4EICDetector_out_e_1-5GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_e_5-10GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_e_10-20GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_e_1-20GeV.root");

  /*
TFile *file1 = TFile::Open("G4EICDetector_out_pi_1-5GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_pi_5-10GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_pi_10-20GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_pi_1-20GeV.root");
*/
/*
TFile *file1 = TFile::Open("G4EICDetector_out_k_1-5GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_k_5-10GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_k_10-20GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_k_1-20GeV.root");
*/

/*
TFile *file1 = TFile::Open("revisited_G4EICDetector_out_hq2_e_0.5-1.0GeV.root");
TFile *file2 = TFile::Open("revisited_G4EICDetector_out_hq2_e_1-2GeV.root");
TFile *file3 = TFile::Open("revisited_G4EICDetector_out_hq2_e_2-5GeV.root");
TFile *file4 = TFile::Open("revisited_G4EICDetector_out_hq2_e_5-10GeV.root");
*/

/*
TFile *file1 = TFile::Open("revisited_G4EICDetector_out_hq2_pi_0.5-1.0GeV.root");
TFile *file2 = TFile::Open("revisited_G4EICDetector_out_hq2_pi_1-2GeV.root");
TFile *file3 = TFile::Open("revisited_G4EICDetector_out_hq2_pi_2-5GeV.root");
TFile *file4 = TFile::Open("revisited_G4EICDetector_out_hq2_pi_5-10GeV.root");
*/
/*
TFile *file1 = TFile::Open("revisited_G4EICDetector_out_hq2_k_0.5-1.0GeV.root");
TFile *file2 = TFile::Open("revisited_G4EICDetector_out_hq2_k_1-2GeV.root");
TFile *file3 = TFile::Open("revisited_G4EICDetector_out_hq2_k_2-5GeV.root");
TFile *file4 = TFile::Open("revisited_G4EICDetector_out_hq2_k_5-10GeV.root");
*/

/*
TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_0.5-1.0GeV.root");
TFile *file2 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_1-2GeV.root");
TFile *file3 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_2-5GeV.root");
TFile *file4 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_5-10GeV.root");
*/
//Pions
/*TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_0.5-1.0GeV.root");
TFile *file2 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_1-2GeV.root");
TFile *file3 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_2-5GeV.root");
TFile *file4 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_5-10GeV.root"); */

//Kaons

/*
TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_k_0.5-1.0GeV.root");
TFile *file2 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_k_1-2GeV.root");
TFile *file3 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_k_2-5GeV.root");
TFile *file4 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_k_5-10GeV.root");
*/

       if (file1 && file2 && file3 && file4->IsZombie()) { cout << "Error opening a file" << endl;
       exit(-1);} 
       else {cout << "Files are okay" << endl;}
 
//  gStyle->SetOptTitle(0); //No title for histograms
 // gStyle->SetOptStat(0);
  
  TH1F *h1_EMCal_Ep = (TH1F*)file1->Get("h_EMCal_Ep");
        h1_EMCal_Ep->GetXaxis()->SetTitle("Becal E/p");
        h1_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h1_EMCal_Ep->SetFillColor(0); 
        h1_EMCal_Ep->SetLineColor(1);
        h1_EMCal_Ep->SetLineWidth(3);  
        h1_EMCal_Ep->Rebin(10);        
      //  h1_EMCal_Ep->GetYaxis()->SetRange(0,100);   

  TH1F *h2_EMCal_Ep = (TH1F*)file2->Get("h_EMCal_Ep");
        h2_EMCal_Ep->GetXaxis()->SetTitle("Becal E/p");
        h2_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h2_EMCal_Ep->SetFillColor(0); 
        h2_EMCal_Ep->SetLineColor(41);
        h2_EMCal_Ep->SetLineWidth(3);  
        h2_EMCal_Ep->Rebin(10);           
       // h2_EMCal_Ep->GetYaxis()->SetRange(0,100);   

  TH1F *h3_EMCal_Ep = (TH1F*)file3->Get("h_EMCal_Ep");
        h3_EMCal_Ep->GetXaxis()->SetTitle("Becal E/p");
        h3_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h3_EMCal_Ep->SetFillColor(0);    
        h3_EMCal_Ep->SetLineColor(46);
        h3_EMCal_Ep->SetLineWidth(3);  
        h3_EMCal_Ep->Rebin(10);       
      //  h3_EMCal_Ep->GetYaxis()->SetRange(0,100);   
    
   
  TH1F *h4_EMCal_Ep = (TH1F*)file4->Get("h_EMCal_Ep");
        h4_EMCal_Ep->GetXaxis()->SetTitle("Becal E/p");
        h4_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h4_EMCal_Ep->SetFillColor(0);    
        h4_EMCal_Ep->SetLineColor(49);
        h4_EMCal_Ep->SetLineWidth(3);  
        h4_EMCal_Ep->Rebin(10);    
       // h4_EMCal_Ep->GetYaxis()->SetRange(0,100);   
       

        Int_t nbinsh1 = h1_EMCal_Ep->Integral();
        Int_t nbinsh2 = h2_EMCal_Ep->Integral();
        Int_t nbinsh3 = h3_EMCal_Ep->Integral();
        Int_t nbinsh4 = h4_EMCal_Ep->Integral();

        Int_t nbintstotal = nbinsh1+nbinsh2+nbinsh3+nbinsh4;

      //h1_EMCal_Ep->Scale(1./(h1_EMCal_Ep)->Integral());
     // h2_EMCal_Ep->Scale(1./(h2_EMCal_Ep)->Integral());
     // h3_EMCal_Ep->Scale(1./(h3_EMCal_Ep)->Integral());

        float totalIntegral_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0), h1_EMCal_Ep->FindFixBin(2));
        
        float rangeIntegral1_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(1), h1_EMCal_Ep->FindFixBin(2));
        float rangeIntegral2_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0.9), h1_EMCal_Ep->FindFixBin(2));
        float rangeIntegral3_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0.8), h1_EMCal_Ep->FindFixBin(2));
        float rangeIntegral4_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0.7), h1_EMCal_Ep->FindFixBin(2));
        float rangeIntegral5_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0.6), h1_EMCal_Ep->FindFixBin(2));
        float rangeIntegral6_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0.5), h1_EMCal_Ep->FindFixBin(2));
        float rangeIntegral7_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0.4), h1_EMCal_Ep->FindFixBin(2));
      /*  float rangeIntegral8_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0.3), h1_EMCal_Ep->FindFixBin(2));
        float rangeIntegral9_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0.2), h1_EMCal_Ep->FindFixBin(2));
        float rangeIntegral10_e = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0.1), h1_EMCal_Ep->FindFixBin(2)); */

        float totalIntegral_e2 = h2_EMCal_Ep->Integral(h2_EMCal_Ep->FindFixBin(0), h2_EMCal_Ep->FindFixBin(2));
        
        float rangeIntegral1_e2 = h2_EMCal_Ep->Integral(h2_EMCal_Ep->FindFixBin(1), h2_EMCal_Ep->FindFixBin(2));
        float rangeIntegral2_e2 = h2_EMCal_Ep->Integral(h2_EMCal_Ep->FindFixBin(0.9), h2_EMCal_Ep->FindFixBin(2));
        float rangeIntegral3_e2 = h2_EMCal_Ep->Integral(h2_EMCal_Ep->FindFixBin(0.8), h2_EMCal_Ep->FindFixBin(2));
        float rangeIntegral4_e2 = h2_EMCal_Ep->Integral(h2_EMCal_Ep->FindFixBin(0.7), h2_EMCal_Ep->FindFixBin(2));
        float rangeIntegral5_e2 = h2_EMCal_Ep->Integral(h2_EMCal_Ep->FindFixBin(0.6), h2_EMCal_Ep->FindFixBin(2));
        float rangeIntegral6_e2 = h2_EMCal_Ep->Integral(h2_EMCal_Ep->FindFixBin(0.5), h2_EMCal_Ep->FindFixBin(2));
        float rangeIntegral7_e2 = h2_EMCal_Ep->Integral(h2_EMCal_Ep->FindFixBin(0.4), h2_EMCal_Ep->FindFixBin(2));

        float totalIntegral_e3 = h3_EMCal_Ep->Integral(h3_EMCal_Ep->FindFixBin(0), h3_EMCal_Ep->FindFixBin(2));
        
        float rangeIntegral1_e3 = h3_EMCal_Ep->Integral(h3_EMCal_Ep->FindFixBin(1), h3_EMCal_Ep->FindFixBin(2));
        float rangeIntegral2_e3 = h3_EMCal_Ep->Integral(h3_EMCal_Ep->FindFixBin(0.9), h3_EMCal_Ep->FindFixBin(2));
        float rangeIntegral3_e3 = h3_EMCal_Ep->Integral(h3_EMCal_Ep->FindFixBin(0.8), h3_EMCal_Ep->FindFixBin(2));
        float rangeIntegral4_e3 = h3_EMCal_Ep->Integral(h3_EMCal_Ep->FindFixBin(0.7), h3_EMCal_Ep->FindFixBin(2));
        float rangeIntegral5_e3 = h3_EMCal_Ep->Integral(h3_EMCal_Ep->FindFixBin(0.6), h3_EMCal_Ep->FindFixBin(2));
        float rangeIntegral6_e3 = h3_EMCal_Ep->Integral(h3_EMCal_Ep->FindFixBin(0.5), h3_EMCal_Ep->FindFixBin(2));
        float rangeIntegral7_e3 = h3_EMCal_Ep->Integral(h3_EMCal_Ep->FindFixBin(0.4), h3_EMCal_Ep->FindFixBin(2));

        float totalIntegral_e4 = h4_EMCal_Ep->Integral(h4_EMCal_Ep->FindFixBin(0), h3_EMCal_Ep->FindFixBin(2));
        
        float rangeIntegral1_e4 = h4_EMCal_Ep->Integral(h4_EMCal_Ep->FindFixBin(1), h4_EMCal_Ep->FindFixBin(2));
        float rangeIntegral2_e4 = h4_EMCal_Ep->Integral(h4_EMCal_Ep->FindFixBin(0.9), h4_EMCal_Ep->FindFixBin(2));
        float rangeIntegral3_e4 = h4_EMCal_Ep->Integral(h4_EMCal_Ep->FindFixBin(0.8), h4_EMCal_Ep->FindFixBin(2));
        float rangeIntegral4_e4 = h4_EMCal_Ep->Integral(h4_EMCal_Ep->FindFixBin(0.7), h4_EMCal_Ep->FindFixBin(2));
        float rangeIntegral5_e4 = h4_EMCal_Ep->Integral(h4_EMCal_Ep->FindFixBin(0.6), h4_EMCal_Ep->FindFixBin(2));
        float rangeIntegral6_e4 = h4_EMCal_Ep->Integral(h4_EMCal_Ep->FindFixBin(0.5), h4_EMCal_Ep->FindFixBin(2));
        float rangeIntegral7_e4 = h4_EMCal_Ep->Integral(h4_EMCal_Ep->FindFixBin(0.4), h4_EMCal_Ep->FindFixBin(2));

        float eff1_e= rangeIntegral1_e/(totalIntegral_e); 
        float eff2_e= rangeIntegral2_e/(totalIntegral_e); 
        float eff3_e= rangeIntegral3_e/(totalIntegral_e); 
        float eff4_e= rangeIntegral4_e/(totalIntegral_e); 
        float eff5_e= rangeIntegral5_e/(totalIntegral_e); 
        float eff6_e= rangeIntegral6_e/(totalIntegral_e); 
        float eff7_e= rangeIntegral7_e/(totalIntegral_e); 
      /*  float eff8_e= rangeIntegral8_e/(totalIntegral_e); 
        float eff9_e= rangeIntegral9_e/(totalIntegral_e); 
        float eff10_e= rangeIntegral10_e/(totalIntegral_e); */

        float eff1_e2= rangeIntegral1_e2/(totalIntegral_e2); 
        float eff2_e2= rangeIntegral2_e2/(totalIntegral_e2); 
        float eff3_e2= rangeIntegral3_e2/(totalIntegral_e2); 
        float eff4_e2= rangeIntegral4_e2/(totalIntegral_e2); 
        float eff5_e2= rangeIntegral5_e2/(totalIntegral_e2); 
        float eff6_e2= rangeIntegral6_e2/(totalIntegral_e2); 
        float eff7_e2= rangeIntegral7_e2/(totalIntegral_e2); 

        float eff1_e3= rangeIntegral1_e3/(totalIntegral_e3); 
        float eff2_e3= rangeIntegral2_e3/(totalIntegral_e3); 
        float eff3_e3= rangeIntegral3_e3/(totalIntegral_e3); 
        float eff4_e3= rangeIntegral4_e3/(totalIntegral_e3); 
        float eff5_e3= rangeIntegral5_e3/(totalIntegral_e3); 
        float eff6_e3= rangeIntegral6_e3/(totalIntegral_e3); 
        float eff7_e3= rangeIntegral7_e3/(totalIntegral_e3); 

        float eff1_e4= rangeIntegral1_e4/(totalIntegral_e4); 
        float eff2_e4= rangeIntegral2_e4/(totalIntegral_e4); 
        float eff3_e4= rangeIntegral3_e4/(totalIntegral_e4); 
        float eff4_e4= rangeIntegral4_e4/(totalIntegral_e4); 
        float eff5_e4= rangeIntegral5_e4/(totalIntegral_e4); 
        float eff6_e4= rangeIntegral6_e4/(totalIntegral_e4); 
        float eff7_e4= rangeIntegral7_e4/(totalIntegral_e4); 

        cout <<"nbinsh1 (number of electrons): " << nbinsh1 << endl;
        cout <<"nbinsh2 (number of pions): " << nbinsh2 << endl;
        cout <<"nbinsh3 (number of kaons): " << nbinsh3 << endl;
        cout <<"nbinsh4 (number of kaons): " << nbinsh4 << endl;

        cout <<"Total bins: " << nbintstotal << endl;

       cout <<"rangeIntegral1_e: " << rangeIntegral1_e << endl;
       cout <<"rangeIntegral2_e: " << rangeIntegral2_e << endl;    
       cout <<"rangeIntegral3_e: " << rangeIntegral3_e << endl;
       cout <<"rangeIntegral4_e: " << rangeIntegral4_e << endl;
       cout <<"rangeIntegral5_e: " << rangeIntegral5_e << endl;
       cout <<"rangeIntegral6_e: " << rangeIntegral6_e << endl;
       cout <<"rangeIntegral7_e: " << rangeIntegral7_e << endl;
    /*   cout <<"rangeIntegral8_e: " << rangeIntegral8_e << endl;
       cout <<"rangeIntegral9_e: " << rangeIntegral9_e << endl;
       cout <<"rangeIntegral10_e: " << rangeIntegral10_e << endl;*/

       cout <<"efficiency1_e: " << eff1_e << endl;
       cout <<"efficiency2_e: " << eff2_e << endl;
       cout <<"efficiency3_e: " << eff3_e << endl;
       cout <<"efficiency4_e: " << eff4_e << endl;
       cout <<"efficiency5_e: " << eff5_e << endl;
       cout <<"efficiency6_e: " << eff6_e << endl;
       cout <<"efficiency7_e: " << eff7_e << endl;

        // h1_EMCal_Ep->Scale(1./(nbintstotal));
        // h2_EMCal_Ep->Scale(1./(nbintstotal));
        //   h1_EMCal_Ep->Scale(1./(h1_EMCal_Ep)->Integral());
        //   h2_EMCal_Ep->Scale(1./(h2_EMCal_Ep)->Integral());

  TCanvas *c1 = new TCanvas("c12","Becal E/p");
  gStyle->SetOptStat(false);
  c1->SetRightMargin(0.1);
  c1->SetTopMargin(0.1);
  c1->SetFillColor(0);

        h1_EMCal_Ep->GetYaxis()->SetRange(0,100);   
        h2_EMCal_Ep->GetYaxis()->SetRange(0,100);   
        h3_EMCal_Ep->GetYaxis()->SetRange(0,100);   
        h4_EMCal_Ep->GetYaxis()->SetRange(0,100);   

    h1_EMCal_Ep->SetTitle("1.0 - 5.0 GeV");
    h2_EMCal_Ep->SetTitle("5.0 - 10.0 GeV");
    h3_EMCal_Ep->SetTitle("10.0 - 20.0 GeV");
    h4_EMCal_Ep->SetTitle("1.0 - 20.0 GeV");

/*
    h1_EMCal_Ep->SetTitle("0.5 - 1.0 GeV");
    h2_EMCal_Ep->SetTitle("1.0 - 2.0 GeV");
    h3_EMCal_Ep->SetTitle("2.0 - 5.0 GeV");
    h4_EMCal_Ep->SetTitle("5.0 - 10.0 GeV");
*/
    h1_EMCal_Ep->Draw();
    h2_EMCal_Ep->Draw("same");
    h3_EMCal_Ep->Draw("same");
    h4_EMCal_Ep->Draw("same");

   // c1->SetLogy();

  c1->BuildLegend();
  c1->SaveAs("Ep_pie.pdf");
   

TCanvas *c2 = new TCanvas("c5","Efficiency of #e^{-},  #pi^{-}, and #k^{-} ",200,10,500,300);
  TGraph* gr1 = new TGraph();
  TGraph* gr2 = new TGraph();
  TGraph* gr3 = new TGraph();
  TGraph* gr4 = new TGraph();

  TMultiGraph *mg = new TMultiGraph();
      mg->SetTitle("e^{-} E/p vs efficiency;(E/p)_{min}; Efficiency");
  //    mg->SetTitle("#pi^{-} E/p vs efficiency;(E/p)_{min}; Efficiency");
   //   mg->SetTitle("k^{-} E/p vs efficiency;(E/p)_{min}; Efficiency");
      mg->GetXaxis()->SetLimits(0.1, 1.02);
      mg->GetXaxis()->SetTitleOffset(1.2);
      mg->GetYaxis()->SetTitleOffset(1.2);
      mg->GetXaxis()->CenterTitle();
      mg->GetYaxis()->CenterTitle();      

    mg->Add(gr1,"lp");
    mg->Add(gr2,"cp");
    mg->Add(gr3,"cp");
    mg->Add(gr4,"cp");
    mg->Draw("AC");
   
   gr1->SetName("gr1");
   gr1->SetTitle("0.5 - 1.0 GeV");
   gr1->SetMarkerStyle(21);
   gr1->SetLineColor(1);
   gr1->SetLineWidth(4);
   gr1->SetFillStyle(0);
 
   gr2->SetName("gr2");
   gr2->SetTitle("1.0 - 2.0 GeV");
   gr2->SetMarkerStyle(22);
   gr2->SetMarkerColor(41);
   gr2->SetLineColor(41);
   gr2->SetLineWidth(4);
   gr2->SetFillStyle(0);

   gr3->SetName("gr3");
   gr3->SetTitle("2.0 - 5.0 GeV");
   gr3->SetMarkerStyle(23);
   gr3->SetMarkerColor(46);
   gr3->SetLineColor(46);
   gr3->SetLineWidth(4);
   gr3->SetFillStyle(0);

   gr4->SetName("gr3");
   gr4->SetTitle("5.0 - 10.0 GeV");
   gr4->SetMarkerStyle(23);
   gr4->SetMarkerColor(49);
   gr4->SetLineColor(49);
   gr4->SetLineWidth(4);
   gr4->SetFillStyle(0);


//  gr1->SetPoint(1,0.1,eff10_e);
//  gr1->SetPoint(2,0.2,eff9_e);
//  gr1->SetPoint(3,0.3,eff8_e);
  gr1->SetPoint(4,0.4,eff7_e);
  gr1->SetPoint(5,0.5,eff6_e); 
  gr1->SetPoint(6,0.6,eff5_e);
  gr1->SetPoint(7,0.7,eff4_e);
  gr1->SetPoint(8,0.8,eff3_e);
  gr1->SetPoint(9,0.9,eff2_e);
  gr1->SetPoint(10,1.0,eff1_e);

  gr2->SetPoint(4,0.4,eff7_e2);
  gr2->SetPoint(5,0.5,eff6_e2); 
  gr2->SetPoint(6,0.6,eff5_e2);
  gr2->SetPoint(7,0.7,eff4_e2);
  gr2->SetPoint(8,0.8,eff3_e2);
  gr2->SetPoint(9,0.9,eff2_e2);
  gr2->SetPoint(10,1.0,eff1_e2);

  gr3->SetPoint(4,0.4,eff7_e3);
  gr3->SetPoint(5,0.5,eff6_e3); 
  gr3->SetPoint(6,0.6,eff5_e3);
  gr3->SetPoint(7,0.7,eff4_e3);
  gr3->SetPoint(8,0.8,eff3_e3);
  gr3->SetPoint(9,0.9,eff2_e3);
  gr3->SetPoint(10,1.0,eff1_e3);

  gr4->SetPoint(4,0.4,eff7_e4);
  gr4->SetPoint(5,0.5,eff6_e4); 
  gr4->SetPoint(6,0.6,eff5_e4);
  gr4->SetPoint(7,0.7,eff4_e4);
  gr4->SetPoint(8,0.8,eff3_e4);
  gr4->SetPoint(9,0.9,eff2_e4);
  gr4->SetPoint(10,1.0,eff1_e4);

  c2->BuildLegend();

  // c2->SetRightMargin(0.0465116);
  // c2->SetTopMargin(0.1);
  // c2->SetFillColor(0);
  c2->SaveAs("eff-1-20GeV.pdf");

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  cout<<"End of the program. Gracias"<<endl;
  return 0;  
}

