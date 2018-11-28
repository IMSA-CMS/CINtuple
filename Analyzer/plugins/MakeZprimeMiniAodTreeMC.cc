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

#include "CINtuple/Analyzer/interface/MakeZprimeMiniAodTreeMC.h"
#include "CINtuple/CIData/interface/CIEvent.h"

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

#include <iostream>

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
  //genEventInfoProductToken_(consumes<GenEventInfoProduct>(iConfig.getParameter<edm::InputTag>("generator")))
  //  genEventInfoProduct_(iConfig.getParameter<edm::InputTag>("generator")),
  //  genEventInfoProductToken_(consumes<GenEventInfoProduct,edm::InEvent>(genEventInfoProduct_))
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

  //Added for doing Helicity weighting 
  isLRHelicity = iConfig.getParameter<bool>("isLRHelicity");
  lambda = iConfig.getParameter<int>("lambda_");
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
}

void MakeZprimeMiniAodTreeMC::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  //==============================================
  //=        Begin of the main program           =
  //==============================================
  std::cout << __LINE__ << '\n';


  event.FillEventInfo(iEvent.id().run(), iEvent.id().event(), iEvent.luminosityBlock(), iEvent.bunchCrossing());
  edm::Handle<double> rhoIso_h;
  iEvent.getByToken(rhoIsoInputTag_, rhoIso_h);
  double rhoIso = *(rhoIso_h.product());//VARIABLE
  // primary vertex candidate collection
  edm::Handle<reco::VertexCollection> vertices;

  std::cout << __LINE__ << '\n';


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
  
  
  float EventWeight = 1.0;//HERE
  edm::Handle<GenEventInfoProduct> gen_ev_info;
  iEvent.getByToken(genInfoProductToken, gen_ev_info);
  if(!gen_ev_info.isValid()) return;
  EventWeight = gen_ev_info->weight();
  const GenEventInfoProduct& genEventInfoProduct = *gen_ev_info;
  
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

  std::cout << __LINE__ << '\n';
  
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

  std::cout << __LINE__ << '\n';
  
  
     
  
  edm::Handle<reco::VertexCollection> pvHandle;
  iEvent.getByToken(vtxToken_,pvHandle);
  const reco::VertexCollection &verticesPointer = *pvHandle.product();//VARIABLE
  
  
  edm::Handle<pat::METCollection> mets;
  iEvent.getByToken(metToken_, mets);
  const pat::MET &met = mets->front();//VARIABLE
  
  
  //MC_weighting.clear(); //seems to not exist
  if(!gen_ev_info.isValid()) return;

  std::cout << __LINE__ << '\n';
  
  
  
  
  edm::Handle<reco::GenJetCollection> h_genjets;
  iEvent.getByToken( EDMGenJetsToken_,h_genjets );
  if (!(h_genjets.isValid())) return;
  std::vector<reco::GenJet> const &genjets = *h_genjets;//VARIABLE

  std::cout << __LINE__ << '\n';
  
  event.PatElectronTree(rhoIso, PV, getHandle(electrons),
                        getHandle(ecalEB), getHandle(ecalEE), *lazyTools_, getHandle(eleHandle));
  event.TriggerMatchingTree(getHandle(triggerBits), getHandle(triggerObjects), getHandle(trigobj_handle), getHandle(triggerPrescales), names);

  std::cout << __LINE__ << '\n';


  event.accessGenInfo(getHandle(h_passMInvCut), getHandle(h_passPreFSRMInvCut),  getHandle(h_passST1MInvCut), 
		      getHandle(h_passHSMInvCut), getHandle(h_passST23MInvCut), getHandle(h_xsWeight), getHandle(pruned), 
		      getHandle(packed), BosonID_, ParticleID1_, ParticleID2_, ParticleID3_, ParticleStatus_);

  std::cout << __LINE__ << '\n';

  std::cout << "Here is where the error is happening\n";


  event.PatMuonTree(PV, getHandle(muons));//THIS REUSES PV from Pat Electron Tree (USE SAME PV)	

  std::cout << __LINE__ << '\n';

	
  event.ComputeMuonMassVtx(getHandle(ttkb1), getHandle(ttkb2), getHandle(ttkb3),
			   PV, getHandle(muons));

  std::cout << __LINE__ << '\n';
    
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

  std::cout << __LINE__ << '\n';


  std::cout << "Going into chosen lepton csiabrwuiabvrwka\n";

  // Object declaration using additional infromation //HERE
  //edm::Handle<GenEventInfoProduct> genEventInfoProductHandle;
  //iEvent.getByToken(genEventInfoProductToken_, genEventInfoProductHandle);
  //const GenEventInfoProduct& genEventInfoProduct = *genEventInfoProductHandle;

  event.findChosenLeptons(genEventInfoProduct, getHandle(pruned), isLRHelicity, lambda);
  //==============================================
  //=        End of the main program             =
  //==============================================
  mytree->Fill();

  std::cout << __LINE__ << '\n';
  std::cout << "bvrwuiabvewifbewyihvrbauggrwauivre\n";
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

