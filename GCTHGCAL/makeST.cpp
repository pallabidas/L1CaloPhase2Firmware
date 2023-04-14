#include "algo_topST.h"

//ap_uint<2> getPeakBinOf3(ap_uint<12> et0, ap_uint<12> et1, ap_uint<12> et2, ap_uint<12> etSum) {
ap_uint<2> getPeakBinOf3(ap_uint<12> et0, ap_uint<12> et1, ap_uint<12> et2) {
#pragma HLS inline
  ap_uint<2> x;
  ap_uint<12> temp;
  if (et0 > et1) { x = 0; temp = et0; }
  else { x = 1; temp = et1; }
  if (et2 > temp) { x = 2; }
  return x;

//  ap_uint<12> etSum = et0 + et1 + et2;
//  ap_uint<12> iEtSum =
//    (et0 >> 1)                +  // 0.5xet[0]
//    (et1 >> 1) + et1        +    // 1.5xet[1]
//    (et2 >> 1) + (et2 << 1);     // 2.5xet[2]
//  ap_uint<12> iAve = 0xEEF;
//  if (iEtSum <= etSum) iAve = 0;
//  else if (iEtSum <= (etSum << 1)) iAve = 1;
//  else  iAve = 2;
//  return iAve;
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

   ap_uint<12> ex_et[N_GCTETA+1][N_GCTPHI];
#pragma HLS ARRAY_PARTITION variable=ex_et dim=0
   for(loop j=0; j<N_GCTPHI; j++){
      ex_et[17][j] = 0;
      for(loop i=0; i<N_GCTETA; i++){
         ex_et[i][j] = GCTintTowers.GCTtower[i][j].et;
      }
   }

   loop index_i = 0;
   loop index_j = 0;
   for(loop i=0; i<18; i+=3){ // N_GCTETA+1 to divide into 6 super towers
      index_j = 0;
      for(loop j=1; j<30; j+=3){ // we convert 24 unique phi into 8 super towers, then for the overlap we only need iphi = 1, 2, 3 and iphi = 28, 29, 30
         stripEta[index_i][index_j][0] = ex_et[i][j] + ex_et[i][j+1] + ex_et[i][j+2];
         stripEta[index_i][index_j][1] = ex_et[i+1][j] + ex_et[i+1][j+1] + ex_et[i+1][j+2];
         stripEta[index_i][index_j][2] = ex_et[i+2][j] + ex_et[i+2][j+1] + ex_et[i+2][j+2];
         stripPhi[index_i][index_j][0] = ex_et[i][j] + ex_et[i+1][j] + ex_et[i+2][j];
         stripPhi[index_i][index_j][1] = ex_et[i][j+1] + ex_et[i+1][j+1] + ex_et[i+2][j+1];
         stripPhi[index_i][index_j][2] = ex_et[i][j+2] + ex_et[i+1][j+2] + ex_et[i+2][j+2];

#pragma HLS unroll
         //std::cout<<i<<"\t"<<j<<"\t"<<GCTintTowers.GCTtower[i][j].et<<std::endl;
         for(loop k=0; k<3; k++){
#pragma HLS unroll
             //std::cout<<index_i<<"\t"<<index_j<<std::endl;
             et_sumEta[index_i][index_j][k] = ex_et[i+k][j] + ex_et[i+k][j+1] + ex_et[i+k][j+2];
             //std::cout<<index_i<<"\t"<<index_j<<"\t"<<ex_et[i+k][j]<<"\t"<<ex_et[i+k][j+1]<<"\t"<<ex_et[i+k][j+2]<<"\t"<<et_sumEta[index_i][index_j][k]<<std::endl;
         }
         index_j++;
      }
      index_i++;
   }
   //std::cout<<"debug"<<std::endl;
 
   loop index = 0;
   for(loop i=0; i<N_STETA; i++){
      for(loop j=0; j<N_STPHI; j++){
         //std::cout<<i<<"\t"<<j<<"\t"<<et_sumEta[i][j][0]<<"\t"<<et_sumEta[i][j][1]<<"\t"<<et_sumEta[i][j][2]<<std::endl;
#pragma HLS unroll
         ap_uint<12> supertowerEt = et_sumEta[i][j][0] + et_sumEta[i][j][1] + et_sumEta[i][j][2];
         barrelST[index].range(11, 0) = supertowerEt;
         ap_uint<2> peakEta = getPeakBinOf3(stripEta[i][j][0], stripEta[i][j][1], stripEta[i][j][2]);
         barrelST[index].range(13, 12) = peakEta;
         ap_uint<2> peakPhi = getPeakBinOf3(stripPhi[i][j][0], stripPhi[i][j][1], stripPhi[i][j][2]);
         barrelST[index].range(15, 14) = peakPhi;
         ap_uint<12> peakEt = ex_et[i*3+peakEta][j*3+1+peakPhi];
         barrelST[index].range(27, 16) = peakEt;
         barrelST[index].range(31, 28) = 0;
         //if(i==0 && j==0) std::cout<<stripEta[i][j][0]<<"\t"<<stripEta[i][j][1]<<"\t"<<stripEta[i][j][2]<<"\t"<<peakEta<<std::endl;
         //if(i==0 && j==0) std::cout<<stripPhi[i][j][0]<<"\t"<<stripPhi[i][j][1]<<"\t"<<stripPhi[i][j][2]<<"\t"<<peakPhi<<std::endl;
         //std::cout<<i<<"\t"<<j<<"\t"<<barrelST[index].range(11, 0)<<"\t"<<barrelST[index].range(13, 12)<<"\t"<<barrelST[index].range(15, 14)<<"\t"<<barrelST[index].range(27, 16)<<"\t"<<barrelST[index].range(31, 28)<<std::endl;
         index++;
      }
   }
   return;
}
