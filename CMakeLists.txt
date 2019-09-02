cmake_minimum_required(VERSION 2.8.9)
project(dkl-time
        #[[VERSION 0.1.2]]
        LANGUAGES C
        )

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic --static")

# tutorial

#[[set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
set(CMAKE_NAME Windows)
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS)
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS)]]

set(incude_ls include/dkl-time.h)
set(all_files
        header/main.h
        ${incude_ls}
        src/now.c src/format.c src/convert.c
        )
#add_library(dkl-time SHARED ${all_files})
add_library(dkl-time STATIC ${all_files})

target_include_directories(dkl-time PRIVATE header)
target_include_directories(dkl-time PUBLIC include)

set_target_properties(
        dkl-time PROPERTIES
        PUBLIC_HEADER "${incude_ls}"
)

# example

add_subdirectory(examples)

install(TARGETS dkl-time
        PUBLIC_HEADER DESTINATION include
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        )