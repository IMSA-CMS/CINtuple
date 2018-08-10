#ifndef CIBTAGS_H
#define CIBTAGS_H

//==============================
//CIBtags Header file 
//MHokinson - Aug 3 
//Handles all of the Jet-Tag
//values in CIEvent 
//==============================

//Include any special Types 
#include "DataFormats/PatCandidates/interface/Jet.h"

class CIBtags 
{
 public:
  //===========================
  //Constructors
  //===========================
  CIBtags(){}
  CIBtags(int bDiscriminatorsNumber, pat::Jet jet, 
	     const std::string & bDiscr, int flavor);

 private:
  //===========================
  //Btagging values
  //===========================
  int   nb_bDiscriminators;
  int   flavor;
  float pfCSVv2IVF_discriminator;
  float pt;
  float eta;
  float phi;

  ClassDefNV(CIBtags, 1)
};



#endif
