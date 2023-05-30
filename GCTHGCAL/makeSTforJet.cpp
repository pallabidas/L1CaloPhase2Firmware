#include "algo_topJet.h"

ap_uint<2> getPeakBinOf3(ap_uint<12> et0, ap_uint<12> et1, ap_uint<12> et2) {
#pragma HLS inline
  ap_uint<2> x;
  ap_uint<12> temp;
  if (et0 > et1) { x = 0; temp = et0; }
  else { x = 1; temp = et1; }
  if (et2 > temp) { x = 2; }
  return x;
}

ap_uint<2> getEWPeakBinOf3(ap_uint<12> et0, ap_uint<12> et1, ap_uint<12> et2) {
#pragma HLS inline
  ap_uint<12> etSum = et0 + et1 + et2;
  ap_uint<12> iEtSum =
    (et0 >> 1)                +  // 0.5xet[0]
    (et1 >> 1) + et1        +    // 1.5xet[1]
    (et2 >> 1) + (et2 << 1);     // 2.5xet[2]
  ap_uint<12> iAve = 0xEEF;
  if (iEtSum <= etSum) iAve = 0;
  else if (iEtSum <= (etSum << 1)) iAve = 1;
  else  iAve = 2;
  return iAve;
}

void makeST(const GCTintTowers_t& GCTintTowers, ap_uint<32> barrelST[N_ST]){
#pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0
#pragma HLS ARRAY_PARTITION variable=barrelST complete dim=0

   ap_uint<12> et_sumEta[N_STETA][N_STPHI][3];
#pragma HLS ARRAY_PARTITION variable=et_sumEta complete dim=0

   ap_uint<12> stripEta[N_STETA][N_STPHI][3];
#pragma HLS ARRAY_PARTITION variable=stripEta complete dim=0

   ap_uint<12> stripPhi[N_STETA][N_STPHI][3];
#pragma HLS ARRAY_PARTITION variable=stripPhi complete dim=0

   ap_uint<12> ex_et[24][36];
#pragma HLS ARRAY_PARTITION variable=ex_et dim=0

   for(loop j=0; j<N_GCTPHI; j++){
      ex_et[0][j+2] = 0;
      for(loop i=0; i<N_GCTETA+6; i++){
#pragma HLS unroll
         ex_et[i+1][j+2] = GCTintTowers.GCTtower[i][j].et;
      }
   }

   for(loop j=0; j<24; j++){
#pragma HLS unroll
      ex_et[j][0] = 0;
      ex_et[j][1] = 0;
      ex_et[j][34] = 0;
      ex_et[j][35] = 0;
   }

   loop index_i = 0;
   loop index_j = 0;
   for(loop i=0; i<24; i+=3){
      index_j = 0;
      for(loop j=0; j<36; j+=3){
         stripEta[index_i][index_j][0] = ex_et[i][j] + ex_et[i][j+1] + ex_et[i][j+2];
         stripEta[index_i][index_j][1] = ex_et[i+1][j] + ex_et[i+1][j+1] + ex_et[i+1][j+2];
         stripEta[index_i][index_j][2] = ex_et[i+2][j] + ex_et[i+2][j+1] + ex_et[i+2][j+2];
         stripPhi[index_i][index_j][0] = ex_et[i][j] + ex_et[i+1][j] + ex_et[i+2][j];
         stripPhi[index_i][index_j][1] = ex_et[i][j+1] + ex_et[i+1][j+1] + ex_et[i+2][j+1];
         stripPhi[index_i][index_j][2] = ex_et[i][j+2] + ex_et[i+1][j+2] + ex_et[i+2][j+2];
#pragma HLS unroll
         for(loop k=0; k<3; k++){
#pragma HLS unroll
             et_sumEta[index_i][index_j][k] = ex_et[i+k][j] + ex_et[i+k][j+1] + ex_et[i+k][j+2];
         }
         index_j++;
      }
      index_i++;
   }
 
   loop index = 0;
//   for(loop i=0; i<N_STETA; i++){
//      for(loop j=0; j<N_STPHI; j++){
   for(loop j=0; j<N_STPHI; j++){
      for(loop i=0; i<N_STETA; i++){
#pragma HLS unroll
         ap_uint<12> supertowerEt = et_sumEta[i][j][0] + et_sumEta[i][j][1] + et_sumEta[i][j][2];
         barrelST[index].range(11, 0) = supertowerEt;
         ap_uint<2> peakEta = getPeakBinOf3(stripEta[i][j][0], stripEta[i][j][1], stripEta[i][j][2]);
         ap_uint<2> EWpeakEta = getEWPeakBinOf3(stripEta[i][j][0], stripEta[i][j][1], stripEta[i][j][2]);
         barrelST[index].range(13, 12) = EWpeakEta;
         ap_uint<2> peakPhi = getPeakBinOf3(stripPhi[i][j][0], stripPhi[i][j][1], stripPhi[i][j][2]);
         ap_uint<2> EWpeakPhi = getEWPeakBinOf3(stripPhi[i][j][0], stripPhi[i][j][1], stripPhi[i][j][2]);
         barrelST[index].range(15, 14) = EWpeakPhi;
         ap_uint<12> peakEt = ex_et[i*3+peakEta][j*3+peakPhi];
         barrelST[index].range(27, 16) = peakEt;
         barrelST[index].range(31, 28) = 0;
         index++;
      }
   }
   return;
}
