#include "algo_topST.h"

void makeST(const GCTintTowers_t& GCTintTowers, ap_uint<11> barrelST[N_ST]){
#pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0
#pragma HLS ARRAY_PARTITION variable=barrelST complete dim=0

   ap_uint<12> et_sumEta[N_STETA][N_STPHI][3];
#pragma HLS ARRAY_PARTITION variable=et_sumEta complete dim=0

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
   for(loop i=0; i<18; i+=3){
      index_j = 0;
      for(loop j=0; j<30; j+=3){
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
         barrelST[index] = et_sumEta[i][j][0] + et_sumEta[i][j][1] + et_sumEta[i][j][2];
         index++;
         //std::cout<<i<<"\t"<<j<<"\t"<<barrelST[i][j]<<std::endl;
      }
   }
   return;
}
