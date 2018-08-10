#ifndef CIGENJETS_H 
#define CIGENJETS_H 

//==============================
//CIGenJets Header file 
//MHokinson - Aug 3rd
//This is used to contain all gen
//jet values from CIEvent 
//==============================

//Include any special classes 
#include "DataFormats/JetReco/interface/GenJet.h"

class CIGenJets 
{
 public:
  //============================
  //Constructors
  //============================
  CIGenJets() {}
  CIGenJets(int nbGenJets, reco::GenJet g);

 private: 
  //============================
  //Gen Jet Values 
  //============================
  int iCount;
  int id;
  int status;
  int charge;
  float pt;
  float eta;
  float phi;

  ClassDefNV(CIGenJets, 1)

};

#endif
