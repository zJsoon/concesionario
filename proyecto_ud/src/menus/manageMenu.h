#ifndef MANAGEMENU_H_
#define MANAGEMENU_H_

#include "../utils/emp/emp.h"
#include "../config/logger/logger.h"

int pedirOp();
int verificarEmpleado(ListaEmp le);
int verificarGerente(ListaEmp le);
void pedirDNI(char *dni);
char* pedirMatricula();
char* pedirIDConce();
void clearInputBuffer_mM();
#endif /* MANAGEMENU_H_ */
