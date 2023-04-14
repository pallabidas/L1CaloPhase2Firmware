#include "algo_topIP1.h"
#include "algo_top_parameters.h"

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

hgcalRegion_t initStructure(tower temporary[TOWER_IN_ETA][TOWER_IN_PHI]){

#pragma HLS ARRAY_PARTITION variable=temporary complete dim=0

ap_uint<5> Phi = 0 ;
ap_uint<5> Eta = 0 ;

hgcalRegion_t out;

out.etaStrip0.cr0.energy=temporary[Eta+0][Phi+0].energy; out.etaStrip0.cr0.eta=0; out.etaStrip0.cr0.phi=0;
out.etaStrip0.cr1.energy=temporary[Eta+0][Phi+1].energy; out.etaStrip0.cr1.eta=0; out.etaStrip0.cr1.phi=1;
out.etaStrip0.cr2.energy=temporary[Eta+0][Phi+2].energy; out.etaStrip0.cr2.eta=0; out.etaStrip0.cr2.phi=2;
out.etaStrip0.cr3.energy=temporary[Eta+0][Phi+3].energy; out.etaStrip0.cr3.eta=0; out.etaStrip0.cr3.phi=3;
out.etaStrip0.cr4.energy=temporary[Eta+0][Phi+4].energy; out.etaStrip0.cr4.eta=0; out.etaStrip0.cr4.phi=4;
out.etaStrip0.cr5.energy=temporary[Eta+0][Phi+5].energy; out.etaStrip0.cr5.eta=0; out.etaStrip0.cr5.phi=5;
out.etaStrip0.cr6.energy=temporary[Eta+0][Phi+6].energy; out.etaStrip0.cr6.eta=0; out.etaStrip0.cr6.phi=6;
out.etaStrip0.cr7.energy=temporary[Eta+0][Phi+7].energy; out.etaStrip0.cr7.eta=0; out.etaStrip0.cr7.phi=7;
out.etaStrip0.cr8.energy=temporary[Eta+0][Phi+8].energy; out.etaStrip0.cr8.eta=0; out.etaStrip0.cr8.phi=8;
out.etaStrip0.cr9.energy=temporary[Eta+0][Phi+9].energy; out.etaStrip0.cr9.eta=0; out.etaStrip0.cr9.phi=9;
out.etaStrip0.cr10.energy=temporary[Eta+0][Phi+10].energy; out.etaStrip0.cr10.eta=0; out.etaStrip0.cr10.phi=10;
out.etaStrip0.cr11.energy=temporary[Eta+0][Phi+11].energy; out.etaStrip0.cr11.eta=0; out.etaStrip0.cr11.phi=11;
out.etaStrip0.cr12.energy=temporary[Eta+0][Phi+12].energy; out.etaStrip0.cr12.eta=0; out.etaStrip0.cr12.phi=12;
out.etaStrip0.cr13.energy=temporary[Eta+0][Phi+13].energy; out.etaStrip0.cr13.eta=0; out.etaStrip0.cr13.phi=13;
out.etaStrip0.cr14.energy=temporary[Eta+0][Phi+14].energy; out.etaStrip0.cr14.eta=0; out.etaStrip0.cr14.phi=14;
out.etaStrip0.cr15.energy=temporary[Eta+0][Phi+15].energy; out.etaStrip0.cr15.eta=0; out.etaStrip0.cr15.phi=15;
out.etaStrip0.cr16.energy=temporary[Eta+0][Phi+16].energy; out.etaStrip0.cr16.eta=0; out.etaStrip0.cr16.phi=16;
out.etaStrip0.cr17.energy=temporary[Eta+0][Phi+17].energy; out.etaStrip0.cr17.eta=0; out.etaStrip0.cr17.phi=17;
out.etaStrip0.cr18.energy=temporary[Eta+0][Phi+18].energy; out.etaStrip0.cr18.eta=0; out.etaStrip0.cr18.phi=18;
out.etaStrip0.cr19.energy=temporary[Eta+0][Phi+19].energy; out.etaStrip0.cr19.eta=0; out.etaStrip0.cr19.phi=19;
out.etaStrip0.cr20.energy=temporary[Eta+0][Phi+20].energy; out.etaStrip0.cr20.eta=0; out.etaStrip0.cr20.phi=20;
out.etaStrip0.cr21.energy=temporary[Eta+0][Phi+21].energy; out.etaStrip0.cr21.eta=0; out.etaStrip0.cr21.phi=21;
out.etaStrip0.cr22.energy=temporary[Eta+0][Phi+22].energy; out.etaStrip0.cr22.eta=0; out.etaStrip0.cr22.phi=22;
out.etaStrip0.cr23.energy=temporary[Eta+0][Phi+23].energy; out.etaStrip0.cr23.eta=0; out.etaStrip0.cr23.phi=23;

out.etaStrip1.cr0.energy=temporary[Eta+1][Phi+0].energy; out.etaStrip1.cr0.eta=1; out.etaStrip1.cr0.phi=0;
out.etaStrip1.cr1.energy=temporary[Eta+1][Phi+1].energy; out.etaStrip1.cr1.eta=1; out.etaStrip1.cr1.phi=1;
out.etaStrip1.cr2.energy=temporary[Eta+1][Phi+2].energy; out.etaStrip1.cr2.eta=1; out.etaStrip1.cr2.phi=2;
out.etaStrip1.cr3.energy=temporary[Eta+1][Phi+3].energy; out.etaStrip1.cr3.eta=1; out.etaStrip1.cr3.phi=3;
out.etaStrip1.cr4.energy=temporary[Eta+1][Phi+4].energy; out.etaStrip1.cr4.eta=1; out.etaStrip1.cr4.phi=4;
out.etaStrip1.cr5.energy=temporary[Eta+1][Phi+5].energy; out.etaStrip1.cr5.eta=1; out.etaStrip1.cr5.phi=5;
out.etaStrip1.cr6.energy=temporary[Eta+1][Phi+6].energy; out.etaStrip1.cr6.eta=1; out.etaStrip1.cr6.phi=6;
out.etaStrip1.cr7.energy=temporary[Eta+1][Phi+7].energy; out.etaStrip1.cr7.eta=1; out.etaStrip1.cr7.phi=7;
out.etaStrip1.cr8.energy=temporary[Eta+1][Phi+8].energy; out.etaStrip1.cr8.eta=1; out.etaStrip1.cr8.phi=8;
out.etaStrip1.cr9.energy=temporary[Eta+1][Phi+9].energy; out.etaStrip1.cr9.eta=1; out.etaStrip1.cr9.phi=9;
out.etaStrip1.cr10.energy=temporary[Eta+1][Phi+10].energy; out.etaStrip1.cr10.eta=1; out.etaStrip1.cr10.phi=10;
out.etaStrip1.cr11.energy=temporary[Eta+1][Phi+11].energy; out.etaStrip1.cr11.eta=1; out.etaStrip1.cr11.phi=11;
out.etaStrip1.cr12.energy=temporary[Eta+1][Phi+12].energy; out.etaStrip1.cr12.eta=1; out.etaStrip1.cr12.phi=12;
out.etaStrip1.cr13.energy=temporary[Eta+1][Phi+13].energy; out.etaStrip1.cr13.eta=1; out.etaStrip1.cr13.phi=13;
out.etaStrip1.cr14.energy=temporary[Eta+1][Phi+14].energy; out.etaStrip1.cr14.eta=1; out.etaStrip1.cr14.phi=14;
out.etaStrip1.cr15.energy=temporary[Eta+1][Phi+15].energy; out.etaStrip1.cr15.eta=1; out.etaStrip1.cr15.phi=15;
out.etaStrip1.cr16.energy=temporary[Eta+1][Phi+16].energy; out.etaStrip1.cr16.eta=1; out.etaStrip1.cr16.phi=16;
out.etaStrip1.cr17.energy=temporary[Eta+1][Phi+17].energy; out.etaStrip1.cr17.eta=1; out.etaStrip1.cr17.phi=17;
out.etaStrip1.cr18.energy=temporary[Eta+1][Phi+18].energy; out.etaStrip1.cr18.eta=1; out.etaStrip1.cr18.phi=18;
out.etaStrip1.cr19.energy=temporary[Eta+1][Phi+19].energy; out.etaStrip1.cr19.eta=1; out.etaStrip1.cr19.phi=19;
out.etaStrip1.cr20.energy=temporary[Eta+1][Phi+20].energy; out.etaStrip1.cr20.eta=1; out.etaStrip1.cr20.phi=20;
out.etaStrip1.cr21.energy=temporary[Eta+1][Phi+21].energy; out.etaStrip1.cr21.eta=1; out.etaStrip1.cr21.phi=21;
out.etaStrip1.cr22.energy=temporary[Eta+1][Phi+22].energy; out.etaStrip1.cr22.eta=1; out.etaStrip1.cr22.phi=22;
out.etaStrip1.cr23.energy=temporary[Eta+1][Phi+23].energy; out.etaStrip1.cr23.eta=1; out.etaStrip1.cr23.phi=23;

out.etaStrip2.cr0.energy=temporary[Eta+2][Phi+0].energy; out.etaStrip2.cr0.eta=2; out.etaStrip2.cr0.phi=0;
out.etaStrip2.cr1.energy=temporary[Eta+2][Phi+1].energy; out.etaStrip2.cr1.eta=2; out.etaStrip2.cr1.phi=1;
out.etaStrip2.cr2.energy=temporary[Eta+2][Phi+2].energy; out.etaStrip2.cr2.eta=2; out.etaStrip2.cr2.phi=2;
out.etaStrip2.cr3.energy=temporary[Eta+2][Phi+3].energy; out.etaStrip2.cr3.eta=2; out.etaStrip2.cr3.phi=3;
out.etaStrip2.cr4.energy=temporary[Eta+2][Phi+4].energy; out.etaStrip2.cr4.eta=2; out.etaStrip2.cr4.phi=4;
out.etaStrip2.cr5.energy=temporary[Eta+2][Phi+5].energy; out.etaStrip2.cr5.eta=2; out.etaStrip2.cr5.phi=5;
out.etaStrip2.cr6.energy=temporary[Eta+2][Phi+6].energy; out.etaStrip2.cr6.eta=2; out.etaStrip2.cr6.phi=6;
out.etaStrip2.cr7.energy=temporary[Eta+2][Phi+7].energy; out.etaStrip2.cr7.eta=2; out.etaStrip2.cr7.phi=7;
out.etaStrip2.cr8.energy=temporary[Eta+2][Phi+8].energy; out.etaStrip2.cr8.eta=2; out.etaStrip2.cr8.phi=8;
out.etaStrip2.cr9.energy=temporary[Eta+2][Phi+9].energy; out.etaStrip2.cr9.eta=2; out.etaStrip2.cr9.phi=9;
out.etaStrip2.cr10.energy=temporary[Eta+2][Phi+10].energy; out.etaStrip2.cr10.eta=2; out.etaStrip2.cr10.phi=10;
out.etaStrip2.cr11.energy=temporary[Eta+2][Phi+11].energy; out.etaStrip2.cr11.eta=2; out.etaStrip2.cr11.phi=11;
out.etaStrip2.cr12.energy=temporary[Eta+2][Phi+12].energy; out.etaStrip2.cr12.eta=2; out.etaStrip2.cr12.phi=12;
out.etaStrip2.cr13.energy=temporary[Eta+2][Phi+13].energy; out.etaStrip2.cr13.eta=2; out.etaStrip2.cr13.phi=13;
out.etaStrip2.cr14.energy=temporary[Eta+2][Phi+14].energy; out.etaStrip2.cr14.eta=2; out.etaStrip2.cr14.phi=14;
out.etaStrip2.cr15.energy=temporary[Eta+2][Phi+15].energy; out.etaStrip2.cr15.eta=2; out.etaStrip2.cr15.phi=15;
out.etaStrip2.cr16.energy=temporary[Eta+2][Phi+16].energy; out.etaStrip2.cr16.eta=2; out.etaStrip2.cr16.phi=16;
out.etaStrip2.cr17.energy=temporary[Eta+2][Phi+17].energy; out.etaStrip2.cr17.eta=2; out.etaStrip2.cr17.phi=17;
out.etaStrip2.cr18.energy=temporary[Eta+2][Phi+18].energy; out.etaStrip2.cr18.eta=2; out.etaStrip2.cr18.phi=18;
out.etaStrip2.cr19.energy=temporary[Eta+2][Phi+19].energy; out.etaStrip2.cr19.eta=2; out.etaStrip2.cr19.phi=19;
out.etaStrip2.cr20.energy=temporary[Eta+2][Phi+20].energy; out.etaStrip2.cr20.eta=2; out.etaStrip2.cr20.phi=20;
out.etaStrip2.cr21.energy=temporary[Eta+2][Phi+21].energy; out.etaStrip2.cr21.eta=2; out.etaStrip2.cr21.phi=21;
out.etaStrip2.cr22.energy=temporary[Eta+2][Phi+22].energy; out.etaStrip2.cr22.eta=2; out.etaStrip2.cr22.phi=22;
out.etaStrip2.cr23.energy=temporary[Eta+2][Phi+23].energy; out.etaStrip2.cr23.eta=2; out.etaStrip2.cr23.phi=23;

out.etaStrip3.cr0.energy=temporary[Eta+3][Phi+0].energy; out.etaStrip3.cr0.eta=3; out.etaStrip3.cr0.phi=0;
out.etaStrip3.cr1.energy=temporary[Eta+3][Phi+1].energy; out.etaStrip3.cr1.eta=3; out.etaStrip3.cr1.phi=1;
out.etaStrip3.cr2.energy=temporary[Eta+3][Phi+2].energy; out.etaStrip3.cr2.eta=3; out.etaStrip3.cr2.phi=2;
out.etaStrip3.cr3.energy=temporary[Eta+3][Phi+3].energy; out.etaStrip3.cr3.eta=3; out.etaStrip3.cr3.phi=3;
out.etaStrip3.cr4.energy=temporary[Eta+3][Phi+4].energy; out.etaStrip3.cr4.eta=3; out.etaStrip3.cr4.phi=4;
out.etaStrip3.cr5.energy=temporary[Eta+3][Phi+5].energy; out.etaStrip3.cr5.eta=3; out.etaStrip3.cr5.phi=5;
out.etaStrip3.cr6.energy=temporary[Eta+3][Phi+6].energy; out.etaStrip3.cr6.eta=3; out.etaStrip3.cr6.phi=6;
out.etaStrip3.cr7.energy=temporary[Eta+3][Phi+7].energy; out.etaStrip3.cr7.eta=3; out.etaStrip3.cr7.phi=7;
out.etaStrip3.cr8.energy=temporary[Eta+3][Phi+8].energy; out.etaStrip3.cr8.eta=3; out.etaStrip3.cr8.phi=8;
out.etaStrip3.cr9.energy=temporary[Eta+3][Phi+9].energy; out.etaStrip3.cr9.eta=3; out.etaStrip3.cr9.phi=9;
out.etaStrip3.cr10.energy=temporary[Eta+3][Phi+10].energy; out.etaStrip3.cr10.eta=3; out.etaStrip3.cr10.phi=10;
out.etaStrip3.cr11.energy=temporary[Eta+3][Phi+11].energy; out.etaStrip3.cr11.eta=3; out.etaStrip3.cr11.phi=11;
out.etaStrip3.cr12.energy=temporary[Eta+3][Phi+12].energy; out.etaStrip3.cr12.eta=3; out.etaStrip3.cr12.phi=12;
out.etaStrip3.cr13.energy=temporary[Eta+3][Phi+13].energy; out.etaStrip3.cr13.eta=3; out.etaStrip3.cr13.phi=13;
out.etaStrip3.cr14.energy=temporary[Eta+3][Phi+14].energy; out.etaStrip3.cr14.eta=3; out.etaStrip3.cr14.phi=14;
out.etaStrip3.cr15.energy=temporary[Eta+3][Phi+15].energy; out.etaStrip3.cr15.eta=3; out.etaStrip3.cr15.phi=15;
out.etaStrip3.cr16.energy=temporary[Eta+3][Phi+16].energy; out.etaStrip3.cr16.eta=3; out.etaStrip3.cr16.phi=16;
out.etaStrip3.cr17.energy=temporary[Eta+3][Phi+17].energy; out.etaStrip3.cr17.eta=3; out.etaStrip3.cr17.phi=17;
out.etaStrip3.cr18.energy=temporary[Eta+3][Phi+18].energy; out.etaStrip3.cr18.eta=3; out.etaStrip3.cr18.phi=18;
out.etaStrip3.cr19.energy=temporary[Eta+3][Phi+19].energy; out.etaStrip3.cr19.eta=3; out.etaStrip3.cr19.phi=19;
out.etaStrip3.cr20.energy=temporary[Eta+3][Phi+20].energy; out.etaStrip3.cr20.eta=3; out.etaStrip3.cr20.phi=20;
out.etaStrip3.cr21.energy=temporary[Eta+3][Phi+21].energy; out.etaStrip3.cr21.eta=3; out.etaStrip3.cr21.phi=21;
out.etaStrip3.cr22.energy=temporary[Eta+3][Phi+22].energy; out.etaStrip3.cr22.eta=3; out.etaStrip3.cr22.phi=22;
out.etaStrip3.cr23.energy=temporary[Eta+3][Phi+23].energy; out.etaStrip3.cr23.eta=3; out.etaStrip3.cr23.phi=23;

out.etaStrip4.cr0.energy=temporary[Eta+4][Phi+0].energy; out.etaStrip4.cr0.eta=4; out.etaStrip4.cr0.phi=0;
out.etaStrip4.cr1.energy=temporary[Eta+4][Phi+1].energy; out.etaStrip4.cr1.eta=4; out.etaStrip4.cr1.phi=1;
out.etaStrip4.cr2.energy=temporary[Eta+4][Phi+2].energy; out.etaStrip4.cr2.eta=4; out.etaStrip4.cr2.phi=2;
out.etaStrip4.cr3.energy=temporary[Eta+4][Phi+3].energy; out.etaStrip4.cr3.eta=4; out.etaStrip4.cr3.phi=3;
out.etaStrip4.cr4.energy=temporary[Eta+4][Phi+4].energy; out.etaStrip4.cr4.eta=4; out.etaStrip4.cr4.phi=4;
out.etaStrip4.cr5.energy=temporary[Eta+4][Phi+5].energy; out.etaStrip4.cr5.eta=4; out.etaStrip4.cr5.phi=5;
out.etaStrip4.cr6.energy=temporary[Eta+4][Phi+6].energy; out.etaStrip4.cr6.eta=4; out.etaStrip4.cr6.phi=6;
out.etaStrip4.cr7.energy=temporary[Eta+4][Phi+7].energy; out.etaStrip4.cr7.eta=4; out.etaStrip4.cr7.phi=7;
out.etaStrip4.cr8.energy=temporary[Eta+4][Phi+8].energy; out.etaStrip4.cr8.eta=4; out.etaStrip4.cr8.phi=8;
out.etaStrip4.cr9.energy=temporary[Eta+4][Phi+9].energy; out.etaStrip4.cr9.eta=4; out.etaStrip4.cr9.phi=9;
out.etaStrip4.cr10.energy=temporary[Eta+4][Phi+10].energy; out.etaStrip4.cr10.eta=4; out.etaStrip4.cr10.phi=10;
out.etaStrip4.cr11.energy=temporary[Eta+4][Phi+11].energy; out.etaStrip4.cr11.eta=4; out.etaStrip4.cr11.phi=11;
out.etaStrip4.cr12.energy=temporary[Eta+4][Phi+12].energy; out.etaStrip4.cr12.eta=4; out.etaStrip4.cr12.phi=12;
out.etaStrip4.cr13.energy=temporary[Eta+4][Phi+13].energy; out.etaStrip4.cr13.eta=4; out.etaStrip4.cr13.phi=13;
out.etaStrip4.cr14.energy=temporary[Eta+4][Phi+14].energy; out.etaStrip4.cr14.eta=4; out.etaStrip4.cr14.phi=14;
out.etaStrip4.cr15.energy=temporary[Eta+4][Phi+15].energy; out.etaStrip4.cr15.eta=4; out.etaStrip4.cr15.phi=15;
out.etaStrip4.cr16.energy=temporary[Eta+4][Phi+16].energy; out.etaStrip4.cr16.eta=4; out.etaStrip4.cr16.phi=16;
out.etaStrip4.cr17.energy=temporary[Eta+4][Phi+17].energy; out.etaStrip4.cr17.eta=4; out.etaStrip4.cr17.phi=17;
out.etaStrip4.cr18.energy=temporary[Eta+4][Phi+18].energy; out.etaStrip4.cr18.eta=4; out.etaStrip4.cr18.phi=18;
out.etaStrip4.cr19.energy=temporary[Eta+4][Phi+19].energy; out.etaStrip4.cr19.eta=4; out.etaStrip4.cr19.phi=19;
out.etaStrip4.cr20.energy=temporary[Eta+4][Phi+20].energy; out.etaStrip4.cr20.eta=4; out.etaStrip4.cr20.phi=20;
out.etaStrip4.cr21.energy=temporary[Eta+4][Phi+21].energy; out.etaStrip4.cr21.eta=4; out.etaStrip4.cr21.phi=21;
out.etaStrip4.cr22.energy=temporary[Eta+4][Phi+22].energy; out.etaStrip4.cr22.eta=4; out.etaStrip4.cr22.phi=22;
out.etaStrip4.cr23.energy=temporary[Eta+4][Phi+23].energy; out.etaStrip4.cr23.eta=4; out.etaStrip4.cr23.phi=23;

out.etaStrip5.cr0.energy=temporary[Eta+5][Phi+0].energy; out.etaStrip5.cr0.eta=5; out.etaStrip5.cr0.phi=0;
out.etaStrip5.cr1.energy=temporary[Eta+5][Phi+1].energy; out.etaStrip5.cr1.eta=5; out.etaStrip5.cr1.phi=1;
out.etaStrip5.cr2.energy=temporary[Eta+5][Phi+2].energy; out.etaStrip5.cr2.eta=5; out.etaStrip5.cr2.phi=2;
out.etaStrip5.cr3.energy=temporary[Eta+5][Phi+3].energy; out.etaStrip5.cr3.eta=5; out.etaStrip5.cr3.phi=3;
out.etaStrip5.cr4.energy=temporary[Eta+5][Phi+4].energy; out.etaStrip5.cr4.eta=5; out.etaStrip5.cr4.phi=4;
out.etaStrip5.cr5.energy=temporary[Eta+5][Phi+5].energy; out.etaStrip5.cr5.eta=5; out.etaStrip5.cr5.phi=5;
out.etaStrip5.cr6.energy=temporary[Eta+5][Phi+6].energy; out.etaStrip5.cr6.eta=5; out.etaStrip5.cr6.phi=6;
out.etaStrip5.cr7.energy=temporary[Eta+5][Phi+7].energy; out.etaStrip5.cr7.eta=5; out.etaStrip5.cr7.phi=7;
out.etaStrip5.cr8.energy=temporary[Eta+5][Phi+8].energy; out.etaStrip5.cr8.eta=5; out.etaStrip5.cr8.phi=8;
out.etaStrip5.cr9.energy=temporary[Eta+5][Phi+9].energy; out.etaStrip5.cr9.eta=5; out.etaStrip5.cr9.phi=9;
out.etaStrip5.cr10.energy=temporary[Eta+5][Phi+10].energy; out.etaStrip5.cr10.eta=5; out.etaStrip5.cr10.phi=10;
out.etaStrip5.cr11.energy=temporary[Eta+5][Phi+11].energy; out.etaStrip5.cr11.eta=5; out.etaStrip5.cr11.phi=11;
out.etaStrip5.cr12.energy=temporary[Eta+5][Phi+12].energy; out.etaStrip5.cr12.eta=5; out.etaStrip5.cr12.phi=12;
out.etaStrip5.cr13.energy=temporary[Eta+5][Phi+13].energy; out.etaStrip5.cr13.eta=5; out.etaStrip5.cr13.phi=13;
out.etaStrip5.cr14.energy=temporary[Eta+5][Phi+14].energy; out.etaStrip5.cr14.eta=5; out.etaStrip5.cr14.phi=14;
out.etaStrip5.cr15.energy=temporary[Eta+5][Phi+15].energy; out.etaStrip5.cr15.eta=5; out.etaStrip5.cr15.phi=15;
out.etaStrip5.cr16.energy=temporary[Eta+5][Phi+16].energy; out.etaStrip5.cr16.eta=5; out.etaStrip5.cr16.phi=16;
out.etaStrip5.cr17.energy=temporary[Eta+5][Phi+17].energy; out.etaStrip5.cr17.eta=5; out.etaStrip5.cr17.phi=17;
out.etaStrip5.cr18.energy=temporary[Eta+5][Phi+18].energy; out.etaStrip5.cr18.eta=5; out.etaStrip5.cr18.phi=18;
out.etaStrip5.cr19.energy=temporary[Eta+5][Phi+19].energy; out.etaStrip5.cr19.eta=5; out.etaStrip5.cr19.phi=19;
out.etaStrip5.cr20.energy=temporary[Eta+5][Phi+20].energy; out.etaStrip5.cr20.eta=5; out.etaStrip5.cr20.phi=20;
out.etaStrip5.cr21.energy=temporary[Eta+5][Phi+21].energy; out.etaStrip5.cr21.eta=5; out.etaStrip5.cr21.phi=21;
out.etaStrip5.cr22.energy=temporary[Eta+5][Phi+22].energy; out.etaStrip5.cr22.eta=5; out.etaStrip5.cr22.phi=22;
out.etaStrip5.cr23.energy=temporary[Eta+5][Phi+23].energy; out.etaStrip5.cr23.eta=5; out.etaStrip5.cr23.phi=23;

return out ;
}

