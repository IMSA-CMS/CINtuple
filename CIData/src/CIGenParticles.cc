//===================================
//CIGenParticles source file 
//Latest Version: Aug 3, 2018 
//MHokinson
//Used to simplify CIEvent and 
//deal with all of the Gen particles
//===================================

//Include for the header file 
#include "CINtuple/CIData/interface/CIGenParticles.h"

//Includes for special types 
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"

CIGenParticles::CIGenParticles(int NbGenMuons, pat::PackedGenParticle p):
  iCount(NbGenMuons),
  id(p.pdgId()),
  status(p.status()),
  pt(p.pt()),
  eta(p.eta()),
  phi(p.phi()),
  charge(p.charge()),
  energy(p.energy()),
  px(p.px()),				
  py(p.py()),
  pz(p.pz())
{}
