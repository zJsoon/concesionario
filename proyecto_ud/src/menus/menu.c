#include <stdio.h>
#include "menu.h"
#include "manageMenu.h"

/*
 * INICIO
 */
int mostrarMenuInicio() {
	int op;

	printf("IDENTIFÍCATE:\n");
	printf("1. Cliente\n");
	printf("2. Empleado\n");
	printf("3. Gerente\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}

/*
 * USUARIO
 */
int mostrarMenuUsuario() {
	int op;

	printf("USUARIO:\n");
	printf("1. Ver concesionarios\n");
	printf("2. Ver vehículos\n");
	printf("3. Consultar historial vehículo\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuUsuarioConce() {
	int op;

	printf("USUARIO - CONCESIONARIO:\n");
	printf("1. Visualizar todos\n");
	printf("2. Filtrar por ciudad\n");
	printf("3. Filtrar por marca\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuUsuarioVeh() {
	int op;

	printf("USUARIO - VEHÍCULO:\n");
	printf("1. Visualizar todos\n");
	printf("2. Filtrar por concesionario\n");
	printf("3. Filtrar por marca\n");
	printf("4. Filtrar por modelo\n");
	printf("5. Filtrar por tipo\n");
	printf("6. Filtrar por estado\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}

/*
 * EMPLEADOS
 */
int mostrarMenuEmp() {
	int op;

	printf("EMPLEADO:\n");
	printf("1. Gestión clientes\n");
	printf("2. Operaciones\n");
	printf("3. Mantenimiento\n");
	printf("4. Informes\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuEmpGest() {
	int op;

	printf("EMPLEADO - GESTIÓN:\n");
	printf("1. Añadir clientes\n");
	printf("2. Modificar clientes\n");
	printf("3. Eliminar clientes\n");
	printf("4. Consultar clieentes\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuEmpOperaciones() {
	int op;

	printf("EMPLEADO - OPERACIONES:\n");
	printf("1. Registrar ventas\n");
	printf("2. Registrar alquiler\n");
	printf("3. Registrar renting\n");
	printf("4. Registrar movimiento coche\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuEmpOperacionesAlquiler() {
	int op;

	printf("EMPLEADO - OPERACIONES ALQUILER:\n");
	printf("1. Inicio alquiler\n");
	printf("2. Estado alquiler\n");
	printf("3. Fin alquiler\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuEmpOperacionesRenting() {
	int op;

	printf("EMPLEADO - OPERACIONES RENTING:\n");
	printf("1. Inicio renting\n");
	printf("2. Estado renting\n");
	printf("3. Fin renting\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuEmpMantenimiento() {
	int op;

	printf("EMPLEADO - MANTENIMIENTO:\n");
	printf("1. Registrar reparaciones\n");
	printf("2. Registrar revisiones\n");
	printf("3. Visualizar reparaciones\n");
	printf("4. Visualizar revisiones\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuEmpInformes() {
	int op;

	printf("EMPLEADO - INFORMES:\n");
	printf("1. Generar informes\n");
	printf("2. Visualizar informes\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuEmpInformesGenerar() {
	int op;

	printf("EMPLEADO - INFORMES GENERAR:\n");
	printf("1. Informe venta\n");
	printf("2. Informe alquiler\n");
	printf("3. Informe renting\n");
	printf("4. Informe movimiento coche\n");
	printf("5. Informe reparaciones\n");
	printf("6. Informe revisiones\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}

/*
 * GERENTES
 */
int mostrarMenuGerente(){
	int op;

	printf("GERENTE:\n");
	printf("1. Gestión empleados\n");
	printf("2. Gestión concesionarios\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;
}
int mostrarMenuGerenteEmp(){
	int op;

	printf("GERENTE - EMPLEADOS:\n");
	printf("1. Añadir empleado\n");
	printf("2. Modificar empleado\n");
	printf("3. Eliminar empleado\n");
	printf("4. Consultar empleado\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;

}
int mostrarMenuGerenteConce(){
	int op;

	printf("GERENTE - CONCESIONARIOS:\n");
	printf("1. Añadir concesionario\n");
	printf("2. Modificar concesionario\n");
	printf("3. Eliminar concesionario\n");
	printf("4. Consultar concesionario\n");
	printf("0. Salir\n");
	printf("Selecciona una opción: ");

	scanf("%d", &op);

	return op;

}
