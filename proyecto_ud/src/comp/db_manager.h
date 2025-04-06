#ifndef DB_MANAGER_H_
#define DB_MANAGER_H_

#include "sqlite3.h"
#include "../utils/alquiler/alquiler.h"
#include "../utils/audit/audit.h"
#include "../utils/client/client.h"
#include "../utils/concesionario/concesionario.h"
#include "../utils/emp/emp.h"
#include "../utils/mantenimiento/mantenimiento.h"
#include "../utils/operaciones/operaciones.h"
#include "../utils/renting/renting.h"
#include "../utils/translados/translados.h"
#include "../utils/translados/translados.h"
#include "../utils/veh/veh.h"
#include "../utils/vent/vent.h"

void addAlquilerToDB(sqlite3 db, ListaAlquileres la);
void addAuditoriaToDB(sqlite3 db, ListaAuditorias lau);
void addClientToDB(sqlite3 db, ListaClientes lc);
void addConceToDB(sqlite3 db, ListaConce lcon);
void addEmpToDB(sqlite3 db, ListaEmp le);
void addMantenimientoToDB(sqlite3 db, ListaMantenimientos lm);
void addOperacionesToDB(sqlite3 db, ListaOperaciones lop);
void addRentingToDB(sqlite3 db, ListaRenting lr);
void addTransladosToDB(sqlite3 db, ListaTraslados lt);
void addVehToDB(sqlite3 db, ListaVeh lv);
void addVentToDB(sqlite3 db, ListaVent lvent);


#endif /* DB_MANAGER_H_ */
