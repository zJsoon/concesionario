#ifndef CLIENT_CLIENT_H_
#define CLIENT_CLIENT_H_

#define TAM_DNI_NIE 10
#define TAM_NOMBRE 50
#define TAM_APELLIDOS 100
#define TAM_DIRECCION 150
#define TAM_TELEFONO 15
#define TAM_EMAIL 100
#define TAM_FECHA 11

typedef struct {
    int ID;
    char dni[TAM_DNI_NIE];
    char nombre[TAM_NOMBRE];
    char apellidos[TAM_APELLIDOS];
    char direccion[TAM_DIRECCION];
    char tlf[TAM_TELEFONO];
    char email[TAM_EMAIL];
    char fecha_registro[TAM_FECHA];
} Client;

typedef struct {
    Client *aClient;
    int numClient;
} ListaClientes;

void iniLC(ListaClientes *lc);
void addClient(ListaClientes *lc, Client c);
void printCli(Client c);
void printLCli(ListaClientes lc);
Client registrarCliente(ListaClientes lc);

#endif /* CLIENT_CLIENT_H_ */
