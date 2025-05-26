#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"

void iniLA(ListaAlquileres *la) {
    la->aAlquiler = NULL;
    la->numAlquileres = 0;
    writeLog("Inicializada lista.",FICHERO_ALQUILER_LOG);
}

void addAlquiler(ListaAlquileres *la, Alquiler a) {
    int i;

    if (la->aAlquiler == NULL) {
        la->aAlquiler = malloc(1 * sizeof(Alquiler));
    } else {
        Alquiler *aux = malloc(la->numAlquileres * sizeof(Alquiler));
        for (i = 0; i < la->numAlquileres; i++) {
            aux[i] = la->aAlquiler[i];
        }
        free(la->aAlquiler);
        la->aAlquiler = malloc((la->numAlquileres + 1) * sizeof(Alquiler));
        for (i = 0; i < la->numAlquileres; i++) {
            la->aAlquiler[i] = aux[i];
        }
        free(aux);
    }
    la->aAlquiler[la->numAlquileres] = a;
    la->numAlquileres++;
    writeLog("Añadido alquiler.",FICHERO_ALQUILER_LOG);
}

void printA(Alquiler a) {
    printf("%15d%15d%15s%15s%15.2f\n",
           a.operacion_id,
           a.vehiculo_id,
           a.fecha_inicio,
           a.fecha_fin,
           a.precio_diario);
    fflush(stdout);
    writeLog("Print alquiler.",FICHERO_ALQUILER_LOG);
}

void printLA(ListaAlquileres la) {
    int i;
    printf("%15s%15s%15s%15s%15s\n",
           "OPERACION_ID",
           "VEHICULO_ID",
           "FECHA_INICIO",
           "FECHA_FIN",
           "PRECIO_DIARIO");
    fflush(stdout);
    for (i = 0; i < la.numAlquileres; i++) {
        printA(la.aAlquiler[i]);
    }
    writeLog("Print lista alquiler.",FICHERO_ALQUILER_LOG);
}

Alquiler realizarAlquiler(ListaAlquileres la) {
    Alquiler a;

    a.operacion_id = la.numAlquileres;
    printf("Introduce el ID del vehículo: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%d", &a.vehiculo_id);
    printf("Introduce la fecha de inicio (YYYY-MM-DD): ");
    fflush(stdout);
    fflush(stdin);
    fgets(a.fecha_inicio, TAM_FECHA, stdin);
    a.fecha_inicio[strcspn(a.fecha_inicio, "\n")] = 0;
    printf("Introduce la fecha de fin (YYYY-MM-DD): ");
    fflush(stdout);
    fflush(stdin);
    fgets(a.fecha_fin, TAM_FECHA, stdin);
    a.fecha_fin[strcspn(a.fecha_fin, "\n")] = 0;
    printf("Introduce el precio diario: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%lf", &a.precio_diario);

    return a;
    writeLog("Pedido alquiler a usuario.",FICHERO_ALQUILER_LOG);
}
