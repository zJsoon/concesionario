#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "audit.h"

void iniLAU(ListaAuditorias *lau) {
    lau->aAuditoria = NULL;
    lau->numAuditorias = 0;
    writeLog("AUDITORIAS: iniLAU Ejecutado", FICHERO_AUDIT_LOG);
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
    writeLog("AUDITORIAS: addAudit Ejecutado", FICHERO_AUDIT_LOG);
}

void printAU(Auditoria a) {
    printf("%10d%15d%20s%15s%30s\n",
           a.id,
           a.operacion_id,
           a.usuario,
           a.fecha_modificacion,
           a.cambios);
}

void printLAU(ListaAuditorias lau) {
    int i;
    printf("%10s%15s%20s%15s%30s\n",
           "ID",
           "OPERACION_ID",
           "USUARIO",
           "FECHA_MODIF",
           "CAMBIOS");
    for (i = 0; i < lau.numAuditorias; i++) {
        printAU(lau.aAuditoria[i]);
    }
    writeLog("AUDITORIAS: printLAU Ejecutado", FICHERO_AUDIT_LOG);
}

Auditoria realizarAuditoria(ListaAuditorias la) {
    Auditoria a;

    a.id = la.numAuditorias;
    printf("Introduce el ID de la operación: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%d", &a.operacion_id);
    printf("Introduce el nombre de usuario: ");
    fgets(a.usuario, TAM_USUARIO, stdin);
    a.usuario[strcspn(a.usuario, "\n")] = 0;
    printf("Introduce la fecha de modificación (YYYY-MM-DD): ");
    fgets(a.fecha_modificacion, TAM_FECHA, stdin);
    a.fecha_modificacion[strcspn(a.fecha_modificacion, "\n")] = 0;
    printf("Introduce los cambios realizados: ");
    fgets(a.cambios, TAM_CAMBIOS, stdin);
    a.cambios[strcspn(a.cambios, "\n")] = 0;
    writeLog("AUDITORIAS: realizarAuditoria Ejecutado", FICHERO_AUDIT_LOG);
    return a;
}
