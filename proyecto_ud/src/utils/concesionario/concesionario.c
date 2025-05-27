#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concesionario.h"
#include "../veh/veh.h"

void iniLCon(ListaConce *lc) {
	lc->aConce = NULL;
	lc->numConces = 0;
	writeLog("CONCE: iniLCon Ejecutado", FICHERO_CONCE_LOG);
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
	writeLog("CONCE: addConce Ejecutado", FICHERO_CONCE_LOG);
}

void printC(Conce c) {
	printf("%10d%30s%40s%15s%15s%30s\n", c.ID, c.nombre, c.direccion, c.ciudad,
			c.tlf, c.email);
	fflush(stdout);
	writeLog("CONCE: printC Ejecutado", FICHERO_CONCE_LOG);
}

void printLC(ListaConce lc) {
	int i;
	printf("%10s%30s%40s%15s%15s%30s\n", "ID", "NOMBRE", "DIRECCIÓN", "CIUDAD",
			"TELÉFONO", "EMAIL");
	fflush(stdout);
	for (i = 0; i < lc.numConces; i++) {
		printC(lc.aConce[i]);
	}
	writeLog("CONCE: printLC Ejecutado", FICHERO_CONCE_LOG);
}

Conce pedirConce(ListaConce lc) {
	Conce c;

	c.ID = lc.numConces;
	printf("Introduce el nombre: ");
	fflush(stdout);
	fflush(stdin);
	fgets(c.nombre, TAM_NOM_EMAIL, stdin);
	c.nombre[strcspn(c.nombre, "\n")] = 0;
	printf("Introduce la dirección: ");
	fflush(stdout);
	fflush(stdin);
	fgets(c.direccion, TAM_DIREC, stdin);
	c.direccion[strcspn(c.direccion, "\n")] = 0;
	printf("Introduce la ciudad: ");
	fflush(stdout);
	fflush(stdin);
	fgets(c.ciudad, TAM_CID_TLF, stdin);
	c.ciudad[strcspn(c.ciudad, "\n")] = 0;
	printf("Introduce el teléfono: ");
	fflush(stdout);
	fflush(stdin);
	fgets(c.tlf, TAM_CID_TLF, stdin);
	c.tlf[strcspn(c.tlf, "\n")] = 0;
	printf("Introduce el email: ");
	fflush(stdout);
	fflush(stdin);
	fgets(c.email, TAM_NOM_EMAIL, stdin);
	c.email[strcspn(c.email, "\n")] = 0;

	return c;
	writeLog("CONCE: pedirConce Ejecutado", FICHERO_CONCE_LOG);
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
	writeLog("CONCE: visualizarConce Ejecutado", FICHERO_CONCE_LOG);
}

