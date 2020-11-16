cmake_minimum_required(VERSION 3.16)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled2 main.cpp Pokemon.cpp Pokemon.h YamlWriter.cpp YamlWriter.h StrongPokemon.cpp StrongPokemon.h FatPokemon.cpp FatPokemon.h)