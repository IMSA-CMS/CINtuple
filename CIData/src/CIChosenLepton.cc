//=========================
//CIChosenLepton source file 
//MHokinson - Aug 9th 
//This will contain the data
//for the chosen leptons
//(There will be two of these
//in CIEvent)
//=========================

//Include the header file 
#include "CINtuple/CIData/interface/CIChosenLepton.h"

CIChosenLepton::CIChosenLepton(const CIElectron & el):
  pt(el.getPt()),
  phi(el.getPhi()),
  eta(el.getEta()),
  charge(el.getCharge()),
  isMuon(false)
{}

CIChosenLepton::CIChosenLepton(const CIMuon & mu):
  pt(mu.getPtTune()),
  phi(mu.getPhiTune()),
  eta(mu.getEtaTune()),
  charge(mu.getCharge()),
  isMuon(true)
{}
