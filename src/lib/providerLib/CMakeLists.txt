cmake_minimum_required(VERSION 3.10)

project(providerLib)

file(
    GLOB
    SOURCE_LIB
    library/*[!winCmdExec].cpp
)

if (WIN32) 
    set(
        SOURCE_LIB
        ${SOURCE_LIB}
        library/winCmdExec.cpp
    )
endif()

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${SOURCE_LIB})
