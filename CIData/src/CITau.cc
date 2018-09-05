//==============================
//CITau header file 
//MHokinson - Aug 3rd 
//This will handle of of the Tau 
//Data from CIEvent 
//==============================

//Include the Header file 
#include "CINtuple/CIData/interface/CITau.h"

//Include special types 
#include "DataFormats/PatCandidates/interface/Tau.h"

CITau::CITau(int tausNumber, const pat::Tau & tau):
  nb_taus(tausNumber),
  pt(tau.pt()),
  eta(tau.eta()),
  phi(tau.phi()),
  id(tau.pdgId()),
  looseCombinedIsolationDeltaBetaCorr3Hits(tau.tauID("byLooseCombinedIsolationDeltaBetaCorr3Hits"))
{}
