cmake_minimum_required(VERSION 3.23)
project(Group_A)

set(CMAKE_CXX_STANDARD 14)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost)
include_directories(.)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(Group_A
            EUoption.cpp
            EUoption.h
            main.cpp
            OptionElements.h)

    target_link_libraries(Group_A ${Boost_LIBRARIES})
endif()

