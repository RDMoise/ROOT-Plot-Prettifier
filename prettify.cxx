void prettify(TString fname, TString histname, TString xtitle, TString ytitle, bool normalise = 1, double yoffset = .7, TString opt = "colz"){
	TRandom *rng = new TRandom();
	TCanvas *c =  new TCanvas(Form("c%d",rng->Uniform()),"c",800,600);
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);
	TGaxis::SetMaxDigits(4);
	c->SetLogz();
	TFile *file = TFile::Open(fname);
	TH1D *h = (TH1D*)file->Get(histname);
	h->SetTitle("");
	cout<<h<<endl;
	h->Draw(opt);
	if(normalise){
		h->Scale(1./h->GetEntries());
	}
	TAxis *ax = h->GetXaxis();
	TAxis *ay = h->GetYaxis();
	ax->SetTitle(xtitle);
	ay->SetTitle(ytitle);
	ax->SetTitleSize(.05);
	ay->SetTitleSize(.05);
	ax->SetLabelSize(.045);
	ay->SetLabelSize(.045);
	ay->SetTitleOffset(yoffset);
	
}
/*
ax->SetBinLabel(1,"#splitline{Second}{minimum}");
	ax->SetBinLabel(2,"D < 5");
	ax->SetBinLabel(3,"#splitline{Incorrect}{matches}");
	ax->SetBinLabel(4,"#splitline{Smallest}{discriminant}");
	*/