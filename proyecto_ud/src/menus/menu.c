#include <stdio.h>

#include "menu.h"
#include "manageMenu.h"

/*
 * INICIO
 */
int mostrarMenuInicio() {
	printf("| ------------- |\n");
	printf("| IDENTIFÍCATE  |\n");
	printf("| ------------- |\n");
	printf("| 1. Empleado   |\n");
	printf("| 2. Gerente    |\n");
	printf("| 0. Salir      |\n");
	printf("| ------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: Menu Inicio Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();
}

/*
 * EMPLEADOS
 */
int mostrarMenuEmp() {
	printf("| ------------------- |\n");
	printf("|       EMPLEADO      |\n");
	printf("| ------------------- |\n");
	printf("| 1. Gestión clientes |\n");
	printf("| 2. Operaciones      |\n");
	printf("| 3. Mantenimiento    |\n");
	printf("| 4. Informes         |\n");
	printf("| 0. Salir            |\n");
	printf("| ------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuEmp Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();
}
int mostrarMenuEmpGest() {
	printf("| ---------------------- |\n");
	printf("|   EMPLEADO - GESTIÓN   |\n");
	printf("| ---------------------- |\n");
	printf("| 1. Añadir clientes     |\n");
	printf("| 2. Modificar clientes  |\n");
	printf("| 3. Eliminar clientes   |\n");
	printf("| 4. Consultar clieentes |\n");
	printf("| 0. Salir               |\n");
	printf("| ---------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuEmpGest Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();

}
int mostrarMenuEmpOperaciones() {
	printf("| ----------------------------- |\n");
	printf("|    EMPLEADO - OPERACIONES     |\n");
	printf("| ----------------------------- |\n");
	printf("| 1. Registrar ventas           |\n");
	printf("| 2. Registrar alquiler         |\n");
	printf("| 3. Registrar renting          |\n");
	printf("| 4. Registrar movimiento coche |\n");
	printf("| 0. Salir                      |\n");
	printf("| ----------------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuEmpOperaciones Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();
}
int mostrarMenuEmpOperacionesAlquiler() {
	printf("| -------------------------------- |\n");
	printf("| EMPLEADO - OPERACIONES ALQUILER  |\n");
	printf("| -------------------------------- |\n");
	printf("| 1. Inicio alquiler               |\n");
	printf("| 2. Estado alquiler               |\n");
	printf("| 3. Fin alquiler                  |\n");
	printf("| 0. Salir                         |\n");
	printf("| -------------------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuEmpOperacionesAlquiler Ejecutado", FICHERO_MENU_LOG);//todo
	fflush(stdout);
	return pedirOp();
}
int mostrarMenuEmpOperacionesRenting() {
	printf("| ------------------------------- |\n");
	printf("| EMPLEADO - OPERACIONES RENTING  |\n");
	printf("| ------------------------------- |\n");
	printf("| 1. Inicio renting               |\n");
	printf("| 2. Estado renting               |\n");
	printf("| 3. Fin renting                  |\n");
	printf("| 0. Salir                        |\n");
	printf("| ------------------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuEmpOperacionesRenting Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();
}
int mostrarMenuEmpMantenimiento() {
	printf("| -------------------------- |\n");
	printf("|  EMPLEADO - MANTENIMIENTO  |\n");
	printf("| -------------------------- |\n");
	printf("| 1. Registrar reparaciones  |\n");
	printf("| 2. Registrar revisiones    |\n");
	printf("| 3. Visualizar reparaciones |\n");
	printf("| 4. Visualizar revisiones   |\n");
	printf("| 0. Salir                   |\n");
	printf("| -------------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuEmpMantenimiento Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();
}
int mostrarMenuEmpInformes() {
	printf("| ---------------------- |\n");
	printf("|   EMPLEADO - INFORMES  |\n");
	printf("| ---------------------- |\n");
	printf("| 1. Generar informes    |\n");
	printf("| 2. Visualizar informes |\n");
	printf("| 0. Salir               |\n");
	printf("| ---------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuEmpInformes Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();
}
int mostrarMenuEmpInformesGenerar() {
	printf("| --------------------------- |\n");
	printf("| EMPLEADO - INFORMES GENERAR |\n");
	printf("| --------------------------- |\n");
	printf("| 1. Informe venta            |\n");
	printf("| 2. Informe alquiler         |\n");
	printf("| 3. Informe renting          |\n");
	printf("| 4. Informe movimiento coche |\n");
	printf("| 0. Salir                    |\n");
	printf("| --------------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuEmpInformesGenerar Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();
}

/*
 * GERENTES
 */
int mostrarMenuGerente() {
	printf("| ------------------------- |\n");
	printf("|          GERENTE          |\n");
	printf("| ------------------------- |\n");
	printf("| 1. Gestión empleados      |\n");
	printf("| 2. Gestión concesionarios |\n");
	printf("| 0. Salir                  |\n");
	printf("| ------------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuGerente Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();
}
int mostrarMenuGerenteEmp() {
	printf("| --------------------- |\n");
	printf("|  GERENTE - EMPLEADOS  |\n");
	printf("| --------------------- |\n");
	printf("| 1. Añadir empleado    |\n");
	printf("| 2. Modificar empleado |\n");
	printf("| 3. Eliminar empleado  |\n");
	printf("| 4. Consultar empleado |\n");
	printf("| 0. Salir              |\n");
	printf("| --------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuGerenteEmp Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();

}
int mostrarMenuGerenteConce() {
	printf("| -------------------------- |\n");
	printf("|  GERENTE - CONCESIONARIOS  |\n");
	printf("| -------------------------- |\n");
	printf("| 1. Añadir concesionario    |\n");
	printf("| 2. Modificar concesionario |\n");
	printf("| 3. Eliminar concesionario  |\n");
	printf("| 4. Consultar concesionario |\n");
	printf("| 0. Salir                   |\n");
	printf("| -------------------------- |\n");
	printf("Selecciona una opción: ");
	writeLog("MENUS: mostrarMenuGerenteConce Ejecutado", FICHERO_MENU_LOG);
	fflush(stdout);
	return pedirOp();

}
