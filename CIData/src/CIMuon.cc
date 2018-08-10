//==============================
//CIMuon source file 
//MHokinson - Aug 9
//CI muon was created to handle 
//the muon values in CIEvent
//==============================

//Include the header file 
#include "ZprimeDiLeptons/CIData/interface/CIMuon.h"

//Include any special types 
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/VertexReco/interface/Vertex.h"

CIMuon::CIMuon(const reco::Vertex & PV, const pat::Muon & mu, int NbMuons)
{
  fillValues(PV, mu, NbMuons);
}

void CIMuon::fillValues(const reco::Vertex & PV, const pat::Muon & mu, int NbMuons)
{
   nbMuon = NbMuons;
   isLooseMuon = mu.isLooseMuon();
   isTightMuon = mu.isTightMuon(PV);
   isHighPtMuon = mu.isHighPtMuon(PV);
   isGlobalMuon = mu.isGlobalMuon();
   isPF = mu.isPFMuon();
   isTrackerMuon = mu.isTrackerMuon();
   nbofpv = PV.size;
   //isMuonsCleaned = mu.userInt("muonsCleaned:oldPF"));
   //============== Parameters related to Kinematics =====================
   /*ERROR - tevOptimized is not a member of Muon 
    Note: these variables are also not defined in CIMuon.h, so they would 
    need to be added if this section is ever uses 

   reco::TrackRef cktTrack;
   cktTrack = (muon::tevOptimized(mu, 200, 17., 40., 0.25)).first;
   ptcocktail = cktTrack->pt();
   dPToverPTcocktail = cktTrack->ptError()/cktTrack->pt();
   absdxy = fabs(cktTrack->dxy(PV.position()));
   absdz = fabs(cktTrack->dz(PV.position()));
   etaCocktail = cktTrack->eta();
   phiCocktail = cktTrack->phi();
   thetaCocktail = cktTrack->theta();
   chargeCocktail = cktTrack->charge();
   pxCocktail = cktTrack->px(); //px component of the track
   pyCocktail = cktTrack->py(); //py component of the track
   pzCocktail = cktTrack->pz(); //pz component of the track
   pCocktail = cktTrack->p(); //magnitude of momentum vector
   */

   // part for TuneP Muon Best track
   const reco::TrackRef& tunePTrack  = mu.tunePMuonBestTrack();
   ptTunePMuonBestTrack = tunePTrack->pt();
   dPToverPTTunePMuonBestTrack = tunePTrack->ptError()/tunePTrack->pt();
   pxTunePMuonBestTrack = tunePTrack->px(); //px component of the track
   pyTunePMuonBestTrack = tunePTrack->py(); //py component of the track
   pzTunePMuonBestTrack = tunePTrack->pz(); //pz component of the track
   pTunePMuonBestTrack = tunePTrack->p();   //magnitude of momentum vector
   etaTunePMuonBestTrack = tunePTrack->eta();
   phiTunePMuonBestTrack = tunePTrack->phi();
   thetaTunePMuonBestTrack = tunePTrack->theta();
   chargeTunePMuonBestTrack = tunePTrack->charge();
   absdxyTunePMuonBestTrack = fabs(tunePTrack->dxy(PV.position()));
   absdzTunePMuonBestTrack = fabs(tunePTrack->dz(PV.position()));
   en = mu.energy();
   et = mu.et();
   pt = mu.pt();
   eta = mu.eta();
   phi = mu.phi();
   charge = mu.charge();
   ptInnerTrack = mu.innerTrack()->pt();
   dPToverPTInnerTrack = mu.innerTrack()->ptError()/mu.innerTrack()->pt();
   pxInnerTrack = mu.innerTrack()->px();
   pyInnerTrack = mu.innerTrack()->py();
   pzInnerTrack = mu.innerTrack()->pz();
   pInnerTrack = mu.innerTrack()->p();
   etaInnerTrack = mu.innerTrack()->eta();
   phiInnerTrack = mu.innerTrack()->phi();
   thetaInnerTrack = mu.innerTrack()->theta();
   chargeInnerTrack = mu.innerTrack()->charge();
   absdxyInnerTrack = fabs(mu.innerTrack()->dxy(PV.position()));
   absdzInnerTrack = fabs(mu.innerTrack()->dz(PV.position()));
   absdxy = fabs(mu.globalTrack()->dxy(PV.position()));
   absdz = fabs(mu.globalTrack()->dz(PV.position()));

   //====================== Parameters related to track quality =====================
   normalizedChi2 = mu.globalTrack()->normalizedChi2();
   numberOfValidPixelHits = mu.globalTrack()->hitPattern().numberOfValidPixelHits();
   numberOfValidMuonHits = mu.globalTrack()->hitPattern().numberOfValidMuonHits();
   numberOftrackerLayersWithMeasurement = mu.globalTrack()->hitPattern().trackerLayersWithMeasurement();
   numberOfMatchedStations = mu.numberOfMatchedStations();

   //============= Parameters related to detector isolation =====================
   emIso = mu.isolationR03().emEt;
   hadIso = mu.isolationR03().hadEt;
   trackiso = mu.isolationR03().sumPt;

   //============= Parameters related to PF isolation =====================
   pfSumChargedHadronPt = mu.pfIsolationR03().sumChargedHadronPt;
   pfSumNeutralHadronEt = mu.pfIsolationR03().sumNeutralHadronEt;
   PFSumPhotonEt = mu.pfIsolationR03().sumPhotonEt;
   pfSumPUPt = mu.pfIsolationR03().sumPUPt;
   // do deltaBeta
   double charged   = mu.pfIsolationR03().sumChargedHadronPt;
   double neutral   = mu.pfIsolationR03().sumNeutralHadronEt;
   double pileup    = mu.pfIsolationR03().sumPUPt;
   double deltaBeta = (charged + std::max(0.0, neutral-0.5*pileup))/mu.pt();
   patDeltaBeta = deltaBeta;
   stationMask = mu.stationMask();
   numberOfMatchedRPCLayers = mu.numberOfMatchedRPCLayers();

   //New Proposed Muon Matched Stations Cut*:
   if(mu.numberOfMatchedStations()>1) 
     {
       passOldMatchedStationsCut = true;
     }
   else 
     {
       passOldMatchedStationsCut = false;
     }

   if (mu.numberOfMatchedStations()>1 || 
       (mu.numberOfMatchedStations()==1 && !(mu.stationMask()==1 || 
					     mu.stationMask()==16)) || 
       ((mu.numberOfMatchedStations()==1 && (mu.stationMask()==1 || 
					     mu.stationMask()==16)) && 
	mu.numberOfMatchedRPCLayers()>2))  
     {
       passNewMatchedStationsCut = true;
     }
   else 
     {
       passNewMatchedStationsCut = false;
     }

   canPassCuts = passesCut(mu, PV, 53);  
}

