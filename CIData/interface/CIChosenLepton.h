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

class CIChosenLepton
{
 public:
  //===============
  //Constructors
  //===============
  CIChosenLepton(double pPt, double pPhi, double pEta, 
		 double pCharge, bool pIsMuon);

 private:
  //===============
  //Class values
  //===============
  double pt;
  double phi;
  double eta;
  double charge;
  bool isMuon;
  
};
