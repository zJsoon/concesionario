#include <stdio.h>

#include "menus/menu.h"

#include "comp/ini.h"

#include "utils/alquiler/alquiler.h"
#include "utils/audit/audit.h"
#include "utils/client/client.h"
#include "utils/concesionario/concesionario.h"
#include "utils/emp/emp.h"
#include "utils/mantenimiento/mantenimiento.h"
#include "utils/operaciones/operaciones.h"
#include "utils/renting/renting.h"
#include "utils/translados/translados.h"
#include "utils/veh/veh.h"
#include "utils/vent/vent.h"

int main() {
	int op, op1, op11, op12, op2, op21, op22, op222, op223, op23, op24, op241, op3, op31, op32, verifyEmpleado, verifyGerente;

	ListaAlquileres la;
	ListaAuditorias lau;
	ListaClientes lc;
	ListaConce lcon;
	ListaEmp le;
	ListaMantenimientos lm;
	ListaOperaciones lop;
	ListaRenting lr;
	ListaTraslados lt;
	ListaVeh lv;
	ListaVent lvent;

	iniListas(&la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt, &lv, &lvent);

	do {
		op = mostrarMenuInicio();
		switch (op) {
		case 0:
			printf("Saliendo...");
			fflush(stdout);
			break;
		case 1: // Usuario
			switch (op1) {
			case 0: // Salir
				printf("Saliendo...");
				fflush(stdout);
				break;
			case 1: // Ver concesionarios
				switch (op11) {
				case 0:
					printf("Saliendo...");
					fflush(stdout);
					break;
				case 1: // Visualizar todos
					break;
				case 2: // Filtrar por ciudad
					break;
				case 3: // Filtrar por marca
					break;
				default:
					printf("Erro! La opción seleccionada no es correcta\n");
					fflush(stdout);
					break;
				}
				break;
			case 2: // Ver vehículos
				switch (op12) {
				case 0:
					printf("Saliendo...");
					fflush(stdout);
					break;
				case 1: // Visualizar todos
					break;
				case 2: // Filtrar por concesionario
					break;
				case 3: // Filtrar por marca
					break;
				case 4: // Filtrar por modelo
					break;
				case 5: // Filtrar por tipo
					break;
				case 6: // Filtrar por estado
					break;
				default:
					printf("Erro! La opción seleccionada no es correcta\n");
					fflush(stdout);
					break;
				}
				break;
			case 3: // Consultar historial un vehículo
				break;
			default:
				printf("Erro! La opción seleccionada no es correcta\n");
				fflush(stdout);
				break;
			}
			break;
		case 2: // Empleado
			if (verifyEmpleado) {
				switch (op2) {
				case 0:
					printf("Saliendo...");
					fflush(stdout);
					break;
				case 1: // Gestión Clientes
					switch (op21) {
					case 0:
						printf("Saliendo...");
						fflush(stdout);
						break;
					case 1: // Añadir Clientes
						break;
					case 2: // Modificar Clientes
						break;
					case 3: // Eliminar Clientes
						break;
					case 4: // Consultar Clientes
						break;
					default:
						printf("Erro! La opción seleccionada no es correcta\n");
						fflush(stdout);
						break;
					}
					break;
				case 2: // Operaciones
					switch (op22) {
					case 0:
						printf("Saliendo...");
						fflush(stdout);
						break;
					case 1: // Registrar venta
						break;
					case 2: // Registrar alquiler
						switch (op222) {
						case 0:
							printf("Saliendo...");
							break;
						case 1: // Inicio alquiler
							break;
						case 2: // Fin alquiler
							break;
						default:
							printf(
									"Error! La opción seleccionada no es correcta\n");
							fflush(stdout);
							break;
						}
						break;
					case 3: // Registrar renting
						switch (op223) {
						case 0:
							printf("Saliendo...");
							break;
						case 1: // Inicio renting
							break;
						case 2: // Fin reinting
							break;
						default:
							break;
						}
						break;
					case 4: // Registrar movimiento coche
						break;
					default:
						printf(
								"Error! La opción seleccionada no es correcta\n");
						fflush(stdout);
						break;
					}
					break;
				case 3: // Mantenimientos
					switch (op23) {
					case 0:
						printf("Saliendo...");
						break;
					case 1: // Registrar reparaciones
						break;
					case 2: // Registrar revisiones
						break;
					default:
						printf(
								"Error! La opción seleccionada no es correcta\n");
						fflush(stdout);
						break;
					}
					break;
				case 4: // Informes
					switch (op24) {
					case 0:
						printf("Saliendo...");
						fflush(stdout);
						break;
					case 1: // Generar informes
						switch (op241) {
						case 0:
							printf("Saliendo...");
							fflush(stdout);
							break;
						case 1: // Informe venta
							break;
						case 2: // Informe alquiler
							break;
						case 3: // Informe renting
							break;
						case 4: // Informe movimiento coche
							break;
						case 5: // Informe reparaciones
							break;
						case 6: // Informe revisiones
							break;
						default:
							printf(
									"Error! La opción seleccionada no es correcta\n");
							fflush(stdout);
							break;
						}
						break;
					case 2: // Visualizar informes
						break;
					default:
						printf(
								"Error! La opción seleccionada no es correcta\n");
						fflush(stdout);
						break;
					}
					break;
				default:
					printf("Erro! La opción seleccionada no es correcta\n");
					fflush(stdout);
					break;
				}
				break;
			}
			break;
		case 3: // Gerente
			if (verifyGerente) {
				switch (op3) {
				case 0:
					printf("Saliendo...");
					fflush(stdout);
					break;
				case 1: // Gestión empleados
					switch (op31) {
					case 0:
						printf("Saliendo...");
						fflush(stdout);
						break;
					case 1: // Añadir empleado
						break;
					case 2: // Modificar empleado
						break;
					case 3: // Eliminar empleado
						break;
					case 4: // Consultar empleado
						break;
					default:
						printf(
								"Error! La opción seleccionada no es correcta\n");
						fflush(stdout);
						break;
					}
					break;
				case 2: // Gestión concesionarios
					switch (op32) {
					case 0:
						printf("Saliendo...");
						fflush(stdout);
						break;
					case 1: // Añadir concesionarios
						break;
					case 2: // Modificar concesionarios
						break;
					case 3: // Eliminar concesionarios
						break;
					case 4: // consultar concesionarios
						break;
					default:
						printf(
								"Error! La opción seleccionada no es correcta\n");
						fflush(stdout);
						break;
					}
					break;
				default:
					printf("Error! La opción seleccionada no es correcta\n");
					fflush(stdout);
					break;
				}
				break;
			}
			break;
		default:
			printf("Error! La opción seleccionada no es correcta\n");
			fflush(stdout);
			break;
		}
	} while (op != 0);

	freeListas(&la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt, &lv, &lvent);
}
