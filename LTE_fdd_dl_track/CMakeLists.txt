include(GrPlatform)
include_directories(hdr
  ${CMAKE_SOURCE_DIR}/liblte/hdr
  ${CMAKE_SOURCE_DIR}/libgraph/hdr
  ${CMAKE_SOURCE_DIR}/libtools/hdr
  ${CMAKE_SOURCE_DIR}/cmn_hdr
  ${CMAKE_SOURCE_DIR}/LTE_fdd_dl_file_track/hdr
  ${CMAKE_SOURCE_DIR}/LTE_fdd_dl_track/hdr
)
add_executable(LTE_fdd_dl_track
  src/LTE_fdd_dl_track_main.cc
  src/LTE_fdd_dl_track_interface.cc
  src/LTE_fdd_dl_track_flowgraph.cc
  src/LTE_fdd_dl_track_state_machine.cc
)
target_link_libraries(LTE_fdd_dl_track lte graph itpp fftw3f tools pthread ${UHD_LIBRARIES} ${Boost_LIBRARIES} ${GNURADIO_RUNTIME_LIBRARIES} ${GNURADIO_BLOCKS_LIBRARIES} ${GNURADIO_FILTER_LIBRARIES} ${GNURADIO_PMT_LIBRARIES} ${GNURADIO_OSMOSDR_LIBRARIES})
set_target_properties(LTE_fdd_dl_track PROPERTIES DEFINE_SYMBOL "LTE_fdd_dl_track_state_machine_EXPORTS")
install(TARGETS LTE_fdd_dl_track DESTINATION bin)
