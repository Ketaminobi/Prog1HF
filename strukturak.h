#ifndef STRUKTURAK_H_INCLUDED
#define STRUKTURAK_H_INCLUDED
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Zenek{
    char cim[50+1];
    char eloado[50+1];
    char lemez_cim[50+1];
    char mufaj[50+1];
    int nap, ho, ev;
    int hossz;
    struct Zenek *kov;
}Zenek;

typedef struct Lemezek{
    char cim[50+1];
    char eloado[50+1];
    char mufaj[50+1];
    int ev,ho,nap;
    struct Lemezek *kov;
}Lemezek;


#endif // STRUKTURAK_H_INCLUDED
