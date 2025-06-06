#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veh.h"

void iniLV(ListaVeh *lv) {
	lv->aVeh = NULL;
	lv->numVeh = 0;
	writeLog("VEH: iniLV Ejecutado.",FICHERO_VEH_LOG);
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
	writeLog("VEH: addVeh Ejecutado.",FICHERO_VEH_LOG);
}

void printV(Veh v) {
	printf("%10d%15s%20s%20s%10d%15s%15s%12.2f%12.2f%15s%15s%10d%10.2f%15s\n",
			v.ID, v.matricula, v.marca, v.modelo, v.year, v.tipo, v.color,
			v.precio_compra, v.precio_venta, v.estado, v.fecha_adquisicion,
			v.concesionario_ID, v.kilometraje, v.tipo_combustible);fflush(stdout);
	writeLog("VEH: printV Ejecutado.",FICHERO_VEH_LOG);
}

void printLV(ListaVeh lv) {
	int i;
	printf("%10s%15s%20s%20s%10s%15s%15s%12s%12s%15s%15s%10s%10s%15s\n", "ID",
			"MATRÍCULA", "MARCA", "MODELO", "AÑO", "TIPO", "COLOR",
			"PRECIO_COMP", "PRECIO_VENT", "ESTADO", "FECHA_ADQ", "CONCE_ID",
			"KM", "COMBUSTIBLE");fflush(stdout);
	for (i = 0; i < lv.numVeh; i++) {
		printV(lv.aVeh[i]);
	}
	writeLog("VEH: printLV Ejecutado.",FICHERO_VEH_LOG);
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
	writeLog("VEH: pedirVeh Ejecutado.",FICHERO_VEH_LOG);
	return v;
}

void visualizarVehConce(ListaVeh lv, int id) {
	int i, encontrados = 0;
	printf("\nVehículos del concesionario ID %d:\n", id);fflush(stdout);

	for (i = 0; i < lv.numVeh; i++) {
		if (lv.aVeh[i].concesionario_ID == id) {
			printV(lv.aVeh[i]);
			encontrados++;
		}
	}

	if (encontrados == 0) {
		printf("No hay vehículos en este concesionario.\n");fflush(stdout);
	}
	writeLog("VEH: visualizarVehConce Ejecutado.",FICHERO_VEH_LOG);
}

void visualizarVehCiudad(ListaVeh lv, char *ciudad) {
	int i, encontrados = 0;
	printf("\nVehículos en la ciudad: %s\n", ciudad);fflush(stdout);

	for (i = 0; i < lv.numVeh; i++) {
		if (strstr(lv.aVeh[i].estado, ciudad)) {
			printV(lv.aVeh[i]);
			encontrados++;
		}
	}

	if (encontrados == 0) {
		printf("No se encontraron vehículos en esta ciudad.\n");fflush(stdout);
	}
	writeLog("VEH: visualizarVehCiudad Ejecutado.",FICHERO_VEH_LOG);
}

void visualizarVehMarca(ListaVeh lv, char *marca) {
	int i, encontrados = 0;
	printf("\nVehículos de la marca: %s\n", marca);fflush(stdout);

	for (i = 0; i < lv.numVeh; i++) {
		if (strcmp(lv.aVeh[i].marca, marca) == 0) {
			printV(lv.aVeh[i]);
			encontrados++;
		}
	}

	if (encontrados == 0) {
		printf("No se encontraron vehículos de esta marca.\n");fflush(stdout);
	}
	writeLog("VEH: visualizarVehMarca Ejecutado.",FICHERO_VEH_LOG);
}

void visualizarVehTipo(ListaVeh lv, char *tipo) {
	int i, encontrados = 0;
	printf("\nVehículos tipo: %s\n", tipo);fflush(stdout);

	for (i = 0; i < lv.numVeh; i++) {
		if (strcmp(lv.aVeh[i].tipo, tipo) == 0) {
			printV(lv.aVeh[i]);
			encontrados++;
		}
	}

	if (encontrados == 0) {
		printf("No se encontraron vehículos de este tipo.\n");fflush(stdout);
	}
	writeLog("VEH: visualizarVehTipo Ejecutado.",FICHERO_VEH_LOG);
}

