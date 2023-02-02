#include <cstdlib>
#include "ap_int.h"
#include <vector>
#include "algo_topGCT360.h"

//    eta:        0  1  2  3  4   5  6  7  8   9 10 11 12  13 14 15 16  17 18 19 20  21 22 23 24  25 26 27 28  29 30 31 32 33
// phi           ____________________________________________________________________________________________________________
// 0             |                                                    |                                                     |
// 1             |                                                    |                                                     |
// 2             |                         0                          |                           5                         |
// 3             |                                                    |                                                     |
//               -----------------------------------------------------|-----------------------------------------------------|
// 4             |                                                    |                                                     |
// 5             |                         1                          |                           6                         |
// 6             |                                                    |                                                     |
// 7             |                                                    |                                                     |
//               ------------------------------------------------------------------------------------------------------------
// 8             |                                                    |                                                     |
// 9             |                         2                          |                           7                         | 
// 10            |                                                    |                                                     |
// 11            |                                                    |                                                     |
//               -----------------------------------------------------|-----------------------------------------------------|
// 12            |                                                    |                                                     |
// 13            |                         3                          |                           8                         |
// 14            |                                                    |                                                     |
// 15            |                                                    |                                                     |
//               _____________________________________________________|_____________________________________________________|
// 16            |                                                    |                                                     |
// 17            |                                                    |                                                     |
// 18            |                         4                          |                           9                         |
// 19            |                                                    |                                                     |
//               |____________________________________________________|_____________________________________________________|               
//
// 8 PFclusters are created in one 21x8 (2+17+2 x 2+4+2) --> Total 6x8 = 48 pfclusters

GCTint_t bestOf2(const GCTint_t& t0, const GCTint_t& t1) {
  GCTint_t x;
  x = (t0.et > t1.et) ? t0 : t1;
  return x;
}

GCTint_t getPeakOfStrip(const etaStrip_t& etaStrip){
#pragma HLS ARRAY_PARTITION variable=etaStrip  complete dim=0
#pragma HLS latency min=5

  GCTint_t best12 = bestOf2(etaStrip.t[1],etaStrip.t[2]);
  GCTint_t best34 = bestOf2(etaStrip.t[3],etaStrip.t[4]);
  GCTint_t best56 = bestOf2(etaStrip.t[5],etaStrip.t[6]);
  GCTint_t best1234 = bestOf2(best12, best34);
  GCTint_t bestAll = bestOf2(best1234, best56);
  
  return bestAll;
}

GCTint_t getPeakBin(const etaStripPeak_t& etaStripPeak){
#pragma HLS ARRAY_PARTITION variable=etaStripPeak  complete dim=0
#pragma HLS latency min=2

  GCTint_t best01 = bestOf2(etaStripPeak.p[0], etaStripPeak.p[1]);
  GCTint_t best23 = bestOf2(etaStripPeak.p[2], etaStripPeak.p[3]);
  GCTint_t best45 = bestOf2(etaStripPeak.p[4], etaStripPeak.p[5]);
  GCTint_t best67 = bestOf2(etaStripPeak.p[6], etaStripPeak.p[7]);
  GCTint_t best89 = bestOf2(etaStripPeak.p[8], etaStripPeak.p[9]);
  GCTint_t best1011 = bestOf2(etaStripPeak.p[10], etaStripPeak.p[11]);
  GCTint_t best1213 = bestOf2(etaStripPeak.p[12], etaStripPeak.p[13]);
  GCTint_t best1415 = bestOf2(etaStripPeak.p[14], etaStripPeak.p[15]);
  GCTint_t best1617 = bestOf2(etaStripPeak.p[16], etaStripPeak.p[17]);
  GCTint_t best0123 = bestOf2(best01, best23);
  GCTint_t best4567 = bestOf2(best45, best67);
  GCTint_t best891011 = bestOf2(best89, best1011);
  GCTint_t best12131415 = bestOf2(best1213, best1415);
  GCTint_t best01234567 = bestOf2(best0123, best4567);
  GCTint_t best01234567891011 = bestOf2(best01234567, best891011);
  GCTint_t best121314151617 = bestOf2(best12131415, best1617);
  GCTint_t best12131415161718 = bestOf2(best121314151617, etaStripPeak.p[18]);
  GCTint_t bestAll = bestOf2(best01234567891011, best12131415161718);

  return bestAll;
}

