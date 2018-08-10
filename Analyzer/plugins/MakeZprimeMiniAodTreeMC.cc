//======================================================
// Make the tree for Z' boson to Di-lepton analysis    =
// electron & muon common tree                         =
// Author: Sherif Elgammal                             =
// CMSSW: 8_0_25                                       =
// Data Format: MINIAOD                                =
// Date: 04/06/2017                                    =
//======================================================
//these header files give us easy to use shortcuts for which cut
//corresponds to which which cutnr
//this is fixed for a given ID (and can be different for each ID)
//hence its hard coded
//also these headerfiles are intentionally completely standalone
//so you can easily include them in your analysis if you find them
//useful

#include "ZprimeDiLeptons/Analyzer/interface/MakeZprimeMiniAodTreeMC.h"
#include "ZprimeDiLeptons/CIData/interface/CIEvent.h"

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
using namespace std;
using namespace edm;
using namespace reco;
using namespace pat;
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

//a struct to count the number of electrons passing/failing
//see https://twiki.cern.ch/twiki/bin/view/CMSPublic/FWMultithreadedFrameworkStreamModuleInterface
//if you dont understand why I'm doing this

namespace
{
  struct NrPassFail 
  {
  	NrPassFail():nrPass(0),nrFail(0){}
    mutable std::atomic<int> nrPass;
    mutable std::atomic<int> nrFail;
  };
}

MakeZprimeMiniAodTreeMC::MakeZprimeMiniAodTreeMC(const edm::ParameterSet& iConfig):
  eleToken_(consumes<edm::View<pat::Electron> >(iConfig.getParameter<edm::InputTag>("eles"))),
  rhoToken(consumes <double> (edm::InputTag(std::string("fixedGridRhoFastjetAll")))),
  genInfoProductToken(consumes <GenEventInfoProduct> (edm::InputTag(std::string("generator")))),
  m_passMInvCutToken(consumes<bool,edm::InEvent>(iConfig.getParameter<edm::InputTag>("passMInvCutTag"))),
  m_passPreFSRMInvCutToken(consumes<bool,edm::InEvent>(iConfig.getParameter<edm::InputTag>("passPreFSRMInvCutTag"))),
  m_passST1MInvCutToken(consumes<bool,edm::InEvent>(iConfig.getParameter<edm::InputTag>("passST1MInvCutTag"))),
  m_passST23MInvCutToken(consumes<bool,edm::InEvent>(iConfig.getParameter<edm::InputTag>("passST23MInvCutTag"))),
  m_passHSMInvCutToken(consumes<bool,edm::InEvent>(iConfig.getParameter<edm::InputTag>("passHSMInvCutTag"))),
  m_xsWeightToken(consumes<double,edm::InEvent>(iConfig.getParameter<edm::InputTag>("xsWeightTag"))),
  EDMGenJetsToken_(consumes<reco::GenJetCollection>(iConfig.getParameter<edm::InputTag>("JetSource"))),
  scProducer_(consumes<reco::SuperClusterCollection>(iConfig.getParameter<edm::InputTag>("scProducer"))),
  vtxToken_(consumes<reco::VertexCollection>(iConfig.getParameter<edm::InputTag>("vertices"))),
  muonToken_(consumes<pat::MuonCollection>(iConfig.getParameter<edm::InputTag>("muons"))),
  electronToken_(consumes<pat::ElectronCollection>(iConfig.getParameter<edm::InputTag>("electrons"))),
  tauToken_(consumes<pat::TauCollection>(iConfig.getParameter<edm::InputTag>("taus"))),
  photonToken_(consumes<pat::PhotonCollection>(iConfig.getParameter<edm::InputTag>("photons"))),
  jetToken_(consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("jets"))),
  metToken_(consumes<pat::METCollection>(iConfig.getParameter<edm::InputTag>("mets"))),
  prunedGenToken_(consumes<edm::View<reco::GenParticle> >(iConfig.getParameter<edm::InputTag>("pruned"))),
  packedGenToken_(consumes<edm::View<pat::PackedGenParticle> >(iConfig.getParameter<edm::InputTag>("packed"))),
  tok_EB_(consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("EBrecHitCollectionLabel"))),
  tok_EE_(consumes<EcalRecHitCollection>(iConfig.getParameter<edm::InputTag>("EErecHitCollectionLabel"))),
  ecalRechitEBToken_(consumes<EcalRecHitCollection>(iConfig.getParameter< edm::InputTag >("ecalRechitEB"))),
  ecalRechitEEToken_(consumes<EcalRecHitCollection>(iConfig.getParameter< edm::InputTag >("ecalRechitEE"))),
  rhoIsoInputTag_(consumes<double>(iConfig.getParameter< edm::InputTag >("rhoIsoInputTag"))),
  triggerBits_(consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("bits"))),
  triggerObjects_(consumes<pat::TriggerObjectStandAloneCollection>(iConfig.getParameter<edm::InputTag>("objects"))),
  triggerPrescales_(consumes<pat::PackedTriggerPrescales>(iConfig.getParameter<edm::InputTag>("prescales"))),
  pfToken_(consumes<pat::PackedCandidateCollection>(iConfig.getParameter< edm::InputTag >("pfCands"))),
  PileupSrc_(consumes<std::vector<PileupSummaryInfo> >(iConfig.getParameter<edm::InputTag>("PileupSrc"))),
  bDiscriminators_(iConfig.getParameter<std::vector<std::string> >("bDiscriminators")),
  outputFile_(iConfig.getParameter<std::string>("outputFile"))
{
  edm::LogWarning("MakeZprimeMiniAodTreeMC::MakeZprimeMiniAodTreeMC")
    << "Using outputFile named" << outputFile_;

  rootFile_           = TFile::Open(outputFile_.c_str(),"RECREATE"); // open output file to store histograms
  BosonID_            = iConfig.getParameter<int>("GenBosonID");
  ParticleID1_        = iConfig.getParameter<int>("ParticleID1");
  ParticleID2_        = iConfig.getParameter<int>("ParticleID2");
  ParticleID3_        = iConfig.getParameter<int>("ParticleID3");
  ParticleStatus_     = iConfig.getParameter<int>("ParticleStatus");
  maxAbsZ_            = iConfig.getParameter<double>("maxAbsZ");
  maxd0_              = iConfig.getParameter<double>("maxd0");
  minNdof_            = iConfig.getParameter<int>("minndof");
  NbGoodPv_           = iConfig.getParameter<int>("NbGoodPv");
}

