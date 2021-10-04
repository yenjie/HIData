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


TGraphAsymmErrors* getALICEZg_2760_2020()
{
   //https://www.hepdata.net/record/ins1127262
   TFile *inf = new TFile ("ALICEZg_2020/aliceCMSNorm.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Graph");
   g->SetName("ALICEZg_2760_2020");
   return g;
}


TGraphAsymmErrors* getSTARZg_200_UNP()
{
   //https://www.hepdata.net/record/ins1127262
   TFile *inf = new TFile ("STARZg_Unpublished/star.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Graph");
   g->SetName("STARZg_200_UNP");
   return g;
}


TGraphAsymmErrors* getCMSZg_5020_2019()
{
   //https://www.hepdata.net/record/ins1127262
   TFile *inf = new TFile ("CMSZg_2018/HEPData-ins1620905-v1-Table_10.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 10/Graph1D_y1");
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



void plotZgStar()
{
   TCanvas *c = new TCanvas("c","",600,600);
   TGraphAsymmErrors *gALICE_Zg = getALICEZg_2760_2020();
   TGraphAsymmErrors *gSTAR_Zg = getSTARZg_200_UNP();
   TGraphAsymmErrors *gCMS_Zg = getCMSZg_5020_2019();

   gALICE_Zg->SetMarkerStyle(25);
   gALICE_Zg->SetLineColor(1);
   gALICE_Zg->SetMarkerColor(1);
   gALICE_Zg->SetMarkerSize(1.5);
   gCMS_Zg->SetMarkerStyle(21);
   gCMS_Zg->SetLineColor(1);
   gCMS_Zg->SetMarkerColor(1);
   gCMS_Zg->SetMarkerSize(1);
   gSTAR_Zg->SetMarkerStyle(20);
   gSTAR_Zg->SetLineColor(2);
   gSTAR_Zg->SetMarkerColor(2);
   gSTAR_Zg->SetMarkerSize(1);
   
   TH1F *h = new TH1F("h","",10000,0,0.5);
   formatHist(h);
   h->SetAxisRange(0,2,"Y");
   h->SetAxisRange(0,0.5,"X");
   
   h->SetXTitle("Z_{g}");
   h->SetYTitle("PbPb / pp reference");
   h->Draw();
   gSTAR_Zg->Draw("p same");
   gALICE_Zg->Draw("p same");
   gCMS_Zg->Draw("p same");
   
   TLegend *leg0 = new TLegend(0.14,0.31,0.52,0.35);
   formatLegend(leg0);
//   leg0->AddEntry(gALICE,"PbPb #sqrt{s_{NN}}=5.02 TeV, 0-10%","");
   leg0->AddEntry(gALICE_Zg,"Anti-k_{T} R=0.4","");
   leg0->Draw();

   TLegend *leg = new TLegend(0.177,0.71,0.93,0.92);
   formatLegend(leg);
   leg->AddEntry(gCMS_Zg,"CMS 160<p_{T}<180 GeV, #Delta R>0.1, PbPb 0-10% 5.02 TeV/pp","pl");
   leg->AddEntry(gALICE_Zg,"ALICE 80<p_{T}<120 GeV, #Delta R>0.1, PbPb 0-10% 2.76 TeV/PYTHIA","pl");
//   leg->AddEntry(gATLAS,"ATLAS, |y|<2.8","pl");
   leg->AddEntry(gSTAR_Zg,"STAR 10<p_{T}<20 GeV, High Tower, AuAu 0-20% 0.2 TeV/pp","pl");
   leg->Draw();
   
   
   
   TLine *l = new TLine(0,1,0.5,1);
   l->SetLineStyle(2);
   l->Draw();

}
