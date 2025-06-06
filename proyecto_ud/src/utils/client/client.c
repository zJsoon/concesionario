#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

void iniLC(ListaClientes *lc) {
	lc->aClient = NULL;
	lc->numClient = 0;
	writeLog("CLIENTES: iniLC Ejecutado", FICHERO_CLIENT_LOG);
}
void addClient(ListaClientes *lc, Client c) {
	int i;

	if (lc->aClient == NULL) {
		lc->aClient = malloc(1 * sizeof(Client));
	} else {
		Client *aux = malloc(lc->numClient * sizeof(Client));
		for (i = 0; i < lc->numClient; i++) {
			aux[i] = lc->aClient[i];
		}
		free(lc->aClient);
		lc->aClient = malloc((lc->numClient + 1) * sizeof(Client));
		for (i = 0; i < lc->numClient; i++) {
			lc->aClient[i] = aux[i];
		}
		free(aux);
	}
	lc->aClient[lc->numClient] = c;
	lc->numClient++;
	writeLog("CLIENTES: addClient Ejecutado", FICHERO_CLIENT_LOG);
}

void printCli(Client c) {
	printf("%5d%15s%20s%25s%30s%15s%25s%15s\n", c.ID, c.dni, c.nombre,
			c.apellidos, c.direccion, c.tlf, c.email, c.fecha_registro);
	fflush(stdout);
	writeLog("CLIENTES: printCli Ejecutado", FICHERO_CLIENT_LOG);
}

void printLCli(ListaClientes lc) {
	int i;
	printf("%5s%15s%20s%25s%30s%15s%25s%15s\n", "ID", "DNI/NIE", "NOMBRE",
			"APELLIDOS", "DIRECCION", "TELEFONO", "EMAIL", "FECHA_REG");
	for (i = 0; i < lc.numClient; i++) {
		printCli(lc.aClient[i]);
	}
	writeLog("CLIENTES: printLCli Ejecutado", FICHERO_CLIENT_LOG);
}
void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}
Client registrarCliente(ListaClientes lc) {
	Client c;

	c.ID = lc.numClient + 1; // Ojo, esto puede causar IDs duplicados

	printf("Introduce el DNI/NIE: ");
	fflush(stdout); // Asegura que el mensaje se muestre antes de la entrada

	fflush(stdin);
	fgets(c.dni, TAM_DNI_NIE, stdin);
	c.dni[strcspn(c.dni, "\n")] = 0;

	printf("Introduce el nombre: ");
	fflush(stdout);
    fflush(stdin);
	fgets(c.nombre, TAM_NOMBRE, stdin);
	c.nombre[strcspn(c.nombre, "\n")] = 0;


	printf("Introduce los apellidos: ");
	fflush(stdout);	
	fflush(stdin);
	fgets(c.apellidos, TAM_APELLIDOS, stdin);
	c.apellidos[strcspn(c.apellidos, "\n")] = 0;
	fflush(stdin);

	printf("Introduce la dirección: ");
	fflush(stdout);
		fflush(stdin);
	fgets(c.direccion, TAM_DIRECCION, stdin);
	c.direccion[strcspn(c.direccion, "\n")] = 0;
	fflush(stdin);

	printf("Introduce el teléfono: ");
	fflush(stdout);
		fflush(stdin);
	fgets(c.tlf, TAM_TELEFONO, stdin);
	c.tlf[strcspn(c.tlf, "\n")] = 0;
	fflush(stdin);

	printf("Introduce el email: ");
	fflush(stdout);
		fflush(stdin);
	fgets(c.email, TAM_EMAIL, stdin);
	c.email[strcspn(c.email, "\n")] = 0;
	fflush(stdin);

	printf("Introduce la fecha de registro (YYYY-MM-DD): ");
	fflush(stdout);
		fflush(stdin);
	fgets(c.fecha_registro, TAM_FECHA, stdin);
	c.fecha_registro[strcspn(c.fecha_registro, "\n")] = 0;
	fflush(stdin);

	writeLog("CLIENTES: registrarCliente Ejecutado", FICHERO_CLIENT_LOG);
	return c;
}