bool CIMuon::passesCut(const pat::Muon & mu, const reco::Vertex & vertex, double ptCut)
{
  return mu.tunePMuonBestTrack()->pt() > ptCut && (mu.isolationR03().sumPt/mu.innerTrack()->pt() < 0.10) && 
         (mu.tunePMuonBestTrack()->ptError()/mu.tunePMuonBestTrack()->pt()<0.3) &&
         fabs(mu.tunePMuonBestTrack()->dxy(vertex.position()))<0.2 &&
         mu.globalTrack()->hitPattern().trackerLayersWithMeasurement()>5 &&
         mu.globalTrack()->hitPattern().numberOfValidPixelHits()>0 &&
         mu.globalTrack()->hitPattern().numberOfValidMuonHits()>0 &&
         (mu.numberOfMatchedStations()>1 || 
	  (mu.numberOfMatchedStations()==1 && !(mu.stationMask()==1 || mu.stationMask()==16)) || 
	  ((mu.numberOfMatchedStations()==1 && (mu.stationMask()==1 || mu.stationMask()==16)) && 
	   mu.numberOfMatchedRPCLayers()>2));
}

//This will take in the current Highest pt, and then will set it the first time around, 
//but then it will make sure to find the second highest pt the second time around 
bool CIMuon::isChosen(double & highestPt)
{
  if(isTrackerMuon->at(i) == 1 &&
     isGlobalMuon->at(i) == 1 &&
     fabs(etaTunePMuonBestTrack->at(i)) < 2.4 &&
     ptTunePMuonBestTrack->at(i) > 53.0 &&
     absdxyTunePMuonBestTrack->at(i) < 0.2 &&
     (trackiso->at(i)/ptInnerTrack->at(i)) < 0.10  &&
     numberOftrackerLayersWithMeasurement->at(i) > 5 &&
     numberOfValidPixelHits->at(i) > 0 &&
     numberOfValidMuonHits->at(i) > 0 &&
     passNewMatchedStationsCut->at(i) == 1 &&
     dPToverPTTunePMuonBestTrack->at(i) < 0.3 )
    {
      if(ptTunePMuonBestTrack > highestPt)
	{
	  highestPt = ptTunePMuonBestTrack;
	  return true;
	}
    }
  return false;
}
