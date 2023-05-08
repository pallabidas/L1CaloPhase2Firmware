#include "algo_topJet.h"

GCTintTowers_t processInputLinksNegative(ap_uint<576> link_in[N_GCTPHI]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
//#pragma HLS inline 

  GCTintTowers_t GCTintTowers ;
  #pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0
   
  ap_uint<12> start = 0;

  for(loop i=0; i<N_GCTPHI; i++){
    start = 0 ;
    for(loop k=0; k<N_GCTETA+6; k++){
#pragma HLS UNROLL
        GCTintTowers.GCTtower[k][i].et = link_in[i].range(start+11, start) ;
        GCTintTowers.GCTtower[k][i].hoe = link_in[i].range(start+15, start+12) ;
        start += 16;
     }
  }

  return GCTintTowers;
}

GCTintTowers_t processInputLinksPositive(ap_uint<576> link_in[N_GCTPHI]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0

  GCTintTowers_t GCTintTowers ;
  #pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0

  ap_uint<12> start = 0;

  for(loop i=0; i<N_GCTPHI; i++){
    start = 0 + (N_GCTETA-6)*16;
    for(loop k=N_GCTETA-6; k<2*N_GCTETA; k++){
#pragma HLS UNROLL
        GCTintTowers.GCTtower[k-N_GCTETA+6][i].et = link_in[i].range(start+11, start) ;
        GCTintTowers.GCTtower[k-N_GCTETA+6][i].hoe = link_in[i].range(start+15, start+12) ;
        start += 16;
     }
  }

  return GCTintTowers;
}

void processST(ap_uint<32> gctST[N_ST], tower allTowers[N_STETA][N_STPHI]){
#pragma HLS ARRAY_PARTITION variable=gctST complete dim=0
#pragma HLS ARRAY_PARTITION variable=allTowers complete dim=0

  //ap_uint<32> start = 0;
  //ap_uint<32> end = 15;

  for(loop i=0; i<N_STETA; i++){
    for(loop j=0; j<N_STPHI; j++){
#pragma HLS UNROLL
      //start = j*32 ; end = start + 31 ;
      allTowers[i][j] = tower(gctST[i+N_STETA*j]);
    }
  }
}

