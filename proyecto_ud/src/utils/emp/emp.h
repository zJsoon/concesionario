#ifndef EMP_H_
#define EMP_H_

#define TAM_DNI 11
#define TAM_NOMBRE 50
#define TAM_CARGO 30
#include "../../config/logger/logger.h"

typedef struct{
	int ID;
	char DNI[TAM_DNI];
	char nombre[TAM_NOMBRE];
	char cargo[TAM_CARGO];
	int conce_id;
}Emp;

typedef struct{
	Emp *aEmp;
	int numEmp;
}ListaEmp;

void iniLE(ListaEmp *le);
void addEmp(ListaEmp *le, Emp e);
void printE(Emp e);
void printLE(ListaEmp le);
Emp pedirEmp(ListaEmp le);
void consultEmp(char *DNI, ListaEmp le);
void modEmp(char *DNI, ListaEmp *le);
void elimEmp(char *DNI, ListaEmp *le);

#endif /* EMP_H_ */
