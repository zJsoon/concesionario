#ifndef MANAGEMENU_H_
#define MANAGEMENU_H_

#include "../utils/emp/emp.h"
#include "../config/logger/logger.h"

int pedirOp();
int verificarEmpleado(ListaEmp le);
int verificarGerente(ListaEmp le);
char* pedirDNI();
char* pedirMatricula();
char* pedirIDConce();

#endif /* MANAGEMENU_H_ */
