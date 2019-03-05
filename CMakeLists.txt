cmake_minimum_required(VERSION 3.2)
PROJECT(ALGORITHM)

INCLUDE_DIRECTORIES(.)
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

add_compile_options(-std=c++11)
ADD_SUBDIRECTORY(test)
ADD_EXECUTABLE(algorithm ${DIR_SRCS})
target_link_libraries(algorithm algorithm_test)
