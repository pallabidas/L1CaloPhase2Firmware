#include "algo_topGCT360.h"


GCTintTowers_t processInputLinks(ap_uint<576> link_in[N_INPUT_LINKS_IP2]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
#pragma HLS inline  // added

  GCTintTowers_t GCTintTowers ;
  #pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0
   
  ap_uint<12> start = 0;
  ap_uint<12> end = start+15;

  for(loop i=0; i<N_INPUT_LINKS_IP2; i++){
//#pragma HLS UNROLL
    start = 0 ; end = 15 ;
    for(loop k=0; k<N_GCTETA; k++){
    #pragma HLS UNROLL
        GCTintTowers.GCTtower[k][i].et = link_in[i].range(start+11, start) ;
        GCTintTowers.GCTtower[k][i].hoe = link_in[i].range(start+15, start+12) ;
        start += 16; end = start + 15 ;
//cout << " et " << GCTintTowers.GCTtower[k][i].et << endl ;
  }}

  return GCTintTowers;
}

void algo_topGCT360(ap_uint<576> link_in[N_INPUT_LINKS_IP2], ap_uint<576> link_out[N_OUTPUT_LINKS_IP2]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
#pragma HLS ARRAY_PARTITION variable=link_out complete dim=0
#pragma HLS PIPELINE II=9
#pragma HLS INTERFACE ap_ctrl_hs port=return

  GCTintTowers_t GCTintTowers;
#pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0

  GCTintTowers = processInputLinks(link_in);

  GCTpfcluster_t TotalPfcluster[48];
#pragma HLS ARRAY_PARTITION variable=TotalPfcluster complete dim=0

  makePfclusters(GCTintTowers, TotalPfcluster);

        /*--------------------------------- link 0, ... , 24  ------------------------------------*/


     for(loop i=0; i<N_GCTCORR_FIBERS; i++){
     //#pragma HLS unroll
        for(loop k=0; k<N_GCTPFCLUSTERS_FIBER; k++){   // 0 to 2
        #pragma HLS UNROLL
            ap_uint<10> start = k*64;
            ap_uint<10> end =  start+63 ;
            loop idx = k*24 + i;
            link_out[i].range(end, start) = TotalPfcluster[idx].et | ((ap_uint<24>) TotalPfcluster[idx].eta << 12 ) | ((ap_uint<24>) TotalPfcluster[idx].phi << 18) ;
        }}

}
