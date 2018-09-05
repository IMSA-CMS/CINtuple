//=========================
//CIMet header file 
//MHokinson - Aug 9
//This handles the Met values 
//in CIEvent 
//=========================

//Include the header file 
#include "CINtuple/CIData/interface/CIMet.h"

//Include any special Types 
#include "DataFormats/PatCandidates/interface/MET.h"

CIMet::CIMet(const pat::MET & met):
  et_cor(met.et()),
  pt_cor(met.pt()),
  phi_cor(met.phi()),
  en_cor(met.energy()),
  px_cor(met.px()),
  py_cor(met.py()),
  pz_cor(met.pz()),
  sumEt_cor(met.sumEt()),
  //Type I MET Uncertainties
  shiftedPtJetEnUp(met.shiftedPt(pat::MET::JetEnUp, pat::MET::Type1)),
  shiftedPtJetEnDn(met.shiftedPt(pat::MET::JetEnDown, pat::MET::Type1)),
  shiftedPtEleEnUp(met.shiftedPt(pat::MET::ElectronEnUp, pat::MET::Type1)),
  shiftedPtEleEnDn(met.shiftedPt(pat::MET::ElectronEnDown, pat::MET::Type1)),
  shiftedPtMuEnUp(met.shiftedPt(pat::MET::MuonEnUp, pat::MET::Type1)),
  shiftedPtMuEnDn(met.shiftedPt(pat::MET::MuonEnDown, pat::MET::Type1)),
  shiftedPtJetResUp(met.shiftedPt(pat::MET::JetResUp, pat::MET::Type1)),
  shiftedPtJetResDn(met.shiftedPt(pat::MET::JetResDown, pat::MET::Type1)),
  shiftedPtUnclEnUp(met.shiftedPt(pat::MET::UnclusteredEnUp, pat::MET::Type1)),
  shiftedPtUnclEnDn(met.shiftedPt(pat::MET::UnclusteredEnDown, pat::MET::Type1)),
  shiftedPtPhoEnUp(met.shiftedPt(pat::MET::PhotonEnUp, pat::MET::Type1)),
  shiftedPtPhoEnDn(met.shiftedPt(pat::MET::PhotonEnDown, pat::MET::Type1)),
  //The raw calo ETmiss
  calo_pt(met.caloMETPt()),
  calo_phi(met.caloMETPhi()),
  calo_sumEt(met.caloMETSumEt()),
  shiftedPt_JetEnUp(met.shiftedPt(pat::MET::JetEnUp)),
  shiftedPt_JetEnDown(met.shiftedPt(pat::MET::JetEnDown))
{
  if (met.genMET() != NULL ) gen_pt = met.genMET()->pt();

  //VALUES NOT CURRENTLY IN USE, CAN BE ADDED LATER 
  //pfMETshiftedPtJetEnUpSmear = met.shiftedPhi(pat::MET::METUncertainty::JetResUpSmear);
  //pfMETshiftedPtJetEnDnSmear = met.shiftedPt(pat::MET::JetResDownSmear, pat::MET::Type1Smear ) ;
  //pfMETUncertaintySize       = met.shiftedPt(pat::MET::METUncertaintySize, pat::MET::Type1 ) ;
  //pfMETFullUncertaintySize   = met.shiftedPt(pat::MET::METFullUncertaintySize, pat::MET::Type1 ) ;

  //The Raw PF Met (un-corrected MET in CMSSW_7_4_12 or later, on 74X version 2 miniAODs)
  /*PFMet_pt_uncor    = met.uncorPt();
    PFMet_phi_uncor   = met.uncorPhi();
    PFMet_en_uncor    = met.uncorEnergy();
    PFMet_px_uncor    = met.uncorPx();
    PFMet_py_uncor    = met.uncorPy();
    PFMet_pz_uncor    = met.uncorPz();
    PFMet_sumEt_uncor = met.uncorSumEt();
    //The Raw PF Met (un-corrected MET in CMSSW_7_4_11 or earlier, on 74X version 1 miniAODs)
    PFMet_pt_uncor    = met.uncorrectedPt();
    PFMet_phi_uncor   = met.uncorrectedPhi();
    PFMet_sumEt_uncor = met.uncorrectedSumEt();*/
}

