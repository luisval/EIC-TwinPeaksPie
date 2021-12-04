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

Int_t HCalTowE_Pie()
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



TFile *file20 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_1-20GeV.root");
TFile *file21 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_1-3GeV.root");
TFile *file22 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_3-5GeV.root");
TFile *file23 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_5-7.5GeV.root");
TFile *file24 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_7.5-10GeV.root");
TFile *file25 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_10-12.5GeV.root");
TFile *file26 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_12.5-15GeV.root");
TFile *file27 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_15-17.5GeV.root");
TFile *file28 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_pi_17.5-20GeV.root");

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
 
 // gStyle->SetOptTitle(0); //No title for histograms
  gStyle->SetOptStat(0);

   
  TH1F *h_tow_E1 = (TH1F*)file1->Get("h_tow_E");
        h_tow_E1->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E1->GetYaxis()->SetTitle("Counts");
        h_tow_E1->SetFillColor(0); 
      //  h_tow_E1->SetLineColor(49);
      //  h_tow_E1->SetLineWidth(3);  
       // h_tow_E1->Rebin(10);        
      //  h_tow_E1->GetYaxis()->SetRange(0,100);   
       h_tow_E1->SetMarkerStyle(22);
       h_tow_E1->SetMarkerColor(41);
       h_tow_E1->SetMarkerSize(1.5);


  TH1F *h_tow_E2 = (TH1F*)file2->Get("h_tow_E");
        h_tow_E2->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E2->GetYaxis()->SetTitle("Counts");
        h_tow_E2->SetFillColor(0); 
        h_tow_E2->SetLineColor(49);
        h_tow_E2->SetLineWidth(3);  
       // h_tow_E2->Rebin(10);        
      //  h_tow_E2->GetYaxis()->SetRange(0,100);  
       h_tow_E2->SetMarkerStyle(22);
       h_tow_E2->SetMarkerColor(41);
       h_tow_E2->SetMarkerSize(1.5);


  TH1F *h_tow_E3 = (TH1F*)file3->Get("h_tow_E");
        h_tow_E3->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E3->GetYaxis()->SetTitle("Counts");
        h_tow_E3->SetFillColor(0); 
      //  h_tow_E3->SetLineColor(49);
      //  h_tow_E3->SetLineWidth(3);  
      //  h_tow_E3->Rebin(10);        
      //  h_tow_E3->GetYaxis()->SetRange(0,100);  
       h_tow_E3->SetMarkerStyle(22);
       h_tow_E3->SetMarkerColor(41);
       h_tow_E3->SetMarkerSize(1.5);

  TH1F *h_tow_E4 = (TH1F*)file4->Get("h_tow_E");
        h_tow_E4->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E4->GetYaxis()->SetTitle("Counts");
        h_tow_E4->SetFillColor(0); 
       // h_tow_E4->SetLineColor(49);
       // h_tow_E4->SetLineWidth(3);  
       // h_tow_E4->Rebin(10);        
      //  h_tow_E->GetYaxis()->SetRange(0,100);  
       h_tow_E4->SetMarkerStyle(22);
       h_tow_E4->SetMarkerColor(41);
       h_tow_E4->SetMarkerSize(1.5);
  
  TH1F *h_tow_E5 = (TH1F*)file5->Get("h_tow_E");
        h_tow_E5->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E5->GetYaxis()->SetTitle("Counts");
        h_tow_E5->SetFillColor(0); 
       // h_tow_E5->SetLineColor(49);
       // h_tow_E5->SetLineWidth(3);  
       // h_tow_E5->Rebin(10);        
      //  h_tow_5->GetYaxis()->SetRange(0,100);  
       h_tow_E5->SetMarkerStyle(22);
       h_tow_E5->SetMarkerColor(41);
       h_tow_E5->SetMarkerSize(1.5);

  TH1F *h_tow_E6 = (TH1F*)file6->Get("h_tow_E");
        h_tow_E6->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E6->GetYaxis()->SetTitle("Counts");
        h_tow_E6->SetFillColor(0); 
        h_tow_E6->SetLineColor(49);
        h_tow_E6->SetLineWidth(3);  
       // h_tow_E6->Rebin(10);        
      //  h_tow_6->GetYaxis()->SetRange(0,100);  
       h_tow_E6->SetMarkerStyle(22);
       h_tow_E6->SetMarkerColor(41);
       h_tow_E6->SetMarkerSize(1.5);


  TH1F *h_tow_E7 = (TH1F*)file7->Get("h_tow_E");
        h_tow_E7->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E7->GetYaxis()->SetTitle("Counts");
        h_tow_E7->SetFillColor(0); 
       // h_tow_E7->SetLineColor(49);
       // h_tow_E7->SetLineWidth(3);  
       // h_tow_E7->Rebin(10);        
      //  h_tow_E7->GetYaxis()->SetRange(0,100);  
       h_tow_E7->SetMarkerStyle(22);
       h_tow_E7->SetMarkerColor(41);
       h_tow_E7->SetMarkerSize(1.5);
      

  TH1F *h_tow_E8 = (TH1F*)file8->Get("h_tow_E");
        h_tow_E8->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E8->GetYaxis()->SetTitle("Counts");
        h_tow_E8->SetFillColor(0); 
       // h_tow_E8->SetLineColor(49);
      //  h_tow_E8->SetLineWidth(3);  
       // h_tow_E8->Rebin(10);        
      //  h_tow_E8->GetYaxis()->SetRange(0,100);  
       h_tow_E8->SetMarkerStyle(22);
       h_tow_E8->SetMarkerColor(41);
       h_tow_E8->SetMarkerSize(1.5);

