#include "lemez_fgk.h"

void lemez_hozzad(Lemezek *lemez){
    Lemezek *tmp = (Lemezek*)malloc(sizeof(Lemezek));
    int allapot = 0;
    printf("Cim: ");
    scanf("%s",tmp->cim);
    printf("Eloado: ");
    scanf("%s",tmp->eloado);
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
    tmp->kov = NULL;
    if(lemez == NULL)
        lemez = tmp;
    Lemezek *mozgo = lemez;
    while(mozgo->kov != NULL)
        mozgo = mozgo->kov;
    mozgo->kov = tmp;
}

void lemezek_kiir(Lemezek *eleje){
    Lemezek *mozgo;
    for(mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov)
        printf("%s %s %s %d/%d/%d\n", mozgo->cim, mozgo->eloado, mozgo->mufaj, mozgo->nap, mozgo->ho, mozgo->ev);
}

void lemez_keres(Lemezek *eleje){
    char cim[51];
    printf("Keresett lemez cime: ");
    scanf("%s", cim);
    system("cls");
    fejlec("Kereses");
    Lemezek *mozgo;
    int figyelo = 0;
    for(mozgo = eleje; mozgo != NULL; mozgo = mozgo->kov)
        if(strcmp(mozgo->cim,cim)==0){
            printf("%s %s %s %d/%d/%d\n", mozgo->cim, mozgo->eloado, mozgo->mufaj, mozgo->nap, mozgo->ho, mozgo->ev);
            figyelo++;
        }
        else if((mozgo == NULL) && (figyelo == 0))
            printf("Nincs ilyen lemez az adatbazisunkban.\n");
}

void lemez_torol(Lemezek *eleje){
    char cim[50+1];
    printf("Torlendo lemez cime: ");
    scanf("%s", cim);
    Lemezek *mozgo = eleje;
    Lemezek *lemarado = NULL;
    while((mozgo!=NULL)&&(strcmp(mozgo->cim,cim)!=0)){
        lemarado = mozgo;
        mozgo = mozgo->kov;
    }
    if(mozgo == NULL)
        printf("Nincs ilyen lemez.");
    else{
        if(lemarado == NULL){
            strcpy(mozgo->cim, mozgo->kov->cim);
            strcpy(mozgo->eloado, mozgo->kov->eloado);
            strcpy(mozgo->mufaj, mozgo->kov->mufaj);
            mozgo->nap = mozgo->kov->nap;
            mozgo->ho = mozgo->kov->ho;
            mozgo->ev = mozgo->kov->ev;
            lemarado = mozgo;
            mozgo = mozgo->kov;
        }
        lemarado->kov = mozgo->kov;
        free(mozgo);
        printf("Sikeresen torolve.");
    }
}
