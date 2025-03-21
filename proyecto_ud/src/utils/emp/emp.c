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
}

void loadEmpCSV(char *csv, ListaEmp *le) {
    char linea[500];
    FILE *pf;
    Emp e;

    pf = fopen(csv, "r");

    if (pf != (FILE*) NULL) {
        while (fscanf(pf, "%s", linea) != EOF) {
            char *id = strtok(linea, ";");
            char *dni = strtok(NULL, ";");
            char *nombre = strtok(NULL, ";");
            char *cargo = strtok(NULL, ";");
            char *conce_id = strtok(NULL, "");

            e.ID = atoi(id);
            strcpy(e.DNI, dni);
            strcpy(e.nombre, nombre);
            strcpy(e.cargo, cargo);
            e.conce_id = atoi(conce_id);

            addEmp(le, e);
        }
        fclose(pf);
    }else{
    	printf("No se encuenta el archivo.\n");
    }
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
}

void printE(Emp e) {
    printf("%10s%30s%30s%10i\n", e.DNI, e.nombre, e.cargo, e.conce_id);
}

void printLE(ListaEmp le) {
    int i;
    printf("%10s%30s%30s%10s\n", "DNI", "NOMBRE", "CARGO", "CONCE_ID");
    for (i = 0; i < le.numEmp; i++) {
        printE(le.aEmp[i]);
    }
}

Emp pedirEmp(ListaEmp le) {
    Emp e;

    e.ID = le.numEmp;
    printf("Introduce el DNI: ");
    fflush(stdout);
    fflush(stdin);
    fgets(e.DNI, TAM_DNI, stdin);
    e.DNI[strcspn(e.DNI, "\n")] = 0; // Eliminar el salto de línea
    printf("Introduce el nombre: ");
    fflush(stdout);
    fflush(stdin);
    fgets(e.nombre, TAM_NOMBRE, stdin);
    e.nombre[strcspn(e.nombre, "\n")] = 0; // Eliminar el salto de línea
    printf("Introduce el cargo: ");
    fflush(stdout);
    fflush(stdin);
    fgets(e.cargo, TAM_CARGO, stdin);
    e.cargo[strcspn(e.cargo, "\n")] = 0; // Eliminar el salto de línea
    printf("Introduce el ID del concesionario: ");
    fflush(stdout);
    fflush(stdin);
    scanf("%d", &e.conce_id);

    return e;
}

void copyEmpCSV(char *csv, ListaEmp le) {
    FILE *pf = fopen(csv, "w");

    if (pf != (FILE*) NULL) {
        for (int i = 0; i < le.numEmp; i++) {
            Emp e = le.aEmp[i];
            fprintf(pf, "%d;%s;%s;%s;%d\n", e.ID, e.DNI, e.nombre, e.cargo, e.conce_id);
        }
        printf("Datos guardados en %s correctamente.\n", csv);
        fflush(stdout);
    } else {
        perror("Error al abrir el archivo.\n");
    }

    fclose(pf);
}
