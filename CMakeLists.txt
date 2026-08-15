cmake_minimum_required(VERSION 3.10.2)
project("redirector")

# Compile to .so
add_library(redirector SHARED redirector.cpp)

# Link essential Android libraries to log
find_library(log-lib log)
target_link_libraries(redirector ${log-lib})
