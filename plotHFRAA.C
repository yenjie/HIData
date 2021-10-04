#include <TFile.h>
#include <TGraphAsymmErrors.h>
#include <TH1D.h>
#include <TCanvas.h>

void formatLegend(TLegend *leg)
{
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
}

void formatHist(TH1* h)
{
  h->GetXaxis()->CenterTitle();
  h->SetTitleOffset(1.2,"X");
  h->GetYaxis()->CenterTitle();
  h->SetMarkerSize(3);

}

TGraphAsymmErrors* getCMSChargedParticleRAA_5020_2021()
{
   // 10.17182/hepdata.77101.v2/t8
   TFile *inf = new TFile ("CMSChargedParticleRAA_5020_2017/HEPData-ins1496050-v2-Table_8.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 8/Graph1D_y1");
   return g;
}

TGraphAsymmErrors* getALICEChargedParticleRAA_5020_2020()
{
   // doi:10.17182/hepdata.86210.v1/t8
   TFile *inf = new TFile ("ALICEChargedParticleRAA_5020_2018/HEPData-ins1657384-v1-Table_8.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 8/Graph1D_y1");
   return g;
}

TGraphAsymmErrors* getALICEDRAA_5020_2018()
{
   //https://www.hepdata.net/record/ins1669819
   TFile *inf = new TFile ("ALICEDRAA_5020_2018/HEPData-ins1669819-v1-Table_29.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 29/Graph1D_y1");
   return g;
}


TGraphAsymmErrors* getCMSDRAA_5020_2018()
{
   //https://www.hepdata.net/record/ins1616207
   TFile *inf = new TFile ("CMSDRAA_5020_2018/HEPData-ins1616207-v1-Table_1.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 1/Graph1D_y2");
   return g;
}

TGraphAsymmErrors* getCMSNPJpsiRAA_5020_2018()
{
   //https://www.hepdata.net/record/ins1644903
   TFile *inf = new TFile ("CMSNPJpsiRAA_5020_2018/HEPData-ins1644903-v1-Table_31.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 31/Graph1D_y1");
   return g;
}


TGraphAsymmErrors* getSTARChargedHadronRAA_200_2003()
{
   //https://www.hepdata.net/record/ins1616207
   TFile *inf = new TFile ("STARChargedHadronRAA_200_2003/HEPData-ins619063-v1-Table_3.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 3/Graph1D_y1");
   return g;
}

TGraphAsymmErrors* getPHENIXPi0RAA_200_2013()
{
   //https://www.hepdata.net/record/ins1127262
   TFile *inf = new TFile ("PHENIXPi0RAA_200_2013/HEPData-ins1127262-v2-Figure_11.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Figure 11/Graph1D_y1");
   return g;
}


//TGraphAsymmErrors* getATLASChargedParticleRAA_5020_2017()
//{
   // doi:10.17182/hepdata.84819.v1/t19
   // https://cds.cern.ch/record/2244824/files/ATLAS-CONF-2017-012.pdf
  // TFile *inf = new TFile ("ATLASChargedParticleRAA_5020_2019/HEPData-ins1673184-v1-Table_19.root");
  // TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 19/Graph1D_y1");
  // return g;
//}



void plotHFRAA()
{
   TCanvas *c = new TCanvas("c","",600,600);
   c->SetLogx();
//   TGraphAsymmErrors *gATLAS = getATLASChargedParticleRAA_5020_2019();
//   TGraphAsymmErrors *gALICE = getALICEChargedParticleRAA_5020_2020();
   TGraphAsymmErrors *gALICE_D = getALICEDRAA_5020_2018();
//   TGraphAsymmErrors *gCMS = getCMSChargedParticleRAA_5020_2021();
   TGraphAsymmErrors *gCMS_D = getCMSDRAA_5020_2018();
   TGraphAsymmErrors *gCMS_NPJpsi = getCMSNPJpsiRAA_5020_2018();
//   TGraphAsymmErrors *gSTAR = getSTARChargedHadronRAA_200_2003();
//   TGraphAsymmErrors *gPHENIX = getPHENIXPi0RAA_200_2013();
   
//   gATLAS->SetMarkerStyle(20);
//   gATLAS->SetMarkerSize(1.5);
   gALICE_D->SetMarkerStyle(25);
   gALICE_D->SetLineColor(1);
   gALICE_D->SetMarkerColor(1);
   gALICE_D->SetMarkerSize(1.5);
   gCMS_D->SetMarkerStyle(21);
   gCMS_D->SetLineColor(1);
   gCMS_D->SetMarkerColor(1);
   gCMS_D->SetMarkerSize(1);
   gCMS_NPJpsi->SetMarkerStyle(20);
   gCMS_NPJpsi->SetLineColor(2);
   gCMS_NPJpsi->SetMarkerColor(2);
   gCMS_NPJpsi->SetMarkerSize(1);
   
   
   TH1F *h = new TH1F("h","",10000,0,1000);
   formatHist(h);
   h->SetAxisRange(0,1.8,"Y");
   h->SetAxisRange(0.5,200,"X");
   
   h->SetXTitle("p_{T} (GeV)");
   h->SetYTitle("R_{AA}");
   h->Draw();
//   gATLAS->Draw("p same");
   gALICE_D->Draw("p same");
//   gALICE_D->Draw("p same");
//   gSTAR->Draw("p same");
   gCMS_D->Draw("p same");
   gCMS_NPJpsi->Draw("p same");
//   gCMS_D->Draw("p same");
//   gSTAR->Draw("p same");
//   gPHENIX->Draw("p same");
   
   TLegend *leg0 = new TLegend(0.4,0.25,0.9,0.35);
   formatLegend(leg0);
//   leg0->AddEntry(gALICE,"PbPb #sqrt{s_{NN}}=5.02 TeV, 0-10%","");
   leg0->AddEntry(gALICE_D,"Charged Particle","");
//   leg0->Draw();

   TLegend *leg = new TLegend(0.2,0.72,0.9,0.92);
   formatLegend(leg);
   leg->AddEntry(gALICE_D,"ALICE D^{0}, D^{#pm}, D^{*+}, PbPb 5.02 TeV 0-10%, |y|<0.5","pl");
//   leg->AddEntry(gATLAS,"ATLAS, |y|<2.8","pl");
   leg->AddEntry(gCMS_D,"CMS D^{0}, PbPb 5.02 TeV 0-10%, |y|<1.0","pl");
   leg->AddEntry(gCMS_NPJpsi,"CMS b#rightarrowJ/#psi, PbPb 5.02 TeV 0-10%, |y|<2.4","pl");
//   leg->AddEntry(gSTAR,"STAR h^{#pm}, AuAu 0.2 TeV 0-5%, |y|<0.5","pl");
//   leg->AddEntry(gPHENIX,"PHENIX #pi^{0}, AuAu 0.2 TeV 0-10%, |y|<0.5","pl");
   leg->Draw();
   
   TLine *l = new TLine(0.5,1,200,1);
   l->SetLineStyle(2);
   l->Draw();

}
