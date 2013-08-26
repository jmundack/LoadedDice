cmake_minimum_required(VERSION 2.8)

project (LoadedDice)
set(CMAKE_INSTALL_PREFIX "debug")
add_definitions(-Wall -Werror) # enable all warnings and mark warnings as errors
add_definitions(-O3)  # enable optimizations
add_definitions(-g)  # enable debugging 

find_package(Boost REQUIRED)
if(Boost_FOUND)
   message(STATUS "Boost Libraries found")
   include_directories(${Boost_INCLUDE_DIRS})
   add_subdirectory (source)
else()
   message(FATAL_ERROR "Boost Libraries not found")
endif()
