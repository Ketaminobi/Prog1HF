cmake_minimum_required(VERSION 3.24)
project(NHF C)

set(CMAKE_C_STANDARD 90)

include_directories(.)

add_executable(NHF
        debugmalloc.h
        init.c
        init.h
        kinezet.c
        kinezet.h
        lemez_fgk.c
        lemez_fgk.h
        listazas.c
        listazas.h
        main.c
        menu.c
        menu.h
        rendezes.c
        rendezes.h
        strukturak.h
        zene_fgk.c
        zene_fgk.h)
