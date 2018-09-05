#ifndef CIMUONVTX_H
#define CIMUONVTX_H 

//=================================
//CIMuonVtx header file 
//MHokinson - Aug 8th 
//This is meant to deal with the muon 
//vertex values from CIEvent, there 
//will be two objects for both the 
//regular vertex and the 30GeV version
//=================================

//Include any special types 
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "RecoVertex/VertexTools/interface/InvariantMassFromVertex.h"
#include "DataFormats/GeometryCommonDetAlgo/interface/Measurement1D.h"
#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"

class CIMuonVtx
{
 public:
  //===================
  //Constructors
  //===================
  CIMuonVtx(){}
  CIMuonVtx(std::vector<reco::TransientTrack> track, reco::TrackRef muTrack,
	    reco::TrackRef muTrack2, int index1, int index2);

  //===================
  //Getters 
  //===================
  //These return the indicies of the two muons in the CIEvent muon collection 
  int lept1()const {return muIndex1;}
  int lept2()const {return muIndex2;}

  float getMass() const {return mass;}
  bool getOppCharge() const {return isOppositeSign;}

 private:
  //===================
  //Helping functions
  //===================
  void fillValues(std::vector<reco::TransientTrack> track, reco::TrackRef & muTrack,
		  reco::TrackRef & muTrack2);

  //==================
  //Values 
  //==================
  float mass;
  float massLept1;
  float massLept2;
  float normChi2;

  bool isOppositeSign;
  int muIndex1;
  int muIndex2;

  ClassDefNV(CIMuonVtx, 1)
};

#endif
