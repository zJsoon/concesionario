#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vent.h"
#include "../veh/veh.h"


void iniLVent(ListaVent *lvent) {
    lvent->aVent = NULL;
    lvent->numVentas = 0;
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
}

void printVent(Vent v) {
    printf("%10d%10d%15.2f%20s\n",
           v.operacion_id,
           v.vehiculo_id,
           v.precio_final,
           v.metodo_pago);
}

void printLVent(ListaVent lvent) {
    int i;
    printf("%10s%10s%15s%20s\n",
           "OPER_ID",
           "VEH_ID",
           "PRECIO_FINAL",
           "METODO_PAGO");
    for (i = 0; i < lvent.numVentas; i++) {
        printVent(lvent.aVent[i]);
    }
}

Vent registrarVent(ListaVent lvent) {
    Vent v;

    v.operacion_id = lvent.numVentas;
    printf("Introduce el ID del vehículo: ");
    scanf("%d", &v.vehiculo_id);
    printf("Introduce el precio final: ");
    scanf("%lf", &v.precio_final);
    getchar(); // Limpiar el buffer
    printf("Introduce el método de pago: ");
    fgets(v.metodo_pago, TAM_METODO_PAGO, stdin);
    v.metodo_pago[strcspn(v.metodo_pago, "\n")] = 0;

    return v;
}

int obtenerVehiculoID(ListaVeh listaVehiculos, const char *matricula) {
    for (int i = 0; i < listaVehiculos.numVeh; i++) {
        if (strcmp(listaVehiculos.aVeh[i].matricula, matricula) == 0) {
            return listaVehiculos.aVeh[i].ID;
        }
    }
    return -1; //Vehiculo no encontrado
}

Vent registrarVenta(ListaVent *listaVentas, ListaVeh listaVehiculos, char *matricula) {
    Vent nuevaVenta;
    int vehiculo_id = obtenerVehiculoID(listaVehiculos, matricula);

    if (vehiculo_id == -1) {
        printf("Vehículo con matrícula %s no encontrado.\n", matricula);
        return nuevaVenta;
    }

    nuevaVenta.vehiculo_id = vehiculo_id;
    nuevaVenta.operacion_id = listaVentas->numVentas;
    printf("Introduce el precio final: ");
    scanf("%lf", &nuevaVenta.precio_final);
    getchar();
    printf("Introduce el método de pago: ");
    fgets(nuevaVenta.metodo_pago, TAM_METODO_PAGO, stdin);
    nuevaVenta.metodo_pago[strcspn(nuevaVenta.metodo_pago, "\n")] = 0;

    addVent(listaVentas, nuevaVenta);
    printf("Venta registrada con éxito.\n");

    return nuevaVenta;
}
