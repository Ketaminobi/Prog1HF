#include <stdio.h>
#include <stdlib.h>
#include "zene_fgk.h"
#include "menu.h"
#include "kinezet.h"


int main(){
    Zenek *zene = zenek_init();
    Lemezek *lemez = lemezek_init();
    menu_belep(zene, lemez);

    return 0;
}
