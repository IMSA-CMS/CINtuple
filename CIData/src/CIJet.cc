//============================
//CIJet Source file 
//MHokinson - Aug 3
//Contains all the jet values 
//from CIEvent 
//============================

//Include the header file 
#include "CINtuple/CIData/interface/CIJet.h"

//Include any special types 
#include "DataFormats/PatCandidates/interface/Jet.h"

CIJet::CIJet(int sum, int in, int jetNumber, const pat::Jet & j):
  jetNb(jetNumber),
  charge(j.charge()),
  et(j.et()),
  pt(j.pt()),
  eta(j.eta()),
  phi(j.phi()),
  en(j.muonEnergy()),
  theta(j.theta()),
  beta(sum ? in/sum : 0),
  pileup_mva_disc(j.userFloat("pileupJetId:fullDiscriminant"))
{}
