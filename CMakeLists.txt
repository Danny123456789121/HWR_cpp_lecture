cmake_minimum_required(VERSION 3.24)
project(vector_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(
        main main.cpp ZeichenElement.cpp ZeichenElement.h Koordinate.cpp Koordinate.h Kreis.cpp Kreis.h Rechteck.cpp Rechteck.h UI.h)
