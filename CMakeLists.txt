cmake_minimum_required(VERSION 3.28)
project(ProjetoIIA C)

set(CMAKE_C_STANDARD 11)

add_executable(ProjetoIIA main.c
        algoritmo.h
        algoritmo.c
        funcao.h
        funcao.c
        utils.h
        utils.c
)