hgcaltp_t bestOf2(const hgcaltp_t& hgcaltp0, const hgcaltp_t& hgcaltp1) {
        hgcaltp_t x;
        x = (hgcaltp0.energy > hgcaltp1.energy)?hgcaltp0:hgcaltp1;
        return x;
}

hgcaltp_t getPeakBin24N(const etaStrip_t& etaStrip){
#pragma HLS latency min=4

hgcaltp_t best01 = bestOf2(etaStrip.cr0,etaStrip.cr1) ;
hgcaltp_t best23 = bestOf2(etaStrip.cr2,etaStrip.cr3) ;
hgcaltp_t best45 = bestOf2(etaStrip.cr4,etaStrip.cr5) ;
hgcaltp_t best67 = bestOf2(etaStrip.cr6,etaStrip.cr7) ;
hgcaltp_t best89 = bestOf2(etaStrip.cr8,etaStrip.cr9) ;
hgcaltp_t best1011 = bestOf2(etaStrip.cr10,etaStrip.cr11) ;
hgcaltp_t best1213 = bestOf2(etaStrip.cr12,etaStrip.cr13) ;
hgcaltp_t best1415 = bestOf2(etaStrip.cr14,etaStrip.cr15) ;
hgcaltp_t best1617 = bestOf2(etaStrip.cr16,etaStrip.cr17) ;
hgcaltp_t best1819 = bestOf2(etaStrip.cr18,etaStrip.cr19) ;
hgcaltp_t best2021 = bestOf2(etaStrip.cr20,etaStrip.cr21) ;
hgcaltp_t best2223 = bestOf2(etaStrip.cr22,etaStrip.cr23) ;

hgcaltp_t best0123 = bestOf2(best01,best23) ;
hgcaltp_t best4567 = bestOf2(best45,best67) ;
hgcaltp_t best891011 = bestOf2(best89,best1011) ;
hgcaltp_t best12131415 = bestOf2(best1213,best1415) ;
hgcaltp_t best16171819 = bestOf2(best1617,best1819) ;
hgcaltp_t best20212223 = bestOf2(best2021,best2223) ;

hgcaltp_t best01234567 = bestOf2(best0123,best4567) ;
hgcaltp_t best89101112131415 = bestOf2(best891011,best12131415) ;
hgcaltp_t best16to23 = bestOf2(best16171819,best20212223) ;

hgcaltp_t best0to15 = bestOf2(best01234567,best89101112131415) ;
hgcaltp_t bestOf24 = bestOf2(best0to15,best16to23) ;

return bestOf24 ;
}

