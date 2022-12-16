cmake_minimum_required(VERSION 3.23)
project(Group_B)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost)

include_directories(.)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(Group_B
            main.cpp
            PerpAmeOption.cpp
            PerpAmeOption.h)

    target_link_libraries(Group_B ${Boost_LIBRARIES})
endif ()