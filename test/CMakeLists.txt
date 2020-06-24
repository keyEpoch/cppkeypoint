cmake_minimum_required(VERSION 2.8)

project(main)

aux_source_directory(. CPPSRC)

add_executable(Main ${CPPSRC})
