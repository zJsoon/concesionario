#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gestion.h"

void visualizarVehHistorial(ListaVeh lv, ListaAlquileres la, ListaRenting lr,
		ListaMantenimientos lm, char *matricula) {
	int i, j, encontrados = 0;
	printf("\nHistorial del vehículo con matrícula: %s\n", matricula);fflush(stdout);

	for (i = 0; i < lv.numVeh; i++) {
		if (strcmp(lv.aVeh[i].matricula, matricula) == 0) {
			printV(lv.aVeh[i]);
			for (j = 0; j < la.numAlquileres; j++) {
				if (lv.aVeh[i].ID == la.aAlquiler[j].vehiculo_id) {
					printA(la.aAlquiler[j]);
				}
			}
			for (j = 0; j < lr.numRenting; j++) {
				if (lv.aVeh[i].ID == lr.aRenting[j].vehiculo_id) {
					printR(lr.aRenting[j]);
				}
			}
			for (j = 0; j < lm.numMantenimientos; j++) {
				if (lv.aVeh[i].ID == lm.aMantenimiento[j].vehiculo_id) {
					printM(lm.aMantenimiento[j]);
				}
			}
			encontrados++;
		}
	}

	if (encontrados == 0) {
		printf("No se encontró ningún vehículo con esta matrícula.\n");fflush(stdout);
	}
	writeLog("GESTION: visualizarVehHistorial Ejecutado", FICHERO_VEH_LOG);
}


Alquiler startAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la) {
    Alquiler nuevoAlquiler;
    int vehiculoEncontrado = 0;

    for (int i = 0; i < lv->numVeh; i++) {
        if (strcmp(lv->aVeh[i].matricula, matricula) == 0) {
            vehiculoEncontrado = 1;
            nuevoAlquiler.vehiculo_id = lv->aVeh[i].ID;
            writeLog("GESTION: VEHICULO ENCONTRADO",FICHERO_ALQUILER_LOG);
            break;
        }
    }

    if (!vehiculoEncontrado) {
        printf("Vehículo con matrícula %s no encontrado.\n", matricula);fflush(stdout);
        exit(1);
        writeLog("GESTION: VEHICULO NO ENCONTRADO.",FICHERO_ALQUILER_LOG);
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
    writeLog("GESTION: visualizarVehHistorial Ejecutado", FICHERO_ALQUILER_LOG);
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
        writeLog("GESTION - Estado Alquiler: Vehiculo encontrado.",FICHERO_ALQUILER_LOG);
    }

    if (!vehiculoEncontrado) {
        printf("Vehículo con matrícula %s no encontrado.\n", matricula);fflush(stdout);
        writeLog("GESTION - Estado Alquiler: Vehiculo no encontrado.",FICHERO_ALQUILER_LOG);
        return;
    }

    // Buscar el alquiler por ID de vehículo
    for (int i = 0; i < la->numAlquileres; i++) {
        if (la->aAlquiler[i].vehiculo_id == vehiculoID) {
            alquilerEncontrado = 1;
            printf("Estado del alquiler para el vehículo con matrícula %s:\n", matricula);fflush(stdout);
            printA(la->aAlquiler[i]);
            writeLog("GESTION - Estado Alquiler: Vehiculo encontrado y se dice su estado.",FICHERO_ALQUILER_LOG);
            break;
        }
    }

    if (!alquilerEncontrado) {
        printf("No se encontró ningún alquiler para el vehículo con matrícula %s.\n", matricula);fflush(stdout);
        writeLog("GESTION - Estado Alquiler: No hay alquileres registrados sobre ese vehiculo.",FICHERO_ALQUILER_LOG);
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
            writeLog("GESTION - End Alquiler: Vehiculo encontrado.",FICHERO_ALQUILER_LOG);
            break;
        }
    }

    if (!vehiculoEncontrado) {
        printf("Vehículo con matrícula %s no encontrado.\n", matricula);fflush(stdout);
        writeLog("GESTION - End Alquiler: Vehiculo no encontrado.",FICHERO_ALQUILER_LOG);
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
        printf("No se encontró ningún alquiler activo para el vehículo con matrícula %s.\n", matricula);fflush(stdout);
        writeLog("GESTION - End Alquiler: Vehiculo encontrado en alquiler.",FICHERO_ALQUILER_LOG);
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
            writeLog("GESTION - End Alquiler: Alquiler cambiado.",FICHERO_ALQUILER_LOG);
            break;
        }
    }

    return alquilerFinalizado;
}
