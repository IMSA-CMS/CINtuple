//=============================
//CIPrimary Vertex header file 
//MHokinson
//Contains all the primary 
//vertex values from CIEvent 
//=============================

//Include the header file 
#include "ZprimeDiLeptons/CIData/interface/CIPrimaryVertex.h"

//Include special types 
#include "DataFormats/VertexReco/interface/Vertex.h"

CIPrimaryVertex::CIPrimaryVertex(int value3_, reco::Vertex v):
  nbPv(value3_),
  nbdof(v.ndof()),
  positionX(v.position().x()),
  positionY(v.position().y()),
  positionZ(v.position().z()),
  positionRho(v.position().rho())
{}
  
