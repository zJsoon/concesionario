#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vent.h"
#include "../veh/veh.h"


void iniLVent(ListaVent *lvent) {
    lvent->aVent = NULL;
    lvent->numVentas = 0;
    writeLog("VENT: iniLVent Ejecutado.",FICHERO_VENT_LOG);
}


void addVent(ListaVent *lvent, Vent v) {
    int i;

    if (lvent->aVent == NULL) {
        lvent->aVent = malloc(1 * sizeof(Vent));
    } else {
        Vent *aux = malloc(lvent->numVentas * sizeof(Vent));
        for (i = 0; i < lvent->numVentas; i++) {
            aux[i] = lvent->aVent[i];
        }
        free(lvent->aVent);
        lvent->aVent = malloc((lvent->numVentas + 1) * sizeof(Vent));
        for (i = 0; i < lvent->numVentas; i++) {
            lvent->aVent[i] = aux[i];
        }
        free(aux);
    }
    lvent->aVent[lvent->numVentas] = v;
    lvent->numVentas++;
    writeLog("VENT: addVent Ejecutado.",FICHERO_VENT_LOG);
}

void printVent(Vent v) {
    printf("%10d%10d%15.2f%20s\n",
           v.operacion_id,
           v.vehiculo_id,
           v.precio_final,
           v.metodo_pago);fflush(stdout);
    writeLog("VENT: printVent Ejecutado.",FICHERO_VENT_LOG);
}

void printLVent(ListaVent lvent) {
    int i;
    printf("%10s%10s%15s%20s\n",
           "OPER_ID",
           "VEH_ID",
           "PRECIO_FINAL",
           "METODO_PAGO");fflush(stdout);
    for (i = 0; i < lvent.numVentas; i++) {
        printVent(lvent.aVent[i]);
    }
    writeLog("VENT: printLVent Ejecutado.",FICHERO_VENT_LOG);
}

Vent registrarVenta(ListaVent *listaVentas, ListaVeh listaVehiculos, char *matricula) {
    Vent nuevaVenta;
    int vehiculo_id = obtenerVehiculoID(listaVehiculos, matricula);

    if (vehiculo_id == -1) {
        printf("Vehículo con matrícula %s no encontrado.\n", matricula);fflush(stdout);
        return nuevaVenta;
    }

    nuevaVenta.vehiculo_id = vehiculo_id;
    nuevaVenta.operacion_id = listaVentas->numVentas;
    printf("Introduce el precio final: ");fflush(stdout);fflush(stdin);
    scanf("%lf", &nuevaVenta.precio_final);
    printf("Introduce el método de pago: ");fflush(stdout);fflush(stdin);
    fgets(nuevaVenta.metodo_pago, TAM_METODO_PAGO, stdin);
    nuevaVenta.metodo_pago[strcspn(nuevaVenta.metodo_pago, "\n")] = 0;

    addVent(listaVentas, nuevaVenta);
    printf("Venta registrada con éxito.\n");fflush(stdout);
    writeLog("VENT: registrarVenta Ejecutado.",FICHERO_VENT_LOG);
    return nuevaVenta;
}
