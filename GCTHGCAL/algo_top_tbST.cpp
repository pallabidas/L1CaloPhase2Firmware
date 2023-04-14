#include "algo_topST.h"
#include <cstdlib>

int main(){


  srand((unsigned)time(0));


  GCTintTowers_t GCTintTowers ;
   
  ap_uint<12> start = 0;
  ap_uint<12> end = start+15;

  for(loop i=0; i<N_GCTPHI; i++){
    for(loop k=0; k<N_GCTETA; k++){
        GCTintTowers.GCTtower[k][i].et = 0 ;
        if(i == 0 && k == 0) GCTintTowers.GCTtower[k][i].et = 100 ;
        GCTintTowers.GCTtower[k][i].hoe = 0 ;
    }
  }
  GCTintTowers.GCTtower[1][0].et = 50 ;
  GCTintTowers.GCTtower[2][0].et = 15 ;
  GCTintTowers.GCTtower[1][1].et = 20 ;
  GCTintTowers.GCTtower[1][2].et = 5 ;
  GCTintTowers.GCTtower[1][3].et = 15 ;
  GCTintTowers.GCTtower[3][0].et = 10 ;
  GCTintTowers.GCTtower[5][5].et = 100 ;
  GCTintTowers.GCTtower[5][6].et = 5 ;
  GCTintTowers.GCTtower[5][7].et = 10 ;


  ap_uint<576> link_in[N_GCTPHI]; // 72 input links
  ap_uint<576> link_out[N_OUTPUT_ST]; // 6 output links
  start = 0;

  for(size_t i=0; i<N_GCTPHI; i++){
    link_in[i] = 0;
  }

  for(loop i=0; i<N_GCTPHI; i++){
    start = 0;
    for(loop k=0; k<N_GCTETA; k++){
        link_in[i].range(start+11, start) = GCTintTowers.GCTtower[k][i].et; 
        start += 16;
    }
  }

  
  algo_topST(link_in, link_out);


    for(loop i=0; i<N_OUTPUT_ST; i++){
    #pragma HLS unroll 
        cout << "f" << i << " / " ;

        for(loop k=0; k<N_ST_PERLINK; k++){
        #pragma HLS UNROLL
            start = k*32 ;
            end =  start + 11;
            cout << " " << link_out[i].range(end, start) ;
        }
        cout << endl ;

    }


  return 0;
}
