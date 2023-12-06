#include "zene_fgk.h"
#include "strukturak.h"
#include "kinezet.h"
#include "debugmalloc.h"
#include <stdio.h>
#include <strings.h>

Zenek *zene_hozzaad(Zenek *zene){
    Zenek *tmp;
    tmp = (Zenek*)malloc(sizeof(Zenek));
    int perc,mp, allapot = 0;
    printf("Cim: ");
    scanf("%s",tmp->cim);
    printf("Eloado: ");
    scanf("%s",tmp->eloado);
    printf("Lemez: ");
    scanf("%s",tmp->lemez_cim);
    printf("Mufaj: ");
    scanf("%s",tmp->mufaj);
    while(allapot == 0){
    printf("Ev: ");
    scanf("%d", &(tmp->ev));
    printf("Honap: ");
    scanf("%d", &(tmp->ho));
    printf("Nap: ");
    scanf("%d", &(tmp->nap));
    allapot = helyes_datum(tmp->nap, tmp->ho, tmp->ev);
    if(allapot == 0)
        printf("Kerem helyes datumot hasznaljon.\n");
    }
    printf("Hossz(perce): ");
    scanf("%d", &perc);
    printf("Hossz(masodperce): ");
    scanf("%d", &mp);
    tmp->hossz = ((perc * 60) + mp);
    tmp->kov = NULL;

    if(tmp == NULL)
        zene = tmp;
    Zenek *mozgo = zene;
    while(mozgo->kov != NULL)
        mozgo = mozgo->kov;
    mozgo->kov = tmp;
}

void zenek_kiir(Zenek *eleje){
    Zenek *mozgo;
    for(mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov)
        printf("%s %s %s %s %d/%d/%d %s\n", mozgo->cim, mozgo->eloado, mozgo->lemez_cim, mozgo->mufaj, mozgo->nap, mozgo->ho, mozgo->ev,  ido_alakito_vissza(mozgo->hossz));
}

void zene_keres(Zenek *eleje){
    char cim[50];
    printf("Keresett zene cime: ");
    scanf("%s", cim);
    system("cls");
    fejlec("Kereses");
    Zenek *mozgo;
    for(mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov)
        if(strcmp(mozgo->cim,cim)==0)
            printf("%s %s %s %s %d/%d/%d %d\n", mozgo->cim, mozgo->eloado, mozgo->lemez_cim, mozgo->mufaj, mozgo->nap, mozgo->ho, mozgo->ev, ido_alakito_vissza(mozgo->hossz));
        else if(mozgo->kov == NULL)
            printf("Nincs ilyen zene az adatbazisunkban.\n");
}

void zene_torol(Zenek *eleje){
    char cim[50+1];
    printf("Torlendo zene cime: ");
    scanf("%s", cim);
    Zenek *mozgo = eleje;
    Zenek *lemarado = NULL;
    while((mozgo!=NULL)&&(strcmp(mozgo->cim,cim)!=0)){
        lemarado = mozgo;
        mozgo = mozgo->kov;
    }
    if(mozgo == NULL)
        printf("Nincs ilyen zene.");
    else{
        if(lemarado == NULL){
            strcpy(mozgo->cim, mozgo->kov->cim);
            strcpy(mozgo->eloado, mozgo->kov->eloado);
            strcpy(mozgo->lemez_cim, mozgo->kov->lemez_cim);
            strcpy(mozgo->mufaj, mozgo->kov->mufaj);
            mozgo->nap = mozgo->kov->nap;
            mozgo->ho = mozgo->kov->ho;
            mozgo->ev = mozgo->kov->ev;
            mozgo->hossz = mozgo->kov->hossz;
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        lemarado->kov = mozgo->kov;
        free(mozgo);
        printf("Sikeresen torolve.");
    }
}
