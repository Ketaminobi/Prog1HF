#include "kinezet.h"

int szokoev(int ev){
    return (((ev % 4 == 0) && (ev % 100 != 0)) || (ev % 400 == 0));
}

int helyes_datum(int nap, int ho, int ev){
    if (ev > 2100 || ev < 1930)
        return 0;
    if (ho < 1 || ho > 12)
        return 0;
    if (nap < 1 || nap > 31)
        return 0;

    if (ho == 2)
    {
        if (szokoev(ev))
            return (nap <= 29);
        else
            return (nap <= 28);
    }

    if (ho == 4 || ho == 6 || ho == 9 || ho == 11)
        return (nap <= 30);
    return 1;
}

char *ido_alakito_vissza(int ertek){
    int mp, perc, ora;
    char *ido = (char*)malloc(3*sizeof(char));
    ora = (ertek / 3600);
    perc = (ertek - (3600*ora))/60;
    mp = (ertek - (3600*ora))-(perc*60);
    sprintf(&ido[0], "%d", perc);
    ido[1] = ':';
    sprintf(&ido[2], "%d", mp);
    return ido;
}

void kozepen(const char* szoveg){
    int hossz =0;
    int hely = 0;
    hossz = (48 - strlen(szoveg))/2;
    for(hely = 0 ; hely < hossz ; hely++)
        printf(" ");
    printf("%s",szoveg);
}

void fejlec(const char *szoveg){
    system("cls");
    printf("************************************************");
    printf("\n************                        ************");
    printf("\n************      Kenobi Music      ************");
    printf("\n************                        ************");
    printf("\n************************************************");
    printf("\n------------------------------------------------\n");
    kozepen(szoveg);
    printf("\n------------------------------------------------\n");
}

void error(){
    printf("\n  --------------------------------------------------------\n");
    printf("\n        *********************************************");
    printf("\n        *                    KEREM                  *");
    printf("\n        *                      A                    *");
    printf("\n        *                 LEHETOSEGEK               *");
    printf("\n        *                    KOZUL                  *");
    printf("\n        *                  VALASSZON                *");
    printf("\n        *********************************************");
    printf("\n  --------------------------------------------------------\n");
}

void udvozles(){
    printf("\n  --------------------------------------------------------\n");
    printf("\n        *********************************************");
    printf("\n        *           KOSZONTI                        *");
    printf("\n        *                   A                       *");
    printf("\n        *                    KENOBI                 *");
    printf("\n        *                         MUSIC             *");
    printf("\n        *********************************************");
    printf("\n  --------------------------------------------------------\n");
}

void tavozas(){
    printf("\n  --------------------------------------------------------\n");
    printf("\n        *********************************************");
    printf("\n        *         KOSZONJUK                         *");
    printf("\n        *                HOGY                       *");
    printf("\n        *                   MINKET                  *");
    printf("\n        *                       VALASZTOTT          *");
    printf("\n        *********************************************");
    printf("\n  --------------------------------------------------------\n");
}
