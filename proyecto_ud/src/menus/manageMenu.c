#include <stdio.h>
#include <string.h>

#include "manageMenu.h"

int pedirOp(){
	int op;

	fflush(stdin);
	scanf("%d", &op);

	return op;
}
int verificarEmpleado(ListaEmp le) {
	loadEmpCSV(EMP_CSV, &le);
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
	return enc;
}

int verificarGerente(ListaEmp le) {
	loadEmpCSV(EMP_CSV, &le);
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
	return enc;
}
