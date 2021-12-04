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

Int_t HCalTowE()
{

TFile *file0 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_1-20GeV.root");
TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_1-3GeV.root");
TFile *file2 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_3-5GeV.root");
TFile *file3 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_5-7.5GeV.root");
TFile *file4 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_7.5-10GeV.root");
TFile *file5 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_10-12.5GeV.root");
TFile *file6 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_12.5-15GeV.root");
TFile *file7 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_15-17.5GeV.root");
TFile *file8 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_17.5-20GeV.root");


/*
TFile *file0 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_1-20GeV.root");
TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_1-3GeV.root");
TFile *file2 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_3-5GeV.root");
TFile *file3 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_5-7.5GeV.root");
TFile *file4 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_7.5-10GeV.root");
TFile *file5 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_10-12.5GeV.root");
TFile *file6 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_12.5-15GeV.root");
TFile *file7 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_15-17.5GeV.root");
TFile *file8 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_17.5-20GeV.root");
*/

/*
TFile *file0 = TFile::Open("G4EICDetector_out_e_1-20GeV.root");
TFile *file1 = TFile::Open("G4EICDetector_out_e_1-3GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_e_3-5GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_e_5-7.5GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_e_7.5-10GeV.root");
TFile *file5 = TFile::Open("G4EICDetector_out_e_10-12.5GeV.root");
TFile *file6 = TFile::Open("G4EICDetector_out_e_12.5-15GeV.root");
TFile *file7 = TFile::Open("G4EICDetector_out_e_15-17.5GeV.root");
TFile *file8 = TFile::Open("G4EICDetector_out_e_17.5-20GeV.root");
*/

/*
TFile *file0 = TFile::Open("G4EICDetector_out_pi_1-20GeV.root");
TFile *file1 = TFile::Open("G4EICDetector_out_pi_1-3GeV.root");
TFile *file2 = TFile::Open("G4EICDetector_out_pi_3-5GeV.root");
TFile *file3 = TFile::Open("G4EICDetector_out_pi_5-7.5GeV.root");
TFile *file4 = TFile::Open("G4EICDetector_out_pi_7.5-10GeV.root");
TFile *file5 = TFile::Open("G4EICDetector_out_pi_10-12.5GeV.root");
TFile *file6 = TFile::Open("G4EICDetector_out_pi_12.5-15GeV.root");
TFile *file7 = TFile::Open("G4EICDetector_out_pi_15-17.5GeV.root");
TFile *file8 = TFile::Open("G4EICDetector_out_pi_17.5-20GeV.root");
*/

/*
TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_1-5GeV.root");
TFile *file2 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_5-10GeV.root");
TFile *file3 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_10-20GeV.root");
TFile *file4 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_1-20GeV.root");
*/
/*
TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_1-5GeV.root");
TFile *file2 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_5-10GeV.root");
TFile *file3 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_10-20GeV.root");
TFile *file4 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_1-20GeV.root");
*/

       if (file1 && file2 && file3 && file4->IsZombie()) { cout << "Error opening a file" << endl;
       exit(-1);} 
       else {cout << "Files are okay" << endl;}
 
//  gStyle->SetOptTitle(0); //No title for histograms
 // gStyle->SetOptStat(0);

   
  TH1F *h_tow_E1 = (TH1F*)file1->Get("h_tow_E");
        h_tow_E1->GetXaxis()->SetTitle("Tower E");
        h_tow_E1->GetYaxis()->SetTitle("Counts");
        h_tow_E1->SetFillColor(0); 
        h_tow_E1->SetLineColor(49);
        h_tow_E1->SetLineWidth(3);  
       // h_tow_E1->Rebin(10);        
      //  h_tow_E1->GetYaxis()->SetRange(0,100);   

  TH1F *h_tow_E2 = (TH1F*)file2->Get("h_tow_E");
        h_tow_E2->GetXaxis()->SetTitle("Tower E");
        h_tow_E2->GetYaxis()->SetTitle("Counts");
        h_tow_E2->SetFillColor(0); 
        h_tow_E2->SetLineColor(49);
        h_tow_E2->SetLineWidth(3);  
       // h_tow_E2->Rebin(10);        
      //  h_tow_E2->GetYaxis()->SetRange(0,100);  

  TH1F *h_tow_E3 = (TH1F*)file3->Get("h_tow_E");
        h_tow_E3->GetXaxis()->SetTitle("Tower E");
        h_tow_E3->GetYaxis()->SetTitle("Counts");
        h_tow_E3->SetFillColor(0); 
        h_tow_E3->SetLineColor(49);
        h_tow_E3->SetLineWidth(3);  
      //  h_tow_E3->Rebin(10);        
      //  h_tow_E3->GetYaxis()->SetRange(0,100);  

  TH1F *h_tow_E4 = (TH1F*)file4->Get("h_tow_E");
        h_tow_E4->GetXaxis()->SetTitle("Tower E");
        h_tow_E4->GetYaxis()->SetTitle("Counts");
        h_tow_E4->SetFillColor(0); 
        h_tow_E4->SetLineColor(49);
        h_tow_E4->SetLineWidth(3);  
       // h_tow_E4->Rebin(10);        
      //  h_tow_E->GetYaxis()->SetRange(0,100);  
  
  TH1F *h_tow_E5 = (TH1F*)file5->Get("h_tow_E");
        h_tow_E5->GetXaxis()->SetTitle("Tower E");
        h_tow_E5->GetYaxis()->SetTitle("Counts");
        h_tow_E5->SetFillColor(0); 
        h_tow_E5->SetLineColor(49);
        h_tow_E5->SetLineWidth(3);  
       // h_tow_E5->Rebin(10);        
      //  h_tow_5->GetYaxis()->SetRange(0,100);  

  TH1F *h_tow_E6 = (TH1F*)file6->Get("h_tow_E");
        h_tow_E6->GetXaxis()->SetTitle("Tower E");
        h_tow_E6->GetYaxis()->SetTitle("Counts");
        h_tow_E6->SetFillColor(0); 
        h_tow_E6->SetLineColor(49);
        h_tow_E6->SetLineWidth(3);  
       // h_tow_E6->Rebin(10);        
      //  h_tow_6->GetYaxis()->SetRange(0,100);  


  TH1F *h_tow_E7 = (TH1F*)file7->Get("h_tow_E");
        h_tow_E7->GetXaxis()->SetTitle("Tower E");
        h_tow_E7->GetYaxis()->SetTitle("Counts");
        h_tow_E7->SetFillColor(0); 
        h_tow_E7->SetLineColor(49);
        h_tow_E7->SetLineWidth(3);  
       // h_tow_E7->Rebin(10);        
      //  h_tow_E7->GetYaxis()->SetRange(0,100);  
      

  TH1F *h_tow_E8 = (TH1F*)file8->Get("h_tow_E");
        h_tow_E8->GetXaxis()->SetTitle("Tower E");
        h_tow_E8->GetYaxis()->SetTitle("Counts");
        h_tow_E8->SetFillColor(0); 
        h_tow_E8->SetLineColor(49);
        h_tow_E8->SetLineWidth(3);  
       // h_tow_E8->Rebin(10);        
      //  h_tow_E8->GetYaxis()->SetRange(0,100);          


  TCanvas *c1 = new TCanvas("c1","Tower E");
 // gStyle->SetOptStat(false);
  c1->SetRightMargin(0.1);
  c1->SetTopMargin(0.1);
  c1->SetFillColor(0);

      /*  h1_EMCal_Ep->GetYaxis()->SetRange(0,100);   
        h2_EMCal_Ep->GetYaxis()->SetRange(0,100);   
        h3_EMCal_Ep->GetYaxis()->SetRange(0,100);   
        h4_EMCal_Ep->GetYaxis()->SetRange(0,100);   */
/*
    h_tow_E1->SetTitle("1.0 - 5.0 GeV");
    h_tow_E2->SetTitle("5.0 - 10.0 GeV");
    h_tow_E3->SetTitle("10.0 - 20.0 GeV");
    h_tow_E4->SetTitle("1.0 - 20.0 GeV");
*/

    h_tow_E1->SetTitle("1.0 - 3.0 GeV");
    h_tow_E2->SetTitle("3.0 - 5.0 GeV");
    h_tow_E3->SetTitle("5.0 - 7.5 GeV");
    h_tow_E4->SetTitle("7.5 - 10.0 GeV");
    h_tow_E5->SetTitle("10.0 - 12.5 GeV");
    h_tow_E6->SetTitle("12.5 - 15.0 GeV");
    h_tow_E7->SetTitle("15.0 - 17.5 GeV");
    h_tow_E8->SetTitle("17.5 - 20.0 GeV");

    h_tow_E1->Draw();
    h_tow_E2->Draw("same");
    h_tow_E3->Draw("same");
    h_tow_E4->Draw("same");
    h_tow_E5->Draw("same");
    h_tow_E6->Draw("same");
    h_tow_E7->Draw("same");
    h_tow_E8->Draw("same");

   // c1->SetLogy();

  c1->BuildLegend();
  c1->SaveAs("TowerE.gif");


  TCanvas *c0 = new TCanvas("c0","Tower E");
  c0->Divide(4,2);
  c0->cd(1); 
 // gStyle->SetOptStat(false);
  c0->SetRightMargin(0.1);
  c0->SetTopMargin(0.1);
  c0->SetFillColor(0);
  c0->SetLogy();


   h_tow_E1->SetTitle("1.0 - 3.0 GeV");
   h_tow_E2->SetTitle("3.0 - 5.0 GeV");
   h_tow_E3->SetTitle("5.0 - 7.5 GeV");
   h_tow_E4->SetTitle("7.5 - 10.0 GeV");
   h_tow_E5->SetTitle("10.0 - 12.5 GeV");
   h_tow_E6->SetTitle("12.5 - 15.0 GeV");
   h_tow_E7->SetTitle("15.0 - 17.5 GeV");
   h_tow_E8->SetTitle("17.5 - 20.0 GeV");
  

   h_tow_E1->GetYaxis()->SetTitleOffset(2);
   h_tow_E2->GetYaxis()->SetTitleOffset(2);
   h_tow_E3->GetYaxis()->SetTitleOffset(2);
   h_tow_E4->GetYaxis()->SetTitleOffset(2);
   h_tow_E5->GetYaxis()->SetTitleOffset(2);
   h_tow_E6->GetYaxis()->SetTitleOffset(2);
   h_tow_E7->GetYaxis()->SetTitleOffset(2);
   h_tow_E8->GetYaxis()->SetTitleOffset(2);


   h_tow_E1->Draw();


   c0->cd(2);
   h_tow_E2->Draw();


   c0->cd(3);
   h_tow_E3->Draw();

   c0->cd(4); 
   h_tow_E4->Draw();

   c0->cd(5); 
   h_tow_E5->Draw();

   c0->cd(6); 
   h_tow_E6->Draw();

   c0->cd(7); 
   h_tow_E7->Draw();

   c0->cd(8); 
   h_tow_E8->Draw();

   

 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  cout<<"End of the program. Gracias"<<endl;
  return 0;  
}

