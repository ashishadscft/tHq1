void mmm() {

  TFile * f = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU200.root");
  TCanvas * C = new TCanvas("Clusters","");
 //C->SetLogy();

  TH2F * H1=NULL;                                                                                                                            


  H1 = (TH2F*)f->Get("BRIL_IT_Analysis/TEPX/perModule/Number of Clusters per module per event");
  if (H1==NULL){
    return;
  }
  H1->GetXaxis()->SetRangeUser(0,20);

//gStyle->SetOptTitle(0);
  //gStyle->SetOptStat(1111);
  H1->Draw("colz");
 C->Print("/home/ashish/206.gif");
}


