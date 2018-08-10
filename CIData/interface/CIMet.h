#ifndef CIMET_H
#define CIMET_H

//=========================
//CIMet header file 
//MHokinson - Aug 9
//This handles the Met values 
//in CIEvent 
//=========================

//Include any special Types 
#include "DataFormats/PatCandidates/interface/MET.h"

class CIMet
{
 public:
  //=======================
  //Constructors
  //=======================
  CIMet(){}
  CIMet(const pat::MET & met);

 private:
  //=======================
  //Values
  //=======================
  double gen_pt;
  //The default type1 corrected MET
  double et_cor;
  double pt_cor;
  double phi_cor;
  double en_cor;
  double px_cor;
  double py_cor;
  double pz_cor;
  double sumEt_cor;

  //Type I MET Uncertainties
  double shiftedPtJetEnUp;
  double shiftedPtJetEnDn;
  double shiftedPtEleEnUp;
  double shiftedPtEleEnDn;
  double shiftedPtMuEnUp;
  double shiftedPtMuEnDn;
  double shiftedPtJetResUp;
  double shiftedPtJetResDn;
  double shiftedPtUnclEnUp;
  double shiftedPtUnclEnDn;
  double shiftedPtPhoEnUp;
  double shiftedPtPhoEnDn;
  
  //The raw calo ETmiss
  double calo_pt;
  double calo_phi;
  double calo_sumEt;

  //double METSign;
  double shiftedPt_JetEnUp;
  double shiftedPt_JetEnDown;

  //VALUES NOT CURRENTLY USED 
  //The Raw PF Met (un-corrected MET)
  //double PFMet_pt_uncor;
  //double PFMet_phi_uncor;
  //double PFMet_sumEt_uncor;

  //double pfMETshiftedPtJetEnUpSmear;
  //double pfMETshiftedPtJetEnDnSmear;
  //double pfMETUncertaintySize;
  //double pfMETFullUncertaintySize;

  ClassDefNV(CIMet, 1)
};

#endif
