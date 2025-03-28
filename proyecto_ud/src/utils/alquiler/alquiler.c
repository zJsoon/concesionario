#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alquiler.h"
#include "../veh/veh.h"

void iniLA(ListaAlquileres *la) {
    la->aAlquiler = NULL;
    la->numAlquileres = 0;
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
}

void printA(Alquiler a) {
    printf("%15d%15d%15s%15s%15.2f\n",
           a.operacion_id,
           a.vehiculo_id,
           a.fecha_inicio,
           a.fecha_fin,
           a.precio_diario);
}

void printLA(ListaAlquileres la) {
    int i;
    printf("%15s%15s%15s%15s%15s\n",
           "OPERACION_ID",
           "VEHICULO_ID",
           "FECHA_INICIO",
           "FECHA_FIN",
           "PRECIO_DIARIO");
    for (i = 0; i < la.numAlquileres; i++) {
        printA(la.aAlquiler[i]);
    }
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
    a.fecha_inicio[strcspn(a.fecha_inicio, "\n")] = 0;  // Eliminar el salto de línea
    printf("Introduce la fecha de fin (YYYY-MM-DD): ");
    fflush(stdout);
    fflush(stdin);
    fgets(a.fecha_fin, TAM_FECHA, stdin);
    a.fecha_fin[strcspn(a.fecha_fin, "\n")] = 0;  // Eliminar el salto de línea
    printf("Introduce el precio diario: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%lf", &a.precio_diario);

    return a;
}

Alquiler startAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la) {
    Alquiler nuevoAlquiler;
    int vehiculoEncontrado = 0;

    for (int i = 0; i < lv->numVeh; i++) {
        if (strcmp(lv->aVeh[i].matricula, matricula) == 0) {
            vehiculoEncontrado = 1;
            nuevoAlquiler.vehiculo_id = lv->aVeh[i].ID;
            break;
        }
    }

    if (!vehiculoEncontrado) {
        printf("Vehículo con matrícula %s no encontrado.\n", matricula);
        exit(1);
    }

    nuevoAlquiler.operacion_id = la->numAlquileres;


    printf("Introduce la fecha de inicio (YYYY-MM-DD): ");
    fflush(stdout);
    fflush(stdin);
    fgets(nuevoAlquiler.fecha_inicio, TAM_FECHA, stdin);
    nuevoAlquiler.fecha_inicio[strcspn(nuevoAlquiler.fecha_inicio, "\n")] = 0;  // Eliminar el salto de línea

    printf("Introduce la fecha de fin (YYYY-MM-DD): ");
    fflush(stdout);
    fflush(stdin);
    fgets(nuevoAlquiler.fecha_fin, TAM_FECHA, stdin);
    nuevoAlquiler.fecha_fin[strcspn(nuevoAlquiler.fecha_fin, "\n")] = 0;  // Eliminar el salto de línea

    printf("Introduce el precio diario: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%lf", &nuevoAlquiler.precio_diario);


    addAlquiler(la, nuevoAlquiler);

    return nuevoAlquiler;
}

void estadoAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la) {
    int vehiculoEncontrado = 0;
    int alquilerEncontrado = 0;
    int vehiculoID;

    // Buscar el vehículo por matrícula
    for (int i = 0; i < lv->numVeh; i++) {
        if (strcmp(lv->aVeh[i].matricula, matricula) == 0) {
            vehiculoEncontrado = 1;
            vehiculoID = lv->aVeh[i].ID;
            break;
        }
    }

    if (!vehiculoEncontrado) {
        printf("Vehículo con matrícula %s no encontrado.\n", matricula);
        return;
    }

    // Buscar el alquiler por ID de vehículo
    for (int i = 0; i < la->numAlquileres; i++) {
        if (la->aAlquiler[i].vehiculo_id == vehiculoID) {
            alquilerEncontrado = 1;
            printf("Estado del alquiler para el vehículo con matrícula %s:\n", matricula);
            printA(la->aAlquiler[i]);
            break;
        }
    }

    if (!alquilerEncontrado) {
        printf("No se encontró ningún alquiler para el vehículo con matrícula %s.\n", matricula);
    }
}

Alquiler endAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la) {
    int vehiculoEncontrado = 0;
    int alquilerEncontrado = 0;
    int vehiculoID;
    Alquiler alquilerFinalizado;

    for (int i = 0; i < lv->numVeh; i++) {
        if (strcmp(lv->aVeh[i].matricula, matricula) == 0) {
            vehiculoEncontrado = 1;
            vehiculoID = lv->aVeh[i].ID;
            break;
        }
    }

    if (!vehiculoEncontrado) {
        printf("Vehículo con matrícula %s no encontrado.\n", matricula);
        exit(1);
    }


    for (int i = 0; i < la->numAlquileres; i++) {
        if (la->aAlquiler[i].vehiculo_id == vehiculoID) {
            alquilerEncontrado = 1;
            alquilerFinalizado = la->aAlquiler[i];
            break;
        }
    }

    if (!alquilerEncontrado) {
        printf("No se encontró ningún alquiler activo para el vehículo con matrícula %s.\n", matricula);
        exit(1);
    }


    printf("Introduce la fecha de fin del alquiler (YYYY-MM-DD): ");
    fflush(stdout);
    fflush(stdin);
    fgets(alquilerFinalizado.fecha_fin, TAM_FECHA, stdin);
    alquilerFinalizado.fecha_fin[strcspn(alquilerFinalizado.fecha_fin, "\n")] = 0;  // Eliminar el salto de línea


    for (int i = 0; i < la->numAlquileres; i++) {
        if (la->aAlquiler[i].vehiculo_id == vehiculoID) {
            la->aAlquiler[i] = alquilerFinalizado;
            break;
        }
    }

    return alquilerFinalizado;
}
