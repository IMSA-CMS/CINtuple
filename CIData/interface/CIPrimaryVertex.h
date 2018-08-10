#ifndef CIPRIMARYVERTEX_H
#define CIPRIMARYVERTEX_H

//=============================
//CIPrimary Vertex header file 
//MHokinson
//Contains all the primary 
//vertex values from CIEvent 
//=============================

//Includes for any special types 
#include "DataFormats/VertexReco/interface/Vertex.h"

class CIPrimaryVertex 
{
 public:
  //===========================
  //Constructors 
  //===========================
  CIPrimaryVertex() {}
  CIPrimaryVertex(int value3_, reco::Vertex v);

 private:
  //===========================
  //Vertex Values 
  //===========================
  int  nbPv;
  int  nbdof;
  float positionX;
  float positionY;
  float positionZ;
  float positionRho;

  ClassDefNV(CIPrimaryVertex, 1)
};

#endif
