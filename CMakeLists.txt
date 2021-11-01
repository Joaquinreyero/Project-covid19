cmake_minimum_required(VERSION 3.19)
project(Project_covid19)

set(CMAKE_CXX_STANDARD 14)


add_executable(Project_covid19 main.cpp estad.cpp p_casos.cpp muertes.cpp casos_edad.cpp casos_cui.cpp)