barrelRegion_t initStructure(tower temporary[N_STETA][N_STPHI]){
#pragma HLS ARRAY_PARTITION variable=temporary complete dim=0

  ap_uint<5> Phi = 0 ;
  ap_uint<5> Eta = 0 ;
  
  barrelRegion_t out;
  
  out.etaStrip0.cr0.energy=temporary[Eta+0][Phi+0].energy; out.etaStrip0.cr0.eta=0; out.etaStrip0.cr0.phi=0;
  out.etaStrip0.cr1.energy=temporary[Eta+0][Phi+1].energy; out.etaStrip0.cr1.eta=0; out.etaStrip0.cr1.phi=1;
  out.etaStrip0.cr2.energy=temporary[Eta+0][Phi+2].energy; out.etaStrip0.cr2.eta=0; out.etaStrip0.cr2.phi=2;
  out.etaStrip0.cr3.energy=temporary[Eta+0][Phi+3].energy; out.etaStrip0.cr3.eta=0; out.etaStrip0.cr3.phi=3;
  out.etaStrip0.cr4.energy=temporary[Eta+0][Phi+4].energy; out.etaStrip0.cr4.eta=0; out.etaStrip0.cr4.phi=4;
  out.etaStrip0.cr5.energy=temporary[Eta+0][Phi+5].energy; out.etaStrip0.cr5.eta=0; out.etaStrip0.cr5.phi=5;
  out.etaStrip0.cr6.energy=temporary[Eta+0][Phi+6].energy; out.etaStrip0.cr6.eta=0; out.etaStrip0.cr6.phi=6;
  out.etaStrip0.cr7.energy=temporary[Eta+0][Phi+7].energy; out.etaStrip0.cr7.eta=0; out.etaStrip0.cr7.phi=7;
  out.etaStrip0.cr8.energy=temporary[Eta+0][Phi+8].energy; out.etaStrip0.cr8.eta=0; out.etaStrip0.cr8.phi=8;
  out.etaStrip0.cr9.energy=temporary[Eta+0][Phi+9].energy; out.etaStrip0.cr9.eta=0; out.etaStrip0.cr9.phi=9;
  out.etaStrip0.cr10.energy=temporary[Eta+0][Phi+10].energy; out.etaStrip0.cr10.eta=0; out.etaStrip0.cr10.phi=10;
  out.etaStrip0.cr11.energy=temporary[Eta+0][Phi+11].energy; out.etaStrip0.cr11.eta=0; out.etaStrip0.cr11.phi=11;
  
  out.etaStrip1.cr0.energy=temporary[Eta+1][Phi+0].energy; out.etaStrip1.cr0.eta=1; out.etaStrip1.cr0.phi=0;
  out.etaStrip1.cr1.energy=temporary[Eta+1][Phi+1].energy; out.etaStrip1.cr1.eta=1; out.etaStrip1.cr1.phi=1;
  out.etaStrip1.cr2.energy=temporary[Eta+1][Phi+2].energy; out.etaStrip1.cr2.eta=1; out.etaStrip1.cr2.phi=2;
  out.etaStrip1.cr3.energy=temporary[Eta+1][Phi+3].energy; out.etaStrip1.cr3.eta=1; out.etaStrip1.cr3.phi=3;
  out.etaStrip1.cr4.energy=temporary[Eta+1][Phi+4].energy; out.etaStrip1.cr4.eta=1; out.etaStrip1.cr4.phi=4;
  out.etaStrip1.cr5.energy=temporary[Eta+1][Phi+5].energy; out.etaStrip1.cr5.eta=1; out.etaStrip1.cr5.phi=5;
  out.etaStrip1.cr6.energy=temporary[Eta+1][Phi+6].energy; out.etaStrip1.cr6.eta=1; out.etaStrip1.cr6.phi=6;
  out.etaStrip1.cr7.energy=temporary[Eta+1][Phi+7].energy; out.etaStrip1.cr7.eta=1; out.etaStrip1.cr7.phi=7;
  out.etaStrip1.cr8.energy=temporary[Eta+1][Phi+8].energy; out.etaStrip1.cr8.eta=1; out.etaStrip1.cr8.phi=8;
  out.etaStrip1.cr9.energy=temporary[Eta+1][Phi+9].energy; out.etaStrip1.cr9.eta=1; out.etaStrip1.cr9.phi=9;
  out.etaStrip1.cr10.energy=temporary[Eta+1][Phi+10].energy; out.etaStrip1.cr10.eta=1; out.etaStrip1.cr10.phi=10;
  out.etaStrip1.cr11.energy=temporary[Eta+1][Phi+11].energy; out.etaStrip1.cr11.eta=1; out.etaStrip1.cr11.phi=11;
  
  out.etaStrip2.cr0.energy=temporary[Eta+2][Phi+0].energy; out.etaStrip2.cr0.eta=2; out.etaStrip2.cr0.phi=0;
  out.etaStrip2.cr1.energy=temporary[Eta+2][Phi+1].energy; out.etaStrip2.cr1.eta=2; out.etaStrip2.cr1.phi=1;
  out.etaStrip2.cr2.energy=temporary[Eta+2][Phi+2].energy; out.etaStrip2.cr2.eta=2; out.etaStrip2.cr2.phi=2;
  out.etaStrip2.cr3.energy=temporary[Eta+2][Phi+3].energy; out.etaStrip2.cr3.eta=2; out.etaStrip2.cr3.phi=3;
  out.etaStrip2.cr4.energy=temporary[Eta+2][Phi+4].energy; out.etaStrip2.cr4.eta=2; out.etaStrip2.cr4.phi=4;
  out.etaStrip2.cr5.energy=temporary[Eta+2][Phi+5].energy; out.etaStrip2.cr5.eta=2; out.etaStrip2.cr5.phi=5;
  out.etaStrip2.cr6.energy=temporary[Eta+2][Phi+6].energy; out.etaStrip2.cr6.eta=2; out.etaStrip2.cr6.phi=6;
  out.etaStrip2.cr7.energy=temporary[Eta+2][Phi+7].energy; out.etaStrip2.cr7.eta=2; out.etaStrip2.cr7.phi=7;
  out.etaStrip2.cr8.energy=temporary[Eta+2][Phi+8].energy; out.etaStrip2.cr8.eta=2; out.etaStrip2.cr8.phi=8;
  out.etaStrip2.cr9.energy=temporary[Eta+2][Phi+9].energy; out.etaStrip2.cr9.eta=2; out.etaStrip2.cr9.phi=9;
  out.etaStrip2.cr10.energy=temporary[Eta+2][Phi+10].energy; out.etaStrip2.cr10.eta=2; out.etaStrip2.cr10.phi=10;
  out.etaStrip2.cr11.energy=temporary[Eta+2][Phi+11].energy; out.etaStrip2.cr11.eta=2; out.etaStrip2.cr11.phi=11;
  
  out.etaStrip3.cr0.energy=temporary[Eta+3][Phi+0].energy; out.etaStrip3.cr0.eta=3; out.etaStrip3.cr0.phi=0;
  out.etaStrip3.cr1.energy=temporary[Eta+3][Phi+1].energy; out.etaStrip3.cr1.eta=3; out.etaStrip3.cr1.phi=1;
  out.etaStrip3.cr2.energy=temporary[Eta+3][Phi+2].energy; out.etaStrip3.cr2.eta=3; out.etaStrip3.cr2.phi=2;
  out.etaStrip3.cr3.energy=temporary[Eta+3][Phi+3].energy; out.etaStrip3.cr3.eta=3; out.etaStrip3.cr3.phi=3;
  out.etaStrip3.cr4.energy=temporary[Eta+3][Phi+4].energy; out.etaStrip3.cr4.eta=3; out.etaStrip3.cr4.phi=4;
  out.etaStrip3.cr5.energy=temporary[Eta+3][Phi+5].energy; out.etaStrip3.cr5.eta=3; out.etaStrip3.cr5.phi=5;
  out.etaStrip3.cr6.energy=temporary[Eta+3][Phi+6].energy; out.etaStrip3.cr6.eta=3; out.etaStrip3.cr6.phi=6;
  out.etaStrip3.cr7.energy=temporary[Eta+3][Phi+7].energy; out.etaStrip3.cr7.eta=3; out.etaStrip3.cr7.phi=7;
  out.etaStrip3.cr8.energy=temporary[Eta+3][Phi+8].energy; out.etaStrip3.cr8.eta=3; out.etaStrip3.cr8.phi=8;
  out.etaStrip3.cr9.energy=temporary[Eta+3][Phi+9].energy; out.etaStrip3.cr9.eta=3; out.etaStrip3.cr9.phi=9;
  out.etaStrip3.cr10.energy=temporary[Eta+3][Phi+10].energy; out.etaStrip3.cr10.eta=3; out.etaStrip3.cr10.phi=10;
  out.etaStrip3.cr11.energy=temporary[Eta+3][Phi+11].energy; out.etaStrip3.cr11.eta=3; out.etaStrip3.cr11.phi=11;
  
  out.etaStrip4.cr0.energy=temporary[Eta+4][Phi+0].energy; out.etaStrip4.cr0.eta=4; out.etaStrip4.cr0.phi=0;
  out.etaStrip4.cr1.energy=temporary[Eta+4][Phi+1].energy; out.etaStrip4.cr1.eta=4; out.etaStrip4.cr1.phi=1;
  out.etaStrip4.cr2.energy=temporary[Eta+4][Phi+2].energy; out.etaStrip4.cr2.eta=4; out.etaStrip4.cr2.phi=2;
  out.etaStrip4.cr3.energy=temporary[Eta+4][Phi+3].energy; out.etaStrip4.cr3.eta=4; out.etaStrip4.cr3.phi=3;
  out.etaStrip4.cr4.energy=temporary[Eta+4][Phi+4].energy; out.etaStrip4.cr4.eta=4; out.etaStrip4.cr4.phi=4;
  out.etaStrip4.cr5.energy=temporary[Eta+4][Phi+5].energy; out.etaStrip4.cr5.eta=4; out.etaStrip4.cr5.phi=5;
  out.etaStrip4.cr6.energy=temporary[Eta+4][Phi+6].energy; out.etaStrip4.cr6.eta=4; out.etaStrip4.cr6.phi=6;
  out.etaStrip4.cr7.energy=temporary[Eta+4][Phi+7].energy; out.etaStrip4.cr7.eta=4; out.etaStrip4.cr7.phi=7;
  out.etaStrip4.cr8.energy=temporary[Eta+4][Phi+8].energy; out.etaStrip4.cr8.eta=4; out.etaStrip4.cr8.phi=8;
  out.etaStrip4.cr9.energy=temporary[Eta+4][Phi+9].energy; out.etaStrip4.cr9.eta=4; out.etaStrip4.cr9.phi=9;
  out.etaStrip4.cr10.energy=temporary[Eta+4][Phi+10].energy; out.etaStrip4.cr10.eta=4; out.etaStrip4.cr10.phi=10;
  out.etaStrip4.cr11.energy=temporary[Eta+4][Phi+11].energy; out.etaStrip4.cr11.eta=4; out.etaStrip4.cr11.phi=11;
  
  out.etaStrip5.cr0.energy=temporary[Eta+5][Phi+0].energy; out.etaStrip5.cr0.eta=5; out.etaStrip5.cr0.phi=0;
  out.etaStrip5.cr1.energy=temporary[Eta+5][Phi+1].energy; out.etaStrip5.cr1.eta=5; out.etaStrip5.cr1.phi=1;
  out.etaStrip5.cr2.energy=temporary[Eta+5][Phi+2].energy; out.etaStrip5.cr2.eta=5; out.etaStrip5.cr2.phi=2;
  out.etaStrip5.cr3.energy=temporary[Eta+5][Phi+3].energy; out.etaStrip5.cr3.eta=5; out.etaStrip5.cr3.phi=3;
  out.etaStrip5.cr4.energy=temporary[Eta+5][Phi+4].energy; out.etaStrip5.cr4.eta=5; out.etaStrip5.cr4.phi=4;
  out.etaStrip5.cr5.energy=temporary[Eta+5][Phi+5].energy; out.etaStrip5.cr5.eta=5; out.etaStrip5.cr5.phi=5;
  out.etaStrip5.cr6.energy=temporary[Eta+5][Phi+6].energy; out.etaStrip5.cr6.eta=5; out.etaStrip5.cr6.phi=6;
  out.etaStrip5.cr7.energy=temporary[Eta+5][Phi+7].energy; out.etaStrip5.cr7.eta=5; out.etaStrip5.cr7.phi=7;
  out.etaStrip5.cr8.energy=temporary[Eta+5][Phi+8].energy; out.etaStrip5.cr8.eta=5; out.etaStrip5.cr8.phi=8;
  out.etaStrip5.cr9.energy=temporary[Eta+5][Phi+9].energy; out.etaStrip5.cr9.eta=5; out.etaStrip5.cr9.phi=9;
  out.etaStrip5.cr10.energy=temporary[Eta+5][Phi+10].energy; out.etaStrip5.cr10.eta=5; out.etaStrip5.cr10.phi=10;
  out.etaStrip5.cr11.energy=temporary[Eta+5][Phi+11].energy; out.etaStrip5.cr11.eta=5; out.etaStrip5.cr11.phi=11;
  
  out.etaStrip6.cr0.energy=temporary[Eta+6][Phi+0].energy; out.etaStrip6.cr0.eta=6; out.etaStrip6.cr0.phi=0;
  out.etaStrip6.cr1.energy=temporary[Eta+6][Phi+1].energy; out.etaStrip6.cr1.eta=6; out.etaStrip6.cr1.phi=1;
  out.etaStrip6.cr2.energy=temporary[Eta+6][Phi+2].energy; out.etaStrip6.cr2.eta=6; out.etaStrip6.cr2.phi=2;
  out.etaStrip6.cr3.energy=temporary[Eta+6][Phi+3].energy; out.etaStrip6.cr3.eta=6; out.etaStrip6.cr3.phi=3;
  out.etaStrip6.cr4.energy=temporary[Eta+6][Phi+4].energy; out.etaStrip6.cr4.eta=6; out.etaStrip6.cr4.phi=4;
  out.etaStrip6.cr5.energy=temporary[Eta+6][Phi+5].energy; out.etaStrip6.cr5.eta=6; out.etaStrip6.cr5.phi=5;
  out.etaStrip6.cr6.energy=temporary[Eta+6][Phi+6].energy; out.etaStrip6.cr6.eta=6; out.etaStrip6.cr6.phi=6;
  out.etaStrip6.cr7.energy=temporary[Eta+6][Phi+7].energy; out.etaStrip6.cr7.eta=6; out.etaStrip6.cr7.phi=7;
  out.etaStrip6.cr8.energy=temporary[Eta+6][Phi+8].energy; out.etaStrip6.cr8.eta=6; out.etaStrip6.cr8.phi=8;
  out.etaStrip6.cr9.energy=temporary[Eta+6][Phi+9].energy; out.etaStrip6.cr9.eta=6; out.etaStrip6.cr9.phi=9;
  out.etaStrip6.cr10.energy=temporary[Eta+6][Phi+10].energy; out.etaStrip6.cr10.eta=6; out.etaStrip6.cr10.phi=10;
  out.etaStrip6.cr11.energy=temporary[Eta+6][Phi+11].energy; out.etaStrip6.cr11.eta=6; out.etaStrip6.cr11.phi=11;
  
  out.etaStrip7.cr0.energy=temporary[Eta+7][Phi+0].energy; out.etaStrip7.cr0.eta=7; out.etaStrip7.cr0.phi=0;
  out.etaStrip7.cr1.energy=temporary[Eta+7][Phi+1].energy; out.etaStrip7.cr1.eta=7; out.etaStrip7.cr1.phi=1;
  out.etaStrip7.cr2.energy=temporary[Eta+7][Phi+2].energy; out.etaStrip7.cr2.eta=7; out.etaStrip7.cr2.phi=2;
  out.etaStrip7.cr3.energy=temporary[Eta+7][Phi+3].energy; out.etaStrip7.cr3.eta=7; out.etaStrip7.cr3.phi=3;
  out.etaStrip7.cr4.energy=temporary[Eta+7][Phi+4].energy; out.etaStrip7.cr4.eta=7; out.etaStrip7.cr4.phi=4;
  out.etaStrip7.cr5.energy=temporary[Eta+7][Phi+5].energy; out.etaStrip7.cr5.eta=7; out.etaStrip7.cr5.phi=5;
  out.etaStrip7.cr6.energy=temporary[Eta+7][Phi+6].energy; out.etaStrip7.cr6.eta=7; out.etaStrip7.cr6.phi=6;
  out.etaStrip7.cr7.energy=temporary[Eta+7][Phi+7].energy; out.etaStrip7.cr7.eta=7; out.etaStrip7.cr7.phi=7;
  out.etaStrip7.cr8.energy=temporary[Eta+7][Phi+8].energy; out.etaStrip7.cr8.eta=7; out.etaStrip7.cr8.phi=8;
  out.etaStrip7.cr9.energy=temporary[Eta+7][Phi+9].energy; out.etaStrip7.cr9.eta=7; out.etaStrip7.cr9.phi=9;
  out.etaStrip7.cr10.energy=temporary[Eta+7][Phi+10].energy; out.etaStrip7.cr10.eta=7; out.etaStrip7.cr10.phi=10;
  out.etaStrip7.cr11.energy=temporary[Eta+7][Phi+11].energy; out.etaStrip7.cr11.eta=7; out.etaStrip7.cr11.phi=11;
  
  return out ;
}

