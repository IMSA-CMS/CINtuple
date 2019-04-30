

void cutDiffCharge()
{
  TFile* file = TFile::Open("mattIsADummy.root");
  TTree* tree = (TTree*)file->Get("tree");
  tree->Draw("Test.calcValues.cosThetaCS", "Test.calcValues.cosThetaCS == Test.calcValues.isSameCharge");
}
