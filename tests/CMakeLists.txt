file(GLOB C_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*.c)
add_custom_target(dkl-time-tests)

# Dependencies

if (NOT TARGET dtest)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/lib/dtest/CMakeLists.txt")
        add_subdirectory(lib/dtest)
        link_libraries(dtest)
        include_directories(../lib/dtest/include ../lib/dtest/header)
    else ()
        include_directories(../lib/dtest/include ../lib/dtest)
    endif()
endif ()

include_directories(../header)

foreach (module ${C_FILES})
    get_filename_component(name ${module} NAME_WE)
    set(libname dkl-time-ts-${name})
    add_library(${libname} SHARED ${module})
    target_link_libraries(${libname} PRIVATE dkl-time)
    add_dependencies(dkl-time-tests ${libname})
endforeach ()
