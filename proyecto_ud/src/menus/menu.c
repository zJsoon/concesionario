#include <stdio.h>
#include "menu.h"
#include "manageMenu.h"

int mostrarMenuInicio(){
	int op;

	printf("IDENTIFÍCATE:\n");
	printf("1. Cliente\n");
	printf("2. Empleado\n");
	printf("3. Gerente\n");
	printf("0. Exit\n");
	printf("Selecciona una opción: ");
	scanf("%d",&op);

	return op;
}
