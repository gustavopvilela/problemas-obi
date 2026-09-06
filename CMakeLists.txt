cmake_minimum_required(VERSION 4.2)
project(ProblemasOBI)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE cpp_files "*.cpp")
foreach(file ${cpp_files})
    get_filename_component(target_name ${file} NAME_WE)
    add_executable(${target_name} ${file})
endforeach()
