#include <TFile.h>
#include <TGraphAsymmErrors.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TLine.h>

void formatLegend(TLegend *leg)
{
   leg->SetBorderSize(0);
   leg->SetFillStyle(0);
}

void formatHist(TH1* h)
{
  h->GetXaxis()->CenterTitle();
  h->GetYaxis()->CenterTitle();
  h->SetMarkerSize(3);

}

TGraphAsymmErrors* getCMSPhotonRAA_5020_2020()
{
   // doi:doi.org/10.17182/hepdata.93877
   // R=0.4
   TFile *inf = new TFile ("CMSPhotonRAA_5020_2020/HEPData-ins1788620-v1-Figure_5.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Figure 5/Graph1D_y1");
   return g;
}


TGraphAsymmErrors* getCMSJetRAA_5020_2021()
{
   // oi:10.17182/hepdata.93881.v1/t10
   // R=0.4
   TFile *inf = new TFile ("CMSJetRAA_5020_2021/HEPData-ins1848440-v1-Figure_7-3.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Figure 7-3/Graph1D_y1");
   return g;
}

TGraphAsymmErrors* getALICEJetRAA_5020_2020()
{
   // doi:10.17182/hepdata.93739.v1/t33
   // R=0.4
   TFile *inf = new TFile ("ALICEJetRAA_5020_2020/HEPData-ins1755387-v1-Table_33.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 33/Graph1D_y1");
   return g;
}

TGraphAsymmErrors* getATLASJetRAA_5020_2019()
{
   // doi:10.17182/hepdata.84819.v1/t19
   // R=0.4
   TFile *inf = new TFile ("ATLASJetRAA_5020_2019/HEPData-ins1673184-v1-Table_19.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 19/Graph1D_y1");
   return g;
}

TGraphAsymmErrors* getSTARJetRAA_200_2020()
{
   //https://www.hepdata.net/record/ins1798665
   //R=0.4
   TFile *inf = new TFile ("STARJetRAA_200_2020/HEPData-ins1798665-v1-Table_10.root");
   TGraphAsymmErrors* g = (TGraphAsymmErrors*) inf->Get("Table 10/Graph1D_y3");
   return g;
}


void plotJetEWRAA()
{
   TCanvas *c = new TCanvas("c","",600,600);
   c->SetLogx();
   TGraphAsymmErrors *gATLAS = getATLASJetRAA_5020_2019();
   TGraphAsymmErrors *gSTAR = getSTARJetRAA_200_2020();
   TGraphAsymmErrors *gALICE = getALICEJetRAA_5020_2020();
   TGraphAsymmErrors *gCMS = getCMSJetRAA_5020_2021();
   TGraphAsymmErrors *gCMSPhoton = getCMSPhotonRAA_5020_2020();
   gATLAS->SetMarkerStyle(20);
   gATLAS->SetMarkerSize(1.5);
 //  gATLAS->Draw("ap");
   gSTAR->SetMarkerStyle(29);
   gALICE->SetMarkerStyle(20);
   gALICE->SetLineColor(2);
   gALICE->SetMarkerColor(2);
   gALICE->SetMarkerSize(1.5);
   gCMS->SetMarkerStyle(20);
   gCMS->SetLineColor(4);
   gCMS->SetMarkerColor(4);
   gCMS->SetMarkerSize(1.5);
//   gSTAR->Draw("p same");
   
   TH1F *h = new TH1F("h","",1000,0,2000);
   formatHist(h);
   h->SetAxisRange(0,2,"Y");
   h->SetAxisRange(20,2000,"X");
   
   h->SetXTitle("p_{T} (GeV)");
   h->SetYTitle("R_{AA}");
   h->Draw();
   gATLAS->Draw("p same");
   gALICE->Draw("p same");
   //gSTAR->Draw("p same");
   gCMS->Draw("p same");
   gCMSPhoton->Draw("p same");
   gCMSPhoton->SetMarkerStyle(24);
   
   TLegend *leg0 = new TLegend(0.4,0.21,0.9,0.31);
   formatLegend(leg0);
   leg0->AddEntry(gALICE,"PbPb #sqrt{s_{NN}}=5.02 TeV, 0-10%","");
//   leg0->AddEntry(gALICE,"Anti-k_{T} jet R=0.4","");
   leg0->Draw();

   TLegend *leg = new TLegend(0.3,0.7,0.94,0.92);
   formatLegend(leg);
   leg->AddEntry(gALICE,"Anti-k_{T} Jet R=0.4","");
   leg->AddEntry(gALICE,"ALICE, |y|<0.3, PbPb lead track p_{T}> 7 GeV","pl");
   leg->AddEntry(gATLAS,"ATLAS, |y|<2.8","pl");
   leg->AddEntry(gCMS,"CMS, |y|<2.0","pl");
   leg->AddEntry(gALICE,"Isolated Prompt Photon","");
   leg->AddEntry(gCMSPhoton,"CMS, |#eta|<1.44","pl");
   leg->Draw();
   
   TLine *l = new TLine(20,1,2000,1);
   l->SetLineStyle(2);
   l->Draw();

}
