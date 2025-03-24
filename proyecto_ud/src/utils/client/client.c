#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

void iniLC(ListaClientes *lc) {
    lc->aClient = NULL;
    lc->numClient = 0;
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
}

void printCli(Client c) {
    printf("%5d%15s%20s%25s%30s%15s%25s%15s\n",
           c.ID,
           c.dni,
           c.nombre,
           c.apellidos,
           c.direccion,
           c.tlf,
           c.email,
           c.fecha_registro);
}

void printLCli(ListaClientes lc) {
    int i;
    printf("%5s%15s%20s%25s%30s%15s%25s%15s\n",
           "ID",
           "DNI/NIE",
           "NOMBRE",
           "APELLIDOS",
           "DIRECCION",
           "TELEFONO",
           "EMAIL",
           "FECHA_REG");
    for (i = 0; i < lc.numClient; i++) {
        printCli(lc.aClient[i]);
    }
}

Client registrarCliente(ListaClientes lc) {
    Client c;

    c.ID = lc.numClient;
    printf("Introduce el DNI/NIE: ");
    fgets(c.dni, TAM_DNI_NIE, stdin);
    c.dni[strcspn(c.dni, "\n")] = 0;
    printf("Introduce el nombre: ");
    fgets(c.nombre, TAM_NOMBRE, stdin);
    c.nombre[strcspn(c.nombre, "\n")] = 0;
    printf("Introduce los apellidos: ");
    fgets(c.apellidos, TAM_APELLIDOS, stdin);
    c.apellidos[strcspn(c.apellidos, "\n")] = 0;
    printf("Introduce la dirección: ");
    fgets(c.direccion, TAM_DIRECCION, stdin);
    c.direccion[strcspn(c.direccion, "\n")] = 0;
    printf("Introduce el teléfono: ");
    fgets(c.tlf, TAM_TELEFONO, stdin);
    c.tlf[strcspn(c.tlf, "\n")] = 0;
    printf("Introduce el email: ");
    fgets(c.email, TAM_EMAIL, stdin);
    c.email[strcspn(c.email, "\n")] = 0;
    printf("Introduce la fecha de registro (YYYY-MM-DD): ");
    fgets(c.fecha_registro, TAM_FECHA, stdin);
    c.fecha_registro[strcspn(c.fecha_registro, "\n")] = 0;

    return c;
}
