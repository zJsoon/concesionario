#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concesionario.h"

void iniLCon(ListaConce *lc) {
    lc->aConce = NULL;
    lc->numConces = 0;
}

void loadConceCSV(char *csv, ListaConce *lc) {
    char linea[500];
    FILE *pf;
    Conce c;

    pf = fopen(csv, "r");

    if (pf != (FILE*) NULL) {
        while (fscanf(pf, "%s", linea) != EOF) {
            char *id = strtok(linea, ";");
            char *nombre = strtok(NULL, ";");
            char *direccion = strtok(NULL, ";");
            char *ciudad = strtok(NULL, ";");
            char *tlf = strtok(NULL, ";");
            char *email = strtok(NULL, "");

            c.ID = atoi(id);
            strcpy(c.nombre, nombre);
            strcpy(c.direccion, direccion);
            strcpy(c.ciudad, ciudad);
            strcpy(c.tlf, tlf);
            strcpy(c.email, email);

            addConce(lc, c);
        }
        fclose(pf);
    }
}

void addConce(ListaConce *lc, Conce c) {
    int i;

    if (lc->aConce == NULL) {
        lc->aConce = malloc(1 * sizeof(Conce));
    } else {
        Conce *aux = malloc(lc->numConces * sizeof(Conce));
        for (i = 0; i < lc->numConces; i++) {
            aux[i] = lc->aConce[i];
        }
        free(lc->aConce);
        lc->aConce = malloc((lc->numConces + 1) * sizeof(Conce));
        for (i = 0; i < lc->numConces; i++) {
            lc->aConce[i] = aux[i];
        }
        free(aux);
    }
    lc->aConce[lc->numConces] = c;
    lc->numConces++;
}

void printC(Conce c) {
    printf("%10d%30s%40s%15s%15s%30s\n", c.ID, c.nombre, c.direccion, c.ciudad, c.tlf, c.email);
}

void printLC(ListaConce lc) {
    int i;
    printf("%10s%30s%40s%15s%15s%30s\n", "ID", "NOMBRE", "DIRECCIÓN", "CIUDAD", "TELÉFONO", "EMAIL");
    for (i = 0; i < lc.numConces; i++) {
        printC(lc.aConce[i]);
    }
}

Conce pedirConce(ListaConce lc) {
    Conce c;

    c.ID = lc.numConces;
    printf("Introduce el nombre: ");
    fflush(stdout);
    fflush(stdin);
    fgets(c.nombre, TAM_NOM_EMAIL, stdin);
    c.nombre[strcspn(c.nombre, "\n")] = 0;  // Eliminar el salto de línea
    printf("Introduce la dirección: ");
    fflush(stdout);
    fflush(stdin);
    fgets(c.direccion, TAM_DIREC, stdin);
    c.direccion[strcspn(c.direccion, "\n")] = 0;  // Eliminar el salto de línea
    printf("Introduce la ciudad: ");
    fflush(stdout);
    fflush(stdin);
    fgets(c.ciudad, TAM_CID_TLF, stdin);
    c.ciudad[strcspn(c.ciudad, "\n")] = 0;  // Eliminar el salto de línea
    printf("Introduce el teléfono: ");
    fflush(stdout);
    fflush(stdin);
    fgets(c.tlf, TAM_CID_TLF, stdin);
    c.tlf[strcspn(c.tlf, "\n")] = 0;  // Eliminar el salto de línea
    printf("Introduce el email: ");
    fflush(stdout);
    fflush(stdin);
    fgets(c.email, TAM_NOM_EMAIL, stdin);
    c.email[strcspn(c.email, "\n")] = 0;  // Eliminar el salto de línea

    return c;
}

void copyConceCSV(char *csv, ListaConce lc) {
    FILE *pf = fopen(csv, "w");

    if (pf != (FILE*) NULL) {
        for (int i = 0; i < lc.numConces; i++) {
            Conce c = lc.aConce[i];
            fprintf(pf, "%d;%s;%s;%s;%s;%s\n", c.ID, c.nombre, c.direccion, c.ciudad, c.tlf, c.email);
        }
        printf("Datos guardados en %s correctamente.\n", csv);
        fflush(stdout);
    } else {
        perror("Error al abrir el archivo.\n");
    }

    fclose(pf);
}

void visualizarConce(Conce c, ListaConce lc) {
	int ID;
	printf("Introduce el ID del concesionario que deseas visualizar: \n");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &ID);
	for (int i = 0; i < lc.numConces; i++) {
		if (ID == lc.aConce[i].ID) {
			printC(lc.aConce[i]);
		}

	}
}

void modConce(ListaConce *lista) {
    int idBuscado;
    printf("Introduce el ID del concesionario que deseas modificar: ");
    scanf("%d", &idBuscado);

    for (int i = 0; i < lista->numConces; i++) {
        if (lista->aConce[i].ID == idBuscado) {
            printf("Modificando concesionario con ID %d\n", idBuscado);
            printf("Introduce el nuevo nombre: ");
            scanf("%s", lista->aConce[i].nombre);
            printf("Introduce la nueva dirección: ");
            scanf("%s", lista->aConce[i].direccion);
            printf("Introduce la nueva ciudad: ");
            scanf("%s", lista->aConce[i].ciudad);
            printf("Introduce el nuevo teléfono: ");
            scanf("%s", lista->aConce[i].tlf);
            printf("Introduce el nuevo email: ");
            scanf("%s", lista->aConce[i].email);
            printf("Concesionario modificado con éxito.\n");
            return;
        }
    }
    printf("Concesionario con ID %d no encontrado.\n", idBuscado);
}

void elimConce(ListaConce *lista) {
    int idBuscado;
    printf("Introduce el ID del concesionario que deseas eliminar: ");
    scanf("%d", &idBuscado);

    for (int i = 0; i < lista->numConces; i++) {
        if (lista->aConce[i].ID == idBuscado) {
            for (int j = i; j < lista->numConces - 1; j++) {
                lista->aConce[j] = lista->aConce[j + 1];
            }
            lista->numConces--;
            printf("Concesionario con ID %d eliminado con éxito.\n", idBuscado);
            return;
        }
    }
    printf("Concesionario con ID %d no encontrado.\n", idBuscado);
}
