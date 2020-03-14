cmake_minimum_required(VERSION 3.10)

project(pcConMon)

cmake_policy(SET CMP0079 NEW)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/out/bin/debug)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/out/lib/debug)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/out/lib/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/out/bin/release)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/out/lib/release)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/out/lib/release)
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -ggdb -Wall -Wextra -pedantic -std=c++17")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Os -Wall -Wextra -pedantic -std=c++17")
set(CMAKE_STATIC_LIBRARY_PREFIX "")

if (CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES Debug Release)
endif()

set(SOURCE_MAIN src/sandbox/source/main.cpp)

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

add_custom_target(
    debug
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
)

add_custom_target(
    release
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
)