GCTint_t getPeakPosition(const region_t& region){
#pragma HLS ARRAY_PARTITION variable=region complete dim=0
#pragma HLS latency min=10

  etaStripPeak_t etaPeak;
#pragma HLS ARRAY_PARTITION variable=etaPeak  complete dim=0

  etaPeak.p[0] = getPeakOfStrip(region.s1);
  etaPeak.p[1] = getPeakOfStrip(region.s2);
  etaPeak.p[2] = getPeakOfStrip(region.s3);
  etaPeak.p[3] = getPeakOfStrip(region.s4);
  etaPeak.p[4] = getPeakOfStrip(region.s5);
  etaPeak.p[5] = getPeakOfStrip(region.s6);
  etaPeak.p[6] = getPeakOfStrip(region.s7);
  etaPeak.p[7] = getPeakOfStrip(region.s8);
  etaPeak.p[8] = getPeakOfStrip(region.s9);
  etaPeak.p[9] = getPeakOfStrip(region.s10);
  etaPeak.p[10] = getPeakOfStrip(region.s11);
  etaPeak.p[11] = getPeakOfStrip(region.s12);
  etaPeak.p[12] = getPeakOfStrip(region.s13);
  etaPeak.p[13] = getPeakOfStrip(region.s14);
  etaPeak.p[14] = getPeakOfStrip(region.s15);
  etaPeak.p[15] = getPeakOfStrip(region.s16);
  etaPeak.p[16] = getPeakOfStrip(region.s17);
  etaPeak.p[17] = getPeakOfStrip(region.s18);
  etaPeak.p[18] = getPeakOfStrip(region.s19);
  GCTint_t max = getPeakBin(etaPeak);

  return max;
}

region_t initStructure(ap_uint<12> temp[21][8]){
#pragma HLS ARRAY_PARTITION variable=temp  complete dim=0
#pragma HLS latency min=5

  region_t r;
#pragma HLS ARRAY_PARTITION variable=r complete dim=0

  for(loop i=0; i<8; i++){
#pragma HLS unroll
    r.s0.t[i].et = temp[0][i];
    r.s0.t[i].eta = 0;
    r.s0.t[i].phi = i;
    r.s1.t[i].et = temp[1][i];
    r.s1.t[i].eta = 1;
    r.s1.t[i].phi = i;
    r.s2.t[i].et = temp[2][i];
    r.s2.t[i].eta = 2;
    r.s2.t[i].phi = i;
    r.s3.t[i].et = temp[3][i];
    r.s3.t[i].eta = 3;
    r.s3.t[i].phi = i;
    r.s4.t[i].et = temp[4][i];
    r.s4.t[i].eta = 4;
    r.s4.t[i].phi = i;
    r.s5.t[i].et = temp[5][i];
    r.s5.t[i].eta = 5;
    r.s5.t[i].phi = i;
    r.s6.t[i].et = temp[6][i];
    r.s6.t[i].eta = 6;
    r.s6.t[i].phi = i;
    r.s7.t[i].et = temp[7][i];
    r.s7.t[i].eta = 7;
    r.s7.t[i].phi = i;
    r.s8.t[i].et = temp[8][i];
    r.s8.t[i].eta = 8;
    r.s8.t[i].phi = i;
    r.s9.t[i].et = temp[9][i];
    r.s9.t[i].eta = 9;
    r.s9.t[i].phi = i;
    r.s10.t[i].et = temp[10][i];
    r.s10.t[i].eta = 10;
    r.s10.t[i].phi = i;
    r.s11.t[i].et = temp[11][i];
    r.s11.t[i].eta = 11;
    r.s11.t[i].phi = i;
    r.s12.t[i].et = temp[12][i];
    r.s12.t[i].eta = 12;
    r.s12.t[i].phi = i;
    r.s13.t[i].et = temp[13][i];
    r.s13.t[i].eta = 13;
    r.s13.t[i].phi = i;
    r.s14.t[i].et = temp[14][i];
    r.s14.t[i].eta = 14;
    r.s14.t[i].phi = i;
    r.s15.t[i].et = temp[15][i];
    r.s15.t[i].eta = 15;
    r.s15.t[i].phi = i;
    r.s16.t[i].et = temp[16][i];
    r.s16.t[i].eta = 16;
    r.s16.t[i].phi = i;
    r.s17.t[i].et = temp[17][i];
    r.s17.t[i].eta = 17;
    r.s17.t[i].phi = i;
    r.s18.t[i].et = temp[18][i];
    r.s18.t[i].eta = 18;
    r.s18.t[i].phi = i;
    r.s19.t[i].et = temp[19][i];
    r.s19.t[i].eta = 19;
    r.s19.t[i].phi = i;
    r.s20.t[i].et = temp[20][i];
    r.s20.t[i].eta = 20;
    r.s20.t[i].phi = i;

  }
  return r;
}

