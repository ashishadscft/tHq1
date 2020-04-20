void wow1() {

  TFile*f = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU0p5.root");
  TFile*f1 = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU1.root");
  TFile*f2 = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU1p5.root");
  TFile*f3 = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU2.root");
  TFile*f4 = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU10.root");
  TFile*f5 = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU30.root");
  TFile*f6 = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU50.root");
  TFile*f7 = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU100.root");
  TFile*f8 = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU140.root");
  TFile*f9 = new TFile("/home/ashish/TEPX/samples_17Feb2020/2023D42PU200.root");
  
  TCanvas * C = new TCanvas("Clusters","");
  //C->SetLogx();
  C->SetLogy();

  TH2F * H =  NULL;
  TH2F * H1 = NULL;
  TH2F * H2 = NULL;
  TH2F * H3 = NULL;
  
   H = (TH2F*)f->Get("BRIL_IT_Analysis/TEPX/2xCoincidences/Number of 2x Coincidences for Disk 4");
  if (H==NULL){
  return;
   }
  H->GetXaxis()->SetRangeUser(0,3000);
  
  H1 = (TH2F*)f1->Get("BRIL_IT_Analysis/TEPX/2xCoincidences/Number of 2x Coincidences for Disk 4");
  H2 = (TH2F*)f2->Get("BRIL_IT_Analysis/TEPX/2xCoincidences/Number of 2x Coincidences for Disk 4");
  H3 = (TH2F*)f3->Get("BRIL_IT_Analysis/TEPX/2xCoincidences/Number of 2x Coincidences for Disk 4");
  

  TH1D* H10 = H->ProjectionY("H10",1,1);
  //H10->GetYaxis()->SetRangeUser(0,0.20);
  H10->SetTitle("Number of 2x Coincidences for Disk 4 Ring 1");
  H10->SetYTitle("# of events ( normalized to unit )"); 
  H10->GetYaxis()->SetRangeUser(0.001,1);
  H10->GetXaxis()->SetRangeUser(0,3000);
  H10->SetLineColor(28);

  H10->Scale(1./H10->Integral());
  gStyle->SetOptStat(0);
  //gStyle->SetOptTitle(0); 

  TH1D* H11 = H1->ProjectionY("H11",1,1);
  H11->GetXaxis()->SetRangeUser(0,3000);
  H11->SetLineColor(1);
  H11->Scale(1./H11->Integral());

  TH1D* H12 = H2->ProjectionY("H12",1,1);
  H12->GetXaxis()->SetRangeUser(0,3000);
  H12->SetLineColor(2);
  H12->Scale(1./H12->Integral());

  TH1D* H13 = H3->ProjectionY("H13",1,1);
  H13->GetXaxis()->SetRangeUser(0,3000);
  H13->SetLineColor(3);
  H13->Scale(1./H13->Integral());

  

  H10->Draw();
  H11->Draw("same");
  H12->Draw("same");
  H13->Draw("same");
  
  auto legend = new TLegend(0.68,0.68,0.89,0.89);
  //legend->SetHeader("Pileup","C"); // option "C" allows to center the header
  legend->AddEntry(H10,"pu = 0.5","l");
  legend->AddEntry(H11,"pu = 1","l");
  legend->AddEntry(H12,"pu = 1.5","l");
  legend->AddEntry(H13,"pu = 2","l");
  legend->SetFillColor(0);
  legend->SetLineColor(0);
  legend->SetFillColor(0);

  legend->Draw();
 
  C->Print("/home/ashish/12beta.gif");
}


