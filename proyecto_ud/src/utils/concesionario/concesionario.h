#ifndef CONCESIONARIO_CONCESIONARIO_H_
#define CONCESIONARIO_CONCESIONARIO_H_
#define TAM_NOM_EMAIL 30
#define TAM_DIREC 40
#define TAM_CID_TLF 15

#include "../veh/veh.h"
#include "../../config/logger/logger.h"

typedef struct{
	int ID;
	char nombre[TAM_NOM_EMAIL];
	char direccion[TAM_DIREC];
	char ciudad[TAM_CID_TLF];
	char tlf[TAM_CID_TLF];
	char email[TAM_NOM_EMAIL];

} Conce;

typedef struct{
	Conce *aConce;
	int numConces;
} ListaConce;

void iniLCon(ListaConce *lc);
void addConce(ListaConce *lc, Conce c);
void printC(Conce c);
void printLC(ListaConce lc);
Conce pedirConce(ListaConce lc);
void visualizarConce(Conce c, ListaConce lc);
void modConce(ListaConce *lista);
void elimConce(ListaConce *lista);
void visualizarConceCiudad(ListaConce lc);
void consultConce(ListaConce lc, ListaVeh lv, char *ID);
void consultConceSocket(SOCKET socket, ListaConce lc, ListaVeh lv, char *ID);
void consultConceCiudadSocket(SOCKET socket, ListaConce lc, char *nombre);
#endif /* CONCESIONARIO_CONCESIONARIO_H_ */
