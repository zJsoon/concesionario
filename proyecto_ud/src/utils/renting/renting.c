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
        printR(lr.aRenting[i]);
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

    // Iniciar un renting (crear uno nuevo para una matrícula)
    Renting startRenting(ListaRenting *lr, int vehiculo_id) {
        Renting r;

        r.operacion_id = lr->numRenting;
        r.vehiculo_id = vehiculo_id;

        printf("Introduce la duración del renting en meses: ");
        scanf("%d", &r.duracion_meses);
        printf("Introduce el precio mensual del renting: ");
        scanf("%lf", &r.precio_mensual);

        addRenting(lr, r);

        printf("Renting iniciado correctamente.\n");
        return r;
    }

    // Mostrar el estado del renting de un vehículo
    void estadoRenting(ListaRenting lr, int vehiculo_id) {
        int i, encontrado = 0;
        for (i = 0; i < lr.numRenting; i++) {
            if (lr.aRenting[i].vehiculo_id == vehiculo_id) {
                printf("Estado del renting:\n");
                printR(lr.aRenting[i]);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            printf("No se encontró un renting activo para el vehículo con ID %d.\n", vehiculo_id);
        }
    }

    // Finalizar un renting (eliminarlo)
    Renting endRenting(ListaRenting *lr, int vehiculo_id) {
        int i, j;
        Renting eliminado;
        eliminado.operacion_id = -1; // indicador de no encontrado

        for (i = 0; i < lr->numRenting; i++) {
            if (lr->aRenting[i].vehiculo_id == vehiculo_id) {
                eliminado = lr->aRenting[i];

                for (j = i; j < lr->numRenting - 1; j++) {
                    lr->aRenting[j] = lr->aRenting[j + 1];
                }
                lr->numRenting--;
                lr->aRenting = realloc(lr->aRenting, lr->numRenting * sizeof(Renting));
                printf("Renting finalizado y eliminado correctamente.\n");
                break;
            }
        }

        if (eliminado.operacion_id == -1) {
            printf("No se encontró un renting para el vehículo con ID %d.\n", vehiculo_id);
        }

        return eliminado;
    }

}
