cmake_minimum_required(VERSION 3.6)
project(Karatsuba_Multiplication)

set(CMAKE_CXX_STANDARD 11)
set(BOOST_ROOT "/usr/local/Cellar/boost/1.63.0")
find_package(Boost 1.63.0)

set(SOURCE_FILES main.cpp)
add_executable(Karatsuba_Multiplication ${SOURCE_FILES})