ap_uint<12> getEt(ap_uint<12> temp[21][8], ap_uint<7> eta, ap_uint<5> phi){
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0
#pragma HLS latency min=37

  ap_uint<12> tempX[23][10] ;
#pragma HLS ARRAY_PARTITION variable=tempX complete dim=0

  for(loop i=0; i<23; i++){
    for(loop j=0; j<10; j++){
#pragma HLS unroll
      tempX[i][j] = 0;
    }
  }

  for(loop i=0; i<21; i++){
    for(loop j=0; j<8; j++){
#pragma HLS unroll
      tempX[i+1][j+1] = temp[i][j];
    }
  }

  ap_uint<12> et_sumEta[3];
#pragma HLS ARRAY_PARTITION variable=et_sumEta complete dim=0

  for(loop i=0; i<21; i++){
    for(loop j=0; j<8; j++){
#pragma HLS unroll
      if (i == eta && j == phi){
        for(loop k=0; k<3; k++){
#pragma HLS unroll
          et_sumEta[k] = tempX[i+k][j] + tempX[i+k][j+1] + tempX[i+k][j+2];
        }
      }
    }
  }

  ap_uint<12> pfcluster_et = et_sumEta[0] + et_sumEta[1] + et_sumEta[2];

  return pfcluster_et;
}

void RemoveTmp(ap_uint<12> temp[21][8], ap_uint<7> eta, ap_uint<5> phi){
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0
#pragma HLS latency min=35
 
  for(loop i=0; i<21; i++){
    if(i+1 >= eta && i <= eta+1) {
      for(loop j=0; j<8; j++){
#pragma HLS unroll
        if(j+1 >= phi && j <= phi+1) {
          temp[i][j] = 0;
        }
      }
    }
  }
  return;
}

ap_uint<24> recoPfcluster(ap_uint<12> temporary[21][8]){ 
#pragma HLS ARRAY_PARTITION variable=temporary  complete dim=0
#pragma HLS latency min=56
#pragma HLS inline

  ap_uint<24> pfclusterReturn = 0;

  region_t region;
#pragma HLS ARRAY_PARTITION variable=region  complete dim=0

  region = initStructure(temporary);

  GCTint_t regionMax = getPeakPosition(region);  

  ap_uint<12> pfcluster_et = getEt(temporary, regionMax.eta, regionMax.phi);

  RemoveTmp(temporary, regionMax.eta, regionMax.phi);

  if(!(regionMax.eta >= 2 && regionMax.eta <= 18 && regionMax.phi >= 2 && regionMax.phi <= 5)) pfcluster_et = 0;

  pfclusterReturn.range(11, 0) = pfcluster_et;
  pfclusterReturn.range(18, 12) = regionMax.eta;
  pfclusterReturn.range(23, 19) = regionMax.phi;

  return pfclusterReturn ;
}