// Consultar cliente por DNI
void consultClientes(ListaClientes lc, char *DNI) {
	int i, encontrado = 0;
	for (i = 0; i < lc.numClient; i++) {
		if (strcmp(lc.aClient[i].dni, DNI) == 0) {
			printCli(lc.aClient[i]);
			encontrado = 1;
			break;
		}
	}
	if (!encontrado) {
		printf("Cliente con DNI %s no encontrado.\n", DNI);fflush(stdout);
	}
	writeLog("CLIENTES: consultClientes Ejecutado", FICHERO_CLIENT_LOG);
}

// Eliminar cliente por DNI
void elimClientes(ListaClientes *lc, char *DNI) {
	int i, j, encontrado = 0;
	for (i = 0; i < lc->numClient; i++) {
		if (strcmp(lc->aClient[i].dni, DNI) == 0) {
			encontrado = 1;
			for (j = i; j < lc->numClient - 1; j++) {
				lc->aClient[j] = lc->aClient[j + 1];
			}
			lc->numClient--;
			lc->aClient = realloc(lc->aClient, lc->numClient * sizeof(Client));
			printf("Cliente con DNI %s eliminado correctamente.\n", DNI);
			fflush(stdout);
			break;
		}
	}
	if (!encontrado) {
		printf("Cliente con DNI %s no encontrado.\n", DNI);fflush(stdout);
	}
	writeLog("CLIENTES: elimClientes Ejecutado", FICHERO_CLIENT_LOG);
}

// Modificar cliente por DNI
void modClientes(ListaClientes *lc) {
	if (lc == NULL) {
		printf("Error: Lista de clientes no válida.\n");fflush(stdout);
		return;
	}
	printf("Número de clientes: %d\n", lc->numClient);fflush(stdout);
	Client c;

	printf("Introduce el DNI: ");
	fflush(stdout);
	fflush(stdin);
	//clearInputBuffer();

	if (fgets(c.dni, sizeof(c.dni), stdin) == NULL) {
		printf("Error al leer el DNI.\n");
		return;
	}

	if (strlen(c.dni) == 0) {
		printf("Error: El DNI no puede estar vacío.\n");
		return;
	}

	int i;
	int encontrado = 0;
	for (i = 0; i < lc->numClient; i++) {
		int res = strcmp(lc->aClient[i].dni, c.dni);
		if (res == 0) {
			printf("Modificando datos del cliente con DNI %s\n", c.dni);
			fflush(stdout);
			printf("Introduce el nuevo nombre: ");
			fflush(stdout);
			fflush(stdin);
			fgets(lc->aClient[i].nombre, TAM_NOMBRE, stdin);
			lc->aClient[i].nombre[strcspn(lc->aClient[i].nombre, "\n")] = '\0';

			printf("Introduce los nuevos apellidos: ");
			fflush(stdout);
			fflush(stdin);
			fgets(lc->aClient[i].apellidos, TAM_APELLIDOS, stdin);
			lc->aClient[i].apellidos[strcspn(lc->aClient[i].apellidos, "\n")] =
					'\0';

			printf("Introduce la nueva dirección: ");
			fflush(stdout);
			fflush(stdin);
			fgets(lc->aClient[i].direccion, TAM_DIRECCION, stdin);
			lc->aClient[i].direccion[strcspn(lc->aClient[i].direccion, "\n")] =
					'\0';

			printf("Introduce el nuevo teléfono: ");
			fflush(stdout);
			fflush(stdin);
			fgets(lc->aClient[i].tlf, TAM_TELEFONO, stdin);
			lc->aClient[i].tlf[strcspn(lc->aClient[i].tlf, "\n")] = '\0';

			printf("Introduce el nuevo email: ");
			fflush(stdout);
			fflush(stdin);
			fgets(lc->aClient[i].email, TAM_EMAIL, stdin);
			lc->aClient[i].email[strcspn(lc->aClient[i].email, "\n")] = '\0';

			printf("Introduce la nueva fecha de registro (YYYY-MM-DD): ");
			fflush(stdout);
			fflush(stdin);
			fgets(lc->aClient[i].fecha_registro, TAM_FECHA, stdin);
			lc->aClient[i].fecha_registro[strcspn(lc->aClient[i].fecha_registro,
					"\n")] = '\0';

			printf("Cliente modificado correctamente.\n");fflush(stdout);

			encontrado = 1;
			break;
		}
	}

	if (!encontrado) {
		printf("Cliente con DNI %s no encontrado.\n", c.dni);fflush(stdout);
	}
	writeLog("CLIENTES: modClientes Ejecutado", FICHERO_CLIENT_LOG);
}
