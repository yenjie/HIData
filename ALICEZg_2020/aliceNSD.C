{
  TFile *outf = new TFile("aliceNSD.root","recreate");
 const Int_t n= 8;
 Double_t x[n]   = {0,1,2,3,4,5,6,7};
   Double_t y[n]   = {2.01, 1.376, 1.127, 0.805, 0.862, 0.7192, 0.572, 0.772};
   Double_t exl[n] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5};
   Double_t eyl[n] = {0.478016736,0.146931957,0.096462428,0.097082439,0.089185201,0.100801587,0.14277955,0.272077195};
   Double_t exh[n] = {0.5,0.5,0.5,0.5,0.5,0.5,0.5,0.5};
   Double_t eyh[n] = {0.37013511,0.146931957,0.100224747,0.110535062,0.089493016,0.098334175,0.129541499,0.266647708};
   auto gr = new TGraphAsymmErrors(n,x,y,exl,exh,eyl,eyh);
   gr->SetTitle("TGraphAsymmErrors Example");
   TH2D *h = new TH2D("h","",9,-1,8,100,0,3);
   TCanvas *c = new TCanvas("c","",600,600);
   h->SetAxisRange(0,3,"Y");
   h->SetXTitle("N_{SD}");
   h->SetYTitle("PbPb / PYTHIA");
   TLine *l = new TLine(-1,1,8,1);
   l->SetLineStyle(2);
   h->Draw();
   l->Draw();
   gr->Draw("p same");
   
   TLegend *leg = new TLegend(0.5,0.7,0.9,0.9);
   leg->AddEntry(gr,"0-10% 2.76 TeV PbPb","");
   leg->AddEntry(gr,"Anti-k_{T} charged jet R=0.4","");
   leg->AddEntry(gr,"80<p_{T, jet}^{ch}<120 GeV/c",""); 
   leg->AddEntry(gr,"Soft Drop Z_{cut}=0.1","");
   leg->SetBorderSize(0);
   leg->SetFillStyle(0); 
   leg->Draw();
   gr->Write();
}
   
