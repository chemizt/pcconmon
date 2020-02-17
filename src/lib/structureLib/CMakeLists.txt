cmake_minimum_required(VERSION 3.10)

project(structureLib)

set(
    SOURCE_LIB 
    library/auxClasses.cpp
    library/coreClasses.cpp
    library/hardwareClasses.cpp
)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})