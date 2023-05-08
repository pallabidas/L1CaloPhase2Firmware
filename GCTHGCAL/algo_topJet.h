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
#define N_STPHI 12 //10
#define N_STETA 8 //6
//#define N_ST 60
#define N_ST 96
//#define N_OUTPUT_ST 4
//#define N_ST_PERLINK 15
#define N_OUTPUT_JET 2
#define N_JET_PERLINK 6

using namespace std;

typedef ap_uint<8> loop;

typedef struct {
ap_uint<12> et ;
ap_uint<4> hoe ;
} GCTtower_t ;

typedef struct {
//GCTtower_t GCTtower[N_GCTETA][N_GCTPHI] ;
GCTtower_t GCTtower[N_GCTETA+6][N_GCTPHI];
} GCTintTowers_t ;

class towerMax{
    public:
    ap_uint<12> energy;
    ap_uint<5> phiMax;
    ap_uint<5> etaMax;

    towerMax(){
        energy = 0;
        phiMax = 0;
        etaMax = 0;
    }

    towerMax& operator=(const towerMax& rhs){
        energy = rhs.energy;
        phiMax = rhs.phiMax;
        etaMax = rhs.etaMax;
        return *this;
    }
};

class tower{
    public:
    ap_uint<12> energy;
    ap_uint<2> peakEta;
    ap_uint<2> peakPhi;
    ap_uint<12> peakEt;
    ap_uint<4> timing;

    tower(){
        energy = 0;
        peakEta = 0;
        peakPhi = 0;
        peakEt = 0;
        timing = 0;
    }

    tower(ap_uint<32> i){
    	this->energy = i.range(11, 0);
        this->peakEta = i.range(13, 12);
        this->peakPhi = i.range(15, 14);
        this->peakEt = i.range(27, 16);
    	this->timing = i.range(31, 28);
    }

    tower& operator=(const tower& rhs){
        energy = rhs.energy;
        peakEta = rhs.peakEta;
        peakPhi = rhs.peakPhi;
        peakEt = rhs.peakEt;
        timing = rhs.timing;
        return *this;
    }
};

class jetInfo{
    public:
    ap_uint<12> seedEnergy;
    ap_uint<12> energy;
    ap_uint<5> phiMax;
    ap_uint<5> etaMax;

    jetInfo(){
        seedEnergy = 0;
        energy = 0;
        phiMax = 0;
        etaMax = 0;
    }

    jetInfo& operator=(const jetInfo& rhs){
        seedEnergy = rhs.seedEnergy;
        energy = rhs.energy;
        phiMax = rhs.phiMax;
        etaMax = rhs.etaMax;
        return *this;
    }
};

//void algo_topST(ap_uint<576> link_in[N_GCTPHI], ap_uint<576> link_out[N_OUTPUT_JET]);
void algo_topJet(ap_uint<576> link_in[N_GCTPHI], ap_uint<576> link_out[N_OUTPUT_JET]);

void makeST(const GCTintTowers_t& GCTintTowers, ap_uint<32> barrelST[N_ST]);

typedef struct {
    ap_uint<12> energy;
    ap_uint<6> timing;
    ap_uint<5> phi;
    ap_uint<5> eta;
} barreltp_t ;

typedef struct {
barreltp_t cr0;
barreltp_t cr1 ;
barreltp_t cr2 ;
barreltp_t cr3 ;
barreltp_t cr4 ;
barreltp_t cr5 ;
barreltp_t cr6 ;
barreltp_t cr7 ;
barreltp_t cr8 ;
barreltp_t cr9 ;
barreltp_t cr10 ;
barreltp_t cr11 ;
} etaStrip_t ;

typedef struct {
etaStrip_t etaStrip0 ;
etaStrip_t etaStrip1 ;
etaStrip_t etaStrip2 ;
etaStrip_t etaStrip3 ;
etaStrip_t etaStrip4 ;
etaStrip_t etaStrip5 ;
etaStrip_t etaStrip6 ;
etaStrip_t etaStrip7 ;
} barrelRegion_t ;

typedef struct {
barreltp_t pk0;
barreltp_t pk1;
barreltp_t pk2;
barreltp_t pk3;
barreltp_t pk4;
barreltp_t pk5;
barreltp_t pk6;
barreltp_t pk7;
} etaStripPeak_t ;


#endif


