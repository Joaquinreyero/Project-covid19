cmake_minimum_required(VERSION 3.19)
project(Project_covid19)

set(CMAKE_CXX_STANDARD 14)


add_executable(Project_covid19 main.cpp estad.h p_casos.h muertes.h casos_edad.h casos_cui.h Estructuras/Hashmap/HashMap.h Estructuras/Hashmap/HashEntry.h)