GCTPfcluster_t pfcluster(ap_uint<12> temporary[21][8], ap_uint<7> etaoffset, ap_uint<5> phioffset) {
#pragma HLS ARRAY_PARTITION variable=temporary complete dim=0
#pragma HLS latency min=457

  ap_uint<24> pfcluster[8];
#pragma HLS ARRAY_RESHAPE variable=pfcluster  complete dim=0

  for(int i=0; i<8; i++){
#pragma HLS unroll
    pfcluster[i] = 0;
  }

  ap_uint<24> temp_cluster0 = recoPfcluster(temporary) ;
  pfcluster[0].range(11, 0) = temp_cluster0.range(11, 0);
  pfcluster[0].range(18, 12) = temp_cluster0.range(18, 12) - 2 + etaoffset;
  pfcluster[0].range(23, 19) = temp_cluster0.range(23, 19) - 2 + phioffset;
  ap_uint<24> temp_cluster1 = recoPfcluster(temporary) ;
  pfcluster[1].range(11, 0) =  temp_cluster1.range(11, 0);
  pfcluster[1].range(18, 12) =  temp_cluster1.range(18, 12) - 2 + etaoffset;
  pfcluster[1].range(23, 19) =  temp_cluster1.range(23, 19) - 2 + phioffset;
  ap_uint<24> temp_cluster2 = recoPfcluster(temporary) ;
  pfcluster[2].range(11, 0) =  temp_cluster2.range(11, 0);
  pfcluster[2].range(18, 12) =  temp_cluster2.range(18, 12) - 2 + etaoffset;
  pfcluster[2].range(23, 19) =  temp_cluster2.range(23, 19) - 2 + phioffset;
  ap_uint<24> temp_cluster3 = recoPfcluster(temporary) ;
  pfcluster[3].range(11, 0) =  temp_cluster3.range(11, 0);
  pfcluster[3].range(18, 12) =  temp_cluster3.range(18, 12) - 2 + etaoffset;
  pfcluster[3].range(23, 19) =  temp_cluster3.range(23, 19) - 2 + phioffset;
  ap_uint<24> temp_cluster4 = recoPfcluster(temporary) ;
  pfcluster[4].range(11, 0) =  temp_cluster4.range(11, 0);
  pfcluster[4].range(18, 12) =  temp_cluster4.range(18, 12) - 2 + etaoffset;
  pfcluster[4].range(23, 19) =  temp_cluster4.range(23, 19) - 2 + phioffset;
  ap_uint<24> temp_cluster5 = recoPfcluster(temporary) ;
  pfcluster[5].range(11, 0) =  temp_cluster5.range(11, 0);
  pfcluster[5].range(18, 12) =  temp_cluster5.range(18, 12) - 2 + etaoffset;
  pfcluster[5].range(23, 19) =  temp_cluster5.range(23, 19) - 2 + phioffset;
  ap_uint<24> temp_cluster6 = recoPfcluster(temporary) ;
  pfcluster[6].range(11, 0) =  temp_cluster6.range(11, 0);
  pfcluster[6].range(18, 12) =  temp_cluster6.range(18, 12) - 2 + etaoffset;
  pfcluster[6].range(23, 19) =  temp_cluster6.range(23, 19) - 2 + phioffset;
  ap_uint<24> temp_cluster7 = recoPfcluster(temporary) ;
  pfcluster[7].range(11, 0) =  temp_cluster7.range(11, 0);
  pfcluster[7].range(18, 12) =  temp_cluster7.range(18, 12) - 2 + etaoffset;
  pfcluster[7].range(23, 19) =  temp_cluster7.range(23, 19) - 2 + phioffset;


  GCTPfcluster_t GCTPfclusters;
#pragma HLS ARRAY_PARTITION variable=GCTPfclusters  complete dim=0

  for(loop i=0; i<8; i++){
#pragma HLS unroll
    GCTPfclusters.GCTpfclusters[i].et = pfcluster[i].range(11, 0);
    GCTPfclusters.GCTpfclusters[i].eta = pfcluster[i].range(18, 12);
    GCTPfclusters.GCTpfclusters[i].phi = pfcluster[i].range(23, 19);
  }

  return GCTPfclusters;
}
