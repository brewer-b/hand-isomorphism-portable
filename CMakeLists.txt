cmake_minimum_required(VERSION 3.10)

project(HandIsomorphism)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    src/hand_index.c
    src/hand_isomorphism.cpp
)

add_library(hand_isomorphism_static STATIC ${SOURCES})
add_library(hand_isomorphism_shared SHARED ${SOURCES})

#add_executable(check_main src/check_main.cpp)
#target_link_libraries(check_main hand_isomorphism_shared)

target_include_directories(hand_isomorphism_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(hand_isomorphism_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
