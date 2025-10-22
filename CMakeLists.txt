cmake_minimum_required(VERSION 3.28.3)
project(lab03)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=maybe-uninitialized")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.0
  TLS_VERIFY false
)

FetchContent_MakeAvailable(googletest)

add_library(${CMAKE_PROJECT_NAME}_lib 
    src/function.cpp
    src/square.cpp
    src/rectangle.cpp
    src/trapezoid.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${CMAKE_PROJECT_NAME}_lib)

enable_testing()

add_executable(tests test/tests03.cpp)
target_link_libraries(tests PRIVATE ${CMAKE_PROJECT_NAME}_lib gtest gtest_main)
target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_test(NAME lab03Tests COMMAND tests)