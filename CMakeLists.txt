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
