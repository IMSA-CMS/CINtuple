#ifndef CIJET_H
#define CIJET_H 

//============================
//CIJet Header file 
//MHokinson - Aug 3
//Contains all the jet values 
//from CIEvent 
//============================

//Include special types 
#include "DataFormats/PatCandidates/interface/Jet.h"

class CIJet 
{
 public:
  //==========================
  //Constructors
  //==========================
  CIJet(){}
  CIJet(int sum, int in, int jetNumber, const pat::Jet & j);

 private:
  int   jetNb;
  float charge;
  float et;
  float pt;
  float eta;
  float phi;
  float en;
  float theta;
  float beta;
  float pileup_mva_disc;

  ClassDefNV(CIJet, 1)
};

#endif
