#include <stdio.h>
#include <stdlib.h>

#include "ini.h"

void iniListas(ListaAlquileres *la, ListaAuditorias *lau, ListaClientes *lc,
		ListaConce *lcon, ListaEmp *le, ListaMantenimientos *lm,
		ListaOperaciones *lop, ListaRenting *lr, ListaTraslados *lt,
		ListaVeh *lv, ListaVent *lvent) {
	iniLA(la);
	iniLAU(lau);
	iniLC(lc);
	iniLCon(lcon);
	iniLE(le);
	iniLM(lm);
	iniLOP(lop);
	iniLR(lr);
	iniLT(lt);
	iniLV(lv);
	iniLVent(lvent);

	printf("Listas inicializadas.\n");
	fflush(stdout);
}

void freeListas(ListaAlquileres *la, ListaAuditorias *lau, ListaClientes *lc,
		ListaConce *lcon, ListaEmp *le, ListaMantenimientos *lm,
		ListaOperaciones *lop, ListaRenting *lr, ListaTraslados *lt,
		ListaVeh *lv, ListaVent *lvent) {
	free(la->aAlquiler);
	free(lau->aAuditoria);
	free(lc->aClient);
	free(lcon->aConce);
	free(le->aEmp);
	free(lm->aMantenimiento);
	free(lop->aOperaciones);
	free(lr->aRenting);
	free(lt->aTraslado);
	free(lv->aVeh);
	free(lvent->aVent);

	printf("Listas liberadas.\n");
	fflush(stdout);
}

void guardarDatos(ListaConce lcon, ListaEmp le, ListaVeh lv) {
	copyEmpCSV(EMP_CSV, le);
	copyConceCSV(CONC_CSV, lcon);
	copyVehCSV(VEH_CSV, lv);
}

void volcarDatosABD(sqlite3 *db, ListaAlquileres la, ListaAuditorias lau,
                    ListaClientes lc, ListaConce lcon, ListaEmp le,
                    ListaMantenimientos lm, ListaOperaciones lop, ListaRenting lr,
                    ListaTraslados lt, ListaVeh lv, ListaVent lvent) {

    if (db == NULL) {
        fprintf(stderr, "Error: No se ha establecido conexión con la base de datos.\n");
        return;
    }

    // Iniciar transacción
    char *errMsg = NULL;
    if (sqlite3_exec(db, "BEGIN TRANSACTION", NULL, NULL, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "Error al iniciar transacción: %s\n", errMsg);
        sqlite3_free(errMsg);
        return;
    }

    // Volcar cada tipo de datos
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

    // Confirmar transacción
    if (sqlite3_exec(db, "COMMIT", NULL, NULL, &errMsg) != SQLITE_OK) {
        fprintf(stderr, "Error al confirmar transacción: %s\n", errMsg);
        sqlite3_free(errMsg);
        sqlite3_exec(db, "ROLLBACK", NULL, NULL, NULL); // Deshacer cambios en caso de error
        return;
    }

    printf("Datos volcados correctamente a la base de datos.\n");
}

void cargarDatosDesdeBD(sqlite3 *db, ListaAlquileres *la, ListaAuditorias *lau,
                         ListaClientes *lc, ListaConce *lcon, ListaEmp *le,
                         ListaMantenimientos *lm, ListaOperaciones *lop,
                         ListaRenting *lr, ListaTraslados *lt, ListaVeh *lv,
                         ListaVent *lvent) {

    if (db == NULL) {
        fprintf(stderr, "Error: No se ha establecido conexión con la base de datos.\n");
        return;
    }

    // Cargar cada tipo de datos
    loadAlquileresFromDB(db, la);
    loadAuditoriaFromDB(db, lau);
    loadClientesFromDB(db, lc);
    loadConceFromDB(db, lcon);
    loadEmpFromDB(db, le);
    loadMantenimientosFromDB(db, lm);
    loadOperacionesFromDB(db, lop);
    loadRentingFromDB(db, lr);
    loadTrasladosFromDB(db, lt);
    loadVehFromDB(db, lv);
    loadVentasFromDB(db, lvent);

    printf("Datos cargados correctamente desde la base de datos.\n");
}
