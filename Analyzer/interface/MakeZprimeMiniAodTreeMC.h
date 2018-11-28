#ifndef MAKEZPRIMEMINIAODTREEMC_H
#define MAKEZPRIMEMINIAODTREEMC_H

#include "FWCore/Framework/interface/stream/EDAnalyzer.h"
#include "FWCore/Utilities/interface/EDGetToken.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
//#include "DataFormats/?EgammaReco/?interface/?SuperClusterFwd.h"
//#include "CommonTools/?PileupAlgos/?plugins/?PuppiProducer.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
//#include "DataFormats/?EcalRecHit/?interface/?EcalRecHitCollections.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h"
#include "FWCore/Framework/interface/stream/EDAnalyzer.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "CINtuple/CIData/interface/CIEvent.h"
#include "TTree.h"
#include <iostream>
#include <string>



namespace edm
{
  class ParameterSet;
  class Event;
  class EventSetup;
}

class TFile;

class MakeZprimeMiniAodTreeMC : public edm::EDAnalyzer {
public:
  explicit MakeZprimeMiniAodTreeMC(const edm::ParameterSet&);
  ~MakeZprimeMiniAodTreeMC();
  MakeZprimeMiniAodTreeMC() {}
  void PatElectronTree(const edm::Event& iEvent,const edm::EventSetup& es);
    void TriggerMatchingTree(const edm::Event& iEvent,const edm::EventSetup& es);
    bool isAncestor(const reco::Candidate * ancestor, const reco::Candidate * particle);
    void accessGenInfo(const edm::Event& iEvent,const edm::EventSetup& es);
    void EBecalRecHitsTree(const edm::Event& iEvent,const edm::EventSetup& es);
    void EEecalRecHitsTree(const edm::Event& iEvent,const edm::EventSetup& es);
    void PatMuonTree(const edm::Event& evt,const edm::EventSetup& es);
    void SuperClusterTree(const edm::Event& iEvent,const edm::EventSetup& es);
    void ComputeMuonMassVtx(const edm::Event& evt,const edm::EventSetup& es);
    void ComputeMuonMassVtx30GeV(const edm::Event& evt,const edm::EventSetup& es);
    void PrimaryVertexTree(const edm::Event& iEvent,const edm::EventSetup& es);
    bool PrimaryVertex(const reco::VertexCollection &vertices);
    void fillMET(const edm::Event& iEvent);
    void GenJetTree(const edm::Event& iEvent);
    void JetsTree(const edm::Event& iEvent,const edm::EventSetup& es);
    void EventsReWeighting(const edm::Event& evt);
    void ParticleFlowPhotonTree(const edm::Event& iEvent,const edm::EventSetup& es);
    void fillPU(const edm::Event& iEvent);
    void fillRho(const edm::Event& evt);
    void BtaggingTree(const edm::Event& iEvent);
    void TauTree(const edm::Event& iEvent);

  	//=============================================================
  	//These are for Simplifying the Long IF statements  
		//=============================================================
    bool findTriggerMatch(const edm::TriggerNames names, const edm::Handle<edm::TriggerResults> triggerBits, int index);
    bool findPathMatch(const std::vector<std::string> pathnames, int index);
    std::vector<std::string> makeTriggerPathCombos();

private:
  
    template<template<typename> class H, typename T>
  T getHandle(H<T> handle);
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void beginJob() override;
  virtual void endJob() override;
  TTree* mytree;
  edm::EDGetTokenT<edm::View<pat::Electron> > eleToken_;
  // ----------member data ---------------------------   //
  edm::EDGetTokenT<double> rhoToken;
  edm::EDGetTokenT<GenEventInfoProduct> genInfoProductToken;
  edm::EDGetTokenT<bool>   m_passMInvCutToken, m_passPreFSRMInvCutToken, m_passST1MInvCutToken, m_passST23MInvCutToken, m_passHSMInvCutToken;
  edm::EDGetTokenT<double> m_xsWeightToken;
  edm::EDGetTokenT<reco::GenJetCollection> EDMGenJetsToken_;
  edm::EDGetTokenT<reco::SuperClusterCollection> scProducer_;
  edm::EDGetTokenT<reco::VertexCollection> vtxToken_;
  edm::EDGetTokenT<pat::MuonCollection> muonToken_;
  edm::EDGetTokenT<pat::ElectronCollection> electronToken_;
  edm::EDGetTokenT<pat::TauCollection> tauToken_;
  edm::EDGetTokenT<pat::PhotonCollection> photonToken_;
  edm::EDGetTokenT<pat::JetCollection> jetToken_;
  edm::EDGetTokenT<pat::METCollection> metToken_;
  edm::EDGetTokenT<edm::View<reco::GenParticle> > prunedGenToken_;
  edm::EDGetTokenT<edm::View<pat::PackedGenParticle> > packedGenToken_;
  edm::EDGetTokenT<EcalRecHitCollection> tok_EB_;
  edm::EDGetTokenT<EcalRecHitCollection> tok_EE_;
  edm::EDGetTokenT<EcalRecHitCollection> ecalRechitEBToken_;
  edm::EDGetTokenT<EcalRecHitCollection> ecalRechitEEToken_;
  edm::EDGetTokenT<double> rhoIsoInputTag_;
  edm::EDGetTokenT<edm::TriggerResults> triggerBits_;
  edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> triggerObjects_;
  edm::EDGetTokenT<pat::PackedTriggerPrescales> triggerPrescales_;
  edm::EDGetTokenT<pat::PackedCandidateCollection> pfToken_;
  edm::EDGetTokenT<std::vector<PileupSummaryInfo> > PileupSrc_;
  const std::vector<std::string> bDiscriminators_;

  CIEvent event;

  int BosonID_;
  int ParticleID1_;
  int ParticleID2_;
  int ParticleID3_;
  int ParticleStatus_;
  double maxAbsZ_;
  double maxd0_;
  int minNdof_;
  int NbGoodPv_;

  bool isLRHelicity;
  int lambda;

  //=============================================================
  TFile*  rootFile_;
  std::string outputFile_; // output file
  edm::InputTag genEventInfoProduct_;
  edm::EDGetTokenT<GenEventInfoProduct> genEventInfoProductToken_;
};

template<template<typename> class H, typename T>
  inline T MakeZprimeMiniAodTreeMC::getHandle(H<T> handle)
   {
     if (!handle.isValid())
       {
	 edm::LogWarning("CIEvent.h") << "Handle not valid!";
       }
     return *handle;
   }

#endif