barreltp_t bestOf2(const barreltp_t& barreltp0, const barreltp_t& barreltp1) {
  barreltp_t x;
  x = (barreltp0.energy > barreltp1.energy)?barreltp0:barreltp1;
  return x;
}

barreltp_t getPeakBin12N(const etaStrip_t& etaStrip){
#pragma HLS latency min=4

  barreltp_t best01 = bestOf2(etaStrip.cr0,etaStrip.cr1) ;
  barreltp_t best23 = bestOf2(etaStrip.cr2,etaStrip.cr3) ;
  barreltp_t best45 = bestOf2(etaStrip.cr4,etaStrip.cr5) ;
  barreltp_t best67 = bestOf2(etaStrip.cr6,etaStrip.cr7) ;
  barreltp_t best89 = bestOf2(etaStrip.cr8,etaStrip.cr9) ;
  barreltp_t best1011 = bestOf2(etaStrip.cr10,etaStrip.cr11);
  
  barreltp_t best0123 = bestOf2(best01,best23) ;
  barreltp_t best4567 = bestOf2(best45,best67) ;
  barreltp_t best891011 = bestOf2(best89,best1011);
  
  barreltp_t best01234567 = bestOf2(best0123,best4567) ;
  
  barreltp_t best0to11 = bestOf2(best01234567,best891011) ;
  
  return best0to11 ;
}

