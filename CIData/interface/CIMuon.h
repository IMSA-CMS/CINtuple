#ifndef CIMUON_H 
#define CIMUON_H 

//==============================
//CIMuon header file 
//MHokinson - Aug 9
//CI muon was created to handle 
//the muon values in CIEvent
//==============================

//Include any special types 
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

class CIMuon 
{
 public:
  //=====================
  //Constructors
  //=====================
  CIMuon(){}
  CIMuon(const reco::Vertex & PV, const pat::Muon & mu, int NbMuons);

  //=======================
  //Getters 
  //========================

  float getEtaTune() const {return etaTunePMuonBestTrack;}
  float getPhiTune() const {return phiTunePMuonBestTrack;}
  float getPtTune() const {return ptTunePMuonBestTrack;}
  float getCharge() const {return charge;}

  //=====================
  //Static Functions
  //=====================
  static bool passesCut(const pat::Muon & mu, const reco::Vertex & vertex,
			 double ptCut);

 private:
  //====================
  //Functions for constructor
  //====================
  void fillValues(const reco::Vertex & PV, const pat::Muon & mu, int NbMuons);

  //====================
  //Values 
  //====================
  int nbMuon;
  bool passOldMatchedStationsCut;
  bool passNewMatchedStationsCut;
  bool isTightMuon;
  bool isLooseMuon;
  bool isGlobalMuon;
  bool isHighPtMuon;
  //bool isMuonsCleaned;
  bool isPF;
  bool isTrackerMuon;
  bool canPassCuts;

  float en;
  float pt;
  float eta;
  float phi;
  float et;
  float charge;
  float normalizedChi2;
  float trackiso;
  int numberOfMatchedStations;
  int numberOfValidPixelHits;
  int numberOftrackerLayersWithMeasurement;
  float pfSumChargedHadronPt;
  float pfSumNeutralHadronEt;
  float PFSumPhotonEt;
  float pfSumPUPt;
  float calEnergy;
  int numberOfValidMuonHits;
  float emIso;
  float hadIso;
  float VTXnormalizedChi2;
  float vtxTotalChi2;
  int nbofpv;
  float pxTunePMuonBestTrack;
  float pyTunePMuonBestTrack;
  float pzTunePMuonBestTrack;
  float pTunePMuonBestTrack;
  float etaTunePMuonBestTrack;
  float ptTunePMuonBestTrack;
  float phiTunePMuonBestTrack;
  float thetaTunePMuonBestTrack;
  float chargeTunePMuonBestTrack;
  float dPToverPTTunePMuonBestTrack;
  float absdxyTunePMuonBestTrack;
  float absdzTunePMuonBestTrack;
  float ptInnerTrack;
  float pxInnerTrack;
  float pyInnerTrack;
  float pzInnerTrack;
  float pInnerTrack;
  float etaInnerTrack;
  float phiInnerTrack;
  float thetaInnerTrack;
  float chargeInnerTrack;
  float dPToverPTInnerTrack;
  float absdxyInnerTrack;
  float absdzInnerTrack;
  float absdxy;
  float absdz;
  float patDeltaBeta;

  int stationMask;
  int numberOfMatchedRPCLayers;

  ClassDefNV(CIMuon, 1)
};

#endif
