#ifndef CIEVENT_H
#define CIEVENT_H

//======================================================================
//CI Event Header File 
//Matthew Hokinson and John Woods 
//Date: July 19th, 2018
//Built to Simplify the existing MakeZprimeMiniAodTreeMC.cc file 
//======================================================================

//======================================================================
//Files to include (Same as the MakeZprimeMiniAodTreeMC header file)
//Can be cut down later 
//======================================================================

//Include the other CI Classes 
#include "CINtuple/CIData/interface/CIElectron.h"
#include "CINtuple/CIData/interface/CIGenParticles.h"
#include "CINtuple/CIData/interface/CIPhoton.h"
#include "CINtuple/CIData/interface/CIPrimaryVertex.h"
#include "CINtuple/CIData/interface/CIGenJets.h"
#include "CINtuple/CIData/interface/CITau.h"
#include "CINtuple/CIData/interface/CIJet.h"
#include "CINtuple/CIData/interface/CIBtags.h"
#include "CINtuple/CIData/interface/CIHLTrigger.h"
#include "CINtuple/CIData/interface/CIHLTObj.h"
#include "CINtuple/CIData/interface/CIMuonVtx.h"
#include "CINtuple/CIData/interface/CIMuon.h"
#include "CINtuple/CIData/interface/CIMet.h"
#include "CINtuple/CIData/interface/CIChosenLepton.h"
#include "CINtuple/CIData/interface/CICalculatedValues.h"

#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
//#include "DataFormats/?EgammaReco/?interface/?SuperClusterFwd.h"
//#include "CommonTools/?PileupAlgos/?plugins/?PuppiProducer.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"
#include "DataFormats/PatCandidates/interface/Electron.h"
#include "RecoEcal/EgammaCoreTools/interface/EcalClusterLazyTools.h"
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
#include "FWCore/Utilities/interface/InputTag.h"
#include "TTree.h"
#include <iostream>
#include <string>
#include <vector>

class CIEvent
{
  public:
  CIEvent() {}

  void PatElectronTree(double rhoIso, const reco::Vertex & PV, const pat::ElectronCollection & electron,
                        const EcalRecHitCollection & ecalEB, const EcalRecHitCollection & ecalEE, const EcalClusterLazyTools & lazyTools_,
                        const edm::View<pat::Electron> & eleHandle);

  void TriggerMatchingTree(const edm::TriggerResults & triggerBits, const pat::TriggerObjectStandAloneCollection & triggerObjects,
			   const pat::TriggerObjectStandAloneCollection & trigobj_handle,
			   const pat::PackedTriggerPrescales & triggerPrescales, const edm::TriggerNames & names);

  bool isAncestor(const reco::Candidate * ancestor, const reco::Candidate * particle);

  void accessGenInfo(bool h_passMInvCut, bool h_passPreFSRMInvCut, bool h_passST1MInvCut, bool h_passST23MInvCut,
		     bool h_passHSMInvCut, double h_xsWeight, const edm::View<reco::GenParticle> & pruned,
		     const edm::View<pat::PackedGenParticle> & packed, int BosonID_,  int ParticleID1_, int ParticleID2_, 
		     int ParticleID3_, int ParticleStatus_);
    
  void PatMuonTree(const reco::Vertex & PV, const pat::MuonCollection & muons);//THIS REUSES PV from Pat Electron Tree (USE SAME PV)		
    
  void ComputeMuonMassVtx(const TransientTrackBuilder & ttkb1, const TransientTrackBuilder & ttkb2, const TransientTrackBuilder & ttkb3,
			  const reco::Vertex & vertex, const pat::MuonCollection & muons);
    
  void PrimaryVertexTree(const reco::VertexCollection & vertices);
  bool PrimaryVertex(const reco::VertexCollection & vertices, double maxAbsZ_, double maxd0_, int minNdof_, int NbGoodPv_);
  void fillMET(const pat::MET & met);
  void GenJetTree(const std::vector<reco::GenJet> & genjets);
  void JetsTree(const pat::JetCollection & jetsC);
  void EventsReWeighting(float EventWeight);
  void ParticleFlowPhotonTree(const pat::PackedCandidateCollection & pfs, const pat::PhotonCollection & photons);
  void fillPU(const std::vector<PileupSummaryInfo> & PupInfo);
  
