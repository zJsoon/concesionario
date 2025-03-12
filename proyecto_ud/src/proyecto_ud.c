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
	int op,verify;

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

	/**
	 * FALTA POR TERMINAR DE MONTAR EL DO WHILE
	 */
	/*do {
		op = mostrarMenuInicio();
		switch (op) {
		case 0:
			printf("Saliendo...");
			fflush(stdout);
			break;
		case 1: // Usuario
			switch (op) {
			case 0: // Salir
				printf("Saliendo...");
				fflush(stdout);
				break;
			case 1: // Ver concesionarios
				switch (op) {
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
					printf("Erro! La opción seleccionada no es correcta\n"); fflush(stdout);
					break;
				}
				break;
			case 2: // Ver vehículos
				switch (op) {
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
					printf("Erro! La opción seleccionada no es correcta\n"); fflush(stdout);
					break;
				}
				break;
			case 3: // Consultar historial un vehículo
				break;
			default:
				printf("Erro! La opción seleccionada no es correcta\n"); fflush(stdout);
				break;
			}
			break;
		case 2: // Empleado
			if(verify){
				switch (op) {
				case 0:
					printf("Saliendo...");
					fflush(stdout);
					break;
				case 1: // Gestión
					switch (op) {
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
					case 5: // Consultar Concesionarios
						break;
					case 6: // Consultar vehículos
						break;
					default:
						printf("Erro! La opción seleccionada no es correcta\n"); fflush(stdout);
						break;
					}
					break;
				case 2: // Operaciones
					break;
				case 3: // Mantenimientos
					break;
				case 4: // Informes
					break;
				default:
					printf("Erro! La opción seleccionada no es correcta\n"); fflush(stdout);
					break;
				}
				break;
			}
		case 3: // Gerente
			break;
		default:
			printf("Error! La opción seleccionada no es correcta\n"); fflush(stdout);
			break;
		}
	} while (op != 0);*/

	freeListas(&la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt, &lv, &lvent);
}
