cmake_minimum_required(VERSION 3.10)

project(pcConMon)

set(SOURCE_MAIN src/sandbox/source/main.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/out/lib)
# set(CMAKE_CXX_FLAGS "-O3 -Os -Wall -Wextra -Wno-unused-value -pedantic -std=c++2a")
set(CMAKE_CXX_FLAGS "-g3 -ggdb -Wall -Wextra -Wno-unused-value -pedantic -std=c++2a")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
cmake_policy(SET CMP0079 NEW)

add_executable(
    testMain
    ${SOURCE_MAIN}
)

target_include_directories(
    testMain
    PUBLIC src/lib/structureLib/include
    PUBLIC src/lib/providerLib/include
)

add_subdirectory(src/lib/structureLib)
add_subdirectory(src/lib/providerLib)

target_include_directories(
    providerLib
    PUBLIC src/lib/structureLib/include
    PUBLIC external/pstreams
)

target_link_libraries(providerLib structureLib)
target_link_libraries(testMain structureLib providerLib)
