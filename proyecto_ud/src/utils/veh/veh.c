#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veh.h"

void iniLV(ListaVeh *lv) {
	lv->aVeh = NULL;
	lv->numVeh = 0;
}


void addVeh(ListaVeh *lv, Veh v) {
	int i;

	if (lv->aVeh == NULL) {
		lv->aVeh = malloc(1 * sizeof(Veh));
	} else {
		Veh *aux = malloc(lv->numVeh * sizeof(Veh));
		for (i = 0; i < lv->numVeh; i++) {
			aux[i] = lv->aVeh[i];
		}
		free(lv->aVeh);
		lv->aVeh = malloc((lv->numVeh + 1) * sizeof(Veh));
		for (i = 0; i < lv->numVeh; i++) {
			lv->aVeh[i] = aux[i];
		}
		free(aux);
	}
	lv->aVeh[lv->numVeh] = v;
	lv->numVeh++;
}

void printV(Veh v) {
	printf("%10d%15s%20s%20s%10d%15s%15s%12.2f%12.2f%15s%15s%10d%10.2f%15s\n",
			v.ID, v.matricula, v.marca, v.modelo, v.year, v.tipo, v.color,
			v.precio_compra, v.precio_venta, v.estado, v.fecha_adquisicion,
			v.concesionario_ID, v.kilometraje, v.tipo_combustible);
}

void printLV(ListaVeh lv) {
	int i;
	printf("%10s%15s%20s%20s%10s%15s%15s%12s%12s%15s%15s%10s%10s%15s\n", "ID",
			"MATRÍCULA", "MARCA", "MODELO", "AÑO", "TIPO", "COLOR",
			"PRECIO_COMP", "PRECIO_VENT", "ESTADO", "FECHA_ADQ", "CONCE_ID",
			"KM", "COMBUSTIBLE");
	for (i = 0; i < lv.numVeh; i++) {
		printV(lv.aVeh[i]);
	}
}

Veh pedirVeh(ListaVeh lv) {
	Veh v;

	v.ID = lv.numVeh;
	printf("Introduce la matrícula: ");
	fflush(stdout);
	fflush(stdin);
	fgets(v.matricula, TAM_MATRICULA, stdin);
	printf("Introduce la marca: ");
	fflush(stdout);
	fflush(stdin);
	fgets(v.marca, TAM_MARCA, stdin);
	printf("Introduce el modelo: ");
	fflush(stdout);
	fflush(stdin);
	fgets(v.modelo, TAM_MODELO, stdin);
	printf("Introduce el año: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", &v.year);
	printf("Introduce el tipo: ");
	fflush(stdout);
	fflush(stdin);
	fgets(v.tipo, TAM_TIPO_VEH, stdin);
	printf("Introduce el color: ");
	fflush(stdout);
	fflush(stdin);
	fgets(v.color, TAM_COLOR, stdin);
	printf("Introduce el Precio Compra: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f", &v.precio_compra);
	v.precio_venta = 0.0;
	printf("Introduce el estado: ");
	fflush(stdout);
	fflush(stdin);
	fgets(v.estado, TAM_ESTADO, stdin);
	printf("Introduce el Fecha Adquisición (dd-mm-YYYY): ");
	fflush(stdout);
	fflush(stdin);
	fgets(v.fecha_adquisicion, TAM_FECHA, stdin);
	printf("Introduce el ID Concesionario: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%i", &v.concesionario_ID);
	printf("Introduce el Kilometraje: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%f", &v.kilometraje);
	printf("Introduce el Tipo Combustible: ");
	fflush(stdout);
	fflush(stdin);
	fgets(v.estado, TAM_COMBUSTIBLE, stdin);

	return v;
}


void visualizarVehConce(ListaVeh lv, int id) {
    int encontrados = 0,i;
    printf("\nVehículos del concesionario ID %d:\n", id);

    for (int i = 0; i < lv.numVeh; i++) {
        if (lv.aVeh[i].concesionario_ID == id) {
            printV(lv.aVeh[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No hay vehículos en este concesionario.\n");
    }
}

void visualizarVehCiudad(ListaVeh lv, char *ciudad) {
    int encontrados = 0,i;
    printf("\nVehículos en la ciudad: %s\n", ciudad);

    for (int i = 0; i < lv.numVeh; i++) {
        if (strstr(lv.aVeh[i].estado, ciudad)) {
            printV(lv.aVeh[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron vehículos en esta ciudad.\n");
    }
}

void visualizarVehMarca(ListaVeh lv, char *marca) {
    int encontrados = 0,i;
    printf("\nVehículos de la marca: %s\n", marca);

    for (int i = 0; i < lv.numVeh; i++) {
        if (strcmp(lv.aVeh[i].marca, marca) == 0) {
            printV(lv.aVeh[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron vehículos de esta marca.\n");
    }
}

void visualizarVehTipo(ListaVeh lv, char *tipo) {
    int encontrados = 0,i;
    printf("\nVehículos tipo: %s\n", tipo);

    for (int i = 0; i < lv.numVeh; i++) {
        if (strcmp(lv.aVeh[i].tipo, tipo) == 0) {
            printV(lv.aVeh[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontraron vehículos de este tipo.\n");
    }
}

void visualizarVehEstado(ListaVeh lv, char *estado) {
    int encontrados = 0,i;
    printf("\nVehículos en estado: %s\n", estado);

    for (int i = 0; i < lv.numVeh; i++) {
        if (strcmp(lv.aVeh[i].estado, estado) == 0) {
            printV(lv.aVeh[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No hay vehículos con este estado.\n");
    }
}

// TODO HAY QUE MIRAR EN RENTING, ALQUILER, MANTENIMIENTO y sacar si hay datos de ahí
void visualizarVehHistorial(ListaVeh lv, char *matricula) {
    int encontrados = 0,i;
    printf("\nHistorial del vehículo con matrícula: %s\n", matricula);

    for (int i = 0; i < lv.numVeh; i++) {
        if (strcmp(lv.aVeh[i].matricula, matricula) == 0) {
            printV(lv.aVeh[i]);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("No se encontró ningún vehículo con esta matrícula.\n");
    }
}
