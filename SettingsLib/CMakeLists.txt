project(Setting)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(setting SHARED ${SOURCES} Setting.cpp)