cmake_minimum_required(VERSION 3.28)
project(PayrollSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(PayrollSystem main.cpp
        PayrollSystem.cpp
        PayrollSystem.h
        Employee.cpp
        Employee.h
        DatabaseConnection.cpp
        DatabaseConnection.h
        TimeLog.cpp
        TimeLog.h)

find_package(SQLite3 REQUIRED)
include_directories(${SQLite3_INCLUDE_DIRS})
target_link_libraries(PayrollSystem ${SQLite3_LIBRARIES})