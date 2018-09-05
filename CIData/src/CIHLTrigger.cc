//==============================
//CIHLT Source file 
//MHokinson - Aug 3rd 
//Handles the HLT values from 
//CIEvent
//==============================

//Include the header file 
#include "CINtuple/CIData/interface/CIHLTrigger.h"

//include special types 
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"

CIHLTrigger::CIHLTrigger(int nbTriggers, edm::TriggerResults triggerBits,
	     const edm::TriggerNames names, int i):
  nb(nbTriggers),
  name(names.triggerName(i)),
  isAccept(triggerBits.accept(i))
{}
