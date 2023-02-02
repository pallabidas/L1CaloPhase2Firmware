#include "algo_topGCT360.h"


GCTintTowers_t processInputLinks(ap_uint<576> link_in[N_INPUT_LINKS_GCTIP2]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
//#pragma HLS inline  // added
//

GCTintTowers_t GCTintTowers ;

    for(loop i=0; i<N_GCTPHI; i++){   // 0 to 19 
//    #pragma HLS unroll 
        link_out[i] = 0;
        for(loop k=0; k<N_GCTETA; k++){   // 0 to 33
        #pragma HLS unroll 
          ap_uint<10> start = k*16 ;
          ap_uint<10> end = start + 11 ;
          GCTintTowers.GCTtower[k][i].et = link_out[i].range(end,start) ;
	  start = start + 12; end = start + 3 ;
          GCTintTowers.GCTtower[k][i].hoe = link_out[i].range(end,start) ;
         }}
  
return GCTintTowers ;
}

void algo_topGCT360(ap_uint<576> link_in[N_INPUT_LINKS_IP2], ap_uint<576> link_out[N_OUTPUT_LINKS_IP2]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
#pragma HLS ARRAY_PARTITION variable=link_out complete dim=0
#pragma HLS PIPELINE II=9
#pragma HLS INTERFACE ap_ctrl_hs port=return
#pragma HLS latency min=120


  GCTinternal_t GCTinternal ;
#pragma HLS ARRAY_PARTITION variable=GCTinternal complete dim=0

// first we fill the GCT area with proper et and eta/phi; the eta is 0....16 and towEtaNeg = 0 or 1
// Phi 0....15 since this is half GCT card and 0...3 is overlap currently on one side, crEta/Phi 0...4
// new: need to have overlap on both Phi 0...19  0...3 16...19 overlap

  GCTinternal = getClustersTowers(GCTcard) ;


  GCTintTowers_t GCTintTowers;
#pragma HLS ARRAY_PARTITION variable=GCTintTowers complete dim=0
  GCTcard = processInputLinks(link_in);

// here we combine towers and clusters to get full towers, and move to internal GCT card coordinate 0...33 in eta and 0...15 in phi,
// should change to 0...31 for the whole card

  GCTintTowers = getFullTowers(GCTinternal) ;

//ok now we have towers combined with clusters, now need to recalculate positions of all clusters in GCT coordinates


// OUTPUT TO CORRELATOR !!!!
// remove overlap region, we send out 24 fibers: 12 pos/12 neg
// all phi now decreases by 4
// this we send to Correlator

  for(int i=4; i<N_GCTPOSITIVE_FIBERS-4; i++){
//#pragma HLS unroll 
    for(int k=0; k<N_GCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].et  = GCTinternal.GCTCorrfiber[i].GCTclusters[k].et   ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].towEtaNeg  = GCTinternal.GCTCorrfiber[i].GCTclusters[k].towEtaNeg  ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].towEta  =  N_GCTETA/2 + GCTinternal.GCTCorrfiber[i].GCTclusters[k].towEta ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].towPhi  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].towPhi-4 ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].crEta  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].crEta ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].crPhi  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].crPhi ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].satur  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].satur ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].hoe  =   0 ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].iso  =   0 ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].shape  =  0 ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTclusters[k].brems  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].brems ;
    }
    for(int k=0; k<N_GCTTOWERS_FIBER; k++){
#pragma HLS unroll 
      GCTtoCorr.GCTCorrfiber[i-4].GCTtowers[k].et  = GCTinternal.GCTCorrfiber[i].GCTtowers[k].et ;
      GCTtoCorr.GCTCorrfiber[i-4].GCTtowers[k].hoe  = GCTinternal.GCTCorrfiber[i].GCTtowers[k].hoe ;
    }
  }


  for(int i=N_GCTPOSITIVE_FIBERS+4; i<N_GCTINTERNAL_FIBERS-4; i++){
//#pragma HLS unroll 
    for(int k=0; k<N_GCTCLUSTERS_FIBER; k++){
#pragma HLS unroll 
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].et  = GCTinternal.GCTCorrfiber[i].GCTclusters[k].et   ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].towEtaNeg  = GCTinternal.GCTCorrfiber[i].GCTclusters[k].towEtaNeg  ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].towEta  =  N_GCTETA/2 - GCTinternal.GCTCorrfiber[i].GCTclusters[k].towEta - 1 ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].towPhi  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].towPhi-4 ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].crEta  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].crEta ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].crPhi  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].crPhi ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].satur  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].satur ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].hoe  =  0  ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].iso  =  0  ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].shape  =  0  ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTclusters[k].brems  =  GCTinternal.GCTCorrfiber[i].GCTclusters[k].brems ;
    }
    for(int k=0; k<N_GCTTOWERS_FIBER; k++){
#pragma HLS unroll 
      GCTtoCorr.GCTCorrfiber[i-12].GCTtowers[k].et  = GCTinternal.GCTCorrfiber[i].GCTtowers[k].et ;
      GCTtoCorr.GCTCorrfiber[i-12].GCTtowers[k].hoe  = GCTinternal.GCTCorrfiber[i].GCTtowers[k].hoe ;
    }
  }

        /*--------------------------------- link 0, ... , 23  ------------------------------------*/

//     to IP3 

    for(loop i=0; i<N_GCTCORR_FIBERS; i++){   // 0 to 24
    #pragma HLS unroll 
        link_out[i] = 0;
        for(loop k=0; k<N_GCTTOWERS_FIBER; k++){   // 0 to 17
        #pragma HLS unroll 
          ap_uint<10> start = k*16 ;
          ap_uint<10> end = start + 15 ;
          link_out[i].range(end,start) = ((ap_uint<16>) GCTtoCorr.GCTCorrfiber[i].GCTtowers[k].hoe << 12) | ((ap_uint<16>) GCTtoCorr.GCTCorrfiber[i].GCTtowers[k].et ) ;
          //cout << " " << GCTtoCorr.GCTCorrfiber[i].GCTtowers[k].et ;
         }
        //cout << " \ "  ;

        for(loop k=0; k<N_GCTCLUSTERS_FIBER; k++){   // 0 to 2
        #pragma HLS UNROLL
            ap_uint<32> start = 272 + k*64;
            ap_uint<32> end =  start + 63 ;;
            link_out[i].range(end, start) = GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].et | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].towEta << 12) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].towPhi << 18) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].crEta << 23) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].crPhi << 26) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].satur << 29) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].hoe << 32) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].iso << 35) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].shape << 38) | ((ap_uint<60>) GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].brems << 41) ;
           //cout << " " << GCTtoCorr.GCTCorrfiber[i].GCTclusters[k].et ;
        }}
        //cout << " \ " ;
        
        /*--------------------------------- link 24, ... , 43  ------------------------------------*/

//        to IP2 

    for(loop i=0; i<N_GCTPHI; i++){   // 0 to 19 
//    #pragma HLS unroll 
        link_out[i+24] = 0;
        for(loop k=0; k<N_GCTETA; k++){   // 0 to 33
        #pragma HLS unroll 
          ap_uint<32> start = k*16 ;
          ap_uint<32> end = start + 15 ;
          link_out[i+24].range(end,start) = ((ap_uint<16>) GCTintTowers.GCTtower[k][i].hoe << 12) | ((ap_uint<16>) GCTintTowers.GCTtower[k][i].et ) ;
         }}

}
