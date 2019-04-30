

void cutNull()
{
  //TFile* file = TFile::Open("mattIsADummy.root");
  //TTree* tree = (TTree*)file->Get("tree");
  //  tree->Draw("Test.calcValues.cosThetaCS", "Test.calcValues.cosThetaCS != -2");
  //tree->Draw("Test.calcValues.cosThetaCS>>hqq(25)", "Test.calcValues.cosThetaCS != -2");

  bool isMuon = false;
  bool isLog = true;
  bool reco = false;
  bool genSim = true;


  TChain * chain = new TChain("tree");
  
  if(isMuon){
      chain->Add("/eos/uscms/store/user/hokinson/MC17_CITo2Mu_M300to800_CP5_Lam16TeVConLRPythia8_v1/CI_M300_L16TeV_LR_Con_NTuple_20190222_101315/190222_161339/0000/*.root");
  }
  else{
  chain->Add("/eos/uscms/store/user/hokinson/MC17_CITo2E_M800to1300_CP5_Lam16TeVConLRPythia8_v1/CITo2E_M800_L16TeV_LR_Con_NTuple_20190306_103028/190306_163050/0000/*.root");
  }
  
  if(isLog){
  TCanvas* c1 = new TCanvas();
  c1->SetLogy();
  }
  
  if(reco){
  chain->Draw("Test.calcValues.cosThetaCS>>bin(50)", "Test.calcValues.cosThetaCS != -2");
  }
  else if(genSim){
  chain->Draw("-Test.calcValues.cosThetaGenSim>>bin(50)");
  }
  else{
  chain->Draw("Test.calcValues.cosThetaCS  + Test.calcValues.cosThetaGenSim>>bin(100,-.5,.5)", "Test.calcValues.cosThetaCS != -2");
  }

  TH1* hist = dynamic_cast<TH1*>(gDirectory->Get("bin"));
  if(reco){
    hist->GetXaxis()->SetTitle("cosTheta Reco");
  }
  else if(genSim){
    hist->GetXaxis()->SetTitle("cosTheta GenSim");
  }
  else{
   hist->GetXaxis()->SetTitle("cosTheta Reco - GenSim");
  }
  hist->GetYaxis()->SetTitle("nEvents");
}
