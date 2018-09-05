//==============================
//CIHLTObj source file 
//MHokinson - Aug 3rd 
//Handles the HLTObj values from 
//CIEvent
//==============================

//Include the Header File 
#include "CINtuple/CIData/interface/CIHLTObj.h"

//include special types 
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"

CIHLTObj::CIHLTObj(int nbTriggerObj, pat::TriggerObjectStandAlone src,
		   std::vector<std::string> const &  pathnames, int j):
  nbObj(nbTriggerObj),
  pt(src.pt()),
  eta(src.eta()),
  phi(src.phi()),
  collection(pathnames[j])
{}
