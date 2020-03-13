cmake_minimum_required(VERSION 3.10)

project(providerLib)

file(
    GLOB
    SOURCE_LIB
    library/*.cpp
)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})
