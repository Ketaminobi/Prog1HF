#ifndef KINEZET_H_INCLUDED
#define KINEZET_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

void kozepen(const char* szoveg);
void fejlec(const char *szoveg);
void error();
void udvozles();
void tavozas();
char *ido_alakito_vissza(int ertek);
int szokoev(int ev);
int helyes_datum(int nap, int ho, int ev);


#endif // KINEZET_H_INCLUDED
