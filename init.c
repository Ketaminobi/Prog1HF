#include "init.h"

Zenek *zenek_init(){
    //fajl inicializalasa
    Zenek *eleje = NULL;
    FILE *fz;
    fz = fopen("zenek.txt", "rt");
    Zenek *zene = (Zenek*)malloc(sizeof(Zenek)); //memoria lefoglalas
    char t[500+1];
    while(fgets(t,501,fz)!=0){
        char tcim[50+1];
        char teloado[50+1];
        char tlemez_cim[50+1];
        char tmufaj[50+1];
        int tnap,tho,tev;
        int thossz;
        //van-e mar benne elem, ha nincs akkor ez lesz az elso
        if(eleje == NULL){
            sscanf(t, "%s\t%s\t%s\t%s\t%d/%d/%d\t%d\n", zene->cim, zene->eloado, zene->lemez_cim, zene->mufaj, &zene->nap, &zene->ho, &zene->ev, &zene->hossz);
            zene->kov = NULL;
            eleje = zene;
        }
        else{
            sscanf(t, "%s\t%s\t%s\t%s\t%d/%d/%d\t%d\n", tcim, teloado, tlemez_cim, tmufaj, &tnap, &tho, &tev, &thossz);
            zene = zene_letrehoz(zene, tcim, teloado, tlemez_cim, tmufaj, tnap, tho, tev, thossz); //hozzafuzzuk a tobbit ha van
        }
    }
    fclose(fz);
    return eleje;
}

void zenek_save(Zenek *eleje){
    //fajlkezeles
    FILE *fz;
    fz = fopen("zenek.txt", "w");
    if(fz == NULL) {
        return NULL;
        //perror("Nem sikerült a fájlt megnyitni");
    }
    for(Zenek *mozgo = eleje; mozgo!=NULL; mozgo = mozgo->kov)
        fprintf(fz, "%s\t%s\t%s\t%s\t%d/%d/%d\t%d\n", mozgo->cim, mozgo->eloado, mozgo->lemez_cim, mozgo->mufaj, mozgo->nap, mozgo->ho, mozgo->ev, mozgo->hossz); //mentes
    fclose(fz);
}

void zenek_free(Zenek *eleje){
    Zenek *mozgo = eleje;
    Zenek *kov = NULL;
    while(mozgo!=NULL){
        kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

Zenek *zene_letrehoz(Zenek *elozo, char *tcim, char *teloado, char *tlemez_cim, char *tmufaj, int tnap, int tho, int tev, int thossz){
    Zenek *uj_zene = (Zenek*)malloc(sizeof(Zenek));
    strcpy(uj_zene->cim, tcim);
    strcpy(uj_zene->eloado, teloado);
    strcpy(uj_zene->lemez_cim, tlemez_cim);
    strcpy(uj_zene->mufaj, tmufaj);
    uj_zene->nap = tnap;
    uj_zene->ho = tho;
    uj_zene->ev = tev;
    uj_zene->hossz = thossz;
    uj_zene->kov = NULL;
    elozo->kov = uj_zene;
    return uj_zene;
}


Lemezek *lemezek_init(){
    Lemezek *lemezek = NULL;
    Lemezek *uj,tmp;
    FILE *fl = fopen("lemezek.txt", "rt");

    while(fscanf(fl, "%s\t%s\t%s\t%d/%d/%d\n",&tmp.cim,&tmp.eloado,&tmp.mufaj,&tmp.nap,&tmp.ho,&tmp.ev)==6){
        uj =(Lemezek*)malloc(sizeof(Lemezek));
        strcpy(uj->cim,tmp.cim);
        strcpy(uj->eloado,tmp.eloado);
        strcpy(uj->mufaj,tmp.mufaj);
        uj->nap = tmp.nap;
        uj->ho = tmp.ho;
        uj->ev = tmp.ev;
        uj->kov = lemezek;
        lemezek = uj;
    }
    fclose(fl);
    return lemezek;
}

void lemezek_save(Lemezek *eleje){
    FILE *fl;
    fl = fopen("lemezek.txt", "w");
    for(Lemezek *mozgo = eleje; mozgo!=NULL; mozgo = mozgo->kov)
        fprintf(fl, "%s\t%s\t%s\t%d/%d/%d\n", mozgo->cim, mozgo->eloado, mozgo->mufaj, mozgo->nap, mozgo->ho, mozgo->ev);
    fclose(fl);
}

void lemezek_free(Lemezek *eleje){
    Lemezek *mozgo = eleje;
    Lemezek *kov = NULL;
    while(mozgo!=NULL){
        kov = mozgo->kov;
        free(mozgo);
        mozgo = kov;
    }
}

Lemezek *lemez_letrehoz(Lemezek *elozo, char *tcim, char *teloado, char *tmufaj, int tnap, int tho, int tev){
    Lemezek *uj_lemez = (Lemezek*)malloc(sizeof(Lemezek));
    strcpy(uj_lemez->cim, tcim);
    strcpy(uj_lemez->eloado, teloado);
    strcpy(uj_lemez->mufaj, tmufaj);
    uj_lemez->nap = tnap;
    uj_lemez->ho = tho;
    uj_lemez->ev = tev;
    uj_lemez->kov = NULL;
    elozo->kov = uj_lemez;
    return uj_lemez;
}