MakeZprimeMiniAodTreeMC::~MakeZprimeMiniAodTreeMC()
{
  delete rootFile_;
}

// ------------ method called once each job just before starting event loop  ------------
void MakeZprimeMiniAodTreeMC::beginJob()
{

  // go to *OUR* rootfile and book histograms
  rootFile_->cd();


  mytree  = new TTree("tree","tr");
  mytree->Branch("Test", &event);
  // Better, use the TFileService for improved compatibility
  // edm::Service< TFileService > fs;
  // mytree  = fs->make<TTree>("tree","tr");
  //=============================================================
  //
  //           Create Branchs for Nb of event,run,lumi
  //
  //=============================================================
//  mytree->Branch("event_runNo",  &Run,   "event_runNo/i");
//  mytree->Branch("event_evtNo",  &Event, "event_evtNo/i");
//  mytree->Branch("event_lumi",   &lumi,  "event_lumi/i");
//  mytree->Branch("event_bunch",  &bunch, "event_bunch/i");
//  //==================================================
//  //
//  //      Create Branchs for Electrons variables
//  //
//  //==================================================
//  mytree->Branch("Ele_nbElectrons",&Ele_nbElectrons);
//  mytree->Branch("Ele_isEcalDrivenSeed",&Ele_isEcalDrivenSeed);
//  mytree->Branch("Ele_isPassConversionVeto",&Ele_isPassConversionVeto);
//  mytree->Branch("Ele_charge",&Ele_charge);
//  mytree->Branch("Ele_nbOfMissingHits",&Ele_nbOfMissingHits);
//  mytree->Branch("Ele_nbVtx",&Ele_nbVtx);
//  mytree->Branch("Ele_Et",&Ele_Et);
//  mytree->Branch("Ele_EtFromCaloEn",&Ele_EtFromCaloEn);
//  mytree->Branch("Ele_pt",&Ele_pt);
//  mytree->Branch("Ele_thetaSC",&Ele_thetaSC);
//  mytree->Branch("Ele_etaSC",&Ele_etaSC);
//  mytree->Branch("Ele_phiSC",&Ele_phiSC);
//  mytree->Branch("Ele_energySC",&Ele_energySC);
//  mytree->Branch("Ele_preshowerEnergySC",&Ele_preshowerEnergySC);
//  mytree->Branch("Ele_thetaTrack",&Ele_thetaTrack);
//  mytree->Branch("Ele_etaTrack",&Ele_etaTrack);
//  mytree->Branch("Ele_phiTrack",&Ele_phiTrack);
//  mytree->Branch("Ele_hadronicOverEm",&Ele_hadronicOverEm);
//  mytree->Branch("Ele_deltaEtaInSeedCluster",&Ele_deltaEtaInSeedCluster);
//  mytree->Branch("Ele_deltaPhiInSeedCluster",&Ele_deltaPhiInSeedCluster);
//  mytree->Branch("Ele_deltaEtaInSC",&Ele_deltaEtaInSC);
//  mytree->Branch("Ele_deltaPhiInSC",&Ele_deltaPhiInSC);
//  mytree->Branch("Ele_sigmaIetaIeta",&Ele_sigmaIetaIeta);
//  mytree->Branch("Ele_e2x5Max",&Ele_e2x5Max);
//  mytree->Branch("Ele_e1x5",&Ele_e1x5);
//  mytree->Branch("Ele_frac15",&Ele_frac15);
//  mytree->Branch("Ele_frac51",&Ele_frac51);
//  mytree->Branch("Ele_e5x5",&Ele_e5x5);
//  mytree->Branch("Ele3x3",&Ele_e3x3);
//  mytree->Branch("Ele_e2x5MaxOver5x5",&Ele_e2x5MaxOver5x5);
//  mytree->Branch("Ele_e1x5Over5x5",&Ele_e1x5Over5x5);
//  mytree->Branch("Ele_sigmaIetaIetaFull5x5",&Ele_sigmaIetaIetaFull5x5);
//  mytree->Branch("Ele_e2x5MaxFull5x5",&Ele_e2x5MaxFull5x5);
//  mytree->Branch("Ele_e1x5Full5x5",&Ele_e1x5Full5x5);
//  mytree->Branch("Ele_e5x5Full5x5",&Ele_e5x5Full5x5);
//  mytree->Branch("Ele_e2x5MaxOver5x5Full5x5",&Ele_e2x5MaxOver5x5Full5x5);
//  mytree->Branch("Ele_e1x5Over5x5Full5x5",&Ele_e1x5Over5x5Full5x5);
//  mytree->Branch("Ele_e2x5Right",&Ele_e2x5Right);
//  mytree->Branch("Ele_e2x5Left",&Ele_e2x5Left);
//  mytree->Branch("Ele_e2x5Top",&Ele_e2x5Top);
//  mytree->Branch("Ele_e2x5Bottom",&Ele_e2x5Bottom);
//  mytree->Branch("Ele_eMax",&Ele_eMax);
//  mytree->Branch("Ele_eRight",&Ele_eRight);
//  mytree->Branch("Ele_eLeft",&Ele_eLeft);
//  mytree->Branch("Ele_eTop",&Ele_eTop);
//  mytree->Branch("Ele_eBottom",&Ele_eBottom);
//  mytree->Branch("Ele_dxy",&Ele_dxy);
//  mytree->Branch("Ele_dz",&Ele_dz);
//  mytree->Branch("Ele_rhoIso",&Ele_rhoIso);
//  mytree->Branch("Ele_fbrem",&Ele_fbrem);
//  mytree->Branch("Ele_EoverP",&Ele_EoverP);
//  mytree->Branch("Ele_Xposition",&Ele_Xposition);
//  mytree->Branch("Ele_Yposition",&Ele_Yposition);
//  mytree->Branch("Ele_EcalPlusHcald1iso",&Ele_EcalPlusHcald1iso);
//  mytree->Branch("Ele_dr03EcalRecHitSumEt",&Ele_dr03EcalRecHitSumEt);
//  mytree->Branch("Ele_dr03HcalDepth1TowerSumEt",&Ele_dr03HcalDepth1TowerSumEt);
//  mytree->Branch("Ele_dr03HcalDepth1TowerSumEtBc",&Ele_dr03HcalDepth1TowerSumEtBc);
//  mytree->Branch("Ele_hcalDepth1OverEcal",&Ele_hcalDepth1OverEcal);
//  mytree->Branch("Ele_hcalDepth2OverEcal",&Ele_hcalDepth2OverEcal);
//  mytree->Branch("Ele_dr03HcalDepth2TowerSumEt",&Ele_dr03HcalDepth2TowerSumEt);
//  mytree->Branch("Ele_hcalDepth2TowerSumEtNoVeto",&Ele_hcalDepth2TowerSumEtNoVeto);
//  mytree->Branch("Ele_hcalDepth1TowerSumEtNoVeto",&Ele_hcalDepth1TowerSumEtNoVeto);
//  mytree->Branch("Ele_pfSumPhotonEt",&Ele_pfSumPhotonEt);
//  mytree->Branch("Ele_pfSumChargedHadronPt",&Ele_pfSumChargedHadronPt);
//  mytree->Branch("Ele_pfSumNeutralHadronEt",&Ele_pfSumNeutralHadronEt);
//  mytree->Branch("Ele_pfSumPUPt",&Ele_pfSumPUPt);
//  mytree->Branch("Ele_pfDeltaBeta",&Ele_pfDeltaBeta);
//  mytree->Branch("Ele_rawId",&Ele_rawId);
//  mytree->Branch("Ele_x",&Ele_x);
//  mytree->Branch("Ele_y",&Ele_y);
//  mytree->Branch("Ele_z",&Ele_z);
//  mytree->Branch("Ele_zTrackPositionAtVtx",&Ele_zTrackPositionAtVtx);
//  mytree->Branch("Ele_ieta",&Ele_ieta);
//  mytree->Branch("Ele_phiWidth",&Ele_phiWidth);
//  mytree->Branch("Ele_etaWidth",&Ele_etaWidth);
//  mytree->Branch("Ele_dr03TkSumPt",&Ele_dr03TkSumPt);
//  mytree->Branch("Ele_dr03TkSumPt_corrected",&Ele_dr03TkSumPt_corrected);
//  mytree->Branch("Ele_nrSatCrys",&Ele_nrSatCrys);
//  mytree->Branch("Ele_isPassHeepID",&Ele_isPassHeepID);
//  //=============================================================
//  //
//  //           Create Branchs for Muons match HLT variables
//  //
//  //=============================================================
//  mytree->Branch("HLT_nb", &HLT_nb);
//  mytree->Branch("HLT_name", &HLT_name);
//  mytree->Branch("HLT_isaccept", &HLT_isaccept);
//  mytree->Branch("HLTObj_nbObj",&HLTObj_nbObj);
//  mytree->Branch("HLTObj_pt",&HLTObj_pt);
//  mytree->Branch("HLTObj_eta",&HLTObj_eta);
//  mytree->Branch("HLTObj_phi",&HLTObj_phi);
//  mytree->Branch("HLTObj_collection", &HLTObj_collection);
//  //===================================================
//  //
//  //    Create vectors for gen jets variables
//  //
//  //===================================================
//  mytree->Branch("iGenJet",&iGenJet);
//  mytree->Branch("idGenJet",&idGenJet);
//  mytree->Branch("statusGenJet",&statusGenJet);
//  mytree->Branch("chargeGenJet",&chargeGenJet);
//  mytree->Branch("ptGenJet",&ptGenJet);
//  mytree->Branch("etaGenJet",&etaGenJet);
//  mytree->Branch("phiGenJet",&phiGenJet);
//  //===================================================
//  //
//  //    Create vectors for gen particles variables
//  //
//  //===================================================
//  mytree->Branch("iGen",&iGen);
//  mytree->Branch("idGen",&idGen);
//  mytree->Branch("statusGen",&statusGen);
//  mytree->Branch("ptGen",&ptGen);
//  mytree->Branch("etaGen",&etaGen);
//  mytree->Branch("phiGen",&phiGen);
//  mytree->Branch("chargeGen",&chargeGen);
//  mytree->Branch("EnergyGen",&EnergyGen);
//  mytree->Branch("pxGen",&pxGen);
//  mytree->Branch("pyGen",&pyGen);
//  mytree->Branch("pzGen",&pzGen);
//  //=============================================================
//  //
//  //           Create Branches GEN level info
//  //
//  //=============================================================
//  mytree->Branch("xsWeight",         &xsWeight);
//  mytree->Branch("passPreFSRMInvCut",&passPreFSRMInvCut);
//  mytree->Branch("passMInvCut",      &passMInvCut);
//  mytree->Branch("passST1MInvCut",&passST1MInvCut);
//  mytree->Branch("passST23MInvCut",&passST23MInvCut);
//  mytree->Branch("passHSMInvCut",&passHSMInvCut);
//  //=============================================================
//  //
//  //           Create Branchs for Muons variables
//  //
//  //=============================================================
//  mytree->Branch("Mu_nbMuon",&Mu_nbMuon);
//  mytree->Branch("Mu_passOldMatchedStationsCut",&Mu_passOldMatchedStationsCut);
//  mytree->Branch("Mu_passNewMatchedStationsCut",&Mu_passNewMatchedStationsCut);
//  mytree->Branch("Mu_isTightMuon",&Mu_isTightMuon);
//  mytree->Branch("Mu_isLooseMuon",&Mu_isLooseMuon);
//  mytree->Branch("Mu_isGlobalMuon",&Mu_isGlobalMuon);
//  mytree->Branch("Mu_isPF",&Mu_isPF);
//  //mytree->Branch("Mu_isMuonsCleaned",&Mu_isMuonsCleaned);
//  mytree->Branch("Mu_isTrackerMuon",&Mu_isTrackerMuon);
//  mytree->Branch("Mu_et",&Mu_et);
//  mytree->Branch("Mu_en",&Mu_en);
//  mytree->Branch("Mu_pt",&Mu_pt);
//  mytree->Branch("Mu_eta",&Mu_eta);
//  mytree->Branch("Mu_phi",&Mu_phi);
//  mytree->Branch("Mu_charge",&Mu_charge);
//  mytree->Branch("Mu_ptTunePMuonBestTrack",&Mu_ptTunePMuonBestTrack);
//  mytree->Branch("Mu_pxTunePMuonBestTrack",&Mu_pxTunePMuonBestTrack);
//  mytree->Branch("Mu_pyTunePMuonBestTrack",&Mu_pyTunePMuonBestTrack);
//  mytree->Branch("Mu_pzTunePMuonBestTrack",&Mu_pzTunePMuonBestTrack);
//  mytree->Branch("Mu_pTunePMuonBestTrack",&Mu_pTunePMuonBestTrack);
//  mytree->Branch("Mu_etaTunePMuonBestTrack",&Mu_etaTunePMuonBestTrack);
//  mytree->Branch("Mu_phiTunePMuonBestTrack",&Mu_phiTunePMuonBestTrack);
//  mytree->Branch("Mu_thetaTunePMuonBestTrack",&Mu_thetaTunePMuonBestTrack);
//  mytree->Branch("Mu_chargeTunePMuonBestTrack",&Mu_chargeTunePMuonBestTrack);
//  mytree->Branch("Mu_dPToverPTTunePMuonBestTrack",&Mu_dPToverPTTunePMuonBestTrack);
//  mytree->Branch("Mu_absdxyTunePMuonBestTrack",&Mu_absdxyTunePMuonBestTrack);
//  mytree->Branch("Mu_absdzTunePMuonBestTrack",&Mu_absdzTunePMuonBestTrack);
//  mytree->Branch("Mu_ptInnerTrack",&Mu_ptInnerTrack);
//  mytree->Branch("Mu_pxInnerTrack",&Mu_pxInnerTrack);
//  mytree->Branch("Mu_pyInnerTrack",&Mu_pyInnerTrack);
//  mytree->Branch("Mu_pzInnerTrack",&Mu_pzInnerTrack);
//  mytree->Branch("Mu_pInnerTrack",&Mu_pInnerTrack);
//  mytree->Branch("Mu_etaInnerTrack",&Mu_etaInnerTrack);
//  mytree->Branch("Mu_phiInnerTrack",&Mu_phiInnerTrack);
//  mytree->Branch("Mu_thetaInnerTrack",&Mu_thetaInnerTrack);
//  mytree->Branch("Mu_chargeInnerTrack",&Mu_chargeInnerTrack);
//  mytree->Branch("Mu_dPToverPTInnerTrack",&Mu_dPToverPTInnerTrack);
//  mytree->Branch("Mu_absdxyInnerTrack",&Mu_absdxyInnerTrack);
//  mytree->Branch("Mu_absdzInnerTrack",&Mu_absdzInnerTrack);
//  mytree->Branch("Mu_normalizedChi2",&Mu_normalizedChi2);
//  mytree->Branch("Mu_absdxy",&Mu_absdxy);
//  mytree->Branch("Mu_absdz",&Mu_absdz);
//  mytree->Branch("Mu_vtxMass",&Mu_vtxMass);
//  mytree->Branch("Mu_vtxNormChi2",&Mu_vtxNormChi2);
//  mytree->Branch("Mu_vtxMassLept",&Mu_vtxMassLept);
//  mytree->Branch("Mu_numberOfMatchedStations",&Mu_numberOfMatchedStations);
//  mytree->Branch("Mu_numberOfValidPixelHits",&Mu_numberOfValidPixelHits);
//  mytree->Branch("Mu_numberOfValidMuonHits",&Mu_numberOfValidMuonHits);
//  mytree->Branch("Mu_numberOftrackerLayersWithMeasurement",&Mu_numberOftrackerLayersWithMeasurement);
//  mytree->Branch("Mu_emIso",&Mu_emIso);
//  mytree->Branch("Mu_hadIso",&Mu_hadIso);
//  mytree->Branch("Mu_trackiso",&Mu_trackiso);
//  mytree->Branch("Mu_pfSumChargedHadronPt",&Mu_pfSumChargedHadronPt);
//  mytree->Branch("Mu_pfSumNeutralHadronEt",&Mu_pfSumNeutralHadronEt);
//  mytree->Branch("Mu_PFSumPhotonEt",&Mu_PFSumPhotonEt);
//  mytree->Branch("Mu_pfSumPUPt",&Mu_pfSumPUPt);
//  mytree->Branch("Mu_nbofpv",&Mu_nbofpv);
//  mytree->Branch("Mu_patDeltaBeta",&Mu_patDeltaBeta);
//  mytree->Branch("Mu_stationMask",&Mu_stationMask);
//  mytree->Branch("Mu_numberOfMatchedRPCLayers",&Mu_numberOfMatchedRPCLayers);
//  mytree->Branch("Mu_vtxMass30GeV",&Mu_vtxMass30GeV);
//  mytree->Branch("Mu_vtxNormChi30GeV",&Mu_vtxNormChi30GeV);
//  mytree->Branch("Mu_vtxMass30GeVLept",&Mu_vtxMass30GeVLept);
//  //=============================================================
//  //
//  //           Create Branches for PF MET
//  //
//  //=============================================================
//  mytree->Branch("GenMet_pt",&GenMet_pt,"GenMet_pt/D");
//  //The default type1 corrected MET
//  mytree->Branch("PFMet_et_cor",   &PFMet_et_cor,   "PFMet_et_cor/D");
//  mytree->Branch("PFMet_pt_cor",   &PFMet_pt_cor,   "PFMet_pt_cor/D");
//  mytree->Branch("PFMet_phi_cor",  &PFMet_phi_cor,  "PFMet_phi_cor/D");
//  mytree->Branch("PFMet_en_cor",   &PFMet_en_cor,   "PFMet_en_cor/D");
//  mytree->Branch("PFMet_px_cor",   &PFMet_px_cor,   "PFMet_px_cor/D");
//  mytree->Branch("PFMet_py_cor",   &PFMet_py_cor,   "PFMet_py_cor/D");
//  mytree->Branch("PFMet_pz_cor",   &PFMet_pz_cor,   "PFMet_pz_cor/D");
//  mytree->Branch("PFMet_sumEt_cor",&PFMet_sumEt_cor,"PFMet_sumEt_cor/D");
//  //The raw calo ETmiss
//  mytree->Branch("CaloMet_pt",   &CaloMet_pt,   "CaloMet_pt/D");
//  mytree->Branch("CaloMet_phi",  &CaloMet_phi,  "CaloMet_phi/D");
//  mytree->Branch("CaloMet_sumEt",&CaloMet_sumEt,"CaloMet_sumEt/D");
//  mytree->Branch("PFMet_shiftedPt_JetEnUp",&PFMet_shiftedPt_JetEnUp,"PFMet_shiftedPt_JetEnUp/D");
//  mytree->Branch("PFMet_shiftedPt_JetEnDown",&PFMet_shiftedPt_JetEnDown,"PFMet_shiftedPt_JetEnDown/D");
//  //The Raw PF Met (un-corrected MET)
//  /*mytree->Branch("PFMet_pt_uncor",   &PFMet_pt_uncor,   "PFMet_pt_uncor/D");
//    mytree->Branch("PFMet_phi_uncor",  &PFMet_phi_uncor,  "PFMet_phi_uncor/D");
//    mytree->Branch("PFMet_sumEt_uncor",&PFMet_sumEt_uncor,"PFMet_sumEt_uncor/D");*/
//  //mytree->Branch("METSign",&METSign,"METSign/D");
//
//  //Type I MET Uncertainties
//  mytree->Branch("PFMet_METshiftedPtJetEnUp",  &pfMETshiftedPtJetEnUp,  "PFMet_METshiftedPtJetEnUp/D");
//  mytree->Branch("PFMet_METshiftedPtJetEnDn",  &pfMETshiftedPtJetEnDn,  "PFMet_METshiftedPtJetEnDn/D");
//  mytree->Branch("PFMet_METshiftedPtEleEnUp",  &pfMETshiftedPtEleEnUp,  "PFMet_METshiftedPtEleEnUp/D");
//  mytree->Branch("PFMet_METshiftedPtEleEnDn",  &pfMETshiftedPtEleEnDn,  "PFMet_METshiftedPtEleEnDn/D");
//  mytree->Branch("PFMet_METshiftedPtMuEnUp",   &pfMETshiftedPtMuEnUp,   "PFMet_METshiftedPtMuEnUp/D");
//  mytree->Branch("PFMet_METshiftedPtMuEnDn",   &pfMETshiftedPtMuEnDn,   "PFMet_METshiftedPtMuEnDn/D");
//  mytree->Branch("PFMet_METshiftedPtJetResUp", &pfMETshiftedPtJetResUp, "PFMet_METshiftedPtJetResUp/D");
//  mytree->Branch("PFMet_METshiftedPtJetResDn", &pfMETshiftedPtJetResDn, "PFMet_METshiftedPtJetResDn/D");
//  mytree->Branch("PFMet_METshiftedPtUnclEnUp", &pfMETshiftedPtUnclEnUp, "PFMet_METshiftedPtUnclEnUp/D");
//  mytree->Branch("PFMet_METshiftedPtUnclEnDn", &pfMETshiftedPtUnclEnDn, "PFMet_METshiftedPtUnclEnDn/D");
//  mytree->Branch("PFMet_METshiftedPtPhoEnUp",  &pfMETshiftedPtPhoEnUp,  "PFMet_METshiftedPtPhoEnUp/D");
//  mytree->Branch("PFMet_METshiftedPtPhoEnDn",  &pfMETshiftedPtPhoEnDn,  "PFMet_METshiftedPtPhoEnDn/D");
//  //mytree->Branch("PFMet_METshiftedPtJetEnUpSmear",  &pfMETshiftedPtJetEnUpSmear,  "PFMet_METshiftedPtJetEnUpSmear/D");
//  //mytree->Branch("PFMet_METshiftedPtJetEnDnSmear",  &pfMETshiftedPtJetEnDnSmear,  "PFMet_METshiftedPtJetEnDnSmear/D");
//  //mytree->Branch("PFMet_METUncertaintySize",        &pfMETUncertaintySize,  "PFMet_METUncertaintySize/D");
//  //mytree->Branch("PFMet_METFullUncertaintySize",    &pfMETFullUncertaintySize,  "PFMet_METFullUncertaintySize/D");
//  //=============================================================
//  //
//  // Create Branches for jets variables
//  //
//  //=============================================================
//  mytree->Branch("jet_nb",&jet_nb);
//  mytree->Branch("jet_charge",&jet_charge);
//  mytree->Branch("jet_et",&jet_et);
//  mytree->Branch("jet_pt",&jet_pt);
//  mytree->Branch("jet_eta",&jet_eta);
//  mytree->Branch("jet_phi",&jet_phi);
//  mytree->Branch("jet_en",&jet_en);
//  mytree->Branch("jet_theta",&jet_theta);
//  mytree->Branch("jet_beta",&jet_beta);
//  mytree->Branch("jet_pileup_mva_disc",&jet_pileup_mva_disc);
//  //=============================================================
//  //
//  // Create Branches for Btagging variables
//  //
//  //=============================================================
//  mytree->Branch("Nb_bDiscriminators",&Nb_bDiscriminators);
//  mytree->Branch("jet_btag_pt",&jet_btag_pt);
//  mytree->Branch("jet_btag_eta",&jet_btag_eta);
//  mytree->Branch("jet_btag_phi",&jet_btag_phi);
//  mytree->Branch("jet_btag_flavor",&jet_btag_flavor);
//  mytree->Branch("jet_btag_pfCSVv2IVF_discriminator",&jet_btag_pfCSVv2IVF_discriminator);
//  //====================================================
//  //
//  // Create vectors for Taus variables
//  //
//  //====================================================
//  mytree->Branch("Nb_taus",&Nb_taus);
//  mytree->Branch("Tau_pt",&Tau_pt);
//  mytree->Branch("Tau_eta",&Tau_eta);
//  mytree->Branch("Tau_phi",&Tau_phi);
//  mytree->Branch("Tau_id",&Tau_id);
//  mytree->Branch("Tau_LooseCombinedIsolationDeltaBetaCorr3Hits",&Tau_LooseCombinedIsolationDeltaBetaCorr3Hits);
//  //===================================================
//  //
//  //    Create vectors for photons variables
//  //
//  //===================================================
//  mytree->Branch("pfphoton_size",&pfphoton_size,"pfphoton_size/I");
//  mytree->Branch("pfphoton_pt",&pfphoton_pt);
//  mytree->Branch("pfphoton_eta",&pfphoton_eta);
//  mytree->Branch("pfphoton_phi",&pfphoton_phi);
//  mytree->Branch("pfphoton_theta",&pfphoton_theta);
//  //mytree->Branch("pfphoton_PFchHad",&pfphoton_PFchHad);
//  //mytree->Branch("pfphoton_PFneuHad",&pfphoton_PFneuHad);
//  //mytree->Branch("pfphoton_PFphoton",&pfphoton_PFphoton);
//  //mytree->Branch("pfphoton_PFPUchAllPart",&pfphoton_PFPUchAllPart);
//  //mytree->Branch("pfphoton_pfphoton_PFX_rho",&pfphoton_pfphoton_PFX_rho);
//  //=============================================================
//  //
//  //           Create Branchs for PileUp tree
//  //
//  //=============================================================
//  mytree->Branch("num_PU_vertices",&num_PU_vertices,"num_PU_vertices/I");
//  mytree->Branch("PU_BunchCrossing",&PU_BunchCrossing,"PU_BunchCrossing/I");
//  mytree->Branch("num_PU_gen_vertices",&num_PU_gen_vertices,"num_PU_gen_vertices/I");
//  //=============================================================
//  //
//  //           Create Branch for Rho
//  //
//  //=============================================================
//  mytree->Branch("Rho",&Rho,"Rho/F");
//  //=============================================================
//  //
//  //           Create Branch for events reweighting
//  //
//  //=============================================================
//  mytree->Branch("MC_weighting",&MC_weighting);
//  //=============================================================
//  //
//  //           Create Branchs for Pimary Vertice variables
//  //
//  //=============================================================
//  /*mytree->Branch("nbPv",&nbPv);
//  mytree->Branch("Nbdof",&Nbdof);
//  mytree->Branch("PositionRho",&PositionRho);
//  mytree->Branch("PositionX",&PositionX);
//  mytree->Branch("PositionY",&PositionY);
//  mytree->Branch("PositionZ",&PositionZ);*/
//
}

