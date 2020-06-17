void Projection(int option){
  
  TCanvas *c1 = new TCanvas();
for (int pu = 0; pu < pulist.size(); pu++) {
    for (int d = 0; d < disklist.size(); d++) {
      for (int r = 0; r < 5; r++){
if (option == 1){


  c1->cd();

  
                if (pu < 4){
            ProjectionY[pu][d][r]->GetXaxis()->SetRangeUser(0, 60);
	    ProjectionY[pu][d][r]->GetYaxis()->SetRangeUser(0, 70000);
	    ProjectionY[pu][d][r]->GetYaxis()->SetTitle("# of events");
	    ProjectionY[pu][d][r]->SetLineColor(r+1);
            ProjectionY[pu][d][r]->Draw("same");
	  
	    auto legend1 = new TLegend(0.7,0.7,0.88,0.88);
	    legend1->AddEntry(ProjectionY[pu][d][0], "Ring 1" ,"l");
	    legend1->AddEntry(ProjectionY[pu][d][1], "Ring 2","l");
	    legend1->AddEntry(ProjectionY[pu][d][2], "Ring 3","l");
	    legend1->AddEntry(ProjectionY[pu][d][3], "Ring 4","l");
	    legend1->AddEntry(ProjectionY[pu][d][4], "Ring 5" ,"l");
	    legend1->SetFillColor(0);
	    legend1->SetLineColor(0);
	    legend1->SetFillColor(0);
	    legend1->Draw("same");
	    char *Projection = new char[12];
            Int_t pro = pu * 8 + d + 1;
	    sprintf(Projection,"Projection_%d.gif", pro);
	    cout<<"=========================="<<Projection<<endl;
	    c1->Print(outputpath1 + "Projection/" + Projection);
            //c1->Clear();
          
	  }
	}
	

	if (option == 2){
	  if( pu < 4){
	    
	    TCanvas *c1 = new TCanvas();
	    c1->cd();
	    ProjectionY[pu][d][r]->GetXaxis()->SetRangeUser(0, 20);
	    ProjectionY[pu][d][r]->GetYaxis()->SetRangeUser(0, 20000);
	    ProjectionY[pu][d][r]->GetYaxis()->SetTitle("# of events");
	    ProjectionY[pu][d][r]->SetLineColor(r+1);
	    ProjectionY[pu][d][r]->Draw("same");
	  
          
          
	  
	    auto legend1 = new TLegend(0.7,0.7,0.88,0.88);
	    legend1->AddEntry(ProjectionY[pu][d][0], "Ring 1" ,"l");
	    legend1->AddEntry(ProjectionY[pu][d][1], "Ring 2" ,"l");
	    legend1->AddEntry(ProjectionY[pu][d][2], "Ring 3" ,"l");
	    legend1->AddEntry(ProjectionY[pu][d][3], "Ring 4" ,"l");
	    legend1->AddEntry(ProjectionY[pu][d][4], "Ring 5" ,"l");
	    
	    legend1->SetFillColor(0);
	    legend1->SetLineColor(0);
	    legend1->SetFillColor(0);
	    legend1->Draw();
	    char *Projection = new char[12];
	    Int_t pro = pu * 8 + d + 1;
	    sprintf(Projection,"Projection2x_pu%d_d%d.gif", pu, d);
	    cout<<"=========================="<<Projection<<endl;
	    c1->Print(outputpath2 + "Projection/" + Projection);
	    c1->Clear();
          }
        }

        if(option == 3){
          TCanvas *c1 = new TCanvas();
	  c1->cd();
	  ProjectionY[pu][d][r]->GetXaxis()->SetRangeUser(0, 20);
	  ProjectionY[pu][d][r]->GetYaxis()->SetRangeUser(0, 2000);
          ProjectionY[pu][d][r]->GetYaxis()->SetTitle("# of events");
	  ProjectionY[pu][d][r]->SetLineColor(r+1);
	  ProjectionY[pu][d][r]->Draw("same");
	  

          auto legend1 = new TLegend(0.7,0.7,0.88,0.88);
	  legend1->AddEntry(ProjectionY[pu][d][1], "Ring 2" ,"l");
	  legend1->AddEntry(ProjectionY[pu][d][2], "Ring 3" ,"l");
	  legend1->AddEntry(ProjectionY[pu][d][3], "Ring 4" ,"l");
	  legend1->AddEntry(ProjectionY[pu][d][4], "Ring 5" ,"l");
	  
	  legend1->SetFillColor(0);
	  legend1->SetLineColor(0);
	  legend1->SetFillColor(0);
	  legend1->Draw();
	  char *Projection = new char[12];
	  Int_t pro = pu * 8 + d + 1;
	  sprintf(Projection,"Projection3x_pu%d_d%d.gif", pu, d);
	  cout<<"=========================="<<Projection<<endl;
	  c1->Print(outputpath3 + "Projection/" + Projection);
	  c1->Clear();


	}

      }
    }
  }
}
