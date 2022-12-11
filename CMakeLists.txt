CMAKE_MINIMUM_REQUIRED(VERSION 2.8)  
PROJECT(RANSAC) 
set( CMAKE_CXX_FLAGS "-std=c++11") 
INCLUDE_DIRECTORIES("/usr/include/eigen3") #("${EIGEN3_INCLUDE_DIR}")  
#SET(EIGEN3_INCLUDE_DIR "$ENV{EIGEN3_INCLUDE_DIR}")  
#IF(NOT EIGEN3_INCLUDE_DIR)  
#    MESSAGE( FATAL_ERROR "Please point the environment variable EIGEN3_INCLUDE_DIR to the include directory of your Eigen3 installation.")  
#ENDIF()  
#INCLUDE_DIRECTORIES(/usr/include/eigen3) #("${EIGEN3_INCLUDE_DIR}")  
  
#ADD_EXECUTABLE(test test.cpp)  
#include_directories(src)
# 找到src目录及其子目录下的所有c文件和h文件
file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp") #"MATRIX/*.cpp" "Grad/*.cpp"
file(GLOB_RECURSE PROJECT_HEADERS "src/*.h" )
#file(GLOB_RECURSE PROJECT_SOURCES "src/*.cpp" "src/*.c" "src/*.cc")
#file(GLOB_RECURSE PROJECT_HEADERS "src/*.hpp" "src/*.h" "src/*.hh")

add_executable(RANSAC ${PROJECT_SOURCES}  ${PROJECT_HEADERS})
