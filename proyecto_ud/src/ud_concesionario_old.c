/*
 ARCHIVO ANTIGUO DONDE SOLO SE USA EL SERVIDOR.
 */

//#include <unistd.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdio.h>
//#include <winsock2.h>
//#define SERVER_IP "127.0.0.1"
//#define SERVER_PORT 6000
//
//#include "menus/menu.h"
//#include "menus/manageMenu.h"
//
//#include "comp/ini.h"
//#include "comp/db_manager.h"
//#include "comp/sqlite3.h"
//
//#include "config/config.h"
//
//#include "utils/alquiler/alquiler.h"
//#include "utils/audit/audit.h"
//#include "utils/client/client.h"
//#include "utils/concesionario/concesionario.h"
//#include "utils/emp/emp.h"
//#include "utils/mantenimiento/mantenimiento.h"
//#include "utils/operaciones/operaciones.h"
//#include "utils/renting/renting.h"
//#include "utils/translados/translados.h"
//#include "utils/veh/veh.h"
//#include "utils/vent/vent.h"
//#include "utils/informes/informes.h"
//#include "utils/gestion/gestion.h"
//
//#define TAM_DNI_MENU 10
//
//int main(int argc, char *argv[]) {
//	int op, op1, op11, op12, op122, op123, op13, op14, op141, op2, op21, op22, result;
//	char dni[TAM_DNI_MENU];
//
//	ListaAlquileres la;
//	ListaAuditorias lau;
//	ListaClientes lc;
//	ListaConce lcon;
//	ListaEmp le;
//	ListaMantenimientos lm;
//	ListaOperaciones lop;
//	ListaRenting lr;
//	ListaTraslados lt;
//	ListaVeh lv;
//	ListaVent lvent;
//	Client c;
//	//Config c = leerConfiguracion("../data/ini.config");
//	//fflush(stdout);
//	sqlite3 *db;
//
//	iniListas(&la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt, &lv, &lvent);
//	result = sqlite3_open("concesionario.db", &db);
//	if (result != SQLITE_OK) {
//		printf("Error al abrir DB.\n");
//		fflush(stdout);
//		return result;
//	}
//
//	loadAlquileresFromDB(db, &la);
//	loadAuditoriaFromDB(db, &lau);
//	loadClientesFromDB(db, &lc);
//	loadConceFromDB(db, &lcon);
//	loadEmpFromDB(db, &le);
//	loadMantenimientosFromDB(db, &lm);
//	loadOperacionesFromDB(db, &lop);
//	loadRentingFromDB(db, &lr);
//	loadTrasladosFromDB(db, &lt);
//	loadVehFromDB(db, &lv);
//	loadVentasFromDB(db, &lvent);
//	printLCli(lc);
//		do {
//			op = mostrarMenuInicio();
//			switch (op) {
//			case 0:
//				printf("Saliendo...\n");
//				fflush(stdout);
//				break;
//
//				/*
//				 * MENU EMPLEADO
//				 */
//			case 1:
//				if (verificarEmpleado(le)) {
//					do {
//						op1 = mostrarMenuEmp();
//						switch (op1) {
//						case 0:
//							printf("Saliendo...\n");
//							fflush(stdout);
//							break;
//							/*
//							 * GESTION CLIENTES
//							 */
//						case 1:
//							do {
//								op11 = mostrarMenuEmpGest();
//								switch (op11) {
//								case 0:
//									printf("Saliendo...\n");
//									fflush(stdout);
//									break;
//								case 1: // Añadir Clientes
//									c = registrarCliente(lc);
//									addClient(&lc, c);
//									break;
//								case 2: // Modificar Clientes
//									modClientes(&lc); // TODO
//									break;
//								case 3: // Eliminar Clientes
//									pedirDNI(dni);
//									elimClientes(&lc, dni); // TODO
//									break;
//								case 4: // Consultar Clientes
//									pedirDNI(dni);
//									consultClientes(lc, dni); // TODO
//									break;
//								default:
//									printf(
//											"Error! La opción seleccionada no es correcta\n");
//									fflush(stdout);
//									break;
//								}
//							} while (op11 != 0);
//							break;
//							/*
//							 * OPERACIONES
//							 */
//						case 2:
//							do {
//								op12 = mostrarMenuEmpOperaciones();
//								switch (op12) {
//								case 0:
//									printf("Saliendo...\n");
//									fflush(stdout);
//									break;
//								case 1: // Registrar venta
//									registrarVenta(&lvent, lv, pedirMatricula());
//									break;
//								case 2: // Registrar alquiler
//									do {
//										op122 = mostrarMenuEmpOperacionesAlquiler();
//										switch (op122) {
//										case 0:
//											printf("Saliendo...\n");
//											fflush(stdout);
//											break;
//										case 1: // Inicio alquiler
//											startAlquiler(pedirMatricula(), &lv,
//													&la);
//											break;
//										case 2: // Estado alquiler
//											estadoAlquiler(pedirMatricula(), &lv,
//													&la);
//											break;
//										case 3: // Fin alquiler
//											endAlquiler(pedirMatricula(), &lv, &la);
//											break;
//										default:
//											printf(
//													"Error! La opción seleccionada no es correcta\n");
//											fflush(stdout);
//											break;
//										}
//									} while (op122 != 0);
//									break;
//								case 3:
//									do {
//										op123 = mostrarMenuEmpOperacionesRenting();
//										switch (op123) {
//										case 0:
//											printf("Saliendo...\n");
//											fflush(stdout);
//											break;
//										case 1: // Inicio renting
//											startRenting(&lr,
//													obtenerVehiculoID(lv,
//															pedirMatricula()));
//											break;
//										case 2: // Estado renting
//											estadoRenting(lr,
//													obtenerVehiculoID(lv,
//															pedirMatricula()));
//											break;
//										case 3: // Fin reinting
//											endRenting(&lr,
//													obtenerVehiculoID(lv,
//															pedirMatricula()));
//											break;
//										default:
//											printf(
//													"Error! La opción seleccionada no es correcta\n");
//											fflush(stdout);
//											break;
//										}
//										break;
//									} while (op123 != 0);
//									break;
//								case 4: // Registrar movimiento coche
//									registrarTranslado(pedirMatricula(), lv, &lt);
//									break;
//								default:
//									printf(
//											"Error! La opción seleccionada no es correcta\n");
//									fflush(stdout);
//									break;
//								}
//							} while (op12 != 0);
//							break;
//							/*
//							 * MANTENIMIENTO
//							 */
//						case 3:
//							do {
//								op13 = mostrarMenuEmpMantenimiento();
//								switch (op13) {
//								case 0:
//									printf("Saliendo...\n");
//									fflush(stdout);
//									break;
//								case 1: // Registrar reparaciones
//									registrarRep(&lm, pedirMatricula());
//									break;
//								case 2: // Registrar revisiones
//									registrarRevi(&lm, pedirMatricula());
//									break;
//								case 3: // Visualizar reparaciones
//									visualizarMantRep(lm, pedirMatricula());
//									break;
//								case 4: // Visualizar revisiones
//									visualizarMantRevi(lm, pedirMatricula());
//									break;
//								default:
//									printf(
//											"Error! La opción seleccionada no es correcta\n");
//									fflush(stdout);
//									break;
//								}
//							} while (op13 != 0);
//							break;
//							/*
//							 * INFORMES
//							 */
//						case 4:
//							do {
//								op14 = mostrarMenuEmpInformes();
//								switch (op14) {
//								case 0:
//									printf("Saliendo...\n");
//									fflush(stdout);
//									break;
//								case 1: // Generar informes
//									do {
//										op141 = mostrarMenuEmpInformesGenerar();
//										switch (op141) {
//										case 0:
//											printf("Saliendo...\n");
//											fflush(stdout);
//											break;
//										case 1: // Informe venta
//											informeVenta(lv, lvent,
//													pedirMatricula());
//											break;
//										case 2: // Informe alquiler
//											informeAlquiler(lv, la,
//													pedirMatricula());
//											break;
//										case 3: // Informe renting
//											informeRenting(lv, lr,
//													pedirMatricula());
//											break;
//										case 4: // Informe movimiento coche
//											informeMovimientoCoche(lv, lt,
//													pedirMatricula());
//											break;
//										default:
//											printf(
//													"Error! La opción seleccionada no es correcta\n");
//											fflush(stdout);
//											break;
//										}
//									} while (op141 != 0);
//
//									break;
//								case 2: // Visualizar informes
//									visualizarInformes(lv, lvent, la, lr, lt,
//											pedirMatricula());
//									break;
//								default:
//									printf(
//											"Error! La opción seleccionada no es correcta\n");
//									fflush(stdout);
//									break;
//								}
//							} while (op14 != 0);
//							break;
//						default:
//							printf(
//									"Error! La opción seleccionada no es correcta\n");
//							fflush(stdout);
//							break;
//						}
//					} while (op1 != 0);
//				} else {
//					printf("No estas autorizado para acceder a este menú.\n");
//					fflush(stdout);
//				}
//				break;
//				/*
//				 * MENU GERENTE
//				 */
//			case 2:
//				if (verificarGerente(le)) {
//					do {
//						op2 = mostrarMenuGerente();
//						switch (op2) {
//						case 0:
//							printf("Saliendo...\n");
//							fflush(stdout);
//							break;
//							/*
//							 * GESTION EMPLEADO
//							 */
//						case 1:
//							do {
//								op21 = mostrarMenuGerenteEmp();
//								switch (op21) {
//								case 0:
//									printf("Saliendo...\n");
//									fflush(stdout);
//									break;
//								case 1: // Añadir empleado
//									addEmp(&le, pedirEmp(le));
//									break;
//								case 2: // Modificar empleado
//									pedirDNI(dni);
//									modEmp(dni, &le);
//									break;
//								case 3: // Eliminar empleado
//									pedirDNI(dni);
//									elimEmp(dni, &le);
//									break;
//								case 4: // Consultar empleado
//									pedirDNI(dni);
//									consultEmp(dni, le);
//									break;
//								default:
//									printf(
//											"Error! La opción seleccionada no es correcta\n");
//									fflush(stdout);
//									break;
//								}
//							} while (op21 != 0);
//							break;
//							/*
//							 * GESTION CONCESIONARIOS
//							 */
//						case 2: // Gestión concesionarios
//							do {
//								op22 = mostrarMenuGerenteConce();
//								switch (op22) {
//								case 0:
//									printf("Saliendo...");
//									fflush(stdout);
//									break;
//								case 1: // Añadir concesionarios
//									addConce(&lcon, pedirConce(lcon));
//									break;
//								case 2: // Modificar concesionarios
//									modConce(&lcon);
//									break;
//								case 3: // Eliminar concesionarios
//									elimConce(&lcon);
//									break;
//								case 4: // Consultar concesionarios
//									consultConce(lcon, lv, pedirIDConce());
//									break;
//								default:
//									printf(
//											"Error! La opción seleccionada no es correcta.\n");
//									fflush(stdout);
//									break;
//								}
//							} while (op22 != 0);
//							break;
//						default:
//							printf(
//									"Error! La opción seleccionada no es correcta.\n");
//							fflush(stdout);
//							break;
//						}
//					} while (op2 != 0);
//				} else {
//					printf("No estas autorizado para acceder a este menú.\n");
//					fflush(stdout);
//				}
//				break;
//			default:
//				printf("Error! La opción seleccionada no es correcta\n");
//				fflush(stdout);
//				break;
//			}
//		} while (op != 0);
//
//	addAlquilerToDB(db, la);
//	addAuditoriaToDB(db, lau);
//	addClientToDB(db, lc);
//	addConceToDB(db, lcon);
//	addEmpToDB(db, le);
//	addMantenimientoToDB(db, lm);
//	addOperacionesToDB(db, lop);
//	addRentingToDB(db, lr);
//	addTransladosToDB(db, lt);
//	addVehToDB(db, lv);
//	addVentToDB(db, lvent);
//
//	sqlite3_close(db);
//	freeListas(&la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt, &lv, &lvent);
//
//
//	return 0;
//}
