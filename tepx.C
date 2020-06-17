void tepx() {

    //TString outputpath = "/home/ashish/";
    TString histoname = "BRIL_IT_Analysis/TEPX/Clusters/Number of clusters for Disk ";
    TString outputpath = "/home/ashish/TEPX_plot1/";
    TString inpath = "/home/ashish/TEPX/samples_17Feb2020/";

    //gROOT->ProcessLine(".x BRIL-upgrade/rootlogon.C");
    
    //string containing names of input sample files
    std::vector<std::string> pulist = { "2023D42PU0p5", "2023D42PU1", "2023D42PU1p5", "2023D42PU2", "2023D42PU10", "2023D42PU30", "2023D42PU50", "2023D42PU100", "2023D42PU140", "2023D42PU200" };
    std::map<std::string, float> pumap = { { "2023D42PU0p5", 0.5 }, { "2023D42PU1", 1 }, { "2023D42PU1p5", 1.5 }, { "2023D42PU2", 2 }, { "2023D42PU10", 10 }, { "2023D42PU30", 30 }, { "2023D42PU50", 50 }, { "2023D42PU100", 100 }, { "2023D42PU140", 140 }, { "2023D42PU200", 200 } };
    std::vector<std::string> disklist = { "-4", "-3", "-2", "-1", "1", "2", "3", "4" };

    //create the profiles to be filled below.
    TGraphErrors* TEPXClustersPerEvent[20][4]; //number of clusters vs pu
    TH2F* Histogram2D[11][16];
    TH1D* ProjectionY[20][20];
    for (int d = 0; d < disklist.size(); d++){
      for (int r = 0; r < 5; r++){
            TEPXClustersPerEvent[d][r] = new TGraphErrors();
      }
    }
    //Non-linearity graphs
    TGraphErrors* NonLinearity_TEPXClustersPerEvent[20][4]; //number of clusters vs pu
    for (int d = 0; d < disklist.size(); d++) {
        for (int r = 0; r < 5; r++) {
            NonLinearity_TEPXClustersPerEvent[d][r] = new TGraphErrors();
        }
    }
    
    

    //read the histograms
    TProfile* Prof_TEPXClustersPerEvent[20][20]; //array pu,disk
    for (int pu = 0; pu < pulist.size(); pu++) {
        TFile F(inpath + pulist[pu].c_str() + ".root", "read");
        gROOT->cd();
              
        for (int d = 0; d < disklist.size(); d++) {

                TH2F* H = (TH2F*)F.Get(histoname + disklist[d].c_str());
		Histogram2D[pu][d] = (TH2F*)H->Clone(TString(H->GetName()));
               	TCanvas *c1 = new TCanvas();
            	c1->cd();
      		Histogram2D[pu][d]->Draw("colz");
      		char *hist2Dname = new char[10];
      		Int_t pud = pu * 8 + d +1;
      		sprintf(hist2Dname,"histo2D_%d.gif",pud);
      		cout<<"=========================="<<hist2Dname<<endl;
      		c1->Print(outputpath + hist2Dname);
      		c1->Clear();
            
   
      

		for (int r = 0; r < 5; r++){
                   

	      //draw the 2D Cluster distributions for all PU
              
              Prof_TEPXClustersPerEvent[pu][d] = (TProfile*)H->ProfileX()->Clone(TString(H->GetName()) + "Profile"); //number of cluster vs ring

	     
      
	   }

	}
    }

}
