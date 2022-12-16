cmake_minimum_required(VERSION 3.24)
project(Group_C)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost)

include_directories(.)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(Group_C
            main.cpp
            NormalGenerator.cpp
            NormalGenerator.hpp
            OptionData.hpp)

    target_link_libraries(Group_C ${Boost_LIBRARIES})
endif ()