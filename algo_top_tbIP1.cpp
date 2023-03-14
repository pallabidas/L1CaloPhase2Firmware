#include "algo_topIP1.h"
#include "algo_top_parameters.h"
#include <cstdlib>

int main(){

  srand((unsigned)time(0));

ap_uint<576> link_in[N_INPUT_LINKS] ;
ap_uint<576> link_out[N_OUTPUT_LINKS] ;

tower allTowers[TOWER_IN_ETA][TOWER_IN_PHI] ;

        ap_uint<32> start = 0;
        ap_uint<32> end = 15;
  
        for(loop i=0; i<TOWER_IN_ETA; i++){
                for(loop j=0; j<TOWER_IN_PHI; j++){
                       start = j*16 ; end = start + 15 ;
                       if(i==2 && j==2) allTowers[i][j].energy = 100 ;
                       if(i==2 && j==12) allTowers[i][j].energy = 200 ;
                       if(i==1 && j==16) allTowers[i][j].energy = 150 ;
                       if(i==3 && j==10) allTowers[i][j].energy = 200 ;
                       if(i==2 && j==22) allTowers[i][j].energy = 16 ;
                       if(i==2 && j==20) allTowers[i][j].energy = 8 ;
                       if(i==2 && j==21) allTowers[i][j].energy = 4 ;
                       if(i==3 && j==22) allTowers[i][j].energy = 2 ;
                       if(i==3 && j==20) allTowers[i][j].energy = 1 ;
                       if(i==3 && j==21) allTowers[i][j].energy = 400 ;
                       if(i==4 && j==23) allTowers[i][j].energy = 33 ;
                       if(i==5 && j==23) allTowers[i][j].energy = 34 ;

                       link_in[i].range(end, start) = ap_uint<16>(allTowers[i][j].energy);
         }}


algo_topIP1(link_in, link_out) ;

jetInfo jet ;

        for(loop i = 0; i <10; i++){
        start=i*34 ; end = start + 11 ;
        jet.energy = link_out[0].range(end, start) ;
        cout << " Jet energy " << jet.energy << endl ;
        }

  return 0;
}
