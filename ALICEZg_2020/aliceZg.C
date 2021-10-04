{
  TFile *outf = new TFile("alice.root","recreate");
 const Int_t n= 5;
 Double_t x[n]   = {0.1376,0.2125,0.2875,0.3625,0.45};
   Double_t y[n]   = {4.71,1.29,0.643,0.339,0.134};
   Double_t exl[n] = {0.0375,0.0375,0.0375,0.0375,0.05};
   Double_t eyl[n] = {0.410121933,0.23430749,0.108503456,0.096607453,0.044598206};
   Double_t exh[n] = {0.0375,0.0375,0.0375,0.0375,0.05};
   Double_t eyh[n] = {0.382883794,0.242074369,0.109881755,0.089554453,0.046518813};
   auto gr = new TGraphAsymmErrors(n,x,y,exl,exh,eyl,eyh);
   gr->SetTitle("TGraphAsymmErrors Example");
   gr->Draw("ap");
   gr->Write();
}
   
