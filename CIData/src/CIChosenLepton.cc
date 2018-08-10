//=========================
//CIChosenLepton source file 
//MHokinson - Aug 9th 
//This will contain the data
//for the chosen leptons
//(There will be two of these
//in CIEvent)
//=========================

//Include the header file 
#include "ZprimeDiLeptons/CIData/interface/CIChosenLepton.h"

CIChosenLepton::CIChosenLepton(double pPt, double pPhi, double pEta,
			       double pCharge, bool pIsMuon):
  pt(pPt),
  phi(pPhi),
  eta(pEta),
  charge(pCharge),
  isMuon(pIsMuon)
{}
