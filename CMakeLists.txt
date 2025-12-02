cmake_minimum_required(VERSION 3.15)
project(MinimalExample CXX)
set(CMAKE_CXX_STANDARD 17)

# Create a small library with the code you want to test
add_library(mylib add.cpp)

# Main executable
add_executable(minimal main.cpp)
target_link_libraries(minimal PRIVATE mylib)

# Enable CTest
enable_testing()

# Test executable
add_executable(test_minimal test_minimal.cpp)
target_link_libraries(test_minimal PRIVATE mylib)

add_test(NAME SimpleTest COMMAND test_minimal)

# ---- GoogleTest ----
# ---- GoogleTest requirse calling CTest enable_testing()
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# ---- Test executable ----
add_executable(gtest_minimal gtest_minimal.cpp)
target_link_libraries(gtest_minimal PRIVATE mylib gtest_main)

include(GoogleTest)
gtest_discover_tests(gtest_minimal)

# ---- End GoogleTest

# ---- Catch2 ----
include(FetchContent)
FetchContent_Declare(
  catch2
  URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.6.0.zip
)
FetchContent_MakeAvailable(catch2)

# ---- Test executable ----
add_executable(catch_test_minimal catch_test_minimal.cpp)
target_link_libraries(catch_test_minimal PRIVATE mylib Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(catch_test_minimal)