cmake_minimum_required(VERSION 3.24)
project(Group_E)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost)

include_directories(ExcelVisualisation)
include_directories(../)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
add_executable(Group_E
        ExcelVisualisation/DatasimException.cpp
        ExcelVisualisation/EUoption.cpp
        ExcelVisualisation/EUoption.h
        ExcelVisualisation/ExcelDriver.cpp
        ExcelVisualisation/ExcelMechanisms.cpp
        ExcelVisualisation/MyTest.cpp
        ExcelVisualisation/StringConversions.cpp
        ExcelVisualisation/TestMultiCurve.cpp
        ExcelVisualisation/TestSingleCurve.cpp
        ExcelVisualisation/TestTwoCurve.cpp)

target_link_libraries(Group_E ${Boost_LIBRARIES})
endif()