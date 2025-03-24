#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mantenimiento.h"

void iniLM(ListaMantenimientos *lm) {
    lm->aMantenimiento = NULL;
    lm->numMantenimientos = 0;
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
}

void printM(Mantenimiento m) {
    printf("%5d%10d%15s%30s%10.2f%30s\n",
           m.id,
           m.vehiculo_id,
           m.fecha,
           m.tipo,
           m.coste,
           m.descripcion);
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

    return m;
}
