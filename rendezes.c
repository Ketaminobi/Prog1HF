#include "rendezes.h"

void zene_abc_novekvo(Zenek *eleje){
    Zenek *tmp = (Zenek*)malloc(sizeof(Zenek));
    tmp = eleje;
    char c;
    while(tmp->kov != NULL){
        tmp = tmp->kov;
        c++;
    }
    tmp = eleje;
    char tcim[50+1];
    char teloado[50+1];
    char tlemez_cim[50+1];
    char tmufaj[50+1];
    int tnap,tho,tev;
    int thossz;
    for(int i = 0; i < c; i++){
        tmp = eleje;
        while(tmp->kov != NULL){
            if(strcmp(tmp->cim, tmp->kov->cim) > 0){
                strcpy(tcim, tmp->cim);
                strcpy(tmp->cim, tmp->kov->cim);
                strcpy(tmp->kov->cim, tcim);
                strcpy(teloado, tmp->eloado);
                strcpy(tmp->eloado, tmp->kov->eloado);
                strcpy(tmp->kov->eloado, teloado);
                strcpy(tlemez_cim, tmp->lemez_cim);
                strcpy(tmp->lemez_cim, tmp->kov->lemez_cim);
                strcpy(tmp->kov->lemez_cim, tlemez_cim);
                strcpy(tmufaj, tmp->mufaj);
                strcpy(tmp->mufaj, tmp->kov->mufaj);
                strcpy(tmp->kov->mufaj, tmufaj);
                tnap = tmp->nap;
                tmp->nap = tmp->kov->nap;
                tmp->kov->nap = tnap;
                tho = tmp->ho;
                tmp->ho = tmp->kov->ho;
                tmp->kov->ho = tho;
                tev = tmp->ev;
                tmp->ev = tmp->kov->ev;
                tmp->kov->ev = tev;
                thossz = tmp->hossz;
                tmp->hossz = tmp->kov->hossz;
                tmp->kov->hossz = thossz;
            }
        tmp = tmp->kov;
        }
    }
    tmp = eleje;
    zenek_kiir(tmp);
    free(tmp);
}
