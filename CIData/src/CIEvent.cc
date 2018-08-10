//CIEvent.cc

//======================================================================
//CI Event Source File 
//Matthew Hokinson and John Woods 
//Date: July 19th, 2018
//Build to Simplify the existing MakeZprimeMiniAodTreeMC.cc file 
//======================================================================

#include "ZprimeDiLeptons/CIData/interface/CIEvent.h"

//======================================================================
//Files to include (Same as the MakeZprimeMiniAodTreeMC source file)
//Can be cut down at a later date 
//======================================================================
#include "FWCore/Utilities/interface/InputTag.h"
#include "FWCore/Utilities/interface/EDGetToken.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/stream/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/PatCandidates/interface/VIDCutFlowResult.h"
#include "HEEP/VID/interface/CutNrs.h"
#include "HEEP/VID/interface/VIDCutCodes.h"
//new by Sherif
// TFile Service
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TTree.h"
// #include "TTree.h"
// #include "TFile.h"
//using namespace std;
//using namespace edm;
//using namespace reco;
//using namespace pat;
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Math/interface/deltaR.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
// Ecal includes
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "Geometry/Records/interface/CaloTopologyRecord.h"
#include "Geometry/CaloGeometry/interface/CaloSubdetectorGeometry.h"
#include "DataFormats/EcalDetId/interface/EcalSubdetector.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterTools.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaHcalIsolation.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HLTReco/interface/TriggerObject.h"
#include "DataFormats/HLTReco/interface/TriggerEvent.h"
#include "DataFormats/HLTReco/interface/TriggerEventWithRefs.h"
#include "DataFormats/HLTReco/interface/TriggerTypeDefs.h"
#include "HLTrigger/HLTcore/interface/HLTConfigProvider.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/MuonReco/interface/MuonSelectors.h"
#include "DataFormats/MuonReco/interface/MuonCocktails.h"
#include "DataFormats/Common/interface/RefCore.h"
#include "RecoVertex/VertexTools/interface/InvariantMassFromVertex.h"
#include "DataFormats/GeometryCommonDetAlgo/interface/Measurement1D.h"
#include "RecoVertex/KalmanVertexFit/interface/KalmanVertexFitter.h"
#include "RecoVertex/VertexPrimitives/interface/TransientVertex.h"
#include "DataFormats/Candidate/interface/VertexCompositePtrCandidate.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHERunInfoProduct.h"
#include "SimDataFormats/GeneratorProducts/interface/LHEEventProduct.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "TrackingTools/Records/interface/TransientTrackRecord.h"
#include "TrackingTools/TransientTrack/interface/TransientTrack.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripMatchedRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/SiPixelRecHit.h"
#include "DataFormats/TrackerRecHit2D/interface/ProjectedSiStripRecHit2D.h"
#include "DataFormats/TrackerRecHit2D/interface/SiStripRecHit1D.h"
#include "DataFormats/TrackReco/interface/DeDxData.h"
#include "RecoTracker/DeDx/interface/DeDxTools.h"
// Jets
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "TH1.h"
// New by Sam
#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "DataFormats/Common/interface/ValueMap.h"
//#include "SHarper/HEEPAnalyzer/interface/HEEPCutCodes.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

