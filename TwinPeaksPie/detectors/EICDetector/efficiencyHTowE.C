// Description:
//      
//       Analysis macro: this macro finds the Energy/momentum value for different efficiencies of electrons. 
//  
// Environment:
//      ROOT
//
// Author List:
//       Luis Valenzuela Cazares          (original author)
//   
//-----------------------------------------------------------
////////////////////////////////////////////////////////////////

Int_t efficiencyHTowE()
{

//TFile *file1 = TFile::Open("G4EICDetector_out_e_1-20GeV.root");


TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_1-20GeV.root");
//TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_1-3GeV.root");
//TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_3-5GeV.root");
//TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_5-7.5GeV.root");
//TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_7.5-10GeV.root");
//TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_10-12.5GeV.root");
//TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_12.5-15GeV.root");
//TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_15-17.5GeV.root");
//TFile *file1 = TFile::Open("Ep_cut_revisited_G4EICDetector_out_hq2_e_17.5-20GeV.root");



       if (file1->IsZombie()) { cout << "Error opening a file" << endl;
       exit(-1);} 
       else {cout << "File is okay" << endl;}
 
//  gStyle->SetOptTitle(0); //No title for histograms
 // gStyle->SetOptStat(0);
  
  TH1F *h1_EMCal_Ep = (TH1F*)file1->Get("h_tow_E");
        h1_EMCal_Ep->GetXaxis()->SetTitle("h_tow_E");
        h1_EMCal_Ep->GetYaxis()->SetTitle("Counts");
        h1_EMCal_Ep->SetMarkerStyle(kFullTriangleUp);
       // h1_EMCal_Ep->SetMarkerStyle(20);
       h1_EMCal_Ep->SetMarkerColor(1);

        Int_t nbinsh1 = h1_EMCal_Ep->Integral();
        Int_t nbintstotal = nbinsh1;

        cout <<"nbinsh1: " << nbinsh1 << endl;
        cout <<"Total bins: " << nbintstotal << endl;

////////////////////////////////Finding the e efficiencicy////////////////////////////////////////////////
 Double_t a = 0.0;
 Double_t fraction =100;
 Double_t epsilon = 0.005; 
 Int_t totalIntegral = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0), h1_EMCal_Ep->FindFixBin(1));

 Double_t eff10 = 0.1;
 Double_t eff20 = 0.2;
 Double_t eff30 = 0.3;
 Double_t eff40 = 0.4;
 Double_t eff50 = 0.5;
 Double_t eff60 = 0.6;
 Double_t eff70 = 0.7;
 Double_t eff80 = 0.8;
 Double_t eff90 = 0.9;
 Double_t eff95 = 0.95;

 Double_t ep10 = 100;
 Double_t ep20 = 100;
 Double_t ep30 = 100;
 Double_t ep40 = 100;
 Double_t ep50 = 100;
 Double_t ep60 = 100;
 Double_t ep70 = 100;
 Double_t ep80 = 100;
 Double_t ep90 = 100;
 Double_t ep95 = 100;


 Int_t bBin = h1_EMCal_Ep->FindFixBin(a);

 Double_t Ep= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

              while (   TMath::Abs(fraction-eff10) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;

                            //    cout <<"ep : " << Ep << endl;
                                // cout <<"efficiency 0.1: " << fraction << endl;

              } 

              ep10= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

              while (   TMath::Abs(fraction-eff20) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;  

                           //  cout <<"efficiency  0.2: " << fraction << endl;
              } 

              ep20= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

              while (   TMath::Abs(fraction-eff30) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;    
              } 
              ep30= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

              while (   TMath::Abs(fraction-eff40) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;    
              } 
              ep40= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

              while (   TMath::Abs(fraction-eff50) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;    
              } 
              ep50= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

              while (   TMath::Abs(fraction-eff60) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;    
              } 
              ep60= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

              while (   TMath::Abs(fraction-eff70) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;    
              } 
              ep70= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

              while (   TMath::Abs(fraction-eff80) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;    
              } 
              ep80= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

              while (   TMath::Abs(fraction-eff90) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;    
              } 
              ep90= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);

               //   cout <<"efficiency 0.9: " << fraction << endl;


              while (   TMath::Abs(fraction-eff95) > epsilon  && bBin < h1_EMCal_Ep->GetNbinsX()  ) {
               bBin =bBin+1;
               fraction =  h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(a),bBin, "") /totalIntegral;  
                //    cout <<"efficiency 0.95: " << fraction << endl;

              } 
              ep95= h1_EMCal_Ep->GetXaxis()->GetBinCenter(bBin);


              double check95 = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(0), h1_EMCal_Ep->FindFixBin(0.08));
            //  float check90 = h1_EMCal_Ep->Integral(h1_EMCal_Ep->FindFixBin(ep10), h1_EMCal_Ep->FindFixBin(1));

              double check95per = check95/totalIntegral;
              double real95per = 0.95*totalIntegral;

               cout<<"ep10: "<<ep10<<endl; 
               cout<<"ep20: "<<ep20<<endl; 
               cout<<"ep30: "<<ep30<<endl; 
               cout<<"ep40: "<<ep40<<endl; 
               cout<<"ep50: "<<ep50<<endl; 
               cout<<"ep60: "<<ep60<<endl; 
               cout<<"ep70: "<<ep70<<endl; 
               cout<<"ep80: "<<ep80<<endl; 
               cout<<"ep90: "<<ep90<<endl; 
               cout<<"ep95: "<<ep95<<endl; 

               cout<<"fraction: "<<fraction<<endl;  
               cout<<"bBin: "<<bBin<<endl; 
               cout<<"epsilon: "<<epsilon<<endl;   

               cout<<"totalIntegral: "<<totalIntegral<<endl;  
              
               cout<<"real95: "<<real95per<<endl; 
               cout<<"check95: "<<check95<<endl; 
               cout<<"check95: "<<check95per<<endl; 

//////////////////////////////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////////////////////////             

  TCanvas *c1 = new TCanvas("c1","EMCal E/p");
  gStyle->SetOptStat(false);
  c1->SetRightMargin(0.0465116);
  c1->SetTopMargin(0.1);
  c1->SetFillColor(0);
  
    h1_EMCal_Ep->Draw();

  TLegend *leg = new TLegend(0.7,0.6,0.92,0.89);
  leg->SetTextFont(62);
  leg->SetLineColor(0);
  leg->SetLineStyle(0);
  leg->SetLineWidth(1);
  leg->SetFillColor(0);
  leg->SetFillStyle(1001);
  leg->AddEntry("","Particle","");
  leg->AddEntry("h1_EMCal_Ep","e^{-}","lep");
  leg->Draw();
  c1->SaveAs("Ep_pie.pdf");
  



 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  cout<<"End of the program. Gracias"<<endl;
  return 0;  
}

