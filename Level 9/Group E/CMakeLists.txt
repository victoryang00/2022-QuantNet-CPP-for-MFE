cmake_minimum_required(VERSION 3.23)
project(Group_E)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost)
include_directories(ExcelVisualisation)
include_directories(../)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(Group_E_MyTest
            ExcelVisualisation/DatasimException.cpp
            ExcelVisualisation/EUoption.cpp
            ExcelVisualisation/EUoption.h
            ExcelVisualisation/ExcelDriver.cpp
            ExcelVisualisation/ExcelMechanisms.cpp
            ExcelVisualisation/MyTest.cpp
            ExcelVisualisation/StringConversions.cpp)

    target_link_libraries(Group_E_MyTest ${Boost_LIBRARIES})
    add_executable(Group_E_TestTwoCurve
            ExcelVisualisation/DatasimException.cpp
            ExcelVisualisation/EUoption.cpp
            ExcelVisualisation/EUoption.h
            ExcelVisualisation/ExcelDriver.cpp
            ExcelVisualisation/ExcelMechanisms.cpp
            ExcelVisualisation/TestTwoCurve.cpp
            ExcelVisualisation/StringConversions.cpp)

    target_link_libraries(Group_E_TestTwoCurve ${Boost_LIBRARIES})
    add_executable(Group_E_TestSingleCurve
            ExcelVisualisation/DatasimException.cpp
            ExcelVisualisation/EUoption.cpp
            ExcelVisualisation/EUoption.h
            ExcelVisualisation/ExcelDriver.cpp
            ExcelVisualisation/ExcelMechanisms.cpp
            ExcelVisualisation/TestSingleCurve.cpp
            ExcelVisualisation/StringConversions.cpp)

    target_link_libraries(Group_E_TestSingleCurve ${Boost_LIBRARIES})
    add_executable(Group_E_TestMultiCurve
            ExcelVisualisation/DatasimException.cpp
            ExcelVisualisation/EUoption.cpp
            ExcelVisualisation/EUoption.h
            ExcelVisualisation/ExcelDriver.cpp
            ExcelVisualisation/ExcelMechanisms.cpp
            ExcelVisualisation/TestMultiCurve.cpp
            ExcelVisualisation/StringConversions.cpp)

    target_link_libraries(Group_E_TestMultiCurve ${Boost_LIBRARIES})
endif ()