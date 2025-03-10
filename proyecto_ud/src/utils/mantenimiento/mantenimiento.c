#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mantenimiento.h"

void iniLM(ListaMantenimientos *lm) {
    lm->aMantenimiento = NULL;
    lm->numMantenimientos = 0;
}
