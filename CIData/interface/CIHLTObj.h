#ifndef CIHLTOBJ_H
#define CIHLTOBJ_H

//==============================
//CIHLTObj header file 
//MHokinson - Aug 3rd 
//Handles the HLTObj values from 
//CIEvent
//==============================

//include special types 
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"

class CIHLTObj 
{
 public:
  //=================================
  //Constructors
  //=================================
  CIHLTObj(){}
  CIHLTObj(int nbTriggerObj, pat::TriggerObjectStandAlone src, 
	   std::vector<std::string> const & pathnames, int j);

 private:
  //=================================
  //Class Variables 
  //=================================
  int    nbObj;
  float  pt;
  float  eta;
  float  phi;
  std::string collection;

  ClassDefNV(CIHLTObj, 1)
};

#endif
