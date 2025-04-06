#ifndef DB_MANAGER_H_
#define DB_MANAGER_H_
#include <string.h>
#include <stdlib.h>

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

void addAlquilerToDB(sqlite3 *db, ListaAlquileres la);
void addAuditoriaToDB(sqlite3 *db, ListaAuditorias lau);
void addClientToDB(sqlite3 *db, ListaClientes lc);
void addConceToDB(sqlite3 *db, ListaConce lcon);
void addEmpToDB(sqlite3 *db, ListaEmp le);
void addMantenimientoToDB(sqlite3 *db, ListaMantenimientos lm);
void addOperacionesToDB(sqlite3 *db, ListaOperaciones lop);
void addRentingToDB(sqlite3 *db, ListaRenting lr);
void addTransladosToDB(sqlite3 *db, ListaTraslados lt);
void addVehToDB(sqlite3 *db, ListaVeh lv);
void addVentToDB(sqlite3 *db, ListaVent lvent);


void loadAlquileresFromDB(sqlite3 *db, ListaAlquileres *la);
void loadAuditoriaFromDB(sqlite3 *db, ListaAuditorias *lau);
void loadClientesFromDB(sqlite3 *db, ListaClientes *lc);
void loadConceFromDB(sqlite3 *db, ListaConce *lcon);
void loadEmpFromDB(sqlite3 *db, ListaEmp *le);
void loadMantenimientosFromDB(sqlite3 *db, ListaMantenimientos *lm);
void loadOperacionesFromDB(sqlite3 *db, ListaOperaciones *lop);
void loadRentingFromDB(sqlite3 *db, ListaRenting *lr);
void loadTrasladosFromDB(sqlite3 *db, ListaTraslados *lt);
void loadVehFromDB(sqlite3 *db, ListaVeh *lv);
void loadVentasFromDB(sqlite3 *db, ListaVent *lvent);


#endif /* DB_MANAGER_H_ */
