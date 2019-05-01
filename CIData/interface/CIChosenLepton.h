#ifndef CICHOSENLEPTON_H
#define CICHOSENLEPTON_H

//=========================
//CIChosenLepton header file 
//MHokinson - Aug 9th 
//This will contain the data
//for the chosen leptons
//(There will be two of these
//in CIEvent)
//=========================
#include "CINtuple/CIData/interface/CIMuon.h"
#include "CINtuple/CIData/interface/CIElectron.h"
#include <iostream>



class CIChosenLepton
{
 public:
  //===============
  //Constructors
  //===============
  CIChosenLepton() {}

  CIChosenLepton(const CIElectron & el);

  CIChosenLepton(const CIMuon & mu);

  CIChosenLepton(int bad);

  //===============
  //Classifying functions
  //===============
  void classifyBarrel();
  void classifyEndcap();
  void print();
  
  //===============
  //Get functions
  //===============
  double getEta() const {return eta;}
  double getPt() const {return pt;}
  double getPhi() const {return phi;}
  double getCharge() const {return charge;}
  double getEt() const {return et;}
  double getEn() const {return en;}
  bool getIsMuon() const {return isMuon;}
  bool getIsEmpty() const {return isEmpty;}
  bool getIsBarrel() const {return isBarrel;}
  bool getIsEndcap() const {return isEndcap;}

  void johnsCodeWas700LinesLong() { std::cout << "JOHNSCODEWAS605LINESLONG"; } //Important
 
  static CIChosenLepton setBadValues();

 private:

  //===============
  //Class values
  //===============
  double pt;
  double phi;
  double eta;
  double charge;
  double et;
  double en;
  bool isMuon;
  bool isEmpty;
  bool isBarrel; 
  bool isEndcap;
  

  ClassDefNV(CIChosenLepton, 1)
};

#endif