towerMax getPeakBin8N(const etaStripPeak_t& etaStrip){
#pragma HLS latency min=4

  towerMax x;
  
  barreltp_t best01 = bestOf2(etaStrip.pk0,etaStrip.pk1) ;
  barreltp_t best23 = bestOf2(etaStrip.pk2,etaStrip.pk3) ;
  barreltp_t best45 = bestOf2(etaStrip.pk4,etaStrip.pk5) ;
  barreltp_t best67 = bestOf2(etaStrip.pk6,etaStrip.pk7) ;
  
  barreltp_t best0123 = bestOf2(best01,best23) ;
  
  barreltp_t best4567 = bestOf2(best45,best67) ;
  
  barreltp_t bestOf8 = bestOf2(best0123,best4567) ;
  
  x.energy = bestOf8.energy ;
  x.etaMax = bestOf8.eta ;
  x.phiMax = bestOf8.phi ;
  
  return x ;
}


jetInfo getJetPosition(const barrelRegion_t& barrelRegion){
#pragma HLS latency min=4

  etaStripPeak_t etaStripPeak;
  jetInfo jet ;
  
  etaStripPeak.pk0 = getPeakBin12N(barrelRegion.etaStrip0);
  etaStripPeak.pk1 = getPeakBin12N(barrelRegion.etaStrip1);
  etaStripPeak.pk2 = getPeakBin12N(barrelRegion.etaStrip2);
  etaStripPeak.pk3 = getPeakBin12N(barrelRegion.etaStrip3);
  etaStripPeak.pk4 = getPeakBin12N(barrelRegion.etaStrip4);
  etaStripPeak.pk5 = getPeakBin12N(barrelRegion.etaStrip5);
  etaStripPeak.pk6 = getPeakBin12N(barrelRegion.etaStrip6);
  etaStripPeak.pk7 = getPeakBin12N(barrelRegion.etaStrip7);
  
  towerMax peakIn8;
  peakIn8 = getPeakBin8N(etaStripPeak);
  
  jet.seedEnergy = peakIn8.energy ;
  jet.energy = 0 ;
  jet.etaMax = peakIn8.etaMax ;
  jet.phiMax = peakIn8.phiMax ;
  
  return jet ;
}

