include(GrPlatform)
add_library(graph
  src/libgraph_common.cc
)
include_directories(hdr ${CMAKE_SOURCE_DIR}/cmn_hdr)
include_directories(hdr ${CMAKE_SOURCE_DIR}/liblte/hdr)
include_directories(hdr ${CMAKE_SOURCE_DIR}/libtools/hdr)
include_directories(hdr ${CMAKE_SOURCE_DIR}/LTE_fdd_dl_file_track/hdr)
include_directories(hdr ${CMAKE_SOURCE_DIR}/LTE_fdd_dl_track/hdr)
