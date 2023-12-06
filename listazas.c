#include "listazas.h"

void zenek_to_lemez(Zenek *zene, Lemezek *lemez){
    char cim[51];
    Zenek *eleje = NULL;
    printf("Lemez lemez cime: ");
    scanf("%s", cim);
    system("cls");
    fejlec(cim);
    Zenek *mozgo;
    for(mozgo = zene; mozgo != NULL; mozgo = mozgo->kov)
        if(strcmp(mozgo->lemez_cim,cim)==0)
            printf("%s %s %s %s %d/%d/%d %s\n", mozgo->cim, mozgo->eloado, mozgo->lemez_cim, mozgo->mufaj, mozgo->nap, mozgo->ho, mozgo->ev,  ido_alakito_vissza(mozgo->hossz));
}
