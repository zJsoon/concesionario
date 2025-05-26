#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emp.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void iniLE(ListaEmp *le) {
    le->aEmp = NULL;
    le->numEmp = 0;
    writeLog("EMP: iniLE Ejecutado", FICHERO_EMP_LOG);
}

void addEmp(ListaEmp *le, Emp e) {
    int i;

    if (le->aEmp == NULL) {
        le->aEmp = malloc(1 * sizeof(Emp));
    } else {
        Emp *aux = malloc(le->numEmp * sizeof(Emp));
        for (i = 0; i < le->numEmp; i++) {
            aux[i] = le->aEmp[i];
        }
        free(le->aEmp);
        le->aEmp = malloc((le->numEmp + 1) * sizeof(Emp));
        for (i = 0; i < le->numEmp; i++) {
            le->aEmp[i] = aux[i];
        }
        free(aux);
    }
    le->aEmp[le->numEmp] = e;
    le->numEmp++;
    writeLog("EMP: addEmp Ejecutado", FICHERO_EMP_LOG);
}

void printE(Emp e) {
    printf("%10s%30s%30s%10i\n", e.DNI, e.nombre, e.cargo, e.conce_id);fflush(stdout);
    writeLog("EMP: printE Ejecutado", FICHERO_EMP_LOG);
}

void printLE(ListaEmp le) {
    int i;
    printf("%10s%30s%30s%10s\n", "DNI", "NOMBRE", "CARGO", "CONCE_ID");fflush(stdout);
    for (i = 0; i < le.numEmp; i++) {
        printE(le.aEmp[i]);
    }
    writeLog("EMP: printLE Ejecutado", FICHERO_EMP_LOG);
}

Emp pedirEmp(ListaEmp le) {
    Emp e;

    e.ID = le.numEmp;
    printf("Introduce el DNI: ");
    fflush(stdout);
    fflush(stdin);
    fgets(e.DNI, TAM_DNI, stdin);
    e.DNI[strcspn(e.DNI, "\n")] = 0;
    printf("Introduce el nombre: ");
    fflush(stdout);
    fflush(stdin);
    fgets(e.nombre, TAM_NOMBRE, stdin);
    e.nombre[strcspn(e.nombre, "\n")] = 0;
    printf("Introduce el cargo: ");
    fflush(stdout);
    fflush(stdin);
    fgets(e.cargo, TAM_CARGO, stdin);
    e.cargo[strcspn(e.cargo, "\n")] = 0;
    printf("Introduce el ID del concesionario: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%d", &e.conce_id);
    writeLog("EMP: pedirEmp Ejecutado", FICHERO_EMP_LOG);
    return e;
}


void consultEmp(char *DNI, ListaEmp le) {
    for (int i = 0; i < le.numEmp; i++) {
        if (strcmp(le.aEmp[i].DNI, DNI) == 0) {
            printE(le.aEmp[i]);
            return;
        }
    }
    printf("No se encontró ningún empleado con el DNI %s.\n", DNI);fflush(stdout);
    writeLog("EMP: consultEmp Ejecutado", FICHERO_EMP_LOG);
}

void modEmp(char *DNI, ListaEmp *le) {
    for (int i = 0; i < le->numEmp; i++) {
        if (strcmp(le->aEmp[i].DNI, DNI) == 0) {
            printf("Modificando empleado con DNI %s\n", DNI);
            printf("Introduce el nuevo nombre: ");
            fflush(stdout);
            fflush(stdin);
            fgets(le->aEmp[i].nombre, TAM_NOMBRE, stdin);
            le->aEmp[i].nombre[strcspn(le->aEmp[i].nombre, "\n")] = 0;
            printf("Introduce el nuevo cargo: ");
            fflush(stdout);
            fflush(stdin);
            fgets(le->aEmp[i].cargo, TAM_CARGO, stdin);
            le->aEmp[i].cargo[strcspn(le->aEmp[i].cargo, "\n")] = 0;
            printf("Introduce el nuevo ID del concesionario: ");
            fflush(stdout);
            fflush(stdin);
            scanf("%d", &le->aEmp[i].conce_id);
            printf("Empleado modificado con éxito.\n");
            return;
        }
    }
    writeLog("EMP: modEmp Ejecutado", FICHERO_EMP_LOG);
    printf("No se encontró ningún empleado con el DNI %s.\n", DNI);fflush(stdout);
}

void elimEmp(char *DNI, ListaEmp *le)	{
	int i, j, encontrado = 0;
		for (i = 0; i < le->numEmp; i++) {
			if (strcmp(le->aEmp[i].DNI, DNI) == 0) {
				encontrado = 1;
				for (j = i; j < le->numEmp - 1; j++) {
					le->aEmp[j] = le->aEmp[j + 1];
				}
				le->numEmp--;
				le->aEmp = realloc(le->aEmp, le->numEmp * sizeof(Emp));
				printf("Cliente con DNI %s eliminado correctamente.\n", DNI);fflush(stdout);
				break;
			}
		}
		if (!encontrado) {
			printf("Cliente con DNI %s no encontrado.\n", DNI);fflush(stdout);
		}
		writeLog("EMP: elimEmp Ejecutado", FICHERO_EMP_LOG);
}
