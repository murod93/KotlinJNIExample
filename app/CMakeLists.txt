cmake_minimum_required(VERSION 3.4.1)

# Global
set(CPP_ROOT src/main/cpp)

find_library( log-lib log)
find_library(android-lib android)

# Verifier
add_library(
        example-lib
        SHARED
        ${CPP_ROOT}/example.cpp
)

target_link_libraries(
        example-lib
        ${android-lib}
        ${log-lib}
)