towerMax getPeakBin6N(const etaStripPeak_t& etaStrip){
#pragma HLS latency min=4

towerMax x;

hgcaltp_t best01 = bestOf2(etaStrip.pk0,etaStrip.pk1) ;
hgcaltp_t best23 = bestOf2(etaStrip.pk2,etaStrip.pk3) ;
hgcaltp_t best45 = bestOf2(etaStrip.pk4,etaStrip.pk5) ;

hgcaltp_t best0123 = bestOf2(best01,best23) ;

hgcaltp_t bestOf6 = bestOf2(best0123,best45) ;

        x.energy = bestOf6.energy ;
        x.etaMax = bestOf6.eta ;
        x.phiMax = bestOf6.phi ;

//cout << " get peak " << x.energy << " eta " << x.etaMax << " phi " << x.phiMax << endl ;

return x ;
}

jetInfo getJetPosition(const hgcalRegion_t& hgcalRegion){
 #pragma HLS latency min=4

        etaStripPeak_t etaStripPeak;
        jetInfo jet ;


                etaStripPeak.pk0 = getPeakBin24N(hgcalRegion.etaStrip0);
                etaStripPeak.pk1 = getPeakBin24N(hgcalRegion.etaStrip1);
                etaStripPeak.pk2 = getPeakBin24N(hgcalRegion.etaStrip2);
                etaStripPeak.pk3 = getPeakBin24N(hgcalRegion.etaStrip3);
                etaStripPeak.pk4 = getPeakBin24N(hgcalRegion.etaStrip4);
                etaStripPeak.pk5 = getPeakBin24N(hgcalRegion.etaStrip5);

        towerMax peakIn6;
        peakIn6 = getPeakBin6N(etaStripPeak);

        jet.seedEnergy = peakIn6.energy ;
        jet.energy = 0 ;
        jet.etaMax = peakIn6.etaMax ;
        jet.phiMax = peakIn6.phiMax ;

return jet ;
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

cout <<  " tmp " << tmp1 << "   " << tmp2 << "  " << tmp3 << endl ;
                eta_slice[m] = tmp1 + tmp2 + tmp3 ;
			}
               }
          }}


         jet_tmp.energy=eta_slice[0] + eta_slice[1] + eta_slice[2] ;

        for(loop i=0; i<TOWER_IN_ETA; i++){
//                        #pragma HLS UNROLL
           if(i+1>=seed_eta && i<=seed_eta+1){ 
           for(loop k=0; k<TOWER_IN_PHI; k++){
                        #pragma HLS UNROLL
            if(k+1>=seed_phi && k<=seed_phi+1)  tempX[i][k].energy = 0 ;}
         }}