///////////////////////////////////////////////////////////////////


 TH1F *h_tow_E21 = (TH1F*)file21->Get("h_tow_E");
        h_tow_E21->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E21->GetYaxis()->SetTitle("Counts");
        h_tow_E21->SetFillColor(0); 
      //  h_tow_E21->SetLineColor(43);
      //  h_tow_E21->SetLineWidth(3);  
       // h_tow_E1->Rebin(10);        
      //  h_tow_E1->GetYaxis()->SetRange(0,100);   
       h_tow_E21->SetMarkerStyle(20);
       h_tow_E21->SetMarkerColor(47);
       h_tow_E21->SetMarkerSize(1.5);

  TH1F *h_tow_E22 = (TH1F*)file22->Get("h_tow_E");
        h_tow_E22->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E22->GetYaxis()->SetTitle("Counts");
        h_tow_E22->SetFillColor(0); 
      //  h_tow_E22->SetLineColor(43);
      //  h_tow_E22->SetLineWidth(3);  
       // h_tow_E2->Rebin(10);        
      //  h_tow_E2->GetYaxis()->SetRange(0,100);  
       h_tow_E22->SetMarkerStyle(20);
        h_tow_E22->SetMarkerColor(47);
        h_tow_E22->SetMarkerSize(1.5);


  TH1F *h_tow_E23 = (TH1F*)file23->Get("h_tow_E");
        h_tow_E23->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E23->GetYaxis()->SetTitle("Counts");
        h_tow_E23->SetFillColor(0); 
      //  h_tow_E23->SetLineColor(43);
      //  h_tow_E23->SetLineWidth(3);  
      //  h_tow_E23->Rebin(10);        
      //  h_tow_E23->GetYaxis()->SetRange(0,100);  
        h_tow_E23->SetMarkerStyle(20);
        h_tow_E23->SetMarkerColor(47);
        h_tow_E23->SetMarkerSize(1.5);

  TH1F *h_tow_E24 = (TH1F*)file24->Get("h_tow_E");
        h_tow_E24->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E24->GetYaxis()->SetTitle("Counts");
        h_tow_E24->SetFillColor(0); 
       // h_tow_E24->SetLineColor(43);
       // h_tow_E24->SetLineWidth(3);  
       // h_tow_E24->Rebin(10);        
      //  h_tow_E2->GetYaxis()->SetRange(0,100);  
        h_tow_E24->SetMarkerStyle(20);
        h_tow_E24->SetMarkerColor(47);
        h_tow_E24->SetMarkerSize(1.5);
  
  TH1F *h_tow_E25 = (TH1F*)file25->Get("h_tow_E");
        h_tow_E25->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E25->GetYaxis()->SetTitle("Counts");
        h_tow_E25->SetFillColor(0); 
       // h_tow_E25->SetLineColor(43);
       // h_tow_E25->SetLineWidth(3);  
       // h_tow_E25->Rebin(10);        
      //  h_tow_5->GetYaxis()->SetRange(0,100); 
        h_tow_E25->SetMarkerStyle(20);
        h_tow_E25->SetMarkerColor(47);
        h_tow_E25->SetMarkerSize(1.5); 

  TH1F *h_tow_E26 = (TH1F*)file26->Get("h_tow_E");
        h_tow_E26->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E26->GetYaxis()->SetTitle("Counts");
        h_tow_E26->SetFillColor(0); 
       // h_tow_E26->SetLineColor(43);
       // h_tow_E26->SetLineWidth(3);  
       // h_tow_E26->Rebin(10);        
      //  h_tow_6->GetYaxis()->SetRange(0,100);  
        h_tow_E26->SetMarkerStyle(20);
        h_tow_E26->SetMarkerColor(47);
        h_tow_E26->SetMarkerSize(1.5);  

  TH1F *h_tow_E27 = (TH1F*)file27->Get("h_tow_E");
        h_tow_E27->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E27->GetYaxis()->SetTitle("Counts");
        h_tow_E27->SetFillColor(0); 
       // h_tow_E27->SetLineColor(43);
       // h_tow_E27->SetLineWidth(3);  
       // h_tow_E27->Rebin(10);        
      //  h_tow_E27->GetYaxis()->SetRange(0,100);  
        h_tow_E27->SetMarkerStyle(20);
        h_tow_E27->SetMarkerColor(47);
        h_tow_E27->SetMarkerSize(1.5);
      

  TH1F *h_tow_E28 = (TH1F*)file28->Get("h_tow_E");
        h_tow_E28->GetXaxis()->SetTitle("Tower E (GeV)");
        h_tow_E28->GetYaxis()->SetTitle("Counts");
        h_tow_E28->SetFillColor(0); 
      //  h_tow_E28->SetLineColor(43);
      //  h_tow_E28->SetLineWidth(3);  
       // h_tow_E28->Rebin(10);        
      //  h_tow_E28->GetYaxis()->SetRange(0,100);   
        h_tow_E28->SetMarkerStyle(20);
        h_tow_E28->SetMarkerColor(47);
        h_tow_E28->SetMarkerSize(1.5);                

