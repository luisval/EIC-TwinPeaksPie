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

Int_t Ep()
{

/*
TFile *file1 = TFile::Open("G4EICDetector_out_e_1-5GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_e_5-10GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_e_10-20GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_e_1-20GeV.root");
*/
/*  
TFile *file1 = TFile::Open("G4EICDetector_out_pi_1-5GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_pi_5-10GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_pi_10-20GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_pi_1-20GeV.root");
*/

TFile *file1 = TFile::Open("G4EICDetector_out_k_1-5GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_k_5-10GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_k_10-20GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_k_1-20GeV.root");

       if (file1 && file2 && file3 && file4->IsZombie()) { cout << "Error opening a file" << endl;
       exit(-1);} 
       else {cout << "Files are okay" << endl;}
 
//  gStyle->SetOptTitle(0); //No title for histograms
 // gStyle->SetOptStat(0);

  TH1F *h_EMCal_Ep = (TH1F*)file4->Get("h_EMCal_Ep");
        h_EMCal_Ep->GetXaxis()->SetTitle("Becal E/p");
        h_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h_EMCal_Ep->SetFillColor(0); 
        h_EMCal_Ep->SetLineColor(49);
        h_EMCal_Ep->SetLineWidth(3);  
        h_EMCal_Ep->Rebin(2);        
      //  h1_EMCal_Ep->GetYaxis()->SetRange(0,100);        
  
  TH1F *h1_EMCal_Ep = (TH1F*)file1->Get("h_EMCal_Ep");
        h1_EMCal_Ep->GetXaxis()->SetTitle("Becal E/p");
        h1_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h1_EMCal_Ep->SetFillColor(0); 
        h1_EMCal_Ep->SetLineColor(49);
        h1_EMCal_Ep->SetLineWidth(3);  
        h1_EMCal_Ep->Rebin(2);        
      //  h1_EMCal_Ep->GetYaxis()->SetRange(0,100);   

  TH1F *h2_EMCal_Ep = (TH1F*)file2->Get("h_EMCal_Ep");
        h2_EMCal_Ep->GetXaxis()->SetTitle("Becal E/p");
        h2_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h2_EMCal_Ep->SetFillColor(0); 
        h2_EMCal_Ep->SetLineColor(49);
        h2_EMCal_Ep->SetLineWidth(3);  
        h2_EMCal_Ep->Rebin(2);      
       // h2_EMCal_Ep->GetYaxis()->SetRange(0,100);   

  TH1F *h3_EMCal_Ep = (TH1F*)file3->Get("h_EMCal_Ep");
        h3_EMCal_Ep->GetXaxis()->SetTitle("Becal E/p");
        h3_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h3_EMCal_Ep->SetFillColor(0);    
        h3_EMCal_Ep->SetLineColor(49);
        h3_EMCal_Ep->SetLineWidth(3);  
        h3_EMCal_Ep->Rebin(2);       
      //  h3_EMCal_Ep->GetYaxis()->SetRange(0,100);   
   
  TH1F *h4_EMCal_Ep = (TH1F*)file4->Get("h_EMCal_Ep");
        h4_EMCal_Ep->GetXaxis()->SetTitle("Becal E/p");
        h4_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h4_EMCal_Ep->SetFillColor(0);    
        h4_EMCal_Ep->SetLineColor(49);
        h4_EMCal_Ep->SetLineWidth(3);  
        h4_EMCal_Ep->Rebin(2);    
       // h4_EMCal_Ep->GetYaxis()->SetRange(0,100);   
       

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  TCanvas *c0 = new TCanvas("c0","Becal E/p");
  //gStyle->SetOptStat(false);
  c0->SetRightMargin(0.1);
  c0->SetTopMargin(0.1);
  c0->SetFillColor(0);
  h_EMCal_Ep->SetTitle("1.0 - 20.0 GeV");

   h_EMCal_Ep->SetStats(kFALSE);
   h_EMCal_Ep->GetXaxis()->SetTitle("E/p");
   h_EMCal_Ep->GetYaxis()->SetTitle("counts");
   h_EMCal_Ep->Draw();


  TCanvas *c1 = new TCanvas("c1","Becal E/p");
  c1->Divide(2,2);
  c1->cd(1); 
  //gStyle->SetOptStat(false);
  c1->SetRightMargin(0.1);
  c1->SetTopMargin(0.1);
  c1->SetFillColor(0);

   h1_EMCal_Ep->SetTitle("1.0 - 5.0 GeV");
   h2_EMCal_Ep->SetTitle("5.0 - 10.0 GeV");
   h3_EMCal_Ep->SetTitle("10.0 - 20.0 GeV");
   h4_EMCal_Ep->SetTitle("1.0 - 20.0 GeV");


   h1_EMCal_Ep->SetStats(kFALSE);
   h1_EMCal_Ep->GetXaxis()->SetTitle("E/p");
   h1_EMCal_Ep->GetYaxis()->SetTitle("counts");
   h1_EMCal_Ep->Draw();


   c1->cd(2);
   h2_EMCal_Ep->SetStats(kFALSE);
   h2_EMCal_Ep->GetXaxis()->SetTitle("E/p");
   h2_EMCal_Ep->GetYaxis()->SetTitle("counts");
   h2_EMCal_Ep->Draw();


   c1->cd(3);
   h3_EMCal_Ep->SetStats(kFALSE);
   h3_EMCal_Ep->GetXaxis()->SetTitle("E/p");
   h3_EMCal_Ep->GetYaxis()->SetTitle("counts");
   h3_EMCal_Ep->Draw();

   c1->cd(4); 
   h4_EMCal_Ep->SetStats(kFALSE);
   h4_EMCal_Ep->GetXaxis()->SetTitle("E/p");
   h4_EMCal_Ep->GetYaxis()->SetTitle("counts");
   h4_EMCal_Ep->Draw();

   
 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  cout<<"End of the program. Gracias"<<endl;
  return 0;  
}