jetInfo getJetValues(tower tempX[N_STETA][N_STPHI], ap_uint<5> seed_eta,  ap_uint<5> seed_phi ){
#pragma HLS ARRAY_PARTITION variable=tempX complete dim=0
#pragma HLS latency min=6

  ap_uint<12> temp[N_STETA+2][N_STPHI+2] ;
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0

  ap_uint<12> eta_slice[3] ;
#pragma HLS ARRAY_PARTITION variable=eta_slice complete dim=0

  jetInfo jet_tmp;

  for(loop i=0; i<N_STETA+2; i++){
#pragma HLS UNROLL
    for(loop k=0; k<N_STPHI+2; k++){
#pragma HLS UNROLL
      temp[i][k] = 0 ;
    }
  }

  for(loop i=0; i<N_STETA; i++){
#pragma HLS UNROLL
    for(loop k=0; k<N_STPHI; k++){
#pragma HLS UNROLL
      temp[i+1][k+1] = tempX[i][k].energy ;
    }
  }

  ap_uint<5> seed_eta1,  seed_phi1 ;

  seed_eta1 = seed_eta ; //to start from corner
  seed_phi1 = seed_phi ; //to start from corner
  ap_uint<12> tmp1, tmp2, tmp3 ;

  for(loop j=0; j<N_STETA; j++){
    for(loop k=0; k<N_STPHI; k++){
#pragma HLS UNROLL
      if(j== seed_eta1 && k == seed_phi1){
        for(loop m=0; m<3 ; m++){
#pragma HLS UNROLL
          tmp1 = temp[j+m][k] ;
          tmp2 = temp[j+m][k+1] ;
          tmp3 = temp[j+m][k+2] ;
          eta_slice[m] = tmp1 + tmp2 + tmp3 ;
        }
      }
    }
  }

  jet_tmp.energy=eta_slice[0] + eta_slice[1] + eta_slice[2] ;

  for(loop i=0; i<N_STETA; i++){
    if(i+1>=seed_eta && i<=seed_eta+1){
      for(loop k=0; k<N_STPHI; k++){
#pragma HLS UNROLL
        if(k+1>=seed_phi && k<=seed_phi+1)  tempX[i][k].energy = 0 ;
      }
    }
  }

  return jet_tmp ;
}

