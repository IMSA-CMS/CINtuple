//=================================
//CIMuonVtx header file 
//MHokinson - Aug 8th 
//This is meant to deal with the muon 
//vertex values from CIEvent, there 
//will be two objects for both the 
//regular vertex and the 30GeV version
//=================================

//Include the header file 
#include "CINtuple/CIData/interface/CIMuonVtx.h"

//Include any special types 
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "RecoVertex/VertexTools/interface/InvariantMassFromVertex.h"
#include "DataFormats/GeometryCommonDetAlgo/interface/Measurement1D.h"
#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"

CIMuonVtx::CIMuonVtx(std::vector<reco::TransientTrack> track, reco::TrackRef
		     muTrack, reco::TrackRef muTrack2, int index1, int index2):
  muIndex1(index1),
  muIndex2(index2)
{
  fillValues(track, muTrack, muTrack2);
}

void CIMuonVtx::fillValues(std::vector<reco::TransientTrack> track, reco::TrackRef&
		      muTrack, reco::TrackRef& muTrack2)
{
  KalmanVertexFitter kvf(true); // false means no smoothing which means no track re-fit
  CachingVertex<5> vtx1 = kvf.vertex(track);
  float vtxNormChi1 = vtx1.totalChiSquared()/vtx1.degreesOfFreedom();

  InvariantMassFromVertex imfv1;

  static const double muon_mass1 = 0.1056583;
  Measurement1D mass1 = imfv1.invariantMass(vtx1, muon_mass1);

  float DiMass1 = mass1.value();

  mass = DiMass1;
  normChi2 = vtxNormChi1;
  massLept1 = muTrack->pt();
  massLept2 = muTrack2->pt();

  isOppositeSign = !(muTrack->charge() == muTrack2->charge());
}
