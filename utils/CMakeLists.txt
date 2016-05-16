cmake_minimum_required(VERSION 2.8)
project(samplelib)

include_directories(${PROJECT_SOURCE_DIR}/..)

add_executable(DoubleLinkedListTest ${PROJECT_SOURCE_DIR}/tst/DoubleLinkedListTest.c
                                    ${PROJECT_SOURCE_DIR}/src/DoubleLinkedList.c)
