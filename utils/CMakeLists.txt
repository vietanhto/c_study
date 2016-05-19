cmake_minimum_required(VERSION 2.8)
project(utils)

include_directories(${PROJECT_SOURCE_DIR}/..)

add_library(utils 
    ${PROJECT_SOURCE_DIR}/src/DoubleLinkedList.c
)

add_executable(DoubleLinkedListTest ${PROJECT_SOURCE_DIR}/tst/DoubleLinkedListTest.c)
target_link_libraries(DoubleLinkedListTest utils)
