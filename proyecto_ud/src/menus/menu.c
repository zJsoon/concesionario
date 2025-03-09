#include <stdio.h>
#include "menu.h"
#include "manageMenu.h"

void mostrarMenuInicio(){
	printf("IDENTIFÍCATE:\n");
	printf("1. Cliente\n");
	printf("2. Empleado\n");
	printf("3. Gerente\n");
	printf("0. Exit\n");
	printf("Selecciona una opción: ");
	fflush(stdout);
}
