#ifndef CICHOSENLEPTON_H
#define CICHOSENLEPTON_H

//=========================
//CIChosenLepton header file 
//MHokinson - Aug 9th 
//This will contain the data
//for the chosen leptons
//(There will be two of these
//in CIEvent)
//=========================
#include "CINtuple/CIData/interface/CIMuon.h"
#include "CINtuple/CIData/interface/CIElectron.h"

class CIChosenLepton
{
 public:
  //===============
  //Constructors
  //===============
  CIChosenLepton() {}

  CIChosenLepton(const CIElectron & el);

  CIChosenLepton(const CIMuon & mu);

 private:
  //===============
  //Class values
  //===============
  double pt;
  double phi;
  double eta;
  double charge;
  bool isMuon;
  
  ClassDefNV(CIChosenLepton, 1)
};

#endif