void CIEvent::FillEventInfo(unsigned int JRun, unsigned int JEvent, unsigned int Jlumi, unsigned int Jbunch)
{
  Run = JRun;
  Event = JEvent;
  lumi = Jlumi;
  bunch = Jbunch;
}
void CIEvent::PatElectronTree(double rhoIso, const reco::Vertex & PV, const pat::ElectronCollection & electron,
			      const EcalRecHitCollection & ecalEB, const EcalRecHitCollection & ecalEE, 
			      const EcalClusterLazyTools & lazyTools_,
			      const edm::View<pat::Electron> & eleHandle)
{
  unsigned int NbElectrons = -1 ;
  elec.clear();
  
  // rho for isolation
  for(auto& el : eleHandle)
    {
      if(el.caloEnergy() * sin(el.p4().theta()) < 20) continue;
      NbElectrons++;
      
      elec.emplace_back(CIElectron(lazyTools_, el, NbElectrons, rhoIso, PV));
    }
}
void CIEvent::TriggerMatchingTree(const edm::TriggerResults & triggerBits, const pat::TriggerObjectStandAloneCollection & triggerObjects,
				  const pat::TriggerObjectStandAloneCollection & trigobj_handle,
				  const pat::PackedTriggerPrescales & triggerPrescales, const edm::TriggerNames & names)
{
  int NbTriggers = 0;
  int NbTriggerObj = 0;
  
  hltValues.clear();

  hltObjValues.clear();

  for (unsigned int i = 0, n = triggerBits.size(); i < n; ++i) {
    if(findTriggerMatch(names, i)) continue;
   
    NbTriggers++;
    
    hltValues.push_back(CIHLTrigger(NbTriggers, triggerBits, names, i));
   
  }
  for (unsigned i = 0; i < trigobj_handle.size(); ++i) {
    pat::TriggerObjectStandAlone src = trigobj_handle.at(i);
    src.unpackPathNames(names);
    std::vector<std::string> const& pathnames = src.pathNames();
    for (unsigned j = 0; j < pathnames.size(); ++j) {
      if( src.pt() < 20.0 ) continue;
      if( fabs(src.eta()) > 3.0 ) continue;
      if( findPathMatch(pathnames, j)) continue;
      
      NbTriggerObj++;

      hltObjValues.push_back(CIHLTObj(NbTriggerObj, src, pathnames, j));

      
    }
  }
}
bool CIEvent::isAncestor(const reco::Candidate * ancestor, const reco::Candidate * particle)
{
  //particle is already the ancestor
  if(ancestor == particle ) return true;
  //otherwise loop on mothers, if any and return true if the ancestor is found
  for(size_t i=0;i< particle->numberOfMothers();i++)
    {
      if(isAncestor(ancestor,particle->mother(i))) return true;
    }
  //if we did not return yet, then particle and ancestor are not relatives
  return false;
}
void CIEvent::accessGenInfo(bool h_passMInvCut, bool h_passPreFSRMInvCut, bool h_passST1MInvCut, bool h_passST23MInvCut,
			    bool h_passHSMInvCut, double h_xsWeight, edm::View<reco::GenParticle> pruned,
			    const edm::View<pat::PackedGenParticle> & packed, int BosonID_,  int ParticleID1_, 
			    int ParticleID2_, int ParticleID3_, int ParticleStatus_)
{
  int NbGenMuons  = 0;
  genParticles.clear();

  xsWeight = -1.;
  passPreFSRMInvCut = false;
  passMInvCut       = false;
  passST1MInvCut    = false;
  passST23MInvCut   = false;
  passHSMInvCut     = false;

  // The navigation from status 1 to pruned is possible (the other direction should be made by hand)

  //let's try to find all status1 originating directly from a B meson decay
  for(auto& i : pruned){
    
    if(i.pdgId() < BosonID_){
      const reco::Candidate * Zprime = &i;
      
      for(auto& j : packed){
	//get the pointer to the first survied ancestor of a given packed GenParticle in the prunedCollection
	const reco::Candidate * motherInPrunedCollection = j.mother(0);
	if(motherInPrunedCollection != nullptr && isAncestor( Zprime , motherInPrunedCollection)){
	  if( j.pt() < 20.0 ) continue;
	  if( fabs(j.pdgId()) != ParticleID1_ &&
	      fabs(j.pdgId()) != ParticleID2_ &&
	      fabs(j.pdgId()) != ParticleID3_ ) continue;
	  if( j.status() > ParticleStatus_ ) continue;
	  NbGenMuons++;
 
	  genParticles.push_back(CIGenParticles(NbGenMuons, j));
	}
      }
    }
  }
}

void CIEvent::PatMuonTree(const reco::Vertex & PV, const pat::MuonCollection & muons)
{
  int NbMuons = 0;
  
  muData.clear();
  
  
  // pat candidate collection
  for (const pat::Muon &mu : muons) 
    {
      NbMuons++;

      muData.push_back(CIMuon(PV, mu, NbMuons));
    }
}
//void SuperClusterTree(const edm::Event& iEvent,const edm::EventSetup& es);

void CIEvent::ComputeMuonMassVtx(const TransientTrackBuilder & ttkb1, const TransientTrackBuilder & ttkb2, 
				 const TransientTrackBuilder & ttkb3,
				 const reco::Vertex & vertex, const pat::MuonCollection & muons)
{
  computeMuonMassVertices(ttkb1, ttkb2, ttkb3, vertex, muons, 53, muonVertices);
  computeMuonMassVertices(ttkb1, ttkb2, ttkb3, vertex, muons, 30, muonVertices30);
}

