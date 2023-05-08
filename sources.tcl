### Set the top level module
set_top algo_topJet

### Add source code
add_files GCTHGCAL/algo_topJet.cpp
add_files GCTHGCAL/makeSTforJet.cpp

### Add testbed files
add_files -tb GCTHGCAL/algo_top_tbJet.cpp

