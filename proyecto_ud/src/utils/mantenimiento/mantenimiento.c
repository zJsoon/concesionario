#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mantenimiento.h"

void iniLM(ListaMantenimientos *lm) {
    lm->aMantenimiento = NULL;
    lm->numMantenimientos = 0;
    writeLog("MANTENIMIENTO: iniLM Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}
void addMantenimiento(ListaMantenimientos *lm, Mantenimiento m) {
    int i;

    if (lm->aMantenimiento == NULL) {
        lm->aMantenimiento = malloc(1 * sizeof(Mantenimiento));
    } else {
        Mantenimiento *aux = malloc(lm->numMantenimientos * sizeof(Mantenimiento));
        for (i = 0; i < lm->numMantenimientos; i++) {
            aux[i] = lm->aMantenimiento[i];
        }
        free(lm->aMantenimiento);
        lm->aMantenimiento = malloc((lm->numMantenimientos + 1) * sizeof(Mantenimiento));
        for (i = 0; i < lm->numMantenimientos; i++) {
            lm->aMantenimiento[i] = aux[i];
        }
        free(aux);
    }
    lm->aMantenimiento[lm->numMantenimientos] = m;
    lm->numMantenimientos++;

    writeLog("MANTENIMIENTO: addMantenimiento Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

void printM(Mantenimiento m) {
    printf("%5d%10d%15s%30s%10.2f%30s\n",
           m.id,
           m.vehiculo_id,
           m.fecha,
           m.tipo,
           m.coste,
           m.descripcion);
    writeLog("MANTENIMIENTO: printM Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

void printLM(ListaMantenimientos lm) {
    int i;
    printf("%5s%10s%15s%30s%10s%30s\n",
           "ID",
           "VEH_ID",
           "FECHA",
           "TIPO_MANTENIMIENTO",
           "COSTE",
           "DESCRIPCION");
    for (i = 0; i < lm.numMantenimientos; i++) {
        printM(lm.aMantenimiento[i]);
    }
    writeLog("MANTENIMIENTO: printLM Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

Mantenimiento registrarMantenimiento(ListaMantenimientos lm) {
    Mantenimiento m;

    m.id = lm.numMantenimientos;
    printf("Introduce el ID del vehículo: ");
    scanf("%d", &m.vehiculo_id);
    getchar(); // Limpiar el buffer
    printf("Introduce la fecha (YYYY-MM-DD): ");
    fgets(m.fecha, TAM_FECHA, stdin);
    m.fecha[strcspn(m.fecha, "\n")] = 0;
    printf("Introduce el tipo de mantenimiento: ");
    fgets(m.tipo, TAM_TIPO_MANTENIMIENTO, stdin);
    m.tipo[strcspn(m.tipo, "\n")] = 0;
    printf("Introduce el coste: ");
    scanf("%lf", &m.coste);
    getchar(); // Limpiar el buffer
    printf("Introduce la descripción: ");
    fgets(m.descripcion, TAM_DESCRIPCION, stdin);
    m.descripcion[strcspn(m.descripcion, "\n")] = 0;
    writeLog("MANTENIMIENTO: registrarMantenimiento Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
    return m;
}

void registrarRep(ListaMantenimientos *lm, char *matricula) {
    printf("Registrando reparación para el vehículo con matrícula: %s\n", matricula);
    Mantenimiento m = registrarMantenimiento(*lm);
    strcpy(m.tipo, "Reparacion");
    addMantenimiento(lm, m);
    writeLog("MANTENIMIENTO: registrarRep Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

void registrarRevi(ListaMantenimientos *lm, char *matricula) {
    printf("Registrando revisión para el vehículo con matrícula: %s\n", matricula);
    Mantenimiento m = registrarMantenimiento(*lm);
    strcpy(m.tipo, "Revision");
    addMantenimiento(lm, m);
    writeLog("MANTENIMIENTO: registrarRevi Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

void visualizarMantRep(ListaMantenimientos lm, char *matricula) {
    printf("Lista de Mantenimientos de reparación para el vehículo con matrícula: %s\n", matricula);
    printf("%5s%10s%15s%30s%10s%30s\n", "ID", "VEH_ID", "FECHA", "TIPO_MANTENIMIENTO", "COSTE", "DESCRIPCION");
    for (int i = 0; i < lm.numMantenimientos; i++) {
        if (strcmp(lm.aMantenimiento[i].tipo, "Reparacion") == 0) {
            printM(lm.aMantenimiento[i]);
        }
    }
    writeLog("MANTENIMIENTO: visualizarMantRep Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

void visualizarMantRevi(ListaMantenimientos lm, char *matricula) {
    printf("Mantenimientos de revisión para el vehículo con matrícula: %s\n", matricula);
    printf("%5s%10s%15s%30s%10s%30s\n", "ID", "VEH_ID", "FECHA", "TIPO_MANTENIMIENTO", "COSTE", "DESCRIPCION");
    for (int i = 0; i < lm.numMantenimientos; i++) {
        if (strcmp(lm.aMantenimiento[i].tipo, "Revision") == 0) {
            printM(lm.aMantenimiento[i]);
        }
    }
    writeLog("MANTENIMIENTO: visualizarMantRevi Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

