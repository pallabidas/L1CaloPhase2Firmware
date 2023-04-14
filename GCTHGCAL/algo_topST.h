#ifndef _ALGO_TOPST_H_
#define _ALGO_TOPST_H_

#include <iostream>
#include "ap_int.h"
#include <algorithm>
#include <utility>
#include <stdint.h>
//#include "algo_top_parameters.h"

#define N_GCTPHI 32  // half-GCT
#define N_GCTETA 17
#define N_STPHI 10
#define N_STETA 6
#define N_ST 60
#define N_OUTPUT_ST 4
#define N_ST_PERLINK 15

using namespace std;

typedef ap_uint<8> loop;

typedef struct {
ap_uint<12> et ;
ap_uint<4> hoe ;
} GCTtower_t ;

typedef struct {
GCTtower_t GCTtower[N_GCTETA][N_GCTPHI] ;
} GCTintTowers_t ;

//class towerMax{
//    public:
//    ap_uint<12> energy;
//    ap_uint<5> phiMax;
//    ap_uint<5> etaMax;
//
//    towerMax(){
//        energy = 0;
//        phiMax = 0;
//        etaMax = 0;
//    }
//
//    towerMax& operator=(const towerMax& rhs){
//        energy = rhs.energy;
//        phiMax = rhs.phiMax;
//        etaMax = rhs.etaMax;
//        return *this;
//    }
//};

class tower{
    public:
    ap_uint<12> energy;
    ap_uint<6> timing;

    tower(){
        energy = 0;
        timing = 0;
    }

    tower(ap_uint<18> i){
    	this->energy = i.range(11, 0);
    	this->timing = i.range(17, 12);
    }

    tower& operator=(const tower& rhs){
        energy = rhs.energy;
        timing = rhs.timing;
        return *this;
    }
};

//class jetInfo{
//    public:
//    ap_uint<12> seedEnergy;
//    ap_uint<12> energy;
//    ap_uint<5> phiMax;
//    ap_uint<5> etaMax;
//
//    jetInfo(){
//        seedEnergy = 0;
//        energy = 0;
//        phiMax = 0;
//        etaMax = 0;
//    }
//
//    jetInfo& operator=(const jetInfo& rhs){
//        seedEnergy = rhs.seedEnergy;
//        energy = rhs.energy;
//        phiMax = rhs.phiMax;
//        etaMax = rhs.etaMax;
//        return *this;
//    }
//};

void algo_topST(ap_uint<576> link_in[N_GCTPHI], ap_uint<576> link_out[N_OUTPUT_ST]);

void makeST(const GCTintTowers_t& GCTintTowers, ap_uint<32> barrelST[N_ST]);

//typedef struct {
//    ap_uint<12> energy;
//    ap_uint<6> timing;
//    ap_uint<5> phi;
//    ap_uint<5> eta;
//} hgcaltp_t ;
//
//typedef struct {
//hgcaltp_t cr0;
//hgcaltp_t cr1 ;
//hgcaltp_t cr2 ;
//hgcaltp_t cr3 ;
//hgcaltp_t cr4 ;
//hgcaltp_t cr5 ;
//hgcaltp_t cr6 ;
//hgcaltp_t cr7 ;
//hgcaltp_t cr8 ;
//hgcaltp_t cr9 ;
//hgcaltp_t cr10 ;
//hgcaltp_t cr11 ;
//hgcaltp_t cr12 ;
//hgcaltp_t cr13 ;
//hgcaltp_t cr14 ;
//hgcaltp_t cr15 ;
//hgcaltp_t cr16 ;
//hgcaltp_t cr17 ;
//hgcaltp_t cr18 ;
//hgcaltp_t cr19 ;
//hgcaltp_t cr20 ;
//hgcaltp_t cr21 ;
//hgcaltp_t cr22 ;
//hgcaltp_t cr23 ;
//} etaStrip_t ;
//
//typedef struct {
//etaStrip_t etaStrip0 ;
//etaStrip_t etaStrip1 ;
//etaStrip_t etaStrip2 ;
//etaStrip_t etaStrip3 ;
//etaStrip_t etaStrip4 ;
//etaStrip_t etaStrip5 ;
//} hgcalRegion_t ;
//
//typedef struct {
//hgcaltp_t pk0;
//hgcaltp_t pk1;
//hgcaltp_t pk2;
//hgcaltp_t pk3;
//hgcaltp_t pk4;
//hgcaltp_t pk5;
//} etaStripPeak_t ;


#endif