jetInfo getRegion(tower temp[N_STETA][N_STPHI]){
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0
#pragma HLS latency min=24
  jetInfo jet_tmp, jet;
  
  barrelRegion_t test;
  
  test = initStructure(temp) ;
  
  jet_tmp = getJetPosition(test) ;
  
  ap_uint<5> seed_phi = jet_tmp.phiMax ;
  ap_uint<5> seed_eta = jet_tmp.etaMax ;
  jet = getJetValues(temp, seed_eta, seed_phi) ;
  
  jet_tmp.energy = jet.energy;
  
  return jet_tmp;
}

ap_uint<5> negGctEta(ap_uint<2> etaMax, ap_uint<2> phiMax, ap_uint<32> supertower[N_ST]){
#pragma HLS ARRAY_PARTITION variable=supertower complete dim=0
  ap_uint<5> index = etaMax + N_STETA*phiMax;
  ap_uint<5> out = 3*etaMax - 1 + supertower[index].range(13, 12);
  return out;
}

ap_uint<5> posGctEta(ap_uint<2> etaMax, ap_uint<2> phiMax, ap_uint<32> supertower[N_ST]){
#pragma HLS ARRAY_PARTITION variable=supertower complete dim=0
  ap_uint<5> index = etaMax + N_STETA*phiMax;
  ap_uint<5> out = 3*etaMax + 11 + supertower[index].range(13, 12);
  return out;
}

