#include <stdio.h>
#include <string.h>

#include "manageMenu.h"

int pedirOp(){
	int op;

	fflush(stdin);
	scanf("%d", &op);
	writeLog("MANAGE MENU: pedirOp Ejecutado", FICHERO_MANAGEMENU_LOG);
	return op;
}
int verificarEmpleado(ListaEmp le) {
	int enc = 0, i;
	Emp e;

	printf("Introduce el DNI: ");
	fflush(stdout);
	fflush(stdin);
	fgets(e.DNI, TAM_DNI, stdin);
	e.DNI[strcspn(e.DNI, "\n")] = 0;

	for (i=0;i<le.numEmp;i++) {
		if (strcmp(le.aEmp[i].DNI, e.DNI)==0) {
			enc = 1;
			break;
		}
	}
	writeLog("MANAGE MENU: verificarEmpleado Ejecutado", FICHERO_MANAGEMENU_LOG);
	return enc;
}

int verificarGerente(ListaEmp le) {
	int enc = 0, i;
	Emp e;

	printf("Introduce el DNI: ");
	fflush(stdout);
	fflush(stdin);
	fgets(e.DNI, TAM_DNI, stdin);

	for (i = 0; i < le.numEmp; i++) {
		if (strcmp(le.aEmp[i].DNI, e.DNI)==0
				&& strcmp(le.aEmp[i].cargo, "gerente")==0) {
			enc = 1;
			break;
		}
	}
	writeLog("MANAGE MENU: verificarGerente Ejecutado", FICHERO_MANAGEMENU_LOG);
	return enc;
}