  void BtaggingTree(const std::vector<pat::Jet> & jets, const std::vector<std::string> & bDiscriminators_);
  void TauTree(const pat::TauCollection & tausC);
  void FillEventInfo(unsigned int JRun, unsigned int JEvent, unsigned int Jlumi, unsigned int Jbunch);

  //=============================================================
  //These are for Simplifying the Long IF statements  
  //=============================================================
  bool findTriggerMatch(const edm::TriggerNames & names, int index);
  bool findPathMatch(const std::vector<std::string> & pathnames, int index);
  std::vector<std::string> makeTriggerPathCombos();

  //================================
  //Finds the the two chosen leptons
  //================================
  void findChosenLeptons(const GenEventInfoProduct & genEventInfoProduct,
			 const edm::View<reco::GenParticle> & pruned,
			 bool isLR,
			 int lambda);
  bool findPassedMuons(CIMuonVtx & bestMuons);
  bool findPassedElectrons(CIElectron passedElectrons[]);

  //===============================
  //Finds the highest pt of leptons
  //===============================
  bool findIsMuon(const CIMuonVtx & bestMuons,
		  CIElectron passedElectrons[]);
  private:

    //This is called twice for both pt cuts by ComputeMuonMassVtx
    void computeMuonMassVertices(const TransientTrackBuilder & ttkb1, const TransientTrackBuilder & ttkb2, const TransientTrackBuilder & ttkb3,
				 const reco::Vertex & vertex, const pat::MuonCollection & muons, double ptCut, std::vector<CIMuonVtx> & vertices);

    //=============================================================
    //
    //           Create Branchs for Nb of event,run,lumi
    //
    //=============================================================
    unsigned int Run;
    unsigned int Event;
    unsigned int lumi;
    unsigned int bunch;
    //==================================================
    //
    //      Create vectors for Electrons variables
    //
    //==================================================
    std::vector<CIElectron> elec;

    //=============================================================
    //
    //           Create Branchs for Muons match HLT variables
    //
    //=============================================================
    std::vector<CIHLTrigger> hltValues;

    std::vector<CIHLTObj> hltObjValues;
     //=============================================================
    //
    //           Create Branchs for Pimary Vertice variables
    //
    //=============================================================
    std::vector<CIPrimaryVertex> pVertex;
    //====================================================
    //
    // Create vectors for Jets variables
    //
    //====================================================
    std::vector<CIJet> jets;
    //====================================================
    //
    // Create vectors for BTagging variables
    //
    //====================================================
    std::vector<CIBtags> jetBtags;
    //====================================================
    //
    // Create vectors for Taus variables
    //
    //====================================================
    std::vector<CITau> taus;
    //=============================================================
    //
    //           Create Branchs for PileUp tree
    //
    //=============================================================
    int num_PU_vertices;
    int PU_BunchCrossing;
    int num_PU_gen_vertices;
    //=============================================================
    //
    //           Create Branch for Rho
    //
    //=============================================================
    float Rho;
    //=============================================================
    //
    //           Create Branch for events reweighting
    //
    //=============================================================
    std::vector<float> MC_weighting;
    //===================================================
    //
    //    Create vectors for gen particles variables
    //
    //===================================================
    std::vector<CIGenParticles> genParticles;
    //=============================================================
    //
    //           Create tree variables for extra GEN level info
    //
    //=============================================================
    double xsWeight;
    bool   passPreFSRMInvCut;
    bool   passMInvCut;
    bool   passST1MInvCut;
    bool   passST23MInvCut;
    bool   passHSMInvCut;
    //==================================================
    //
    //           Create vectors for Muons variables
    //
    //==================================================
    std::vector<CIMuon> muData;

    std::vector<CIMuonVtx> muonVertices;
    std::vector<CIMuonVtx> muonVertices30;
    //=============================================================
    //
    //           Create Branches for PF MET
    //
    //=============================================================
    CIMet metData;
    //===================================================
    //
    //    Create vectors for gen Jets variables
    //
    //===================================================
    std::vector<CIGenJets> genJet;
    //===================================================
    //
    //    Create vectors for photons variables
    //
    //===================================================
    std::vector<CIPhoton> photon;
    //===================================================
    //
    //   Values for the two chosen Leptons (One for each)
    //
    //===================================================
    CIChosenLepton lepton1;
    CIChosenLepton lepton2;

    CICalculatedValues calcValues;

    
    ClassDefNV(CIEvent,1)
};

#endif


