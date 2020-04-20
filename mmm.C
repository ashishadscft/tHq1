void mmm() {

  TFile * f = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU100.root");
  TCanvas * C = new TCanvas("Hits","");


  TH2F * H1=NULL;                                                                                                                            


  H1 = (TH2F*)f->Get("BRIL_IT_Analysis/TEPX/Clusters/Number of clusters for Disk 4");
  if (H1==NULL){
    return;
  }
  H1->GetYaxis()->SetRangeUser(0,3500);

//gStyle->SetOptTitle(0);
  gStyle->SetOptStat(1111);
  H1->Draw("colz");
 C->Print("/home/ashish/206.gif");
}