ap_uint<5> gctPhi(ap_uint<2> etaMax, ap_uint<2> phiMax, ap_uint<32> supertower[N_ST]){
#pragma HLS ARRAY_PARTITION variable=supertower complete dim=0
  ap_uint<5> index = etaMax + N_STETA*phiMax;
  ap_uint<5> out = 3*phiMax - 2 + supertower[index].range(15, 14);
  return out;
}

void algo_topJet(ap_uint<576> link_in[N_GCTPHI], ap_uint<576> link_out[N_OUTPUT_JET]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
#pragma HLS ARRAY_PARTITION variable=link_out complete dim=0
#pragma HLS PIPELINE II=9
#pragma HLS INTERFACE ap_ctrl_hs port=return

  GCTintTowers_t negativeGCTintTowers;
#pragma HLS ARRAY_PARTITION variable=negativeGCTintTowers complete dim=0

  GCTintTowers_t positiveGCTintTowers;
#pragma HLS ARRAY_PARTITION variable=positiveGCTintTowers complete dim=0

  negativeGCTintTowers = processInputLinksNegative(link_in);

  positiveGCTintTowers = processInputLinksPositive(link_in);

  ap_uint<32> negativeST[N_ST];
#pragma HLS ARRAY_PARTITION variable=negativeST complete dim=0

  ap_uint<32> positiveST[N_ST];
#pragma HLS ARRAY_PARTITION variable=positiveST complete dim=0

  makeST(negativeGCTintTowers, negativeST);

  makeST(positiveGCTintTowers, positiveST);

  tower negativeRegion[N_STETA][N_STPHI];
#pragma HLS ARRAY_PARTITION variable=negativeRegion complete dim=0

  processST(negativeST, negativeRegion);

  tower positiveRegion[N_STETA][N_STPHI];
#pragma HLS ARRAY_PARTITION variable=positiveRegion complete dim=0

  processST(positiveST, positiveRegion);

  jetInfo negative_jet[6];
  jetInfo positive_jet[6];

  //for(loop i=0; i<6; i++) negative_jet[i] = getRegion(negativeRegion);
  //for(loop i=0; i<6; i++) positive_jet[i] = getRegion(positiveRegion);

  for(loop i=0; i<6; i++){
#pragma HLS UNROLL
    negative_jet[i] = getRegion(negativeRegion);
    if((negative_jet[i].etaMax > 5) || (negative_jet[i].phiMax < 2) || (negative_jet[i].phiMax > 9)) {
      negative_jet[i].energy = 0;
    }
  }

  for(loop i=0; i<6; i++){
#pragma HLS UNROLL
    positive_jet[i] = getRegion(positiveRegion);
    if((positive_jet[i].etaMax < 2) || (positive_jet[i].phiMax < 2) || (positive_jet[i].phiMax > 9)) {
      positive_jet[i].energy = 0;
    }
  }

  ap_uint<12> bitHi1 = 0;
  ap_uint<12> bitLo1 = 0;
  ap_uint<12> bitHi2 = 0;
  ap_uint<12> bitLo2 = 0;
  ap_uint<12> bitHi3 = 0;
  ap_uint<12> bitLo3 = 0;

  for(loop i=0; i<N_JET_PERLINK; i++){
    bitLo1 = i*46 ;
    bitHi1 = bitLo1 + 11 ;
    link_out[0].range(bitHi1, bitLo1) = negative_jet[i].energy;
    link_out[1].range(bitHi1, bitLo1) = positive_jet[i].energy;
    bitLo2 = bitHi1 + 1;
    bitHi2 = bitLo2 + 4;
    link_out[0].range(bitHi2, bitLo2) = negGctEta(negative_jet[i].etaMax, negative_jet[i].phiMax, negativeST);
    link_out[1].range(bitHi2, bitLo2) = posGctEta(positive_jet[i].etaMax, positive_jet[i].phiMax, positiveST);
    bitLo3 = bitHi2 + 1;
    bitHi3 = bitLo3 + 4;
    link_out[0].range(bitHi3, bitLo3) = gctPhi(negative_jet[i].etaMax, negative_jet[i].phiMax, negativeST);
    link_out[1].range(bitHi3, bitLo3) = gctPhi(positive_jet[i].etaMax, positive_jet[i].phiMax, positiveST);
    //std::cout<<"pos: "<<link_out[0].range(bitHi1, bitLo1)<<"\t"<<link_out[0].range(bitHi2, bitLo2)<<"\t"<<link_out[0].range(bitHi3, bitLo3)<<std::endl;
    //std::cout<<"neg: "<<link_out[1].range(bitHi1, bitLo1)<<"\t"<<link_out[1].range(bitHi2, bitLo2)<<"\t"<<link_out[1].range(bitHi3, bitLo3)<<std::endl;
  }

}
