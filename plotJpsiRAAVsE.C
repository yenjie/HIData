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


TGraphAsymmErrors* getATLASPromptJpsiRAA_2018()
{
  //https://doi.org/10.17182/hepdata.103082
  // 0-10%
   TFile *inf = new TFile ("ATLASPromptJpsi_5020_2018/HEPData-ins1672469-v1-Table_6.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 6/Graph1D_y1");
   return g;
}

TGraphAsymmErrors* getALICEInclusiveJpsiRAA_2020()
{
   //https://doi.org/10.17182/hepdata.94384
   // 0-20%
   TFile *inf = new TFile ("ALICEInclusiveJpsi_5020_2020/HEPData-ins1762353-v1-Table_6.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 6/Graph1D_y1");
   return g;
}

TGraphAsymmErrors* getSTARInclusiveJpsiRAA_200_2018()
{
   //https://doi.org/10.17182/hepdata.94384
   // 0-20%
   TFile *inf = new TFile ("STARInclusiveJpsiRAA_200_2019/HEPData-ins1737650-v1-Figure_4.0.1.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Figure 4.0.1/Graph1D_y1");
   return g;
}


TGraphAsymmErrors* getALICEInclusiveJpsiForwardRAA_2760_2016()
{
   //https://doi.org/10.17182/hepdata.93341
   // 0-20%
   TFile *inf = new TFile("ALICEInclusiveJpsiForwardRAA_2760_2016/HEPData-ins1380192-v1-Table_7.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 7/Graph1D_y1");
   return g;
}

TGraphAsymmErrors* getALICEInclusiveJpsiForwardRAA_2020()
{
   //https://doi.org/10.17182/hepdata.93341
   // 0-20%
   TFile *inf = new TFile ("ALICEInclusiveJpsiForward_5020_2020/HEPData-ins1753083-v1-Table_7.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 7/Graph1D_y1");
   return g;
}


TGraphAsymmErrors* getCMSPromptJpsiRAA_5020_2018()
{
   //https://doi.org/10.17182/hepdata.80816
   
   // 0-10%
   TFile *inf = new TFile ("CMSPromptJpsiRAA_5020_2018/HEPData-ins1644903-v1-Table_13.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 13/Graph1D_y1");
   return g;
}