void MakeZprimeMiniAodTreeMC::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  //==============================================
  //=        Begin of the main program           =
  //==============================================
  event.FillEventInfo(iEvent.id().run(), iEvent.id().event(), iEvent.luminosityBlock(), iEvent.bunchCrossing());
  edm::Handle<double> rhoIso_h;
  iEvent.getByToken(rhoIsoInputTag_, rhoIso_h);
  double rhoIso = *(rhoIso_h.product());//VARIABLE
  // primary vertex candidate collection
  edm::Handle<reco::VertexCollection> vertices;
  iEvent.getByToken(vtxToken_, vertices);
  const reco::Vertex &PV = vertices->front();//VARIABLE
  edm::Handle<pat::ElectronCollection> electrons;//VARIABLE
  iEvent.getByToken(electronToken_, electrons);
  //------------ Rec Hits in EB ----------------
  edm::Handle<EcalRecHitCollection> ecalEB;//VARIABLE
  iEvent.getByToken(tok_EB_,ecalEB);
  //------------ Rec Hits in EE ----------------
  edm::Handle<EcalRecHitCollection> ecalEE;//VARIABLE
  iEvent.getByToken(tok_EE_,ecalEE);
  std::auto_ptr<EcalClusterLazyTools> lazyTools_;//VARIABLE ? 
  lazyTools_ .reset(new EcalClusterLazyTools( iEvent, iSetup, ecalRechitEBToken_, ecalRechitEEToken_ ));
  edm::Handle<edm::View<pat::Electron>> eleHandle;//VARIABLE
  iEvent.getByToken(eleToken_,eleHandle);
  //===================== Handle For Primary Vertics ===========
  /*edm::Handle<reco::VertexCollection> pvHandle;
  iEvent.getByToken(vtxToken_,pvHandle);
  const reco::VertexCollection &vertices = *pvHandle.product();
  bool GoodPv = PrimaryVertex(vertices);
  //cout << "At least one good primary vertex" << GoodPv << endl;
  if( GoodPv == 0 ) return; //the aim of that command is to select only events*/
  
  
    // define a jet handle
  edm::Handle<std::vector<pat::Jet> > jets;
  // get jets from the event
  iEvent.getByToken(jetToken_, jets);
  
  
  
  edm::Handle<vector<PileupSummaryInfo> > PupInfo;
  iEvent.getByToken(PileupSrc_, PupInfo);
  
  Handle<edm::View<pat::PackedGenParticle>> packed;//VARIABLE
  iEvent.getByToken(packedGenToken_,packed);

  Handle<edm::View<reco::GenParticle>> pruned;//VARIABLE
  iEvent.getByToken(prunedGenToken_,pruned);
  
  edm::Handle<pat::TauCollection> taus;
  iEvent.getByToken(tauToken_, taus);
  
  
  edm::Handle<edm::TriggerResults> triggerBits;//VARIABLE
  edm::Handle<pat::TriggerObjectStandAloneCollection> triggerObjects;//VARIABLE
  edm::Handle<pat::TriggerObjectStandAloneCollection> trigobj_handle;//VARIABLE
  edm::Handle<pat::PackedTriggerPrescales> triggerPrescales;//VARIABLE
  std::string full_name;
  iEvent.getByToken(triggerBits_, triggerBits);
  iEvent.getByToken(triggerObjects_, triggerObjects);
  iEvent.getByToken(triggerObjects_, trigobj_handle);
  iEvent.getByToken(triggerPrescales_, triggerPrescales);
  const edm::TriggerNames &names = iEvent.triggerNames(*triggerBits);//VARIABLE

  edm::Handle<pat::PackedCandidateCollection> pfs;
  iEvent.getByToken(pfToken_, pfs);
  edm::Handle<pat::PhotonCollection> photons;
  iEvent.getByToken(photonToken_, photons);
  
  
  float EventWeight = 1.0;
  edm::Handle<GenEventInfoProduct> gen_ev_info;
  iEvent.getByToken(genInfoProductToken, gen_ev_info);
  if(!gen_ev_info.isValid()) return;
  EventWeight = gen_ev_info->weight();
  
  edm::Handle<bool>   h_passMInvCut;
  edm::Handle<bool>   h_passPreFSRMInvCut;
  edm::Handle<bool>   h_passST1MInvCut;
  edm::Handle<bool>   h_passST23MInvCut;
  edm::Handle<bool>   h_passHSMInvCut;
  edm::Handle<double> h_xsWeight;


  iEvent.getByToken(m_passMInvCutToken,       h_passMInvCut);
  iEvent.getByToken(m_passPreFSRMInvCutToken, h_passPreFSRMInvCut);
  iEvent.getByToken(m_passST1MInvCutToken,    h_passST1MInvCut);
  iEvent.getByToken(m_passST23MInvCutToken,   h_passST23MInvCut);
  iEvent.getByToken(m_passHSMInvCutToken,     h_passHSMInvCut);
  iEvent.getByToken(m_xsWeightToken,          h_xsWeight);
 