/*
  TCanvas *c1 = new TCanvas("c1","Tower E");
 // gStyle->SetOptStat(false);
  c1->SetRightMargin(0.1);
  c1->SetTopMargin(0.1);
  c1->SetFillColor(0);

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
*/

  TCanvas *c0 = new TCanvas("c0","Tower E");
  c0->Divide(4,2);
  c0->cd(1); 
 // gStyle->SetOptStat(false);
  c0->SetRightMargin(0.1);
  c0->SetTopMargin(0.1);
  c0->SetFillColor(0);
  c0->SetLogy();
//  c0->BuildLegend();

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


//////Total normalization//////
   /*
Int_t h_tot_total1 = h_tow_E1->Integral()+h_tow_E21->Integral();
Int_t h_tot_total2 = h_tow_E2->Integral()+h_tow_E22->Integral();
Int_t h_tot_total3 = h_tow_E3->Integral()+h_tow_E23->Integral();
Int_t h_tot_total4 = h_tow_E4->Integral()+h_tow_E24->Integral();
Int_t h_tot_total5 = h_tow_E5->Integral()+h_tow_E25->Integral();
Int_t h_tot_total6 = h_tow_E6->Integral()+h_tow_E26->Integral();
Int_t h_tot_total7 = h_tow_E7->Integral()+h_tow_E27->Integral();
Int_t h_tot_total8 = h_tow_E8->Integral()+h_tow_E28->Integral();

h_tow_E1->Scale(1./h_tot_total1);
h_tow_E2->Scale(1./h_tot_total2);
h_tow_E3->Scale(1./h_tot_total3);
h_tow_E4->Scale(1./h_tot_total4);
h_tow_E5->Scale(1./h_tot_total5);
h_tow_E6->Scale(1./h_tot_total6);
h_tow_E7->Scale(1./h_tot_total7);
h_tow_E8->Scale(1./h_tot_total8);

h_tow_E21->Scale(1./h_tot_total1);
h_tow_E22->Scale(1./h_tot_total2);
h_tow_E23->Scale(1./h_tot_total3);
h_tow_E24->Scale(1./h_tot_total4);
h_tow_E25->Scale(1./h_tot_total5);
h_tow_E26->Scale(1./h_tot_total6);
h_tow_E27->Scale(1./h_tot_total7);
h_tow_E28->Scale(1./h_tot_total8);
*/
/////////////


