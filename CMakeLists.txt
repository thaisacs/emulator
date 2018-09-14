cmake_minimum_required(VERSION 3.4)
project(emulator)
include_directories(includes)


file(GLOB FONTES "src/*.cpp")
add_executable(Main ${FONTES})
