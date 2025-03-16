#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "audit.h"

void iniLAU(ListaAuditorias *lau) {
    lau->aAuditoria = NULL;
    lau->numAuditorias = 0;
}

void addAudit(ListaAuditorias *lau, Auditoria a) {
    int i;

    if (lau->aAuditoria == NULL) {
    	lau->aAuditoria = malloc(1 * sizeof(Auditoria));
    } else {
    	Auditoria *aux = malloc(lau->numAuditorias * sizeof(Auditoria));
        for (i = 0; i < lau->numAuditorias; i++) {
            aux[i] = lau->aAuditoria[i];
        }
        free(lau->aAuditoria);
        lau->aAuditoria = malloc((lau->numAuditorias + 1) * sizeof(Auditoria));
        for (i = 0; i < lau->numAuditorias; i++) {
        	lau->aAuditoria[i] = aux[i];
        }
        free(aux);
    }
    lau->aAuditoria[lau->numAuditorias] = a;
    lau->numAuditorias++;
}
