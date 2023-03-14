#include "algo_top.h"
#include "algo_top_parameters.h"
#include "bitonicSort16.h"

void processInputLinks(ap_uint<576> link_in[N_INPUT_LINKS], tower allTowers[TOWER_IN_ETA][TOWER_IN_PHI]){
	#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
        #pragma HLS ARRAY_PARTITION variable=allTowers complete dim=0

        ap_uint<32> start = 0;
        ap_uint<32> end = 15;
  
        for(loop i=0; i<TOWER_IN_ETA; i++){
//                #pragma HLS UNROLL
                for(loop j=0; j<TOWER_IN_PHI; j++){
                        #pragma HLS UNROLL
                       start = j*16 ; end = start + 15 ;
                       allTowers[i][j] = tower(link_in[i].range(end, start));
         }}


}


jetInfo getJetValues(tower tempX[TOWER_IN_ETA][TOWER_IN_PHI], ap_uint<5> seed_eta,  ap_uint<5> seed_phi ){
#pragma HLS ARRAY_PARTITION variable=tempX complete dim=0
#pragma HLS latency min=6

        ap_uint<12> temp[TOWER_IN_ETA+2][TOWER_IN_PHI+2] ;
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0

        ap_uint<12> eta_slice[3] ;
#pragma HLS ARRAY_PARTITION variable=eta_slice complete dim=0


jetInfo jet_tmp;

        for(loop i=0; i<TOWER_IN_ETA+2; i++){
                       #pragma HLS UNROLL
           for(loop k=0; k<TOWER_IN_PHI+2; k++){
                        #pragma HLS UNROLL
            temp[i][k] = 0 ;
         }}

        for(loop i=0; i<TOWER_IN_ETA; i++){
                        #pragma HLS UNROLL
           for(loop k=0; k<TOWER_IN_PHI; k++){
                        #pragma HLS UNROLL
            temp[i+1][k+1] = tempX[i][k].energy ;
         }}


        ap_uint<5> seed_eta1,  seed_phi1 ;

        seed_eta1 = seed_eta ; //to start from corner
        seed_phi1 = seed_phi ; //to start from corner
// now we are in the left bottom corner 
        ap_uint<12> tmp1, tmp2, tmp3 ;

        for(loop j=0; j<TOWER_IN_ETA; j++){
//                        #pragma HLS UNROLL
           for(loop k=0; k<TOWER_IN_PHI; k++){
                        #pragma HLS UNROLL
              if(j== seed_eta1 && k == seed_phi1)
                 {
                for(loop m=0; m<3 ; m++){
                        #pragma HLS UNROLL
                tmp1 = temp[j+m][k] ;
                tmp2 = temp[j+m][k+1] ;
                tmp3 = temp[j+m][k+2] ;

                eta_slice[m] = tmp1 + tmp2 + tmp3 ;
			}
               }
          }}


         jet_tmp.energy=eta_slice[1] + eta_slice[2] + eta_slice[3] ;

        for(loop i=0; i<TOWER_IN_ETA; i++){
//                        #pragma HLS UNROLL
           if(i+1>=seed_eta && i<=seed_eta+1){ 
           for(loop k=0; k<TOWER_IN_PHI; k++){
                        #pragma HLS UNROLL
            if(k+1>=seed_phi && k<=seed_phi+1)  tempX[i][k].energy = 0 ;}
         }}

return jet_tmp ;
}



void algo_topIP12SP(ap_uint<576> link_in[N_INPUT_LINKS], ap_uint<576> link_out[N_OUTPUT_LINKS]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
#pragma HLS ARRAY_PARTITION variable=link_out complete dim=0
#pragma HLS PIPELINE II=9
#pragma HLS INTERFACE ap_ctrl_hs port=return

tower HGCALRegion[TOWER_IN_ETA][TOWER_IN_PHI];
#pragma HLS ARRAY_PARTITION variable=HGCALRegion3 complete dim=0

jetInfo jet1, jet_tmp ;

//creating 18x4 towers temporary 

processInputLinks(link_in, HGCALRegion, jet_tmp);

        ap_uint<5> seed_phi = jet_tmp.phiMax ;
        ap_uint<5> seed_eta = jet_tmp.etaMax ;

// it gets values and removes used 
//
        jet = getJetValues(HGCALRegion, seed_eta, seed_phi) ;

        jet_tmp.energy = jet.energy;


        /*---------------------------------link 0------------------------------------*/
        
	link_out[0] = 0;
        ap_uint<32> start = 0;
        ap_uint<32> end = 33;

            link_out[0].range(end, start) = jet_tmp ;

}