void CIEvent::computeMuonMassVertices(const TransientTrackBuilder & ttkb1, const TransientTrackBuilder & ttkb2, 
				      const TransientTrackBuilder & ttkb3, const reco::Vertex & vertex, 
				      const pat::MuonCollection & muons, double ptCut, 
				      const std::vector<CIMuonVtx> & vertices)
{
  int NbMuons1 = 0;
  int NbMuons2 = 0;
  int NbMuons3 = 0;

  vertices.clear();

  std::vector<reco::TransientTrack> ttv1;
  std::vector<reco::TransientTrack> ttv2;
  std::vector<reco::TransientTrack> ttv3;
  reco::TrackRef MuonBestTrack1;
  reco::TrackRef MuonBestTrack2;
  reco::TrackRef MuonBestTrack3;
  // Get TransientTracks (for use in e.g. the vertex fit) for each of
  // the muon tracks, using e.g. the cocktail momentum.
    
  for (const pat::Muon &mu : muons) 
   {
    if(mu.pt() < 5.0 || !mu.globalTrack().isNonnull() || !mu.isTrackerMuon()) continue;

    MuonBestTrack1 = mu.tunePMuonBestTrack();
    if( CIMuon::passesCut(mu, vertex, ptCut) )
     {

      NbMuons1++;
      if(NbMuons1>1) continue;

      ttv1.push_back(ttkb1.build(MuonBestTrack1));
      //find the second high pt muon
      for (const pat::Muon &mu2 : muons) 
       {
	if(mu2.pt() < 5.0 || !mu2.globalTrack().isNonnull() || !mu2.isTrackerMuon()) continue;

	MuonBestTrack2 = mu2.tunePMuonBestTrack();

        if(MuonBestTrack2->pt() == MuonBestTrack1->pt()) continue;

	if( CIMuon::passesCut(mu2, vertex, ptCut) )
	  {

	  NbMuons2++;
	  if(NbMuons2>1) continue;
	  ttv1.push_back(ttkb1.build(MuonBestTrack2));

	  vertices.push_back(CIMuonVtx(ttv1, MuonBestTrack1, MuonBestTrack2));   

	  //find the third high pt muon
	  for (const pat::Muon &mu3 : muons) 
	   {
	    if(mu3.pt() < 5.0 || !mu3.globalTrack().isNonnull() || !mu3.isTrackerMuon()) continue;

	    MuonBestTrack3 = mu3.tunePMuonBestTrack();
	    
	    if(MuonBestTrack3->pt() == MuonBestTrack1->pt()) continue;
	    if(MuonBestTrack3->pt() == MuonBestTrack2->pt()) continue;

	    if( CIMuon::passesCut(mu3, vertex, ptCut) )
	      {

	      NbMuons3++;
	      if(NbMuons3==0) continue;
	      
	      ttv2.push_back(ttkb2.build(MuonBestTrack1));
	      ttv2.push_back(ttkb2.build(MuonBestTrack3));
	      ttv3.push_back(ttkb3.build(MuonBestTrack2));
	      ttv3.push_back(ttkb3.build(MuonBestTrack3));

	      vertices.push_back(CIMuonVtx(ttv2, MuonBestTrack1, MuonBestTrack3));	      
	      vertices.push_back(CIMuonVtx(ttv3, MuonBestTrack2, MuonBestTrack3));

	    }
	  }
	}
      }
    }
  }
}


void CIEvent::PrimaryVertexTree(const reco::VertexCollection & vertices)
{
  int value3_ = 0;
  pVertex.clear();
  
  for(auto& it : vertices){
    value3_ ++;
    pVertex.push_back(CIPrimaryVertex(value3_, it));
  }
}
bool CIEvent::PrimaryVertex(const reco::VertexCollection & vertices, double maxAbsZ_, double maxd0_, int minNdof_, int NbGoodPv_)
{
  int nbGoodPv = 0;
  bool result = false;
  for(reco::VertexCollection::const_iterator it=vertices.begin() ; it!=vertices.end() ; ++it)
    {
      if(it->ndof() > minNdof_ &&
	 ( (maxAbsZ_ <= 0.0) || fabs(it->position().z()) <= maxAbsZ_ ) &&
	 ( (maxd0_ <= 0.0) || fabs(it->position().rho()) <= maxd0_ ) ) nbGoodPv++;
    }
  if( nbGoodPv>=NbGoodPv_ ) result = true;
  return result;
}
void CIEvent::fillMET(const pat::MET & met)
{
  //[1] https://twiki.cern.ch/twiki/bin/viewauth/CMS/MissingETRun2Corrections
  //It is strongly recommended to use the Type-1 corrected MET, directly available from miniaod.
  //In case it is needed to recompute the Type-1 MET, please follow this twiki: here you find how
  //to get straight from miniAOD (slimmedMET and slimmedMETnoHF), how to recalculate correction
  //and uncertainties with the latest and greatest JEC.
  //You can find instructions for each analysis release.
  //[2] https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookMiniAOD#Run2_Fall15_MiniAOD_v2_campaign
  //the slimmedMETsNoHF was dropped (the recommendation from the MET group is to use standard slimmedMETs in 76X)
  //The default type1 corrected MET
  
  metData = CIMet(met);
}

