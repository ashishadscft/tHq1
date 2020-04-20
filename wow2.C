void wow2() {

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

  TH2F * H4 = NULL;
  TH2F * H5 = NULL;
  TH2F * H6 = NULL;
  TH2F * H7 = NULL;
  TH2F * H8 = NULL;
  TH2F * H9 = NULL;
  
  
  H4 = (TH2F*)f4->Get("BRIL_IT_Analysis/TFPX/3xCoincidences/Number of 3x Coincidences for Disk 4");
  H5 = (TH2F*)f5->Get("BRIL_IT_Analysis/TFPX/3xCoincidences/Number of 3x Coincidences for Disk 4");
  H6 = (TH2F*)f6->Get("BRIL_IT_Analysis/TFPX/3xCoincidences/Number of 3x Coincidences for Disk 4");
  H7 = (TH2F*)f7->Get("BRIL_IT_Analysis/TFPX/3xCoincidences/Number of 3x Coincidences for Disk 4");
  H8 = (TH2F*)f8->Get("BRIL_IT_Analysis/TFPX/3xCoincidences/Number of 3x Coincidences for Disk 4");
  H9 = (TH2F*)f9->Get("BRIL_IT_Analysis/TFPX/3xCoincidences/Number of 3x Coincidences for Disk 4");


  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0); 

  TH1D*H14 = H4->ProjectionY("H14",5,5);
  H14->GetXaxis()->SetRangeUser(0,30);
  H14->SetLineColor(4);
  //H14->Scale(1./H14->Integral());  

  TH1D* H15 = H5->ProjectionY("H15",5,5);
  H15->GetXaxis()->SetRangeUser(0,500);
  H15->SetLineColor(32);
  //H15->Scale(1./H15->Integral());

  TH1D* H16 = H6->ProjectionY("H16",5,5);
  H16->GetXaxis()->SetRangeUser(0,500);
  H16->SetLineColor(6);
  //H16->Scale(1./H16->Integral());

  TH1D* H17 = H7->ProjectionY("H17",5,5);
  H17->GetXaxis()->SetRangeUser(0,500);
  H17->SetLineColor(41);
  //H17->Scale(1./H17->Integral());

  TH1D* H18 = H8->ProjectionY("H18",5,5);
  H18->GetXaxis()->SetRangeUser(0,500);
  H18->SetLineColor(8);
  //H18->Scale(1./H18->Integral());

  TH1D* H19 = H9->ProjectionY("H19",5,5);
  H19->GetXaxis()->SetRangeUser(0,500);
  H19->SetLineColor(46);
  //H19->Scale(1./H19->Integral());

  H14->Draw("same");
  H15->Draw("same");
  H16->Draw("same");
  H17->Draw("same");
  H18->Draw("same");
  H19->Draw("same");

  auto legend = new TLegend(0.65,0.65,0.88,0.88);
  legend->SetHeader("Pileup","C"); // option "C" allows to center the header
  legend->AddEntry(H14,"10","l");
  legend->AddEntry(H15,"30","l");
  legend->AddEntry(H16,"50","l");
  legend->AddEntry(H17,"100","l");
  legend->AddEntry(H18,"140","l");
  legend->AddEntry(H19,"200","l");
  legend->SetFillColor(0);
  legend->SetLineColor(0);
  legend->SetFillColor(0);

  legend->Draw();
 
  C->Print("/home/ashish/13beta.gif");
}


