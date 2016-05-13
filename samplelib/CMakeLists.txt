cmake_minimum_required(VERSION 2.8)
project(samplelib)

include_directories(${PROJECT_SOURCE_DIR}/..)
add_executable(samplelib ${PROJECT_SOURCE_DIR}/src/samplelib.c)

enable_testing()
add_test(samplelibTest samplelib)