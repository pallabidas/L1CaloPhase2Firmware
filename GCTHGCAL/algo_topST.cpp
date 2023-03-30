#include "algo_topST.h"

GCTintTowers_t processInputLinks(ap_uint<576> link_in[N_GCTPHI]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
//#pragma HLS inline 

  GCTintTowers_t GCTintTowers ;
  #pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0
   
  ap_uint<12> start = 0;

  for(loop i=0; i<N_GCTPHI; i++){
    start = 0 ;
    for(loop k=0; k<N_GCTETA; k++){
    #pragma HLS UNROLL
        GCTintTowers.GCTtower[k][i].et = link_in[i].range(start+11, start) ;
        //std::cout<<k<<"\t"<<i<<"\t"<<GCTintTowers.GCTtower[k][i].et<<std::endl;
        GCTintTowers.GCTtower[k][i].hoe = link_in[i].range(start+15, start+12) ;
        start += 16;
     }
  }

  return GCTintTowers;
}

void algo_topST(ap_uint<576> link_in[N_GCTPHI], ap_uint<576> link_out[N_OUTPUT_ST]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
#pragma HLS ARRAY_PARTITION variable=link_out complete dim=0
#pragma HLS PIPELINE II=9
#pragma HLS INTERFACE ap_ctrl_hs port=return

   GCTintTowers_t GCTintTowers;
#pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0

   GCTintTowers = processInputLinks(link_in);

   ap_uint<11> barrelST[N_ST];
#pragma HLS ARRAY_PARTITION variable=barrelST complete dim=0

   makeST(GCTintTowers, barrelST);

   ap_uint<12> start = 0;
   ap_uint<12> end = 0;

   for(loop i=0; i<N_ST_PERLINK; i++){
      start = i*32 ;
      end = start + 11 ;
      link_out[0].range(end, start) = barrelST[i];
      link_out[1].range(end, start) = barrelST[i+15];
      link_out[2].range(end, start) = barrelST[i+30];
      link_out[3].range(end, start) = barrelST[i+45];
   }
}
