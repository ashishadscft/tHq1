void linearity1(){
  
  TString inpath="/home/ashish/TEPX/samples_17Feb2020/";
  TString histoname="BRIL_IT_Analysis/TEPX/Clusters/Number of clusters for Disk ";

  //std::vector<std::string> pulist={"0p5","1","1p5","2","10","50","100","140","200"};
  //std::map<std::string,int> pumap={{"0p5",0.5},{"1",1},{"1p5",1.5},{"2",2},{"10",10},{"50",50},{"100",100},{"140",140},{"200",200}};

  std::vector<std::string> pulist={"2023D42noPU","2023D42PU0p5","2023D42PU1","2023D42PU1p5","2023D42PU2","2023D42PU10","2023D42PU30","2023D42PU50","2023D42PU100","2023D42PU140","2023D42PU200"};
  std::map<std::string,float> pumap={{"2023D42noPU",0},{"2023D42PU0p5",0.5},{"2023D42PU1",1},{"2023D42PU1p5",1.5},{"2023D42PU2",2},{"2023D42PU10",10},{"2023D42PU30",30},{"2023D42PU50",50},{"2023D42PU100",100},{"2023D42PU140",140},{"2023D42PU200",200}};

  std::vector<std::string> disklist={"-4","-3","-2","-1","1","2","3","4"};

  ///create the profiles to be filled below.
  TGraphErrors * TEPXClustersPerEvent[20][4];//number of clusters vs pu
  TGraphErrors * TEPXClustersPerEvent1[20][4];
  for(int d=0; d<disklist.size(); d++) 
    for(int r=0 ; r<5; r++)
      TEPXClustersPerEvent[d][r] = new TGraphErrors();



  ///Non-linearity graphs
  TGraphErrors * NonLinearity_TEPXClustersPerEvent[20][4];//number of clusters vs pu
  for(int d=0; d<disklist.size(); d++){
    for(int r=0 ; r<5; r++){
      NonLinearity_TEPXClustersPerEvent[d][r] = new TGraphErrors();
    }
  }


  ///read the histograms
  TProfile * Prof_TEPXClustersPerEvent[20][20];//array pu,disk
  TProfile * Prof_TEPXClustersPerEvent1[20][20];
  for(int pu=0;pu<pulist.size();pu++){
    TFile F(inpath+pulist[pu]+".root","read");  
    gROOT->cd();

    for(int d=0;d<disklist.size();d++){
      TH2F* H=(TH2F*)F.Get(histoname+disklist[d]);
      Prof_TEPXClustersPerEvent[pu][d] = (TProfile*) H->ProfileX()->Clone(TString(H->GetName())+"Profile");//number of cluster vs ring
      
 
      
      
      for(int r=0;r<5;r++){
	TEPXClustersPerEvent[d][r]->SetPoint(pu, pumap[pulist[pu]], Prof_TEPXClustersPerEvent[pu][d]->GetBinContent(r+1));
	TEPXClustersPerEvent[d][r]->SetPointError(pu, 0, Prof_TEPXClustersPerEvent[pu][d]->GetBinError(r+1));
        
        //cout<<"pu is "<<pu<<endl;
         
        cout<<"First Bin Content of Histogram H-X is "<<H->ProfileX()->GetBinContent(1)<<endl;
        cout<<"First Bin Error of Histogram H-X is "<<H->ProfileX()->GetBinError(1)<<endl;
        cout<<"Second Bin Content of Histogram H-X is "<<H->ProfileX()->GetBinContent(2)<<endl;
        cout<<"Second Bin Error of Histogram H-X is "<<H->ProfileX()->GetBinError(2)<<endl;
        cout<<"Third Bin Content of Histogram H-X is "<<H->ProfileX()->GetBinContent(3)<<endl;
        cout<<"Third Bin Error of Histogram H-X is "<<H->ProfileX()->GetBinError(3)<<endl;
        cout<<"Fourth Bin Content of Histogram H-X is "<<H->ProfileX()->GetBinContent(4)<<endl;
        cout<<"Fourth Bin Error of Histogram H-X is "<<H->ProfileX()->GetBinError(4)<<endl;
        cout<<"Fifth Bin Content of Histogram H-X is "<<H->ProfileX()->GetBinContent(5)<<endl;
        cout<<"Fifth Bin Error of Histogram H-X is "<<H->ProfileX()->GetBinError(5)<<endl;
        

        
        
       


	//NonLinearity_TEPXClustersPerEvent[d][r]->SetPoint(pu, pumap[pulist[pu]], Prof_TEPXClustersPerEvent[pu][d]->GetBinContent(r+1));
      }

    }
  }
  

  //gROOT->SetStyle("Style");
 //std::cout<<"done style"<<std::endl;

  gStyle->SetCanvasColor     (0);
  gStyle->SetCanvasBorderSize(10);
  gStyle->SetCanvasBorderMode(0);
  // gStyle->SetCanvasDefH      (700);
  // gStyle->SetCanvasDefW      (700);
  // gStyle->SetCanvasDefX      (100);
  // gStyle->SetCanvasDefY      (100);

  // color palette for 2D temperature plots
  gStyle->SetPalette(1,0);
  
  // Pads
  gStyle->SetPadColor       (0);
  gStyle->SetPadBorderSize  (10);
  gStyle->SetPadBorderMode  (0);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadTopMargin   (0.08);
  gStyle->SetPadLeftMargin  (0.15);
  gStyle->SetPadRightMargin (0.05);
  gStyle->SetPadGridX       (0);
  gStyle->SetPadGridY       (0);
  gStyle->SetPadTickX       (1);
  gStyle->SetPadTickY       (1);

  // Frames
  gStyle->SetLineWidth(3);
  gStyle->SetFrameFillStyle ( 0);
  gStyle->SetFrameFillColor ( 0);
  gStyle->SetFrameLineColor ( 1);
  gStyle->SetFrameLineStyle( 0);
  gStyle->SetFrameLineWidth ( 2);
  gStyle->SetFrameBorderSize(10);
  gStyle->SetFrameBorderMode( 0);

  ////// Histograms
  gStyle->SetHistFillColor(0);
  gStyle->SetHistFillStyle(0);
  gStyle->SetHistLineColor(1);
  gStyle->SetHistLineStyle(0);
  gStyle->SetHistLineWidth(1);
  gStyle->SetNdivisions(6);

  // Functions
  gStyle->SetFuncColor(1);
  gStyle->SetFuncStyle(0);
  gStyle->SetFuncWidth(2);

  // Various
  gStyle->SetMarkerStyle(8);
  gStyle->SetMarkerColor(kBlack);
  gStyle->SetMarkerSize (0.3);

  gStyle->SetTitleBorderSize(0);
  gStyle->SetTitleFillColor (0);
  gStyle->SetTitleX         (0.2);

  gStyle->SetTitleSize  (0.055,"X");
  gStyle->SetTitleOffset(1.400,"X");
  gStyle->SetLabelOffset(0.005,"X");
  gStyle->SetLabelSize  (0.050,"X");
  gStyle->SetLabelFont  (42   ,"X");

  gStyle->SetStripDecimals(kFALSE);
  gStyle->SetLineStyleString(11,"20 10");

  gStyle->SetTitleSize  (0.055,"Y");
  gStyle->SetTitleOffset(1.400,"Y");
  gStyle->SetLabelOffset(0.010,"Y");
  gStyle->SetLabelSize  (0.050,"Y");
  gStyle->SetLabelFont  (42   ,"Y");

  gStyle->SetTextSize   (0.055);
  gStyle->SetTextFont   (42);

  gStyle->SetStatFont   (42);
  gStyle->SetTitleFont  (42);
  gStyle->SetTitleFont  (42,"X");
  gStyle->SetTitleFont  (42,"Y");

  gStyle->SetOptStat    (0);

  ///Make the graphs
  TLatex label; 
  label.SetTextSize(0.2);
  TF1 * FitTEPXClustersPerEvent[20][4];
 
//  C.Divide(5,8);
  for(long d=0;d<disklist.size();d++)
    for(long r=0;r<5;r++){

      //fix the pads
    //  TVirtualPad* pad = C.cd(d*5+r+1);
    //  TVirtualPad* pad = C.cd();
   //   pad->SetBottomMargin(0.3);
   //   pad->SetLeftMargin(0.3);
       Int_t l = d*5+r+1;
       TCanvas C("C");
       C.cd();
 
      //fit
      FitTEPXClustersPerEvent[d][r]=new TF1(TString("Fit_")+d+"_"+r,"[0]+[1]*x",0,2);
      FitTEPXClustersPerEvent[d][r]->SetLineColor(4);
      TEPXClustersPerEvent[d][r]->Fit(FitTEPXClustersPerEvent[d][r],"","",0,2);

      cout<<"Intercept is "<<FitTEPXClustersPerEvent[d][r]->GetParameter(0)<<endl;
       cout<<"Slope is "<<FitTEPXClustersPerEvent[d][r]->GetParameter(1)<<endl;
      cout<<"Chisquare value is "<<FitTEPXClustersPerEvent[d][r]->GetChisquare()<<endl;
      cout<<"Number of degrees of freedom are "<<FitTEPXClustersPerEvent[d][r]->GetNDF()<<endl;
      cout<<"Intercept error is "<<FitTEPXClustersPerEvent[d][r]->GetParError(0)<<endl;
      cout<<"Slope error is "<<FitTEPXClustersPerEvent[d][r]->GetParError(1)<<endl;
      
    
      
      
      //draw
      TEPXClustersPerEvent[d][r]->GetYaxis()->SetNdivisions(12);
      TEPXClustersPerEvent[d][r]->GetYaxis()->SetLabelSize(0.05);
      //TEPXClustersPerEvent[d][r]->GetYaxis()->SetMaxDigits();
      TEPXClustersPerEvent[d][r]->GetYaxis()->SetTitle("Mean Number of Clusters");
      TEPXClustersPerEvent[d][r]->GetYaxis()->SetRangeUser(0,30);
      TEPXClustersPerEvent[d][r]->GetXaxis()->SetNdivisions(12);
      TEPXClustersPerEvent[d][r]->GetXaxis()->SetLabelSize(0.05);
      TEPXClustersPerEvent[d][r]->GetXaxis()->SetRangeUser(0,4);
      TEPXClustersPerEvent[d][r]->GetXaxis()->SetTitle("Pileup");
      TEPXClustersPerEvent[d][r]->SetMarkerStyle(21);
      TEPXClustersPerEvent[d][r]->SetMarkerSize(1);
      TEPXClustersPerEvent[d][r]->SetMarkerColor(2);
      gStyle->SetOptFit(1111);
      gPad->SetGrid(1,1);
      TEPXClustersPerEvent[d][r]->Draw("ape");
      FitTEPXClustersPerEvent[d][r]->Draw("lsame");
      label.DrawLatexNDC(0.35,0.3,TString("D=")+(long)(d<=3?d-4:d+1-4)+",  R="+(long)(r+1));
      char *histname = new char[10];
      sprintf(histname,"histo%d_linearity.pdf",l);
      cout<<"=========================="<<histname<<endl;
      C.Print(histname);
      C.Clear();
    }

      
//  C.Print("/home/valyrian/HepSoft/ashish/linearity.gif");

for(int d=0; d<disklist.size(); d++){
    for(int r=0 ; r<5; r++){
      for(int pu=0;pu<pulist.size();pu++){
    
  	NonLinearity_TEPXClustersPerEvent[d][r]->SetPoint(pu, pumap[pulist[pu]], 
							  (Prof_TEPXClustersPerEvent[pu][d]->GetBinContent(r+1) - FitTEPXClustersPerEvent[d][r]->Eval(pumap[pulist[pu]]))/FitTEPXClustersPerEvent[d][r]->Eval(pumap[pulist[pu]]));

NonLinearity_TEPXClustersPerEvent[d][r]->SetPointError(pu,0, 
							  (Prof_TEPXClustersPerEvent[pu][d]->GetBinError(r+1))/FitTEPXClustersPerEvent[d][r]->Eval(pumap[pulist[pu]]));

        cout<<"pu is "<<pu<<endl;
        cout<<"PU list name is "<<pulist[pu]<<endl;
        cout<<"First Bin Content is "<<Prof_TEPXClustersPerEvent[pu][d]->GetBinContent(1)<<endl;
        cout<<"Second Bin Content is "<<Prof_TEPXClustersPerEvent[pu][d]->GetBinContent(2)<<endl;
        cout<<"Third Bin Content is "<<Prof_TEPXClustersPerEvent[pu][d]->GetBinContent(3)<<endl;
        cout<<"Fourth Bin Content is "<<Prof_TEPXClustersPerEvent[pu][d]->GetBinContent(4)<<endl;
        cout<<"Fifth Bin Content is "<<Prof_TEPXClustersPerEvent[pu][d]->GetBinContent(5)<<endl;
        
        
        

      } 
    }
  }



 // C.Clear();
//  C.Divide(4,8);
  for(long d=0;d<disklist.size();d++)
    for(long r=0;r<5;r++){

      //fix the pads
   //   TVirtualPad* pad = C.cd(d*4+r+1);
   //   pad->SetBottomMargin(0.3);
    //  pad->SetLeftMargin(0.3);
      Int_t l = d*5+r+1;
      TCanvas C2("C2");
      C2.cd();
      //draw

      NonLinearity_TEPXClustersPerEvent[d][r]->GetYaxis()->SetNdivisions(10);
      NonLinearity_TEPXClustersPerEvent[d][r]->GetYaxis()->SetLabelSize(0.04);
      NonLinearity_TEPXClustersPerEvent[d][r]->GetYaxis()->SetTitle("Residual   (Data-Fit)/Fit");
      //NonLinearity_TEPXClustersPerEvent[d][r]->GetYaxis()->SetMaxDigits(4);
      //NonLinearity_TEPXClustersPerEvent[d][r]->GetYaxis()->SetRangeUser(0,1500);
      NonLinearity_TEPXClustersPerEvent[d][r]->GetYaxis()->SetRangeUser(-0.015,0.015);
      NonLinearity_TEPXClustersPerEvent[d][r]->GetXaxis()->SetNdivisions(12);
      NonLinearity_TEPXClustersPerEvent[d][r]->GetXaxis()->SetLabelSize(0.04);
      NonLinearity_TEPXClustersPerEvent[d][r]->GetXaxis()->SetRangeUser(0,2);
      NonLinearity_TEPXClustersPerEvent[d][r]->GetXaxis()->SetTitle("Pileup");
      NonLinearity_TEPXClustersPerEvent[d][r]->SetMarkerStyle(21);
      NonLinearity_TEPXClustersPerEvent[d][r]->SetMarkerColor(2);
      NonLinearity_TEPXClustersPerEvent[d][r]->SetMarkerSize(1); 
      TLine *line = new TLine(0,0,2,0);
      line->SetLineColor(kBlack);

      gPad->SetGrid(1,1);
      NonLinearity_TEPXClustersPerEvent[d][r]->Draw("ape");
      line->Draw("same");
      label.DrawLatexNDC(0.23,0.8,TString("D=")+(long)(d<=3?d-4:d+1-4)+",  R="+(long)(r+1));
      char *histname = new char[10];
      sprintf(histname,"histo%d_residual.pdf",l);
      cout<<"=========================="<<histname<<endl;
      C2.Print(histname);
      C2.Clear();

}

// C.Print("/home/valyrian/HepSoft/ashish/linearity_residual.gif");

}
