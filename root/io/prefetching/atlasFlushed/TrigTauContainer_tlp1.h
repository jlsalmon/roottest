//////////////////////////////////////////////////////////
//   This class has been generated by TFile::MakeProject
//     (Tue Jun 14 15:33:00 2011 by ROOT version 5.31/01)
//      from the StreamerInfo in file http://root.cern.ch/files/atlasFlushed.root
//////////////////////////////////////////////////////////


#ifndef TrigTauContainer_tlp1_h
#define TrigTauContainer_tlp1_h
class TrigTauContainer_tlp1;

#include "Riostream.h"
#include <vector>
#include "TrigTauContainer_p1.h"
#include "TrigTau_p2.h"
#include "P4PtEtaPhiM_p1.h"

class TrigTauContainer_tlp1 {

public:
// Nested classes declaration.

public:
// Data Members.
   vector<TrigTauContainer_p1> m_TrigTauContainers;    //(TrigTauContainer_p1)
   vector<TrigTau_p2>          m_Tau;                  //(TrigTau_p2)
   vector<P4PtEtaPhiM_p1>      m_P4PtEtaPhiM;          //(P4PtEtaPhiM_p1)

   TrigTauContainer_tlp1();
   TrigTauContainer_tlp1(const TrigTauContainer_tlp1 & );
   virtual ~TrigTauContainer_tlp1();

};
#endif