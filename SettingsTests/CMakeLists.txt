project(setting_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(${PROJECT_NAME} UnitTests.cpp)

add_library(setting SHARED ${SOURCES} Setting.cpp)

target_link_libraries(setting)
