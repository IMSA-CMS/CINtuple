#ifndef CITAU_H
#define CITAU_H

//==============================
//CITau header file 
//MHokinson - Aug 3rd 
//This will handle of of the Tau 
//Data from CIEvent 
//==============================

//Include special types 
#include "DataFormats/PatCandidates/interface/Tau.h" 

class CITau 
{
 public: 
  //============================
  //Constructors 
  //============================
  CITau(){}
  CITau(int tausNumber, const pat::Tau & tau);

 private: 
  int   nb_taus;
  float pt;
  float eta;
  float phi;
  int   id;
  float looseCombinedIsolationDeltaBetaCorr3Hits;

  ClassDefNV(CITau, 1)
};

#endif 
