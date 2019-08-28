cmake_minimum_required(VERSION 2.8.9)
project(dkl-time
        #[[VERSION 0.1.0]]
        LANGUAGES C
        )

set(CMAKE_C_STANDARD 11)

set(all_files
        header/main.h
        include/dkl-time.h
        src/now.c src/format.c
        )
add_library(dkl-time SHARED ${all_files})
#add_library(dkl-time STATIC ${all_files})

target_include_directories(dkl-time PRIVATE header)
target_include_directories(dkl-time PUBLIC include)

# example

add_executable(dkl-time-now examples/now/main.c)
target_include_directories(dkl-time-now PRIVATE include)
target_link_libraries(dkl-time-now PRIVATE dkl-time)
