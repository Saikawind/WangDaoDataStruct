cmake_minimum_required(VERSION 3.19)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(DataStruct)

set(CMAKE_CXX_STANDARD 98) #使用c++98

file(GLOB_RECURSE files *.cpp)
foreach (file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
endforeach ()
