//==============================
//CIGenJets Source file 
//MHokinson - Aug 3rd
//This is used to contain all gen
//jet values from CIEvent 
//==============================

//Include the header file 
#include "ZprimeDiLeptons/CIData/interface/CIGenJets.h"

//Include special types 
#include "DataFormats/JetReco/interface/GenJet.h"

CIGenJets::CIGenJets(int nbGenJets, reco::GenJet g):
  iCount(nbGenJets),
  id(g.pdgId()),
  status(g.status()),
  charge(g.charge()),
  pt(g.pt()),
  eta(g.eta()),
  phi(g.phi())
{}
