{
  TFile *outf = new TFile("aliceCMSNorm.root","recreate");
 const Int_t n= 5;
 Double_t x[n]   = {0.1376,0.2125,0.2875,0.3625,0.45};
   Double_t y[n]   = {1.094392719,0.967685366,0.945259285,0.773699771,0.440672478};
   Double_t exl[n] = {0.0375,0.0375,0.0375,0.0375,0.05};
   Double_t eyl[n] = {0.09529394,0.175764286,0.159508397,0.22048721,0.146665687};
   Double_t exh[n] = {0.0375,0.0375,0.0375,0.0375,0.05};
   Double_t eyh[n] = {0.088965018,0.181590561,0.161534602,0.204390146,0.152981797};
   auto gr = new TGraphAsymmErrors(n,x,y,exl,exh,eyl,eyh);
   gr->SetTitle("TGraphAsymmErrors Example");
   gr->Draw("ap");
   gr->Write();
}
   
