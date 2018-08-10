#ifndef CIELECTRON_H
#define CIELECTRON_H

//===================================
//CIElectron header file 
//Latest Version: Aug 2, 2018 
//MHokinson
//Used to simplify CIEvent and 
//contain all values pertaining to 
//electrons 
//===================================

//Things to include 
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
#include <cmath>

class CIElectron 
{
 public:
  //================================
  //Constructors
  //================================
  CIElectron() {}
  CIElectron(EcalClusterLazyTools lazyTools_, pat::Electron el,
	     unsigned NbElectrons, double rhoIso,
	     const reco::Vertex& PV);

 private:
  //=================================
  //Private Functions
  //=================================

  //This is going to be called by the contructor so that the constructor 
  //does not have to contain a large block of code 
  void fillValues(EcalClusterLazyTools lazyTools_, pat::Electron el,
		  unsigned NbElectrons, double rhoIso, 
		  const reco::Vertex& PV);

  //==================================
  //Class Variables 
  //==================================
  int rawId;
  int nbElectrons;
  bool isEcalDrivenSeed;
  bool isPassConversionVeto;
  int charge;
  int nbOfMissingHits;
  int nbVtx;
  float Et;
  float EtFromCaloEn;
  float pt;
  float thetaSC;
  float etaSC;
  float phiSC;
  float energySC;
  float preshowerEnergySC;
  float thetaTrack;
  float etaTrack;
  float phiTrack;
  float hadronicOverEm;
  float deltaEtaInSeedCluster;
  float deltaPhiInSeedCluster;
  float deltaEtaInSC;
  float deltaPhiInSC;
  float sigmaIetaIeta;
  float e2x5Max;
  float e1x5;
  float frac51;
  float frac15;
  float e5x5;
  float e3x3;
  float e2x5MaxOver5x5;
  float e1x5Over5x5;
  float sigmaIetaIetaFull5x5;
  float e2x5MaxFull5x5;
  float e1x5Full5x5;
  float e5x5Full5x5;
  float e2x5MaxOver5x5Full5x5;
  float e1x5Over5x5Full5x5;
  float e2x5Right;
  float e2x5Left;
  float e2x5Top;
  float e2x5Bottom;
  float eMax;
  float eRight;
  float eLeft;
  float eTop;
  float eBottom;
  float dxy;
  float dz;
  float rhoIso;
  float fbrem;
  float EoverP;
  float Xposition;
  float Yposition;
  //------------- detector isolation -------------------------
  float EcalPlusHcald1iso;
  float dr03TkSumPt;
  float dr03TkSumPt_corrected;
  float dr03EcalRecHitSumEt;
  float dr03HcalDepth1TowerSumEt;
  float dr03HcalDepth1TowerSumEtBc;
  float hcalDepth1OverEcal;
  float hcalDepth2OverEcal;
  float dr03HcalDepth2TowerSumEt;
  float hcalDepth2TowerSumEtNoVeto;
  float hcalDepth1TowerSumEtNoVeto;
  //------------- PF isolation from pat::ele -------------------------
  float pfSumPhotonEt;
  float pfSumChargedHadronPt;
  float pfSumNeutralHadronEt;
  float pfSumPUPt;
  float pfDeltaBeta;
  float x;
  float y;
  float z;
  float zTrackPositionAtVtx;
  int ieta;
  float phiWidth;
  float etaWidth;
  float nrSatCrys;
  bool  isPassHeepID;
  ClassDefNV(CIElectron, 1)
};

#endif