void CIEvent::GenJetTree(const std::vector<reco::GenJet> & genjets)
{
  int NbGenJets  = 0;
  genJet.clear();

  /**** GET GENJETS ****/
  for(auto& gJets : genjets){
    if(gJets.pt()<20.0) continue;
    NbGenJets++;
    
    genJet.push_back(CIGenJets(NbGenJets, gJets));
  }
}
void CIEvent::JetsTree(const pat::JetCollection & jetsC)
{
  jets.clear();
  int jetnumber=0;

  for (const pat::Jet &j : jetsC) {
    double in = 0, out = 0;
    for (unsigned int id = 0, nd = j.numberOfDaughters(); id < nd; ++id) {
      const pat::PackedCandidate &dau = dynamic_cast<const pat::PackedCandidate &>(*j.daughter(id));
      if (dau.charge() == 0) continue;
      (fabs(dau.dz())<0.1 ? in : out) += dau.pt();
    }
    double sum = in + out;
    // Loose ID jet selection
    if( fabs(j.eta()) < 2.4 &&
	j.pt() > 20 &&
	j.neutralHadronEnergyFraction() < 0.99 &&
	j.neutralEmEnergyFraction() < 0.99 &&
	j.numberOfDaughters() > 1.0 &&
	j.chargedHadronEnergyFraction() > 0.0 &&
	j.chargedMultiplicity() > 0.0 &&
	j.chargedEmEnergyFraction() < 0.99 ) {

      jetnumber++;

      jets.push_back(CIJet(sum, in, jetnumber, j));
    }
    else continue;
  }
}
void CIEvent::EventsReWeighting(float EventWeight)
{
  MC_weighting.clear();

  float mc_weight = ( EventWeight > 0 ) ? 1 : -1;
 
  MC_weighting.push_back(mc_weight);
}
void CIEvent::ParticleFlowPhotonTree(const pat::PackedCandidateCollection & pfs, const pat::PhotonCollection & photons)
{
  std::vector<const reco::Candidate *> leptons;
  photon.clear();

  for (const pat::Photon &pho : photons) leptons.push_back(&pho);
  for (const reco::Candidate *lep : leptons) {
    // initialize sums
    double charged = 0, neutral = 0, pileup  = 0;
    // now get a list of the PF candidates used to build this lepton, so to exclude them
    std::vector<reco::CandidatePtr> footprint;
    for (unsigned int i = 0, n = lep->numberOfSourceCandidatePtrs(); i < n; ++i) {
      footprint.push_back(lep->sourceCandidatePtr(i));
    }
    // now loop on pf candidates
    for (unsigned int i = 0, n = pfs.size(); i < n; ++i) {
      const pat::PackedCandidate &pf = (pfs)[i];
      if (deltaR(pf,*lep) < 0.2) {
	// pfcandidate-based footprint removal
	if(std::find(footprint.begin(), footprint.end(), reco::CandidatePtr(&pfs,i)) != footprint.end()) continue;
	if( pf.pt() < 20.0 ) continue;
	if( fabs(pf.eta()) > 2.5 ) continue;

	photon.push_back(CIPhoton(pf));

	if (pf.charge() == 0) {
	  if (pf.pt() > 0.5) neutral += pf.pt();
	} else if (pf.fromPV() >= 2) {
	  charged += pf.pt();
	} else {
	  if (pf.pt() > 0.5) pileup += pf.pt();
	}
      }
    }
  }
}
void CIEvent::fillPU(const std::vector<PileupSummaryInfo> & PupInfo)
{
  for( std::vector<PileupSummaryInfo>::const_iterator cand = PupInfo.begin();cand != PupInfo.end(); ++ cand ) {
    num_PU_vertices = cand->getTrueNumInteractions();
    PU_BunchCrossing = cand->getBunchCrossing();
    num_PU_gen_vertices = cand->getPU_NumInteractions();
  }
}

