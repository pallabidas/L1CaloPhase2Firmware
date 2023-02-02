#include "algo_topGCT360.h"
#include <cstdlib>

int main(){


  srand((unsigned)time(0));


  GCTintTowers_t GCTintTowers ;
   
  ap_uint<12> start = 0;
  ap_uint<12> end = start+15;

  for(loop i=0; i<N_INPUT_LINKS_IP2; i++){
    for(loop k=0; k<N_GCTETA; k++){
        GCTintTowers.GCTtower[k][i].et = 0 ;
        if(i == 0 && k == 0) GCTintTowers.GCTtower[k][i].et = 100 ;
        GCTintTowers.GCTtower[k][i].hoe = 0 ;
        start += 16; end = start + 15 ;
  }}


  ap_uint<576> link_in[N_INPUT_LINKS_IP2]; // 24 output links
  ap_uint<576> link_out[N_OUTPUT_LINKS_IP2]; // 24 output links
  start = 0;

  for(size_t i=0; i<N_INPUT_LINKS_IP2; i++){
    link_in[i] = 0;
  }

  for(loop i=0; i<N_INPUT_LINKS_IP2; i++){  // 5 RCT cards in each eta-half
    start = 0;
    for(loop k=0; k<N_GCTETA; k++){  // 4 links in each RCT card
        link_in[i].range(start+11, start) = GCTintTowers.GCTtower[k][i].et; 
        start += 15;
      }}

  
  algo_topGCT360(link_in, link_out);


    for(loop i=0; i<N_GCTCORR_FIBERS; i++){
    #pragma HLS unroll 
        cout << "f" << i << " / " ;

        for(loop k=0; k<N_GCTPFCLUSTERS_FIBER; k++){
        #pragma HLS UNROLL
            ap_uint<32> start = k*64 ;
            ap_uint<32> end =  start + 11;
            cout << " " << link_out[i].range(end, start) ;
        }
        cout << endl ;

    }


  return 0;
}
