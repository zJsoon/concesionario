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
	int op, op1, op11, op12, op2, op21, op22, op222, op223, op23, op24, op241,
			verifyEmpleado = 1, op3, op31, op32, verifyGerente = 1;

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
			printf("Saliendo...\n");
			break;
		/*
		 * MENU USUARIO
		 */
		case 1:
			do {
				op1 = mostrarMenuUsuario();
				switch (op1) {
				case 0: // Salir
					printf("Saliendo...\n");
					fflush(stdout);
					break;
				case 1: // Ver concesionarios
					do {
						op11 = mostrarMenuUsuarioConce();
						switch (op11) {
						case 0:
							printf("Saliendo...\n");
							fflush(stdout);
							break;
						case 1: // Visualizar todos
							printf("Visualizar todos los concesionarios.\n");
							fflush(stdout);
							break;
						case 2: // Filtrar por ciudad
							printf("Filtrar concesionarios por ciudad.\n");
							fflush(stdout);
							break;
						case 3: // Filtrar por marca
							printf("Filtrar concesionarios por marca.\n");
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
				case 2: // Ver vehículos
					do {
						op12 = mostrarMenuUsuarioVeh();
						switch (op12) {
						case 0:
							printf("Saliendo...\n");
							fflush(stdout);
							break;
						case 1: // Visualizar todos
							printf("Visualizar todos los vehículos.\n");
							fflush(stdout);
							break;
						case 2: // Filtrar por concesionario
							printf("Filtrar por concesionarios\n");
							fflush(stdout);
							break;
						case 3: // Filtrar por marca
							printf("Filtrar por marca\n");
							fflush(stdout);
							break;
						case 4: // Filtrar por modelo
							printf("Filtrar por modelo\n");
							fflush(stdout);
							break;
						case 5: // Filtrar por tipo
							printf("Filtrar por tipo\n");
							fflush(stdout);
							break;
						case 6: // Filtrar por estado
							printf("Filtrar por estado\n");
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
				case 3: // Consultar historial un vehículo
					printf("Consultar historial un vehículo.\n");
					fflush(stdout);
					break;
				default:
					printf("Error! La opción seleccionada no es correcta\n");
					fflush(stdout);
					break;
				}
			} while (op1 != 0);
			break;

		/*
		* MENU EMPLEADO
		*/
		case 2:
			if (verifyEmpleado) {
				do {
					op2 = mostrarMenuEmp();
					switch (op2) {
					case 0:
						printf("Saliendo...\n");
						fflush(stdout);
						break;
					case 1:
						do {
							op21 = mostrarMenuEmpGest();
							switch (op21) {
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
						} while (op21 != 0);
						break;
					case 2:
						do {
							op22 = mostrarMenuEmpOperaciones();
							switch (op22) {
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
									op222 = mostrarMenuEmpOperacionesAlquiler();
									switch (op222) {
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
								} while (op222 != 0);
								break;
							case 3:
								do {
									op223 = mostrarMenuEmpOperacionesRenting();
									switch (op223) {
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
								} while (op223 != 0);
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
						} while (op22 != 0);
						break;
					case 3: //Mantenimiento
						do {
							op23 = mostrarMenuEmpMantenimiento();
							switch (op23) {
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
						} while (op23 != 0);
						break;
					case 4: //Informes
						do {
							op24 = mostrarMenuEmpInformes();
							switch (op24) {
							case 0:
								printf("Saliendo...\n");
								fflush(stdout);
								break;
							case 1: // Generar informes
								do {
									op241 = mostrarMenuEmpInformesGenerar();
									switch (op241) {
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
								} while (op241 != 0);

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
						} while (op24 != 0);
						break;
					default:
						printf(
								"Error! La opción seleccionada no es correcta\n");
						fflush(stdout);
						break;
					}
				} while (op2 != 0);
			}
			break;
		/*
		* MENU GERENTE
		*/
		case 3:
			if (verifyGerente) {
				do {
					op3 = mostrarMenuGerente();
					switch (op3) {
					case 0:
						printf("Saliendo...\n");
						fflush(stdout);
						break;
					case 1: // Gestión empleado
						do {
							op31 = mostrarMenuGerenteEmp();
							switch (op31) {
							case 0:
								printf("Saliendo...\n");
								fflush(stdout);
								break;
							case 1: // Añadir empleado
								printf("Añadir empleado\n");
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
						} while (op31 != 0);
						break;
					case 2: // Gestión concesionarios
						do {
							op32 = mostrarMenuGerenteConce();
							switch (op32) {
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
								printf("Error! La opción seleccionada no es correcta.\n");
								fflush(stdout);
								break;
							}
						} while (op32 != 0);
						break;
					default:
						printf("Error! La opción seleccionada no es correcta.\n");
						fflush(stdout);
						break;
					}
				} while (op3 != 0);
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
