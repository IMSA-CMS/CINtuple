#ifndef CIHLT_H
#define CIHLT_H

//==============================
//CIHLT header file 
//MHokinson - Aug 3rd 
//Handles the HLT values from 
//CIEvent
//==============================

//Include special types 
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "Rtypes.h"

class CIHLTrigger
{
 public:
  //======================
  //Constructor
  //======================
  CIHLTrigger(){}
  CIHLTrigger(int nbTriggers, edm::TriggerResults triggerBits, 
	const edm::TriggerNames names, int i);

 private:
  //=====================
  //Values
  //=====================
  int nb;
  std::string name;
  bool isAccept;
  
  ClassDefNV(CIHLTrigger, 1)
};


#endif
