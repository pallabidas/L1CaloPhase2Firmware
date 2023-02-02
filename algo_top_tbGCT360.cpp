#include "algo_topGCT360.h"
#include <cstdlib>

int main(){

  GCTcard_t GCTcard ; 


  ap_uint<15> cluster[10];

  srand((unsigned)time(0));


  for(int i=0; i<N_RCTCARDS_PHI; i++){
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
      for(int k=0; k<N_RCTTOWERS_FIBER; k++){
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTtowers[k].et = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTtowers[k].et = 0 ;
      }
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta = 0 ;
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi = 0 ;
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta = 0 ;
        GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta = 0 ;
        GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi = 0 ;
      }
    }
  }

  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].et = 50 ;
  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].towEta = 2 ;
  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 3 ;
  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].crEta = 0 ;
  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 4 ;

  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].et = 100 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].towEta = 1 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 0 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].crEta = 4 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 0 ;
//  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[3].RCTtowers[7].et = 30 ;
//
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].et = 15 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].towEta = 4 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 0 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].crEta = 3 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 0 ;

  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].et = 20 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].towEta = 4 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 3 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].crEta = 4 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 4 ;
//  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[3].RCTtowers[7].et = 5 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].et = 40 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].towEta = 0 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].towPhi = 1 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].crEta = 0 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTclusters[1].crPhi = 4 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTtowers[1].et = 55 ;

  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].et = 10 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].towEta = 0 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].towPhi = 2 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].crEta = 0 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[0].RCTclusters[0].crPhi = 0 ;


  GCTcard.RCTcardEtaPos[0].RCTtoGCTfiber[2].RCTtowers[5].et = 11 ;
  GCTcard.RCTcardEtaPos[1].RCTtoGCTfiber[2].RCTtowers[5].et = 12 ;
  GCTcard.RCTcardEtaPos[2].RCTtoGCTfiber[2].RCTtowers[5].et = 13 ;
  GCTcard.RCTcardEtaPos[3].RCTtoGCTfiber[2].RCTtowers[5].et = 14 ;
  GCTcard.RCTcardEtaPos[4].RCTtoGCTfiber[2].RCTtowers[5].et = 15 ;

  GCTcard.RCTcardEtaNeg[0].RCTtoGCTfiber[1].RCTtowers[5].et = 21 ;
  GCTcard.RCTcardEtaNeg[1].RCTtoGCTfiber[1].RCTtowers[5].et = 22 ;
  GCTcard.RCTcardEtaNeg[2].RCTtoGCTfiber[1].RCTtowers[5].et = 23 ;
  GCTcard.RCTcardEtaNeg[3].RCTtoGCTfiber[1].RCTtowers[5].et = 24 ;
  GCTcard.RCTcardEtaNeg[4].RCTtoGCTfiber[1].RCTtowers[5].et = 25 ;

  GCTcard_t GCTcombinedClusters ;
  for(int i=0; i<N_RCTCARDS_PHI; i++){
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
        GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et  ;
        GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et  ;
      }
    }
  }

  for(int i=0; i<N_RCTCARDS_PHI-1; i=i+2){
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
        ap_uint<15> eta1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta*5+GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        ap_uint<15> phi1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        if(GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi == 3 && phi1 == 4){
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
              ap_uint<15> eta2 = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towEta*5+GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              ap_uint<15> phi2 = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi ;
              if( GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi == 0 && phi2 == 0) {
                ap_uint<15> dEta ; dEta=(eta1 > eta2)?(eta1-eta2):(eta2-eta1) ;
                if(dEta < 2) {
                  ap_uint<12> one = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTcombinedClusters.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ;
                  }
                  else {
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTcombinedClusters.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  for(int i=1; i<N_RCTCARDS_PHI-1; i=i+2){
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
        ap_uint<15> eta1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta*5+GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        ap_uint<15> phi1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        if(GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi == 3 && phi1 == 4) {
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
              ap_uint<15> eta2 = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towEta*5+GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              ap_uint<15> phi2 = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi ;
              if(GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi == 0 && phi2 == 0) {
                ap_uint<15> dEta ; dEta=(eta1 > eta2)?(eta1-eta2):(eta2-eta1) ;
                if(dEta <2) {
                  ap_uint<12> one = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcard.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTcombinedClusters.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ;
                  }
                  else {
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTcombinedClusters.RCTcardEtaPos[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  for(int i=0; i<N_RCTCARDS_PHI-1; i=i+2){
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
        ap_uint<15> eta1 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta*5+GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        ap_uint<15> phi1 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        if(GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi == 0 && phi1 == 0 ) {
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
              ap_uint<15> eta2 = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towEta*5+GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              ap_uint<15> phi2 = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi ;
              if(GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi == 3 && phi2 == 4 ) {
                ap_uint<15> dEta ; dEta=(eta1 > eta2)?(eta1-eta2):(eta2-eta1) ;
                if(dEta < 2) {
                  ap_uint<12> one = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTcombinedClusters.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ;
                  }
                  else {
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTcombinedClusters.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  for(int i=1; i<N_RCTCARDS_PHI-1; i=i+2){
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
        ap_uint<15> eta1 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta*5+GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        ap_uint<15> phi1 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        if(GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi == 0 && phi1 == 0 ) {
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
              ap_uint<15> eta2 = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towEta*5+GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              ap_uint<15> phi2 = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi ;
              if(GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi == 3 && phi2 == 4 ) {
                ap_uint<15> dEta ; dEta=(eta1 > eta2)?(eta1-eta2):(eta2-eta1) ;
                if(dEta < 2) {
                  ap_uint<12> one = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcard.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTcombinedClusters.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ;
                  }
                  else {
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTcombinedClusters.RCTcardEtaNeg[i+1].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  for(int i=0; i<N_RCTCARDS_PHI; i++){
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
        ap_uint<15> phi1 = (i*4+GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi)*5+GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi ;
        ap_uint<15> eta1 = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta ;
        if(GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta == 0 && eta1 == 0 ) {
          for(int j1=0; j1<N_RCTGCT_FIBERS; j1++){
            for(int k1=0; k1<N_RCTCLUSTERS_FIBER; k1++){
              ap_uint<15> phi2 = (i*4+(3-GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].towPhi))*5+(4-GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].crPhi) ;
              ap_uint<15> eta2 = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].crEta ;
              if(GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].towEta == 0 && eta2 == 0 ) {
                ap_uint<15> dPhi ; dPhi=(phi1 > phi2)?(phi1-phi2):(phi2-phi1) ;
                if(dPhi < 2) {
                  ap_uint<12> one = GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et ;
                  ap_uint<12> two = GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].et ;
                  if(one > two){
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = one + two ;
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].et = 0 ;
                  }
                  else {
                    GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et = 0 ;
                    GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j1].RCTclusters[k1].et = one + two ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  GCTinternal_t GCTinternal ;
  for(int i=0; i<N_RCTCARDS_PHI; i++){
    for(int j=0; j<N_RCTGCT_FIBERS; j++){
      for(int k=0; k<N_RCTCLUSTERS_FIBER; k++){
        GCTinternal.GCTCorrfiber[i*4+j].GCTclusters[k].et  = GCTcombinedClusters.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].et;
        GCTinternal.GCTCorrfiber[i*4+j].GCTclusters[k].towEtaNeg  = 0;
        GCTinternal.GCTCorrfiber[i*4+j].GCTclusters[k].towEta  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towEta;
        GCTinternal.GCTCorrfiber[i*4+j].GCTclusters[k].towPhi  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi+i*4;
        GCTinternal.GCTCorrfiber[i*4+j].GCTclusters[k].crEta  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crEta;
        GCTinternal.GCTCorrfiber[i*4+j].GCTclusters[k].crPhi  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi;
        GCTinternal.GCTCorrfiber[i*4+j].GCTclusters[k].satur  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].satur;
        GCTinternal.GCTCorrfiber[i*4+j].GCTclusters[k].brems = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTclusters[k].brems;

        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].et  = GCTcombinedClusters.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].et;
        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].towEtaNeg  = 1;
        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].towEta  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towEta;
        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].towPhi  = (3-GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].towPhi)+i*4;
        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].crEta  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crEta;
        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].crPhi  = (4-GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].crPhi);
        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].satur  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].satur;
        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTclusters[k].brems  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTclusters[k].brems;
      }
      for(int k=0; k<N_RCTTOWERS_FIBER; k++){
        GCTinternal.GCTCorrfiber[i*4+j].GCTtowers[k].et  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTtowers[k].et  ;
        GCTinternal.GCTCorrfiber[i*4+j].GCTtowers[k].hoe  = GCTcard.RCTcardEtaPos[i].RCTtoGCTfiber[j].RCTtowers[k].hoe  ;
        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTtowers[k].et  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTtowers[k].et  ;
        GCTinternal.GCTCorrfiber[i*4+(3-j)+N_GCTPOSITIVE_FIBERS].GCTtowers[k].hoe  = GCTcard.RCTcardEtaNeg[i].RCTtoGCTfiber[j].RCTtowers[k].hoe  ;
      }
    }
  }

  GCTintTowers_t GCTintTowers;
  for(int i=0; i<N_GCTPOSITIVE_FIBERS; i=i+4){
    for(int i1=0; i1<4; i1++){
      for(int k=0; k<N_GCTTOWERS_FIBER; k++){
        ap_uint<15> phi = i+i1 ;
        ap_uint<15> eta = N_GCTETA/2 + k ;
        GCTintTowers.GCTtower[eta][phi].et  = GCTinternal.GCTCorrfiber[phi].GCTtowers[k].et ;
        for(int ic1=0; ic1<4; ic1++){
          for(int jc=0; jc<N_GCTCLUSTERS_FIBER; jc++){
            ap_uint<15> eta1 = N_GCTETA/2 + GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].towEta ;
            ap_uint<15> phi1 = GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].towPhi ;
            if( eta == eta1 && phi == phi1) GCTintTowers.GCTtower[eta][phi].et  = GCTintTowers.GCTtower[eta][phi].et + GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].et ;
          }
        }
      }
    }
  }

  for(int i=N_GCTPOSITIVE_FIBERS; i<N_GCTINTERNAL_FIBERS; i=i+4){
    for(int i1=0; i1<4; i1++){
      for(int k=0; k<N_GCTTOWERS_FIBER; k++){
        ap_uint<15> eta = N_GCTETA/2 - k - 1 ;
        ap_uint<15> phi = i+i1-N_GCTPOSITIVE_FIBERS ;
        GCTintTowers.GCTtower[eta][phi].et  = GCTinternal.GCTCorrfiber[i+i1].GCTtowers[k].et ;
        for(int ic1=0; ic1<4; ic1++){
          for(int jc=0; jc<N_GCTCLUSTERS_FIBER; jc++){
            ap_uint<15> eta1 = N_GCTETA/2 - 1 - GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].towEta ;
            ap_uint<15> phi1 = GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].towPhi ;
            if( eta == eta1 && phi == phi1) GCTintTowers.GCTtower[eta][phi].et  = GCTintTowers.GCTtower[eta][phi].et + GCTinternal.GCTCorrfiber[i+ic1].GCTclusters[jc].et ;
          }
        }
      }
    }
  }
/////////////////////////// GOT GCTintTowers /////////////////////////////

  GCTpfcluster_t TotalPfcluster[48];
  
  algo_topGCT360(GCTintTowers, TotalPfcluster);


  cout << "printing pfclusters et, eta, phi" << endl;

  for(loop i = 0; i < 24; i++){
    cout << "pfcluster " << i << " in positive eta: " << TotalPfcluster[i].et << " " << TotalPfcluster[i].eta << " " << TotalPfcluster[i].phi << endl;
    cout << "pfcluster " << i << " in negative eta: " << TotalPfcluster[24+i].et << " " << TotalPfcluster[24+i].eta << " " << TotalPfcluster[24+i].phi << endl;
  }


  return 0;
}
