void omg() {

  TFile * f = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU100.root");
  TCanvas * C = new TCanvas("Hits","");


  TH2F * H1=NULL;                                                                                                                            


  H1 = (TH2F*)f->Get("BRIL_IT_Analysis/TEPX/3xCoincidences/Number of 3x Coincidences for Disk 4");
  if (H1==NULL){
    return;
  }
  //H1->GetYaxis()->SetRangeUser(0,100);

  TProfile *p = H1->ProfileY();

//gStyle->SetOptTitle(0);
  gStyle->SetOptStat(1111);
  //H1->Draw("colz");
  p->Draw();
 C->Print("/home/ashish/206.gif");
}


