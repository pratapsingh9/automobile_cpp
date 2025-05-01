cmake_minimum_required(VERSION 3.14)
project(AutomobileMaintenance VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Main library
add_library(AutomobileMaintenance
    src/Automobile.cpp
    src/ElectricCar.cpp
    src/GasCar.cpp
    src/DieselCar.cpp
    src/MaintenanceTask.cpp
    src/MaintenanceLibrary.cpp
)

# Demo application
add_executable(maintenance_demo app/main.cpp)
target_link_libraries(maintenance_demo AutomobileMaintenance)

# Unit tests with Google Test
if(BUILD_TESTING)
    enable_testing()
    find_package(GTest REQUIRED)
    
    add_executable(tests
        test/test_main.cpp
        test/AutomobileTest.cpp
        test/MaintenanceLibraryTest.cpp
    )
    
    target_link_libraries(tests 
        AutomobileMaintenance 
        GTest::GTest 
        GTest::Main
    )
    
    include(GoogleTest)
    gtest_discover_tests(tests)
endif()