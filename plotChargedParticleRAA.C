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



void plotChargedParticleRAA()
{
   TCanvas *c = new TCanvas("c","",600,600);
   c->SetLogx();
//   TGraphAsymmErrors *gATLAS = getATLASChargedParticleRAA_5020_2019();
   TGraphAsymmErrors *gALICE = getALICEChargedParticleRAA_5020_2020();
   TGraphAsymmErrors *gALICE_D = getALICEDRAA_5020_2018();
   TGraphAsymmErrors *gCMS = getCMSChargedParticleRAA_5020_2021();
   TGraphAsymmErrors *gCMS_D = getCMSDRAA_5020_2018();
   TGraphAsymmErrors *gSTAR = getSTARChargedHadronRAA_200_2003();
   TGraphAsymmErrors *gPHENIX = getPHENIXPi0RAA_200_2013();
   
//   gATLAS->SetMarkerStyle(20);
//   gATLAS->SetMarkerSize(1.5);
   gALICE->SetMarkerStyle(25);
   gALICE->SetLineColor(1);
   gALICE->SetMarkerColor(1);
   gALICE->SetMarkerSize(1.5);
   gCMS->SetMarkerStyle(21);
   gCMS->SetLineColor(1);
   gCMS->SetMarkerColor(1);
   gCMS->SetMarkerSize(1);
   
   gSTAR->SetMarkerStyle(20);
   gSTAR->SetMarkerColor(2);
   gSTAR->SetLineColor(2);
   gPHENIX->SetMarkerStyle(24);
   gPHENIX->SetMarkerColor(2);
   gPHENIX->SetMarkerSize(1.5);
   gPHENIX->SetLineColor(2);
   
   TH1F *h = new TH1F("h","",10000,0,1000);
   formatHist(h);
   h->SetAxisRange(0,1.6,"Y");
   h->SetAxisRange(0.1,1000,"X");
   
   h->SetXTitle("p_{T} (GeV)");
   h->SetYTitle("R_{AA}");
   h->Draw();
//   gATLAS->Draw("p same");
   gALICE->Draw("p same");
//   gALICE_D->Draw("p same");
//   gSTAR->Draw("p same");
   gCMS->Draw("p same");
//   gCMS_D->Draw("p same");
   gSTAR->Draw("p same");
   gPHENIX->Draw("p same");
   
   TLegend *leg0 = new TLegend(0.4,0.25,0.9,0.35);
   formatLegend(leg0);
//   leg0->AddEntry(gALICE,"PbPb #sqrt{s_{NN}}=5.02 TeV, 0-10%","");
   leg0->AddEntry(gALICE,"Charged Particle","");
//   leg0->Draw();

   TLegend *leg = new TLegend(0.2,0.72,0.9,0.92);
   formatLegend(leg);
   leg->AddEntry(gALICE,"ALICE h^{#pm}, PbPb 5.02 TeV 0-5%, |y|<0.8","pl");
//   leg->AddEntry(gATLAS,"ATLAS, |y|<2.8","pl");
   leg->AddEntry(gCMS,"CMS h^{#pm}, PbPb 5.02 TeV 0-5%, |y|<1.0","pl");
   leg->AddEntry(gSTAR,"STAR h^{#pm}, AuAu 0.2 TeV 0-5%, |y|<0.5","pl");
   leg->AddEntry(gPHENIX,"PHENIX #pi^{0}, AuAu 0.2 TeV 0-10%, |y|<0.5","pl");
   leg->Draw();
   
   TLine *l = new TLine(0.1,1,1000,1);
   l->SetLineStyle(2);
   l->Draw();

}
