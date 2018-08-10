#ifndef CIGENPARTICLES_H
#define CIGENPARTICLES_H

//===================================
//CIGenParticles header file 
//Latest Version: Aug 3, 2018 
//MHokinson
//Used to simplify CIEvent and 
//deal with all of the Gen particles
//===================================

//Includes for special types 
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"

class CIGenParticles
{
 public:
  //=================================
  //Constructors
  //=================================
  CIGenParticles() {}
  CIGenParticles(int NbGenMuons, pat::PackedGenParticle p);
  
 private: 
  //=================================
  //Variables for Gen Particles
  //(This ommits the unused variables 
  //from MakeZprimeMC/CIEvent)
  //=================================
  int iCount;
  int id;
  int status;
  float pt;
  float eta;
  float phi;
  int charge;
  float energy;
  float px;
  float py;
  float pz;

  /*//The ones below this are not used 
      MAYBE DELETE LATER 
    std::vector<float> vxGen;
    std::vector<float> vyGen;
    std::vector<float> vzGen;
    std::vector<int> NbOfDaughters;
    std::vector<float> McZmass;
    std::vector<float> McZpt;
    std::vector<float> McZpx;
    std::vector<float> McZpy;
    std::vector<float> McZpz;
    std::vector<float> McZen;*/

  ClassDefNV(CIGenParticles, 1)
};


#endif
