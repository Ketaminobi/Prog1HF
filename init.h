#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED
#include <string.h>
#include "zene_fgk.h"

Zenek *zenek_init();
void zenek_save(Zenek *eleje);
void zenek_free(Zenek *eleje);
Zenek *zene_letrehoz(Zenek *elozo, char *tcim, char *teloado, char *tlemez_cim, char *tmufaj, int tnap, int tho, int tev, int thossz);
Lemezek *lemezek_init();
void lemezek_save(Lemezek *eleje);
void lemezek_free(Lemezek *eleje);
Lemezek *lemez_letrehoz(Lemezek *elozo, char *tcim, char *teloado, char *tmufaj, int tnap, int tho, int tev);

#endif // INIT_H_INCLUDED

