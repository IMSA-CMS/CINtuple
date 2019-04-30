//=========================
//CIChosenLepton source file 
//MHokinson - Aug 9th 
//This will contain the data
//for the chosen leptons
//(There will be two of these
//in CIEvent)
//=========================

//Include the header file 
#include "CINtuple/CIData/interface/CIChosenLepton.h"

CIChosenLepton::CIChosenLepton(const CIElectron & el):
  pt(el.getPt()),
  phi(el.getPhi()),
  eta(el.getEta()),
  charge(el.getCharge()),
  et(el.getEt()),
  en(el.getEn()),
  isMuon(false),
  isEmpty(false)
{
  classifyBarrel();
  classifyEndcap();
}

CIChosenLepton::CIChosenLepton(const CIMuon & mu):
  pt(mu.getPtTune()),
  phi(mu.getPhiTune()),
  eta(mu.getEtaTune()),
  charge(mu.getCharge()),
  et(mu.getEt()),
  en(mu.getEn()),
  isMuon(true),
  isEmpty(false)
{
  std::cout << " We have set a chosen muon\n P.S. John is big Dumb and Matt is Biggest Dumb Jay is Big Mess up our code boi\n";
  std::cout << "Ayan is also a big dummy!Ayan is also a big dummy!Ayan is also a big dummy!Ayan is also a big dummy!Ayan is also a big dummy!\n";
  classifyBarrel();
  classifyEndcap();
}

CIChosenLepton::CIChosenLepton(int bad):
  pt(bad),
  phi(bad),
  eta(bad),
  charge(bad),
  et(bad),
  en(bad),
  isMuon(false),
  isEmpty(true),
  isBarrel(false),
  isEndcap(false)
{
}

//Printing functions 
void CIChosenLepton::print()
{
  std::cout << "pt: " << pt << "\nphi: " << phi << "\n isItEmpty: " << isEmpty << "\n";
}

CIChosenLepton CIChosenLepton::setBadValues()
{
  return CIChosenLepton(-1);
}


//determines if the chosen lepton is barrel
void CIChosenLepton::classifyBarrel()
{
  if (isMuon)
    {
      if (eta < 1.2 && eta > -1.2)
	isBarrel = true;
      else
	isBarrel = false;
    }
  else
    {
      if (eta < 1.4442 && eta > -1.4442)
	isBarrel = true;
      else
	isBarrel = false;
    }
  std::cout << "\nisBarrel = " << isBarrel;
}

//determines if the chosen lepton is endcap
void CIChosenLepton::classifyEndcap()
{
  std::cout << eta;
  if (isMuon)
    {
      if (eta > 1.2 && eta < -1.2)
	isEndcap = true;
      else
	isEndcap = false;
    }
  else
    {
      if (eta > 1.562 && eta < -1.562)
	isEndcap = true;
      else
	isEndcap = false;
    }
  std::cout << "\nisEndcap = " << isEndcap;
}


