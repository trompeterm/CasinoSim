# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CasinoSim_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CasinoSim_autogen.dir\\ParseCache.txt"
  "CasinoSim_autogen"
  )
endif()
