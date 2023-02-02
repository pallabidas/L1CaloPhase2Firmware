#include "algo_topGCT360.h"

void makePfclusters(const GCTintTowers_t& GCTintTowers, GCTpfcluster_t TotalPfcluster[48]){
#pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0
#pragma HLS ARRAY_PARTITION variable=TotalPfcluster complete dim=0
#pragma HLS latency min=463

  ap_uint<12> temporary1[21][8];
#pragma HLS ARRAY_PARTITION variable=temporary1  complete dim=0
  ap_uint<12> temporary2[21][8];
#pragma HLS ARRAY_PARTITION variable=temporary2  complete dim=0
  ap_uint<12> temporary3[21][8];
#pragma HLS ARRAY_PARTITION variable=temporary3  complete dim=0
  ap_uint<12> temporary6[21][8];
#pragma HLS ARRAY_PARTITION variable=temporary6  complete dim=0
  ap_uint<12> temporary7[21][8];
#pragma HLS ARRAY_PARTITION variable=temporary7  complete dim=0
  ap_uint<12> temporary8[21][8];
#pragma HLS ARRAY_PARTITION variable=temporary8  complete dim=0

  for(loop i=0; i<21; i++){
    for(loop j=0; j<8; j++){
#pragma HLS unroll
      temporary1[i][j] = 0;
      temporary2[i][j] = 0;
      temporary3[i][j] = 0;
      temporary6[i][j] = 0;
      temporary7[i][j] = 0;
      temporary8[i][j] = 0;
    }
  }

  for(loop i=2; i<21; i++){
    for(loop j=0; j<8; j++){
#pragma HLS unroll
      temporary1[i][j] = GCTintTowers.GCTtower[i-2][j+2].et;
      temporary2[i][j] = GCTintTowers.GCTtower[i-2][j+6].et;
      temporary3[i][j] = GCTintTowers.GCTtower[i-2][j+10].et;
    }
  }

  for(loop i=0; i<19; i++){
    for(loop j=0; j<8; j++){
#pragma HLS unroll
      temporary6[i][j] = GCTintTowers.GCTtower[i+15][j+2].et;
      temporary7[i][j] = GCTintTowers.GCTtower[i+15][j+6].et;
      temporary8[i][j] = GCTintTowers.GCTtower[i+15][j+10].et;
    }
  }

  GCTPfcluster_t Pfclusters1;
#pragma HLS ARRAY_PARTITION variable=Pfclusters1  complete dim=0
  Pfclusters1 = pfcluster(temporary1, 0, 4);

  GCTPfcluster_t Pfclusters2;
#pragma HLS ARRAY_PARTITION variable=Pfclusters2  complete dim=0
  Pfclusters2 = pfcluster(temporary2, 0, 8);

  GCTPfcluster_t Pfclusters3;
#pragma HLS ARRAY_PARTITION variable=Pfclusters3  complete dim=0
  Pfclusters3 = pfcluster(temporary3, 0, 12);

  GCTPfcluster_t Pfclusters6;
#pragma HLS ARRAY_PARTITION variable=Pfclusters6  complete dim=0
  Pfclusters6 = pfcluster(temporary6, 17, 4);

  GCTPfcluster_t Pfclusters7;
#pragma HLS ARRAY_PARTITION variable=Pfclusters7  complete dim=0
  Pfclusters7 = pfcluster(temporary7, 17, 8);

  GCTPfcluster_t Pfclusters8;
#pragma HLS ARRAY_PARTITION variable=Pfclusters8  complete dim=0
  Pfclusters8 = pfcluster(temporary8, 17, 12);

// OUTPUT

  for(loop i=0; i<8; i++){
#pragma HLS UNROLL
    TotalPfcluster[i] = Pfclusters1.GCTpfclusters[i];
    TotalPfcluster[8+i] = Pfclusters2.GCTpfclusters[i];
    TotalPfcluster[16+i] = Pfclusters3.GCTpfclusters[i];
    TotalPfcluster[24+i] = Pfclusters6.GCTpfclusters[i];
    TotalPfcluster[32+i] = Pfclusters7.GCTpfclusters[i];
    TotalPfcluster[40+i] = Pfclusters8.GCTpfclusters[i];
  }

  return;
}
