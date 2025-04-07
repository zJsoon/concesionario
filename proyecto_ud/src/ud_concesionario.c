#include <stdio.h>

#include "menus/menu.h"
#include "menus/manageMenu.h"

#include "comp/ini.h"
#include "comp/db_manager.h"
#include "comp/sqlite3.h"

#include "config/config.h"

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
	int op, op1, op11, op12, op122, op123, op13, op14, op141, op2, op21, op22,
			result;

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

	Config c = leerConfiguracion("../data/ini.config");

	sqlite3 *db;

	iniListas(&la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt, &lv, &lvent);
	result = sqlite3_open(c.nombreBD, &db);
	if (result != SQLITE_OK) {
		printf("Error al abrir DB.\n");
		fflush(stdout);
		return result;
	}
	cargarDatosDesdeBD(db, &la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt,
			&lv, &lvent);
	do {
		op = mostrarMenuInicio();
		switch (op) {
		case 0:
			printf("Saliendo...\n");
			break;

			/*
			 * MENU EMPLEADO
			 */
		case 1:
			if (verificarEmpleado(le)) {
				do {
					op1 = mostrarMenuEmp();
					switch (op1) {
					case 0:
						printf("Saliendo...\n");
						fflush(stdout);
						break;
						/*
						 * GESTION CLIENTES
						 */
					case 1:
						do {
							op11 = mostrarMenuEmpGest();
							switch (op11) {
							case 0:
								printf("Saliendo...\n");
								fflush(stdout);
								break;
							case 1: // Añadir Clientes
								printf("Añadir clientes\n");
								fflush(stdout);
								break;
							case 2: // Modificar Clientes
								printf("Modificar clientes\n");
								fflush(stdout);
								break;
							case 3: // Eliminar Clientes
								printf("Eliminar clientes\n");
								fflush(stdout);
								break;
							case 4: // Consultar Clientes
								printf("Consultar clientes\n");
								fflush(stdout);
								break;
							default:
								printf(
										"Error! La opción seleccionada no es correcta\n");
								fflush(stdout);
								break;
							}
						} while (op11 != 0);
						break;
						/*
						 * OPERACIONES
						 */
					case 2:
						do {
							op12 = mostrarMenuEmpOperaciones();
							switch (op12) {
							case 0:
								printf("Saliendo...\n");
								fflush(stdout);
								break;
							case 1: // Registrar venta
								printf("Registrar venta.\n");
								fflush(stdout);
								break;
							case 2: // Registrar alquiler
								do {
									op122 = mostrarMenuEmpOperacionesAlquiler();
									switch (op122) {
									case 0:
										printf("Saliendo...\n");
										break;
									case 1: // Inicio alquiler
										printf("Inicio alquiler.\n");
										fflush(stdout);
										break;
									case 2: // Estado alquiler
										printf("Estado alquiler.\n");
										fflush(stdout);
										break;
									case 3: // Fin alquiler
										printf("Fin alquiler.\n");
										fflush(stdout);
										break;
									default:
										printf(
												"Error! La opción seleccionada no es correcta\n");
										fflush(stdout);
										break;
									}
								} while (op122 != 0);
								break;
							case 3:
								do {
									op123 = mostrarMenuEmpOperacionesRenting();
									switch (op123) {
									case 0:
										printf("Saliendo...\n");
										fflush(stdout);
										break;
									case 1: // Inicio renting
										printf("Inicio renting\n");
										fflush(stdout);
										break;
									case 2: // Estado renting
										printf("Estado renting\n");
										fflush(stdout);
										break;
									case 3: // Fin reinting
										printf("Fin renting");
										fflush(stdout);
										break;
									default:
										printf(
												"Error! La opción seleccionada no es correcta\n");
										fflush(stdout);
										break;
									}
									break;
								} while (op123 != 0);
								break;
							case 4: // Registrar movimiento coche
								printf("Registrar movimiento coche.\n");
								fflush(stdout);
								break;
							default:
								printf(
										"Error! La opción seleccionada no es correcta\n");
								fflush(stdout);
								break;
							}
						} while (op12 != 0);
						break;
						/*
						 * MANTENIMIENTO
						 */
					case 3:
						do {
							op13 = mostrarMenuEmpMantenimiento();
							switch (op13) {
							case 0:
								printf("Saliendo...\n");
								fflush(stdout);
								break;
							case 1: // Registrar reparaciones
								printf("Registrar reparaciones.\n");
								fflush(stdout);
								break;
							case 2: // Registrar revisiones
								printf("Registrar revisiones.\n");
								fflush(stdout);
								break;
							case 3: // Visualizar reparaciones
								printf("Visualizar reparaciones.\n");
								fflush(stdout);
								break;
							case 4: // Visualizar revisiones
								printf("Visualizar revisiones.\n");
								fflush(stdout);
								break;
							default:
								printf(
										"Error! La opción seleccionada no es correcta\n");
								fflush(stdout);
								break;
							}
						} while (op13 != 0);
						break;
						/*
						 * INFORMES
						 */
					case 4:
						do {
							op14 = mostrarMenuEmpInformes();
							switch (op14) {
							case 0:
								printf("Saliendo...\n");
								fflush(stdout);
								break;
							case 1: // Generar informes
								do {
									op141 = mostrarMenuEmpInformesGenerar();
									switch (op141) {
									case 0:
										printf("Saliendo...\n");
										fflush(stdout);
										break;
									case 1: // Informe venta
										printf("Informe venta.\n");
										fflush(stdout);
										break;
									case 2: // Informe alquiler
										printf("Informe alquiler.\n");
										fflush(stdout);
										break;
									case 3: // Informe renting
										printf("Informe renting.\n");
										fflush(stdout);
										break;
									case 4: // Informe movimiento coche
										printf("Informe movimiento coche.\n");
										fflush(stdout);
										break;
									case 5: // Informe reparaciones
										printf("Informe reparaciones.\n");
										fflush(stdout);
										break;
									case 6: // Informe revisiones
										printf("Informe revisiones.\n");
										fflush(stdout);
										break;
									default:
										printf(
												"Error! La opción seleccionada no es correcta\n");
										fflush(stdout);
										break;
									}
								} while (op141 != 0);

								break;
							case 2: // Visualizar informes
								printf("Visualizar informes.\n");
								fflush(stdout);
								break;
							default:
								printf(
										"Error! La opción seleccionada no es correcta\n");
								fflush(stdout);
								break;
							}
						} while (op14 != 0);
						break;
					default:
						printf(
								"Error! La opción seleccionada no es correcta\n");
						fflush(stdout);
						break;
					}
				} while (op1 != 0);
			} else {
				printf("No estas autorizado para acceder a este menú.\n");
				fflush(stdout);
			}
			break;
			/*
			 * MENU GERENTE
			 */
		case 2:
			if (verificarGerente(le)) {
				do {
					op2 = mostrarMenuGerente();
					switch (op2) {
					case 0:
						printf("Saliendo...\n");
						fflush(stdout);
						break;
						/*
						 * GESTION EMPLEADO
						 */
					case 1:
						do {
							op21 = mostrarMenuGerenteEmp();
							switch (op21) {
							case 0:
								printf("Saliendo...\n");
								fflush(stdout);
								break;
							case 1: // Añadir empleado
								addEmp(&le, pedirEmp(le));
								printf("Empleado añadido.\n");
								fflush(stdout);
								break;
							case 2: // Modificar empleado
								printf("Modificar empleado\n");
								fflush(stdout);
								break;
							case 3: // Eliminar empleado
								printf("Eliminar empleado\n");
								fflush(stdout);
								break;
							case 4: // Consultar empleado
								printf("Consular empleado\n");
								fflush(stdout);
								break;
							default:
								printf(
										"Error! La opción seleccionada no es correcta\n");
								fflush(stdout);
								break;
							}
						} while (op21 != 0);
						break;
						/*
						 * GESTION CONCESIONARIOS
						 */
					case 2: // Gestión concesionarios
						do {
							op22 = mostrarMenuGerenteConce();
							switch (op22) {
							case 0:
								printf("Saliendo...");
								fflush(stdout);
								break;
							case 1: // Añadir concesionarios
								printf("Añadir concesionario.\n");
								fflush(stdout);
								break;
							case 2: // Modificar concesionarios
								printf("Modificar concesionario.\n");
								fflush(stdout);
								break;
							case 3: // Eliminar concesionarios
								printf("Eliminar concesionarios");
								fflush(stdout);
								break;
							case 4: // Consultar concesionarios
								printf("Consultar concesionarios");
								fflush(stdout);
								break;
							default:
								printf(
										"Error! La opción seleccionada no es correcta.\n");
								fflush(stdout);
								break;
							}
						} while (op22 != 0);
						break;
					default:
						printf(
								"Error! La opción seleccionada no es correcta.\n");
						fflush(stdout);
						break;
					}
				} while (op2 != 0);
			} else {
				printf("No estas autorizado para acceder a este menú.\n");
				fflush(stdout);
			}
			break;
		default:
			printf("Error! La opción seleccionada no es correcta\n");
			fflush(stdout);
			break;
		}
	} while (op != 0);

	volcarDatosABD(db, la, lau, lc, lcon, le, lm, lop, lr, lt, lv, lvent);

	freeListas(&la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt, &lv, &lvent);
}