void modConce(ListaConce *lista) {
	int idBuscado;
	printf("Introduce el ID del concesionario que deseas modificar: ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &idBuscado);

	for (int i = 0; i < lista->numConces; i++) {
		if (lista->aConce[i].ID == idBuscado) {
			printf("Modificando concesionario con ID %d\n", idBuscado);
			printf("Introduce el nuevo nombre: ");
			fflush(stdout);
			fflush(stdin);
			scanf("%s", lista->aConce[i].nombre);
			printf("Introduce la nueva dirección: ");
						fflush(stdout);
			fflush(stdin);
			scanf("%s", lista->aConce[i].direccion);
			printf("Introduce la nueva ciudad: ");
						fflush(stdout);
			fflush(stdin);
			scanf("%s", lista->aConce[i].ciudad);
			printf("Introduce el nuevo teléfono: ");
						fflush(stdout);
			fflush(stdin);
			scanf("%s", lista->aConce[i].tlf);
			printf("Introduce el nuevo email: ");
						fflush(stdout);
			fflush(stdin);
			scanf("%s", lista->aConce[i].email);
			printf("Concesionario modificado con éxito.\n");
						fflush(stdout);
			
			return;
		}
	}
	writeLog("CONCE: modConce Ejecutado", FICHERO_CONCE_LOG);
	printf("Concesionario con ID %d no encontrado.\n", idBuscado);fflush(stdout);
}

void elimConce(ListaConce *lista) {
	int idBuscado;
	printf("Introduce el ID del concesionario que deseas eliminar: ");fflush(stdout);fflush(stdin);
	scanf("%d", &idBuscado);

	for (int i = 0; i < lista->numConces; i++) {
		if (lista->aConce[i].ID == idBuscado) {
			for (int j = i; j < lista->numConces - 1; j++) {
				lista->aConce[j] = lista->aConce[j + 1];
			}
			lista->numConces--;
			printf("Concesionario con ID %d eliminado con éxito.\n", idBuscado);fflush(stdout);
			return;
		}
	}
	writeLog("CONCE: elimConce Ejecutado", FICHERO_CONCE_LOG);
	printf("Concesionario con ID %d no encontrado.\n", idBuscado);fflush(stdout);
}

void visualizarConceCiudad(ListaConce lc) {
	char ciudadBuscada[TAM_CID_TLF];
	printf("Introduce la ciudad de los concesionarios que deseas visualizar: ");fflush(stdout);fflush(stdin);
	scanf("%s", ciudadBuscada);

	int encontrados = 0;
	for (int i = 0; i < lc.numConces; i++) {
		if (strcmp(lc.aConce[i].ciudad, ciudadBuscada) == 0) {
			printf("ID: %d\n", lc.aConce[i].ID);
			printf("Nombre: %s\n", lc.aConce[i].nombre);
			printf("Dirección: %s\n", lc.aConce[i].direccion);
			printf("Ciudad: %s\n", lc.aConce[i].ciudad);
			printf("Teléfono: %s\n", lc.aConce[i].tlf);
			printf("Email: %s\n", lc.aConce[i].email);
			printf("\n");
			fflush(stdout);
			encontrados++;
		}
	}
	if (encontrados == 0) {
		printf("No se encontraron concesionarios en la ciudad %s.\n",
				ciudadBuscada);fflush(stdout);
	}
	writeLog("CONCE: visualizarConceCiudad Ejecutado", FICHERO_CONCE_LOG);
}

void consultConce(ListaConce lc, ListaVeh lv, char *ID) {

	int idBuscado = atoi(ID);
	int encontrado = 0;

	for (int i = 0; i < lc.numConces; i++) {
		if (lc.aConce[i].ID == idBuscado) {
			printC(lc.aConce[i]);fflush(stdout);
			encontrado = 1;
			break;
		}
	}

	if (!encontrado) {
		printf("Concesionario con ID %d no encontrado.\n", idBuscado);fflush(stdout);
		return;
	}

	printf("\n--- Vehículos del Concesionario ---\n");
	for (int i = 0; i < lv.numVeh; i++) {
		if (lv.aVeh[i].ID == idBuscado) {
			printf("ID del vehículo: %d\n", lv.aVeh[i].ID);
			printf("Matrícula: %s\n", lv.aVeh[i].matricula);
			printf("Modelo: %s\n", lv.aVeh[i].modelo);
			printf("\n");
			fflush(stdout);
		}
	}
	writeLog("CONCE: consultConce Ejecutado", FICHERO_CONCE_LOG);
}

void consultConceSocket(SOCKET socket, ListaConce lc, ListaVeh lv, char *ID) {
    char sendBuff[4096];
    int offset = 0;
    int idBuscado = atoi(ID);
    int encontrado = 0;

    memset(sendBuff, 0, sizeof(sendBuff));

    // Buscar el concesionario
    for (int i = 0; i < lc.numConces; i++) {
        if (lc.aConce[i].ID == idBuscado) {
            // Construir información del concesionario
            offset += sprintf(sendBuff + offset, "=== INFORMACIÓN DEL CONCESIONARIO ===\n");
            offset += sprintf(sendBuff + offset, "ID: %d\n", lc.aConce[i].ID);
            offset += sprintf(sendBuff + offset, "Nombre: %s\n", lc.aConce[i].nombre);
            offset += sprintf(sendBuff + offset, "Dirección: %s\n", lc.aConce[i].direccion);
            offset += sprintf(sendBuff + offset, "Ciudad: %s\n", lc.aConce[i].ciudad);
            offset += sprintf(sendBuff + offset, "Teléfono: %s\n", lc.aConce[i].tlf);
            offset += sprintf(sendBuff + offset, "Email: %s\n", lc.aConce[i].email);
            offset += sprintf(sendBuff + offset, "\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        sprintf(sendBuff, "Concesionario con ID %d no encontrado.\n", idBuscado);
        send(socket, sendBuff, strlen(sendBuff), 0);
        return;
    }

    // Buscar vehículos del concesionario
    offset += sprintf(sendBuff + offset, "=== VEHÍCULOS DEL CONCESIONARIO ===\n");
    int vehiculosEncontrados = 0;

    for (int i = 0; i < lv.numVeh; i++) {
        if (lv.aVeh[i].ID == idBuscado) {
            offset += sprintf(sendBuff + offset, "ID del vehículo: %d\n", lv.aVeh[i].ID);
            offset += sprintf(sendBuff + offset, "Matrícula: %s\n", lv.aVeh[i].matricula);
            offset += sprintf(sendBuff + offset, "Modelo: %s\n", lv.aVeh[i].modelo);
            offset += sprintf(sendBuff + offset, "------------------------\n");
            vehiculosEncontrados++;
        }
    }

    if (vehiculosEncontrados == 0) {
        offset += sprintf(sendBuff + offset, "No hay vehículos registrados para este concesionario.\n");
    }

    send(socket, sendBuff, strlen(sendBuff), 0);
    writeLog("CONCE: consultConce Ejecutado", FICHERO_CONCE_LOG);
}

void consultConceCiudadSocket(SOCKET socket, ListaConce lc, char *nombre){
	char sendBuff[4096];
	    int offset = 0;
	    int encontrado = 0;

	    memset(sendBuff, 0, sizeof(sendBuff));

	    // Buscar el concesionario
	    for (int i = 0; i < lc.numConces; i++) {
	        if (strcmp(lc.aConce[i].ciudad,nombre)==0) {
	            // Construir información del concesionario
	            offset += sprintf(sendBuff + offset, "=== INFORMACIÓN DEL CONCESIONARIO ===\n");
	            offset += sprintf(sendBuff + offset, "ID: %d\n", lc.aConce[i].ID);
	            offset += sprintf(sendBuff + offset, "Nombre: %s\n", lc.aConce[i].nombre);
	            offset += sprintf(sendBuff + offset, "Dirección: %s\n", lc.aConce[i].direccion);
	            offset += sprintf(sendBuff + offset, "Ciudad: %s\n", lc.aConce[i].ciudad);
	            offset += sprintf(sendBuff + offset, "Teléfono: %s\n", lc.aConce[i].tlf);
	            offset += sprintf(sendBuff + offset, "Email: %s\n", lc.aConce[i].email);
	            offset += sprintf(sendBuff + offset, "\n");
	            encontrado = 1;
	            break;
	        }
	    }

	    if (!encontrado) {
	        sprintf(sendBuff, "Concesionarios en ciudad %s no encontrado.\n", nombre);
	        send(socket, sendBuff, strlen(sendBuff), 0);
	        return;
	    }

	    send(socket, sendBuff, strlen(sendBuff), 0);
	    writeLog("CONCE: consultConce Ejecutado", FICHERO_CONCE_LOG);
}