void plotJpsiRAAVsE()
{
   TCanvas *c = new TCanvas("c","",600,600);
//   c->SetLogx();
   TGraphAsymmErrors *gATLAS_PromptJpsi = getATLASPromptJpsiRAA_2018();
//   TGraphAsymmErrors *gALICE = getALICEChargedParticleRAA_5020_2020();
   TGraphAsymmErrors *gALICE_InclusiveJpsi = getALICEInclusiveJpsiRAA_2020();
   TGraphAsymmErrors *gALICE_InclusiveJpsiForward = getALICEInclusiveJpsiForwardRAA_2020();
   TGraphAsymmErrors *gALICE_InclusiveJpsiForward_2760 = getALICEInclusiveJpsiForwardRAA_2760_2016();
   TGraphAsymmErrors *gSTAR_InclusiveJpsi = getSTARInclusiveJpsiRAA_200_2018();
//   TGraphAsymmErrors *gCMS = getCMSChargedParticleRAA_5020_2021();
   TGraphAsymmErrors *gCMS_PromptJpsi = getCMSPromptJpsiRAA_5020_2018();
   TGraphAsymmErrors *gCMS_NPJpsi = getCMSNPJpsiRAA_5020_2018();
//   TGraphAsymmErrors *gSTAR = getSTARChargedHadronRAA_200_2003();
//   TGraphAsymmErrors *gPHENIX = getPHENIXPi0RAA_200_2013();
   
   gSTAR_InclusiveJpsi->SetMarkerStyle(20);
   gSTAR_InclusiveJpsi->SetMarkerSize(1.5);
   gSTAR_InclusiveJpsi->SetMarkerColor(4);
   gALICE_InclusiveJpsi->SetMarkerStyle(21);
   gALICE_InclusiveJpsi->SetLineColor(1);
   gALICE_InclusiveJpsi->SetMarkerColor(1);
   gALICE_InclusiveJpsiForward->SetMarkerSize(1.5);
   gALICE_InclusiveJpsiForward->SetMarkerStyle(25);
   gALICE_InclusiveJpsiForward->SetLineColor(1);
   gALICE_InclusiveJpsiForward->SetMarkerColor(1);
   gALICE_InclusiveJpsiForward->SetMarkerSize(1.5);
   gALICE_InclusiveJpsiForward_2760->SetMarkerSize(1.5);
   gALICE_InclusiveJpsiForward_2760->SetMarkerStyle(25);
   gALICE_InclusiveJpsiForward_2760->SetLineColor(2);
   gALICE_InclusiveJpsiForward_2760->SetMarkerColor(2);
   gALICE_InclusiveJpsiForward_2760->SetMarkerSize(1.5);
   gCMS_PromptJpsi->SetMarkerStyle(20);
   gCMS_PromptJpsi->SetLineColor(1);
   gCMS_PromptJpsi->SetMarkerColor(4);
   gCMS_PromptJpsi->SetMarkerSize(1.5);
   gCMS_NPJpsi->SetMarkerStyle(20);
   gCMS_NPJpsi->SetLineColor(2);
   gCMS_NPJpsi->SetMarkerColor(2);
   gCMS_NPJpsi->SetMarkerSize(1);
   
   
   TH1F *h = new TH1F("h","",10000,0,1000);
   formatHist(h);
   h->SetAxisRange(0,1.8,"Y");
   h->SetAxisRange(0,15,"X");
   
   h->SetXTitle("p_{T} (GeV)");
   h->SetYTitle("R_{AA}");
   h->Draw();
//   gATLAS_PromptJpsi->Draw("p same");
   gALICE_InclusiveJpsi->Draw("p same");
//   gALICE_InclusiveJpsiForward_2760->Draw("p same");
   gALICE_InclusiveJpsiForward->Draw("p same");
//   gALICE_InclusiveJpsi->Draw("p same");
//   gSTAR->Draw("p same");
//   gCMS_PromptJpsi->Draw("p same");
//   gCMS_NPJpsi->Draw("p same");
//   gCMS_PromptJpsi->Draw("p same");
   gSTAR_InclusiveJpsi->Draw("p same");
//   gPHENIX->Draw("p same");
   
   TLegend *leg0 = new TLegend(0.274,0.711,0.918,0.913);
   formatLegend(leg0);
   leg0->AddEntry(gALICE_InclusiveJpsi,"PbPb #sqrt{s_{NN}}=5.02 TeV","");
//   leg0->AddEntry(gALICE_InclusiveJpsi,"J/#psi","");
//   leg0->Draw();

   TLegend *leg = new TLegend(0.30,0.711,0.945,0.913);
   formatLegend(leg);
   leg->AddEntry(gALICE_InclusiveJpsi,"Centrality 0-20%","");
   leg->AddEntry(gALICE_InclusiveJpsi,"ALICE Inclusive J/#psi, PbPb 5.02 TeV, |y|<0.9","pl");
   leg->AddEntry(gALICE_InclusiveJpsiForward,"ALICE Inclusive J/#psi, PbPb 5.02 TeV, 2.5<y<4.0","pl");
//   leg->AddEntry(gALICE_InclusiveJpsiForward_2760,"ALICE Inclusive J/#psi, PbPb 2.76 TeV, 2.5<y<4.0","pl");
   leg->AddEntry(gSTAR_InclusiveJpsi,"STAR Inclusive J/#psi,AuAu 0.2 TeV, |y|<0.5","pl");
//   leg->AddEntry(gSTAR,"STAR h^{#pm}, AuAu 0.2 TeV 0-5%, |y|<0.5","pl");
//   leg->AddEntry(gPHENIX,"PHENIX #pi^{0}, AuAu 0.2 TeV 0-10%, |y|<0.5","pl");
   leg->Draw();
   
   TLine *l = new TLine(0.,1,15,1);
   l->SetLineStyle(2);
   l->Draw();

}
