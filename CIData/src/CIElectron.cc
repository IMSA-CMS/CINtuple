//===================================
//CIElectron source file 
//Latest Version: Aug 2, 2018 
//MHokinson
//Used to simplify CIEvent and 
//contain all values pertaining to 
//electrons 
//===================================

//Include the header file 
#include "ZprimeDiLeptons/CIData/interface/CIElectron.h"

//Things to include for special types used 
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
#include <cmath>

CIElectron::CIElectron(EcalClusterLazyTools lazyTools_, pat::Electron el,
		       unsigned NbElectrons, double rhoIso,
		       const reco::Vertex& PV)
{
  fillValues(lazyTools_, el, NbElectrons, rhoIso, PV);
}

void CIElectron::fillValues(EcalClusterLazyTools lazyTools_, pat::Electron el,
			    unsigned NbElectrons, double rhoIso, 
			    const reco::Vertex& PV)
{
   nbElectrons = NbElectrons;
   Et = el.superCluster()->energy() * std::sin(el.p4().theta());
   EtFromCaloEn = el.caloEnergy() * std::sin(el.p4().theta());
   //================================================================
   //
   // Begin New piece of code by Sam
   //
   //================================================================
   //access new tracker isolation
   const float trkIso = el.userFloat("trkPtIso");
   dr03TkSumPt_corrected = trkIso;
   dr03TkSumPt = el.dr03TkSumPt();
   //access # saturated crystals in the 5x5
   const float nrSatCrysP = el.userInt("nrSatCrys");
   nrSatCrys = nrSatCrysP;
   //access the HEEP ID pass / fail
   const bool heepID = el.userInt("heepElectronID_HEEPV70");
   isPassHeepID = heepID;
   //================================================================
   //
   // End New piece of code by Sam
   //
   //================================================================
   pt = el.pt();
   thetaSC = el.caloPosition().theta(); //theta SC
   etaSC = el.superCluster()->eta();    //eta SC
   phiSC = el.superCluster()->phi();    //phi SC
   phiWidth = el.superCluster()->phiWidth();
   etaWidth = el.superCluster()->etaWidth();
   energySC = el.superCluster()->energy(); //energy SC
   preshowerEnergySC = el.superCluster()->preshowerEnergy();
   thetaTrack = el.p4().theta(); //theta track
   etaTrack = el.p4().eta();     //eta track
   phiTrack = el.p4().phi();     //phi track
   x = el.p4().x();
   y = el.p4().y();
   z = el.p4().z();
   zTrackPositionAtVtx = el.TrackPositionAtVtx().Z();
   hadronicOverEm = el.hadronicOverEm();
   deltaEtaInSC = el.deltaEtaSuperClusterTrackAtVtx();
   deltaPhiInSC = el.deltaPhiSuperClusterTrackAtVtx();
   deltaEtaInSeedCluster = el.deltaEtaSeedClusterTrackAtVtx();
   deltaPhiInSeedCluster = el.deltaPhiSeedClusterTrackAtCalo();
   sigmaIetaIeta = el.sigmaIetaIeta();
   e2x5Max = el.e2x5Max();
   e1x5 = el.e1x5();
   //e5x1 = el.e5x1());
   //e3x3 = el.e3x3());
   e5x5 = el.e5x5();
   e2x5MaxOver5x5 = el.e2x5Max()/el.e5x5();
   e1x5Over5x5 = el.e1x5()/el.e5x5();
   sigmaIetaIetaFull5x5 = el.full5x5_sigmaIetaIeta();
   e2x5MaxFull5x5 = el.full5x5_e2x5Max();
   e1x5Full5x5 = el.full5x5_e1x5();
   e5x5Full5x5 = el.full5x5_e5x5();
   e2x5MaxOver5x5Full5x5 = el.full5x5_e2x5Max()/el.full5x5_e5x5();
   e1x5Over5x5Full5x5 = el.full5x5_e1x5()/el.full5x5_e5x5();
   //rawId = el.superCluster()->seed()->seed().id());
   EBDetId BarrelId = el.superCluster()->seed()->seed();
   rawId = BarrelId.rawId();
   ieta = BarrelId.ieta();
   e2x5Right = lazyTools_.e2x5Right(*(el.superCluster()->seed()));
   e2x5Left = lazyTools_.e2x5Left(*(el.superCluster()->seed()));
   e2x5Top = lazyTools_.e2x5Top(*(el.superCluster()->seed()));
   e2x5Bottom = lazyTools_.e2x5Bottom(*(el.superCluster()->seed()));
   eMax = lazyTools_.eMax(*(el.superCluster()->seed()));
   eRight = lazyTools_.eRight(*(el.superCluster()->seed()));
   eLeft = lazyTools_.eLeft(*(el.superCluster()->seed()));
   eTop = lazyTools_.eTop(*(el.superCluster()->seed()));
   eBottom = lazyTools_.eBottom(*(el.superCluster()->seed()));
   e3x3 = lazyTools_.e3x3(*(el.superCluster()->seed()));
   frac51 =  lazyTools_.e5x1(*(el.superCluster()->seed()))/el.full5x5_e5x5();
   frac15 =  lazyTools_.e1x5(*(el.superCluster()->seed()))/el.full5x5_e5x5();
   nbVtx = PV.size;
   if(PV.size>0){
     dxy = el.gsfTrack()->dxy(PV.position());
     dz = el.gsfTrack()->dz(PV.position());
   }
   else{
     dxy = el.gsfTrack()->dxy();
     dz = el.gsfTrack()->dz();
   }
   isEcalDrivenSeed = el.ecalDrivenSeed();
   isPassConversionVeto = el.passConversionVeto();
   charge = el.gsfTrack()->charge();
   rhoIso = rhoIso;
   nbOfMissingHits = el.gsfTrack()->numberOfLostHits();
   fbrem = el.fbrem();
   EoverP = el.eSeedClusterOverP();
   Xposition = el.caloPosition().x();
   Yposition = el.caloPosition().y();
   //------------- detector isolation -------------------------
   hcalDepth1OverEcal = el.hcalDepth1OverEcal();
   hcalDepth2OverEcal = el.hcalDepth2OverEcal();
   dr03HcalDepth2TowerSumEt = el.dr03HcalDepth2TowerSumEt();
   hcalDepth2TowerSumEtNoVeto = el.isolationVariables03().hcalDepth2TowerSumEt;// hcaldepht2 iso deposit with
   // electron footprint removed
   hcalDepth1TowerSumEtNoVeto = el.isolationVariables03().hcalDepth1TowerSumEt;// hcaldepht1 iso deposit with
   // electron footprint removed
   EcalPlusHcald1iso = el.dr03EcalRecHitSumEt() + el.dr03HcalDepth1TowerSumEt();
   dr03EcalRecHitSumEt = el.dr03EcalRecHitSumEt();
   dr03HcalDepth1TowerSumEt = el.dr03HcalDepth1TowerSumEt();
   dr03HcalDepth1TowerSumEtBc = el.dr03HcalDepth1TowerSumEtBc();
   //------------- PF isolation from pat::ele -------------------------
   pfSumPhotonEt = el.pfIsolationVariables().sumPhotonEt;
   pfSumChargedHadronPt = el.pfIsolationVariables().sumChargedHadronPt;
   pfSumNeutralHadronEt = el.pfIsolationVariables().sumNeutralHadronEt;
   pfSumPUPt = el.pfIsolationVariables().sumPUPt;
   // do deltaBeta
   double charged   = el.pfIsolationVariables().sumPhotonEt;
   double neutral   = el.pfIsolationVariables().sumNeutralHadronEt;
   double pileup    = el.pfIsolationVariables().sumPUPt;
   double deltaBeta = charged + std::max(0.0, neutral-0.5*pileup);
   pfDeltaBeta = deltaBeta;
}

		       
