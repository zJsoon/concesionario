#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veh.h"

void iniLV(ListaVeh *lv) {
	lv->aVeh = NULL;
	lv->numVeh = 0;
}

void loadVehCSV(char *csv, ListaVeh *lv) {
	char linea[500];
	FILE *pf;
	Veh v;

	pf = fopen(csv, "r");

	if (pf != (FILE*) NULL) {
		while (fscanf(pf, "%s", linea) != EOF) {
			char *id = strtok(linea, ";");
			char *matricula = strtok(NULL, ";");
			char *marca = strtok(NULL, ";");
			char *modelo = strtok(NULL, ";");
			char *year = strtok(NULL, ";");
			char *tipo = strtok(NULL, ";");
			char *color = strtok(NULL, ";");
			char *precio_compra = strtok(NULL, ";");
			char *precio_venta = strtok(NULL, ";");
			char *estado = strtok(NULL, ";");
			char *fecha_adquisicion = strtok(NULL, ";");
			char *concesionario_ID = strtok(NULL, ";");
			char *kilometraje = strtok(NULL, ";");
			char *tipo_combustible = strtok(NULL, "");

			strcpy(v.ID, id);
			strcpy(v.matricula, matricula);
			strcpy(v.marca, marca);
			strcpy(v.modelo, modelo);
			v.year = atoi(year);
			strcpy(v.tipo, tipo);
			strcpy(v.color, color);
			v.precio_compra = atof(precio_compra);
			v.precio_venta = atof(precio_venta);
			strcpy(v.estado, estado);
			strcpy(v.fecha_adquisicion, fecha_adquisicion);
			v.concesionario_ID = atoi(concesionario_ID);
			v.kilometraje = atoi(kilometraje);
			strcpy(v.tipo_combustible, tipo_combustible);

			addVeh(lv, v);
		}
		fclose(pf);
	}
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
	printf("%10s%30s%30s%30s%10i%20s\n", v.matricula, v.marca, v.modelo, v.year,
			v.estado);
}

void printLV(ListaVeh lv) {
	int i;
	printf("%10s%30s%30s%30s%10s%20s\n", "MATRÍCULA", "MARCA", "MODELO", "AÑO",
			"ESTADO");
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
	fgets(v.tipo, TAM_TIPO, stdin);
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

void copyVehCSV(char *csv, ListaVeh lv) {
	FILE *pf = fopen(csv, "w");

	if (pf != (FILE*) NULL) {
		for (int i = 0; i < lv.numVeh; i++) {
			Veh v = lv.aVeh[i];
			fprintf(pf, "%d;%s;%s;%s;%d;%s;%s;%.2f;%.2f;%s;%s;%d;%d;%s\n", v.ID,
					v.matricula, v.marca, v.modelo, v.year, v.tipo, v.color,
					v.precio_compra, v.precio_venta, v.estado,
					v.fecha_adquisicion, v.concesionario_ID, v.kilometraje,
					v.tipo_combustible);
		}
		printf("Datos guardados en %s correctamente.\n", csv);
		fflush(stdout);
	} else {
		perror("Error al abrir el archivo.\n");
	}

	fclose(pf);
}
