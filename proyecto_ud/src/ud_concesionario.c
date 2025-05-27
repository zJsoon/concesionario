#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <winsock2.h>
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 6000

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
#include "utils/informes/informes.h"
#include "utils/gestion/gestion.h"

#define TAM_DNI_MENU 10

int main(int argc, char *argv[]) {
	WSADATA wsaData;
	SOCKET conn_socket; //el que lleva la conexion
	SOCKET comm_socket; //el que lo comunica
	struct sockaddr_in server;
	struct sockaddr_in client;
	char sendBuff[4096], recvBuff[512]; // lo que yo envio, lo que yo recibo
	//int op, op1, op11, op12, op122, op123, op13, op14, op141, op2, op21, op22,
	int result;
	//char dni[TAM_DNI_MENU];

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
	//Client c;
	//Config c = leerConfiguracion("../data/ini.config");
	//fflush(stdout);
	sqlite3 *db;

	iniListas(&la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt, &lv, &lvent);
	result = sqlite3_open("concesionario.db", &db);
	if (result != SQLITE_OK) {
		printf("Error al abrir DB.\n");
		fflush(stdout);
		return result;
	}

	loadAlquileresFromDB(db, &la);
	loadAuditoriaFromDB(db, &lau);
	loadClientesFromDB(db, &lc);
	loadConceFromDB(db, &lcon);
	loadEmpFromDB(db, &le);
	loadMantenimientosFromDB(db, &lm);
	loadOperacionesFromDB(db, &lop);
	loadRentingFromDB(db, &lr);
	loadTrasladosFromDB(db, &lt);
	loadVehFromDB(db, &lv);
	loadVentasFromDB(db, &lvent);
	//printLCli(lc);

	printf("\nInitialising Winsock...\n"); // inicializa la libreria
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		printf("Failed. Error Code : %d", WSAGetLastError());
		return -1;
	}

	printf("Initialised.\n");

	if ((conn_socket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		printf("Could not create socket : %d", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	printf("Socket created.\n");

	server.sin_addr.s_addr = inet_addr(SERVER_IP); //INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);

	if (bind(conn_socket, (struct sockaddr*) &server,
			sizeof(server)) == SOCKET_ERROR) {
		printf("Bind failed with error code: %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}

	printf("Bind done.\n");

	if (listen(conn_socket, 1) == SOCKET_ERROR) {
		printf("Listen failed with error code: %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}

	printf("Waiting for incoming connections...\n");
	int stsize = sizeof(struct sockaddr);
	comm_socket = accept(conn_socket, (struct sockaddr*) &client, &stsize);

	if (comm_socket == INVALID_SOCKET) {
		printf("accept failed with error code : %d", WSAGetLastError());
		closesocket(conn_socket);
		WSACleanup();
		return -1;
	}
	printf("Incomming connection from: %s (%d)\n", inet_ntoa(client.sin_addr),
			ntohs(client.sin_port));

	closesocket(conn_socket);

	int opcion, opcion1, opcion2;
	do {
		// Limpiar buffers ANTES de usarlos
		memset(recvBuff, 0, sizeof(recvBuff));
		memset(sendBuff, 0, sizeof(sendBuff));

		recv(comm_socket, recvBuff, sizeof(recvBuff), 0); // Recibir opción del cliente
		sscanf(recvBuff, "%d", &opcion);

		// Limpiar de nuevo antes de enviar respuesta
		memset(sendBuff, 0, sizeof(sendBuff));
		sprintf(sendBuff, "Servidor: Opción recibida %d", opcion);
		send(comm_socket, sendBuff, sizeof(sendBuff), 0);

		switch (opcion) {
		case 1:
			// Limpiar ANTES de recibir subopción
			memset(recvBuff, 0, sizeof(recvBuff));
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sscanf(recvBuff, "%d", &opcion1);

			switch (opcion1) {
			case 1:

				// SOLUCIÓN: Enviar todo en un solo mensaje grande
				memset(sendBuff, 0, sizeof(sendBuff));

				// Construir mensaje completo con todos los concesionarios
				//char temp[1000];
				int offset = 0;

				// Añadir cabecera
				offset += sprintf(sendBuff + offset,
						"LISTA DE CONCESIONARIOS:\n");
				offset += sprintf(sendBuff + offset,
						"%-10s%-30s%-40s%-15s%-15s%-30s\n", "ID", "NOMBRE",
						"DIRECCIÓN", "CIUDAD", "TELÉFONO", "EMAIL");
				offset +=
						sprintf(sendBuff + offset,
								"------------------------------------------------------------------------------------------------------------------------------------\n");

				// Añadir cada concesionario
				for (int i = 0; i < lcon.numConces; i++) {
					offset += sprintf(sendBuff + offset,
							"%-10d%-30s%-40s%-15s%-15s%-30s\n",
							lcon.aConce[i].ID, lcon.aConce[i].nombre,
							lcon.aConce[i].direccion, lcon.aConce[i].ciudad,
							lcon.aConce[i].tlf, lcon.aConce[i].email);
				}

				send(comm_socket, sendBuff, strlen(sendBuff), 0);
				break;

			case 2:
				// NUEVA OPCIÓN: Consultar concesionario específico
				memset(sendBuff, 0, sizeof(sendBuff));
				sprintf(sendBuff,
						"Ingrese el ID del concesionario a consultar:");
				send(comm_socket, sendBuff, strlen(sendBuff), 0);

				// Recibir el ID del concesionario
				memset(recvBuff, 0, sizeof(recvBuff));
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);

				// Ejecutar la consulta
				consultConceSocket(comm_socket, lcon, lv, recvBuff);
				break;

			case 3:
				// NUEVA OPCIÓN: Consultar concesionario específico
				memset(sendBuff, 0, sizeof(sendBuff));
				sprintf(sendBuff,
						"Ingrese la ciudad del concesionario a consultar:");
				send(comm_socket, sendBuff, strlen(sendBuff), 0);

				// Recibir el ID del concesionario
				memset(recvBuff, 0, sizeof(recvBuff));
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);

				// Ejecutar la consulta
				consultConceCiudadSocket(comm_socket, lcon, recvBuff);
				break;

			case 0:
				memset(sendBuff, 0, sizeof(sendBuff));
				sprintf(sendBuff, "Saliendo del menú concesionarios.");
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				break;

			default:
				memset(sendBuff, 0, sizeof(sendBuff));
				sprintf(sendBuff, "Opción no válida: %d", opcion1);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				break;
			}
			break;

		case 2:
			// Limpiar ANTES de recibir subopción
			memset(recvBuff, 0, sizeof(recvBuff));
			recv(comm_socket, recvBuff, sizeof(recvBuff), 0);
			sscanf(recvBuff, "%d", &opcion2);

			switch (opcion2) {
			case 1:
				memset(sendBuff, 0, sizeof(sendBuff));

				// Construir mensaje completo con todos los concesionarios
				//char temp[1000];
				int offset = 0;

				// Añadir cabecera
				offset += sprintf(sendBuff + offset, "LISTA DE VEHÍCULOS:\n");
				offset +=
						sprintf(sendBuff + offset,
								"%-10s%-15s%-20s%-20s%-10s%-15s%-15s%-12s%-12s%-15s%-15s%-10s%-10s%-15s\n",
								"ID", "MATRÍCULA", "MARCA", "MODELO", "AÑO",
								"TIPO", "COLOR", "PRECIO_COMP", "PRECIO_VENT",
								"ESTADO", "FECHA_ADQ", "CONCE_ID", "KM",
								"COMBUSTIBLE");

				// Añadir cada vehículo
				for (int i = 0; i < lv.numVeh; i++) {
					offset +=
							sprintf(sendBuff + offset,
									"%10d%15s%20s%20s%10d%15s%15s%12.2f%12.2f%15s%15s%10d%10.2f%15s\n",
									lv.aVeh[i].ID, lv.aVeh[i].matricula,
									lv.aVeh[i].marca, lv.aVeh[i].modelo,
									lv.aVeh[i].year, lv.aVeh[i].tipo,
									lv.aVeh[i].color, lv.aVeh[i].precio_compra,
									lv.aVeh[i].precio_venta, lv.aVeh[i].estado,
									lv.aVeh[i].fecha_adquisicion,
									lv.aVeh[i].concesionario_ID, lv.aVeh[i].kilometraje,
									lv.aVeh[i].tipo_combustible);
				}

				send(comm_socket, sendBuff, strlen(sendBuff), 0);
				break;

			case 2:
				// NUEVA OPCIÓN: Consultar concesionario específico
				memset(sendBuff, 0, sizeof(sendBuff));
				sprintf(sendBuff,
						"Ingrese el ID del vehículo a consultar:");
				send(comm_socket, sendBuff, strlen(sendBuff), 0);

				// Recibir el ID del concesionario
				memset(recvBuff, 0, sizeof(recvBuff));
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);

				// Ejecutar la consulta
				consultVehSocket(comm_socket, lv, recvBuff);
				break;

			case 3:
				// NUEVA OPCIÓN: Consultar concesionario específico
				memset(sendBuff, 0, sizeof(sendBuff));
				sprintf(sendBuff,
						"Ingrese el marca del vehículo a consultar:");
				send(comm_socket, sendBuff, strlen(sendBuff), 0);

				// Recibir el ID del concesionario
				memset(recvBuff, 0, sizeof(recvBuff));
				recv(comm_socket, recvBuff, sizeof(recvBuff), 0);

				// Ejecutar la consulta
				consultVehMarcaSocket(comm_socket, lv, recvBuff);
				break;

			case 0:
				memset(sendBuff, 0, sizeof(sendBuff));
				sprintf(sendBuff, "Saliendo del menú vehículos.");
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				break;

			default:
				memset(sendBuff, 0, sizeof(sendBuff));
				sprintf(sendBuff, "Opción no válida: %d", opcion1);
				send(comm_socket, sendBuff, sizeof(sendBuff), 0);
				break;
			}
			break;
		case 0:
			memset(sendBuff, 0, sizeof(sendBuff));
			sprintf(sendBuff, "Desconectando...");
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			break;

		default:
			memset(sendBuff, 0, sizeof(sendBuff));
			sprintf(sendBuff, "Opción no válida: %d", opcion);
			send(comm_socket, sendBuff, sizeof(sendBuff), 0);
			break;
		}

	} while (opcion != 0);

	printf("Servidor: Cerrando conexión...\n");

	addAlquilerToDB(db, la);
	addAuditoriaToDB(db, lau);
	addClientToDB(db, lc);
	addConceToDB(db, lcon);
	addEmpToDB(db, le);
	addMantenimientoToDB(db, lm);
	addOperacionesToDB(db, lop);
	addRentingToDB(db, lr);
	addTransladosToDB(db, lt);
	addVehToDB(db, lv);
	addVentToDB(db, lvent);

	sqlite3_close(db);
	freeListas(&la, &lau, &lc, &lcon, &le, &lm, &lop, &lr, &lt, &lv, &lvent);

	// CLOSING the sockets and cleaning Winsock...
	closesocket(comm_socket);
	WSACleanup();

	return 0;
}