//  bool passMInvCut = getHandle(h_passMInvCut);
//  bool passPreFSRMInvCut = getHandle(h_passPreFSRMInvCut);
//  bool passST1MInvCut = getHandle(h_passST1MInvCut);
//  bool passST23MInvCut = getHandle(h_passST23MInvCut);
//  bool passHSMInvCut = getHandle(h_passHSMInvCut);
//  double xsWeight = getHandle(h_xsWeight);
//
  edm::Handle<pat::MuonCollection> muons;//VARIABLE
  iEvent.getByToken(muonToken_, muons);
  
  edm::ESHandle<TransientTrackBuilder> ttkb1;//VARIABLE
  iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder", ttkb1);
  std::vector<reco::TransientTrack> ttv1;
  edm::ESHandle<TransientTrackBuilder> ttkb2;//VARIABLE
  iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder", ttkb2);
  std::vector<reco::TransientTrack> ttv2;
  edm::ESHandle<TransientTrackBuilder> ttkb3;//VARIABLE
  iSetup.get<TransientTrackRecord>().get("TransientTrackBuilder", ttkb3);
  std::vector<reco::TransientTrack> ttv3;
  //find the first high pt muon
  reco::TrackRef MuonBestTrack1;
  reco::TrackRef MuonBestTrack2;
  reco::TrackRef MuonBestTrack3;
  
  
     
  
  edm::Handle<reco::VertexCollection> pvHandle;
  iEvent.getByToken(vtxToken_,pvHandle);
  const reco::VertexCollection &verticesPointer = *pvHandle.product();//VARIABLE
  
  
  edm::Handle<pat::METCollection> mets;
  iEvent.getByToken(metToken_, mets);
  const pat::MET &met = mets->front();//VARIABLE
  
  
  //MC_weighting.clear(); //seems to not exist
  if(!gen_ev_info.isValid()) return;
  
  
  
  
  edm::Handle<reco::GenJetCollection> h_genjets;
  iEvent.getByToken( EDMGenJetsToken_,h_genjets );
  if (!(h_genjets.isValid())) return;
  std::vector<reco::GenJet> const &genjets = *h_genjets;//VARIABLE
  
  event.PatElectronTree(rhoIso, PV, getHandle(electrons),
                        getHandle(ecalEB), getHandle(ecalEE), *lazyTools_, getHandle(eleHandle));
  event.TriggerMatchingTree(getHandle(triggerBits), getHandle(triggerObjects), getHandle(trigobj_handle), getHandle(triggerPrescales), names);
  event.accessGenInfo(getHandle(h_passMInvCut), getHandle(h_passPreFSRMInvCut),  getHandle(h_passST1MInvCut), 
		      getHandle(h_passHSMInvCut), getHandle(h_passST23MInvCut), getHandle(h_xsWeight), getHandle(pruned), 
		      getHandle(packed), BosonID_, ParticleID1_, ParticleID2_, ParticleID3_, ParticleStatus_);
  event.PatMuonTree(PV, getHandle(muons));//THIS REUSES PV from Pat Electron Tree (USE SAME PV)		
  event.ComputeMuonMassVtx(getHandle(ttkb1), getHandle(ttkb2), getHandle(ttkb3),
			   PV, getHandle(muons));
    
  event.PrimaryVertexTree(verticesPointer);
  event.PrimaryVertex(verticesPointer, maxAbsZ_, maxd0_, minNdof_, NbGoodPv_);
  event.fillMET(met);
  event.GenJetTree(genjets);
  event.JetsTree(getHandle(jets));
  event.EventsReWeighting(EventWeight);
  event.ParticleFlowPhotonTree(getHandle(pfs), getHandle(photons));
  event.fillPU(getHandle(PupInfo));

  event.BtaggingTree(getHandle(jets), bDiscriminators_);
  event.TauTree(getHandle(taus));
  //==============================================
  //=        End of the main program             =
  //==============================================
  mytree->Fill();
}
// ------------ method called once each job just after ending the event loop  ------------
void MakeZprimeMiniAodTreeMC::endJob()
{
  // go to *OUR* root file and store histograms
  rootFile_->cd();
  mytree->Write();
  rootFile_->Close();
}
//define this as a plug-in
DEFINE_FWK_MODULE(MakeZprimeMiniAodTreeMC);



