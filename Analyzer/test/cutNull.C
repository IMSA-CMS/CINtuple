

void cutNull()
{
  TFile* file = TFile::Open("mattIsADummy.root");
  TTree* tree = (TTree*)file->Get("tree");
  //  tree->Draw("Test.calcValues.cosThetaCS", "Test.calcValues.cosThetaCS != -2");
  tree->Draw("Test.calcValues.cosThetaCS>>hqq(20)", "Test.calcValues.cosThetaCS != -2");
}
