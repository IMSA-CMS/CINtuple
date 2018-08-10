#ifndef CIPHOTON_H
#define CIPHOTON_H

//===================================
//CIPhoton header file 
//Latest Version: Aug 3, 2018 
//MHokinson
//Used to simplify CIEvent and contain 
//the photon values 
//===================================

//Includes for special types 
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

class CIPhoton
{
 public:
  //=================================
  //Constructors
  //=================================
  CIPhoton() {}
  CIPhoton(const pat::PackedCandidate & pf);

 private:
  //================================
  //Values
  //================================
  float pt;
  float eta;
  float phi;
  float theta;
  ClassDefNV(CIPhoton, 1)
};

#endif
