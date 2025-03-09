#include <stdio.h>
#include "menu.h"
#include "manageMenu.h"

void mostrarMenuInicio(){
	printf("IDENTIFÍCATE:");
	printf("1. Cliente");
	printf("2. Empleado");
	printf("3. Gerente");
	printf("0. Gerente");
	fflush(stdout);
}