void CIEvent::BtaggingTree(const std::vector<pat::Jet> & jets, const std::vector<std::string> & bDiscriminators_)
{
  int bDiscriminatorsNumber=0;
  jetBtags.clear();

  // loop over jets
  for(auto& jet : jets)
    {
      // fill discriminator variables
      int flavor = std::abs( jet.partonFlavour() );
      for( const std::string &bDiscr : bDiscriminators_ )
	{
          if( jet.pt()<20.0 || std::abs(jet.eta())>2.4 ) continue; // skip jets with low pT or outside the tracker acceptance

          bDiscriminatorsNumber++;

	  jetBtags.push_back(CIBtags(bDiscriminatorsNumber, jet, bDiscr, flavor));
	}
    }
}
void CIEvent::TauTree(const pat::TauCollection & tausC)
{
  int TausNumber=0;
  taus.clear();

  for (const pat::Tau &tau : tausC) {
    if(tau.pt() < 18.0) continue;
    if(fabs(tau.eta()) > 2.3) continue;
  
    TausNumber++;

    taus.push_back(CITau(TausNumber, tau));
    
  }
}


//The following three functions were created to simplify long if statements in the trigger matching tree 
bool CIEvent::findTriggerMatch(const edm::TriggerNames names, int index)
{
  std::vector<std::string> matchList = makeTriggerPathCombos();
  for (unsigned int j=0; j<matchList.size(); j++)
    {
      if (names.triggerName(index)==matchList[j])
	{
	  return true;
	}
    }
  return false;
}	   

bool CIEvent::findPathMatch(const std::vector<std::string> & pathnames, int index)
{
  std::vector<std::string> matchList = makeTriggerPathCombos();
  for (unsigned int j=0; j < matchList.size(); j++)
    {
      if (pathnames[index]==matchList[j])
	{
	  return true;
	}
    }
  return false;
}

std::vector<std::string> CIEvent::makeTriggerPathCombos()
{
  std::vector<std::string> pathNameStart {"HLT_Mu27", "HLT_TkMu27", "HLT_Mu50", "HLT_TkMu50", "HLT_DoubleEle33_CaloIDL_MW"};
  std::vector<std::string> matchList;
  for (unsigned int j=0; j<pathNameStart.size(); j++)
    {
      for (unsigned int i=1; i<11; i++)
	{
	  std::string pathName= pathNameStart[j] + "_v" + to_string(i);
	  matchList.push_back(pathName);
	}
    }
  return matchList;
}

void CIEvent::findChosenLeptons()
{
  //Only find the highest 2 pt's for each 
  std::vector<CIMuon> passedMuons;
  std::vector<CIElectron> passedElectrons;

  findPassedMuons(passedMuons);
  findPassedElectrons(passedElectrons);

  bool isMuon = findIsMuon(passedMuons, passedElectrons);

  if(isMuon)
    {
      lepton1 = CIChosenLepton(passedMuons[0]);
      lepton2 = CIChosenLepton(passedMuons[1]);
    }
  else
    {
      lepton1 = CIChosenLepton(passedElectrons[0]);
      lepton2 = CIChosenLepton(passedElectrons[1]);
    }
}

void CIEvent::findPassedMuons(std::vector<CIMuon> & passedMuons)
{
  double highestPt = 0;
  double secondHightestPt = 0;

  //muData is the collection of CIMuons
  for(CIMuon & ciMu : muData)
    {
      if(ciMu.isChosen(highestPt))
	{
	  passedMuons[0] = ciMu;
	  continue;
	}
      if(ciMu.isChosen(secondHighestPt))
	{
	  passedMuons[1] = ciMu;
	}
    }
}

void CIEvent::findPassedElectrons(std::vector<CIElectron> & passedElectrons)
{
  double highestPt = 0;
  double secondHightestPt = 0;

  //muData is the collection of CIElectrons
  for(CIElectron & ciEle : elec)
    {
      if(ciEle.isChosen(highestPt))
	{
	  passedElectrons[0] = ciEle;
	  continue;
	}
      if(ciEle.isChosen(secondHighestPt))
	{
	  passedElectrons[1] = ciEle;
	}
    }
}

bool CIEvent::findIsMuon(const std::vector<CIMuon> & passedMuons,
			 const std::vector<CIElectron> & passedElectrons)
{
  
}
			 
