void visualizarVehEstado(ListaVeh lv, char *estado) {
	int i, encontrados = 0;
	printf("\nVehículos en estado: %s\n", estado);fflush(stdout);

	for (i = 0; i < lv.numVeh; i++) {
		if (strcmp(lv.aVeh[i].estado, estado) == 0) {
			printV(lv.aVeh[i]);
			encontrados++;
		}
	}

	if (encontrados == 0) {
		printf("No hay vehículos con este estado.\n");fflush(stdout);
	}
	writeLog("VEH: visualizarVehEstado Ejecutado.",FICHERO_VEH_LOG);
}
int obtenerVehiculoID(ListaVeh listaVehiculos, char *matricula) {
    for (int i = 0; i < listaVehiculos.numVeh; i++) {
        if (strcmp(listaVehiculos.aVeh[i].matricula, matricula) == 0) {
            return listaVehiculos.aVeh[i].ID;
        }
    }
    return -1;
    writeLog("VENT: obtenerVehiculoID Ejecutado.",FICHERO_VENT_LOG);
}

void consultVehSocket(SOCKET socket, ListaVeh lv, char *ID) {
    char sendBuff[4096];
    int offset = 0;
    int idBuscado = atoi(ID);
    int encontrado = 0;

    memset(sendBuff, 0, sizeof(sendBuff));

    for (int i = 0; i < lv.numVeh; i++) {
        if (lv.aVeh[i].ID == idBuscado) {
            offset += sprintf(sendBuff + offset, "=== INFORMACIÓN DEL VEHÍCULO ===\n");
            offset += sprintf(sendBuff + offset, "ID: %d\n", lv.aVeh[i].ID);
            offset += sprintf(sendBuff + offset, "Matrícula: %s\n", lv.aVeh[i].matricula);
            offset += sprintf(sendBuff + offset, "Marca: %s\n", lv.aVeh[i].marca);
            offset += sprintf(sendBuff + offset, "Modelo: %s\n", lv.aVeh[i].modelo);
            offset += sprintf(sendBuff + offset, "Año: %d\n", lv.aVeh[i].year);
            offset += sprintf(sendBuff + offset, "Tipo: %s\n", lv.aVeh[i].tipo);
            offset += sprintf(sendBuff + offset, "Color: %s\n", lv.aVeh[i].color);
            offset += sprintf(sendBuff + offset, "Precio Compra: %.2f\n", lv.aVeh[i].precio_compra);
            offset += sprintf(sendBuff + offset, "Precio Venta: %.2f\n", lv.aVeh[i].precio_venta);
            offset += sprintf(sendBuff + offset, "Estado: %s\n", lv.aVeh[i].estado);
            offset += sprintf(sendBuff + offset, "Fecha Adquisición: %s\n", lv.aVeh[i].fecha_adquisicion);
            offset += sprintf(sendBuff + offset, "ID Concesionario: %d\n", lv.aVeh[i].concesionario_ID);
            offset += sprintf(sendBuff + offset, "Kilometraje: %.2f\n", lv.aVeh[i].kilometraje);
            offset += sprintf(sendBuff + offset, "Combustible: %s\n", lv.aVeh[i].tipo_combustible);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        sprintf(sendBuff, "Vehículo con ID %d no encontrado.\n", idBuscado);
    }

    send(socket, sendBuff, strlen(sendBuff), 0);
    writeLog("VEH: consultVehSocket Ejecutado.", FICHERO_VEH_LOG);
}

void consultVehMarcaSocket(SOCKET socket, ListaVeh lv, char *marca) {
    char sendBuff[2048];
    int offset = 0;
    int encontrados = 0;

    memset(sendBuff, 0, sizeof(sendBuff));
    offset += sprintf(sendBuff + offset, "=== VEHÍCULOS DE LA MARCA: %s ===\n", marca);

    for (int i = 0; i < lv.numVeh; i++) {
        if (strcmp(lv.aVeh[i].marca, marca) == 0) {
            offset += sprintf(sendBuff + offset, "ID: %d | Matrícula: %s | Modelo: %s | Año: %d\n",
                lv.aVeh[i].ID, lv.aVeh[i].matricula, lv.aVeh[i].modelo, lv.aVeh[i].year);
            offset += sprintf(sendBuff + offset, "------------------------\n");
            encontrados++;
        }
    }

    if (encontrados == 0) {
        offset += sprintf(sendBuff + offset, "No se encontraron vehículos de la marca '%s'.\n", marca);
    }

    send(socket, sendBuff, strlen(sendBuff), 0);
    writeLog("VEH: consultVehMarcaSocket Ejecutado.", FICHERO_VEH_LOG);
}
