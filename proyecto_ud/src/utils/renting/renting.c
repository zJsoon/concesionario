#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "renting.h"

void iniLR(ListaRenting *lr) {
    lr->aRenting = NULL;
    lr->numRenting = 0;
}

void addRenting(ListaRenting *lr, Renting r) {
    int i;

    if (lr->aRenting == NULL) {
        lr->aRenting = malloc(1 * sizeof(Renting));
    } else {
        Renting *aux = malloc(lr->numRenting * sizeof(Renting));
        for (i = 0; i < lr->numRenting; i++) {
            aux[i] = lr->aRenting[i];
        }
        free(lr->aRenting);
        lr->aRenting = malloc((lr->numRenting + 1) * sizeof(Renting));
        for (i = 0; i < lr->numRenting; i++) {
            lr->aRenting[i] = aux[i];
        }
        free(aux);
    }
    lr->aRenting[lr->numRenting] = r;
    lr->numRenting++;
}

void printR(Renting r) {
    printf("%10d%10d%15d%15.2f\n",
           r.operacion_id,
           r.vehiculo_id,
           r.duracion_meses,
           r.precio_mensual);
}

void printLR(ListaRenting lr) {
    int i;
    printf("%10s%10s%15s%15s\n",
           "OPER_ID",
           "VEH_ID",
           "DURACION",
           "PRECIO_MENSUAL");
    for (i = 0; i < lr.numRenting; i++) {
        printRenting(lr.aRenting[i]);
    }
}

Renting registrarRenting(ListaRenting lr) {
    Renting r;

    r.operacion_id = lr.numRenting;
    printf("Introduce el ID del vehículo: ");
    scanf("%d", &r.vehiculo_id);
    printf("Introduce la duración en meses: ");
    scanf("%d", &r.duracion_meses);
    printf("Introduce el precio mensual: ");
    scanf("%lf", &r.precio_mensual);

    return r;
}
