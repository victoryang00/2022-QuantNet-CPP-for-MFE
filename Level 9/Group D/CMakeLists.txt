cmake_minimum_required(VERSION 3.24)
project(Group_D)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost)

include_directories(.)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
add_executable(Group_D
        ArrayMechanisms.cpp
        ArrayMechanisms.hpp
        main.cpp
        NormalGenerator.cpp
        NormalGenerator.hpp
        OptionData.hpp
        Range.cpp
        Range.hpp
        Vector.cpp
        Vector.hpp)

target_link_libraries(Group_D ${Boost_LIBRARIES})
endif()