h_tow_E1->Scale(1./h_tow_E1->Integral());
h_tow_E2->Scale(1./h_tow_E2->Integral());
h_tow_E3->Scale(1./h_tow_E3->Integral());
h_tow_E4->Scale(1./h_tow_E4->Integral());
h_tow_E5->Scale(1./h_tow_E5->Integral());
h_tow_E6->Scale(1./h_tow_E6->Integral());
h_tow_E7->Scale(1./h_tow_E7->Integral());
h_tow_E8->Scale(1./h_tow_E8->Integral());


h_tow_E21->Scale(1./h_tow_E21->Integral());
h_tow_E22->Scale(1./h_tow_E22->Integral());
h_tow_E23->Scale(1./h_tow_E23->Integral());
h_tow_E24->Scale(1./h_tow_E24->Integral());
h_tow_E25->Scale(1./h_tow_E25->Integral());
h_tow_E26->Scale(1./h_tow_E26->Integral());
h_tow_E27->Scale(1./h_tow_E27->Integral());
h_tow_E28->Scale(1./h_tow_E28->Integral());


   h_tow_E1->Draw();
   h_tow_E21->Draw("same");

   TLegend *leg1 = new TLegend(0.7,0.7,0.9,0.9);
   leg1->AddEntry(h_tow_E1,"e^{-}","p");
   leg1->AddEntry(h_tow_E21,"#pi^{-}","p");
   leg1->Draw();

   c0->cd(2);
   h_tow_E2->Draw("");
   h_tow_E22->Draw("same");

   TLegend *leg2 = new TLegend(0.7,0.7,0.9,0.9);
   leg2->AddEntry(h_tow_E2,"e^{-}","p");
   leg2->AddEntry(h_tow_E22,"#pi^{-}","p");
   leg2->Draw();

   c0->cd(3);
   h_tow_E3->Draw("");
   h_tow_E23->Draw("same");

   TLegend *leg3 = new TLegend(0.7,0.7,0.9,0.9);
   leg3->AddEntry(h_tow_E3,"e^{-}","p");
   leg3->AddEntry(h_tow_E23,"#pi^{-}","p");
   leg3->Draw();

   c0->cd(4); 
   h_tow_E4->Draw("");
   h_tow_E24->Draw("same");

  TLegend *leg4 = new TLegend(0.7,0.7,0.9,0.9);
   leg4->AddEntry(h_tow_E4,"e^{-}","p");
   leg4->AddEntry(h_tow_E24,"#pi^{-}","p");
   leg4->Draw();

   c0->cd(5); 
   h_tow_E5->Draw("");
   h_tow_E23->Draw("same");

   TLegend *leg5 = new TLegend(0.7,0.7,0.9,0.9);
   leg5->AddEntry(h_tow_E5,"e^{-}","p");
   leg5->AddEntry(h_tow_E25,"#pi^{-}","p");
   leg5->Draw();

   c0->cd(6); 
   h_tow_E6->Draw("");
   h_tow_E26->Draw("same");

   TLegend *leg6 = new TLegend(0.7,0.7,0.9,0.9);
   leg6->AddEntry(h_tow_E6,"e^{-}","p");
   leg6->AddEntry(h_tow_E26,"#pi^{-}","p");
   leg6->Draw();

   c0->cd(7); 
   h_tow_E7->Draw("");
   h_tow_E27->Draw("same");

   TLegend *leg7 = new TLegend(0.7,0.7,0.9,0.9);
   leg7->AddEntry(h_tow_E7,"e^{-}","p");
   leg7->AddEntry(h_tow_E27,"#pi^{-}","p");
   leg7->Draw();

   c0->cd(8); 
   h_tow_E8->Draw("");
   h_tow_E28->Draw("same");

TLegend *leg8 = new TLegend(0.7,0.7,0.9,0.9);
   leg8->AddEntry(h_tow_E8,"e^{-}","p");
   leg8->AddEntry(h_tow_E28,"#pi^{-}","p");
   leg8->Draw();




 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  cout<<"End of the program. Gracias"<<endl;
  return 0;  
}

