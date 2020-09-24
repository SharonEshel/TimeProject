cmake_minimum_required(VERSION 3.18)
project(TimeProject)

set(CMAKE_CXX_STANDARD 98)

add_executable(TimeProject main.cpp my_time.cpp my_time.h msg_printer.cpp msg_printer.h timers.cpp timers.h)