add_executable(dkl-time-now main.c)

target_include_directories(dkl-time-now PRIVATE ../include)

target_link_libraries(dkl-time-now PRIVATE dkl-time pthread)