return jet_tmp ;
}


jetInfo getRegion(tower temp[TOWER_IN_ETA][TOWER_IN_PHI]){
#pragma HLS ARRAY_PARTITION variable=temp complete dim=0
#pragma HLS latency min=24
jetInfo jet_tmp, jet;

hgcalRegion_t hgcalRegion;

        hgcalRegion = initStructure(temp) ;

        jet_tmp = getJetPosition(hgcalRegion) ;

        ap_uint<5> seed_phi = jet_tmp.phiMax ;
        ap_uint<5> seed_eta = jet_tmp.etaMax ;

// it gets values and removes used 
//
        jet = getJetValues(temp, seed_eta, seed_phi) ;

        jet_tmp.energy = jet.energy;


return jet_tmp;
}


void algo_topIP1(ap_uint<576> link_in[N_INPUT_LINKS], ap_uint<576> link_out[N_OUTPUT_LINKS]){
#pragma HLS ARRAY_PARTITION variable=link_in complete dim=0
#pragma HLS ARRAY_PARTITION variable=link_out complete dim=0
#pragma HLS PIPELINE II=9
#pragma HLS INTERFACE ap_ctrl_hs port=return

	tower HGCALRegion[TOWER_IN_ETA][TOWER_IN_PHI];
#pragma HLS ARRAY_PARTITION variable=HGCALRegion complete dim=0

	jetInfo jet[10] ;

//creating 18x4 towers temporary 

	processInputLinks(link_in, HGCALRegion);

        for(loop i=0; i<10; i++) jet[i] = getRegion(HGCALRegion);

        /*---------------------------------link 0------------------------------------*/
        
	link_out[0] = 0;
        ap_uint<32> start ;
        ap_uint<32> end ;

        for(loop i=0; i<10; i++)
          {    
		cout << " inside " << jet[i].energy << endl ;

		start=34*i ; end=34*i+11; 
		link_out[0].range(end, start) = jet[i].energy ; }
}