//====================================== the end of subrotines ======================================
/*
  [0] kgood=0,                   // channel ok, the energy and time measurement are reliable
  [1] kpoorreco,                 // the energy is available from the uncalibrechit, but approximate (bad shape, large chi2)
  [2] koutoftime,                // the energy is available from the uncalibrechit (sync reco), but the event is out of time
  [3] kfaultyhardware,           // the energy is available from the uncalibrechit, channel is faulty at some hardware level (e.g. noisy)
  [4] knoisy,                    // the channel is very noisy
  [5] kpoorcalib,                // the energy is available from the uncalibrechit, but the calibration of the channel is poor
  [6] ksaturated,                // saturated channel (recovery not tried)
  [7] kleadingedgerecovered,     // saturated channel: energy estimated from the leading edge before saturation
  [8] kNeighboursRecovered,      // saturated/isolated dead: energy estimated from neighbours
  [9] kTowerRecovered,           // channel in TT with no data link, info retrieved from Trigger Primitive
  [10] kDead,                     // channel is dead and any recovery fails
  [11] kKilled,                   // MC only flag: the channel is killed in the real detector
  [12] kTPSaturated,              // the channel is in a region with saturated TP
  [13] kL1SpikeFlag,              // the channel is in a region with TP with sFGVB = 0
  [14] kWeird,                    // the signal is believed to originate from an anomalous deposit (spike)
  [15] kDiWeird,                  // the signal is anomalous, and neighbors another anomalous signal
  [16] kHasSwitchToGain6,         // at least one data frame is in G6
  [17] kHasSwitchToGain1,         // at least one data frame is in G1
  [18] kUnknown                   // to ease the interface with functions returning flags.
*/
//====================================== The end of subrotines ======================================

