//==============================
//CIBtags Source file 
//MHokinson - Aug 3 
//Handles all of the Jet-Tag
//values in CIEvent 
//==============================

//Include the Header file 
#include "CINtuple/CIData/interface/CIBtags.h"

//Include special types 
#include "DataFormats/PatCandidates/interface/Jet.h"

CIBtags::CIBtags(int bDiscriminatorsNumber, pat::Jet jet,
		       const std::string & bDiscr, int flavor):
  nb_bDiscriminators(bDiscriminatorsNumber),
  flavor(flavor),
  pfCSVv2IVF_discriminator(jet.bDiscriminator(bDiscr)),
  pt(jet.pt()),
  eta(jet.eta()),
  phi(jet.phi())
{}
