#include <stdio.h>
#include "db_manager.h"

int i;
char sql[200];
sqlite3_stmt *stmt;

void addAlquilerToDB(sqlite3 *db, ListaAlquileres la) {
	sprintf(sql, "DELETE FROM alquiler");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia

	for (i = 0; i < la.numAlquileres; i++) {
		sprintf(sql, "INSERT INTO alquiler VALUES(%i,%i,'%s','%s',%f)",
				la.aAlquiler[i].operacion_id, la.aAlquiler[i].vehiculo_id,
				la.aAlquiler[i].fecha_inicio, la.aAlquiler[i].fecha_fin,
				la.aAlquiler[i].precio_diario);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addAuditoriaToDB(sqlite3 *db, ListaAuditorias lau) {
	sprintf(sql, "DELETE FROM auditoria");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia

	for (i = 0; i < lau.numAuditorias; i++) {
		sprintf(sql, "INSERT INTO auditoria VALUES(%i,%i,'%s','%s','%s')",
				lau.aAuditoria[i].id, lau.aAuditoria[i].operacion_id,
				lau.aAuditoria[i].usuario, lau.aAuditoria[i].fecha_modificacion,
				lau.aAuditoria[i].cambios);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addClientToDB(sqlite3 *db, ListaClientes lc) {
	sprintf(sql, "DELETE FROM cliente");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia

	for (i = 0; i < lc.numClient; i++) {
		sprintf(sql,
				"INSERT INTO cliente VALUES(%i,'%s','%s','%s','%s','%s','%s','%s')",
				lc.aClient[i].ID, lc.aClient[i].dni, lc.aClient[i].nombre,
				lc.aClient[i].apellidos, lc.aClient[i].direccion,
				lc.aClient[i].tlf, lc.aClient[i].email,
				lc.aClient[i].fecha_registro);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addConceToDB(sqlite3 *db, ListaConce lcon) {
	sprintf(sql, "DELETE FROM concesionario");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia

	for (i = 0; i < lcon.numConces; i++) {
		sprintf(sql,
				"INSERT INTO concesionario VALUES(%i,'%s','%s','%s','%s','%s')",
				lcon.aConce[i].ID, lcon.aConce[i].nombre,
				lcon.aConce[i].direccion, lcon.aConce[i].ciudad,
				lcon.aConce[i].tlf, lcon.aConce[i].email);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addEmpToDB(sqlite3 *db, ListaEmp le) {
	sprintf(sql, "DELETE FROM empleado");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia

	for (i = 0; i < le.numEmp; i++) {
		sprintf(sql, "INSERT INTO empleado VALUES(%i,'%s','%s','%s',%i)",
				le.aEmp[i].ID, le.aEmp[i].DNI, le.aEmp[i].nombre,
				le.aEmp[i].cargo, le.aEmp[i].conce_id);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addMantenimientoToDB(sqlite3 *db, ListaMantenimientos lm) {
	sprintf(sql, "DELETE FROM mantenimiento");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia

	for (i = 0; i < lm.numMantenimientos; i++) {
		sprintf(sql,
				"INSERT INTO mantenimiento VALUES(%i,%i,'%s','%s',%f,'%s')",
				lm.aMantenimiento[i].id, lm.aMantenimiento[i].vehiculo_id,
				lm.aMantenimiento[i].fecha, lm.aMantenimiento[i].tipo,
				lm.aMantenimiento[i].coste, lm.aMantenimiento[i].descripcion);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addOperacionesToDB(sqlite3 *db, ListaOperaciones lop) {
	sprintf(sql, "DELETE FROM operaciones");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia

	for (i = 0; i < lop.numOperaciones; i++) {
		sprintf(sql,
				"INSERT INTO operaciones VALUES(%i,'%s', %i,%i,%i,'%s',%i)",
				lop.aOperaciones[i].ID, lop.aOperaciones[i].tipo,
				lop.aOperaciones[i].vehiculo_ID, lop.aOperaciones[i].cliente_ID,
				lop.aOperaciones[i].empleado_ID,
				lop.aOperaciones[i].fecha_operacion,
				lop.aOperaciones[i].concesionario_ID);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addRentingToDB(sqlite3 *db, ListaRenting lr) {
	sprintf(sql, "DELETE FROM renting");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia
	for (i = 0; i < lr.numRenting; i++) {
		sprintf(sql, "INSERT INTO renting VALUES(%i,%i,%i,%f)",
				lr.aRenting[i].operacion_id, lr.aRenting[i].vehiculo_id,
				lr.aRenting[i].duracion_meses, lr.aRenting[i].precio_mensual);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addTransladosToDB(sqlite3 *db, ListaTraslados lt) {
	sprintf(sql, "DELETE FROM translados");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia
	for (i = 0; i < lt.numTraslados; i++) {
		sprintf(sql, "INSERT INTO renting VALUES(%i,%i,%i,%i,'%s', %i)",
				lt.aTraslado[i].id, lt.aTraslado[i].vehiculo_id,
				lt.aTraslado[i].concesionario_origen_id,
				lt.aTraslado[i].concesionario_destino_id,
				lt.aTraslado[i].fecha_traslado, lt.aTraslado[i].responsable_id);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addVehToDB(sqlite3 *db, ListaVeh lv) {
	sprintf(sql, "DELETE FROM vehiculo");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia
	for (i = 0; i < lv.numVeh; i++) {
		sprintf(sql,
				"INSERT INTO renting VALUES(%i,'%s','%s','%s',%i,'%s','%s',%f,%f,'%s','%s',%i,%f,'%s')",
				lv.aVeh[i].ID, lv.aVeh[i].matricula, lv.aVeh[i].marca,
				lv.aVeh[i].modelo, lv.aVeh[i].year, lv.aVeh[i].tipo,
				lv.aVeh[i].color, lv.aVeh[i].precio_compra,
				lv.aVeh[i].precio_venta, lv.aVeh[i].estado,
				lv.aVeh[i].fecha_adquisicion, lv.aVeh[i].concesionario_ID,
				lv.aVeh[i].kilometraje, lv.aVeh[i].tipo_combustible);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}
void addVentToDB(sqlite3 *db, ListaVent lvent) {
	sprintf(sql, "DELETE FROM venta");
	sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
	sqlite3_step(stmt); //Ejecutar la sentencia
	sqlite3_finalize(stmt); //Cerrar la sentencia
	for (i = 0; i < lvent.numVentas; i++) {
		sprintf(sql, "INSERT INTO renting VALUES(%i,%i,%f,'%s')",
				lvent.aVent[i].operacion_id, lvent.aVent[i].vehiculo_id,
				lvent.aVent[i].precio_final, lvent.aVent[i].metodo_pago);
		printf("%s\n", sql);
		sqlite3_prepare_v2(db, sql, -1, &stmt, NULL); //Preparar la sentencia
		sqlite3_step(stmt); //Ejecutar la sentencia
		sqlite3_finalize(stmt); //Cerrar la sentencia
	}
}

void loadAlquileresFromDB(sqlite3 *db, ListaAlquileres *la) {
	int rc;

	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
		if (la->aAlquiler == NULL) {
			la->aAlquiler = malloc(1 * sizeof(Alquiler));
		} else {

			Alquiler *temp = realloc(la->aAlquiler,
					(la->numAlquileres+1) * sizeof(Alquiler));
			la->aAlquiler = temp;
		}

		Alquiler *a = &la->aAlquiler[la->numAlquileres];

		// Extraer datos con manejo de posibles NULLs
		a->operacion_id = sqlite3_column_int(stmt, 0);
		a->vehiculo_id = sqlite3_column_int(stmt, 1);

		// Manejo seguro de strings
		const char *fecha_inicio = (const char*) sqlite3_column_text(stmt, 2);
		if (fecha_inicio) {
			strncpy(a->fecha_inicio, fecha_inicio, TAM_FECHA - 1);
			a->fecha_inicio[TAM_FECHA - 1] = '\0';
		} else {
			strcpy(a->fecha_inicio, "0000-00-00");
		}

		const char *fecha_fin = (const char*) sqlite3_column_text(stmt, 3);
		if (fecha_fin) {
			strncpy(a->fecha_fin, fecha_fin, TAM_FECHA - 1);
			a->fecha_fin[TAM_FECHA - 1] = '\0';
		} else {
			strcpy(a->fecha_fin, "0000-00-00");
		}

		a->precio_diario = sqlite3_column_double(stmt, 4);

		la->numAlquileres++;
	}

	if (rc != SQLITE_DONE) {
		fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
	}

	sqlite3_finalize(stmt);
}
void loadAuditoriaFromDB(sqlite3 *db, ListaAuditorias *lau) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM auditoria");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    lau->numAuditorias = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (lau->aAuditoria == NULL) {
            lau->aAuditoria = malloc(1 * sizeof(Auditoria));
        } else {
            Auditoria *temp = realloc(lau->aAuditoria,
                    (lau->numAuditorias + 1) * sizeof(Auditoria));
            lau->aAuditoria = temp;
        }

        Auditoria *a = &lau->aAuditoria[lau->numAuditorias];

        // Extraer datos con manejo de posibles NULLs
        a->id = sqlite3_column_int(stmt, 0);
        a->operacion_id = sqlite3_column_int(stmt, 1);

        // Manejo seguro de strings
        const char *usuario = (const char*) sqlite3_column_text(stmt, 2);
        if (usuario) {
            strncpy(a->usuario, usuario, TAM_USUARIO - 1);
            a->usuario[TAM_USUARIO - 1] = '\0';
        } else {
            strcpy(a->usuario, "");
        }

        const char *fecha_modificacion = (const char*) sqlite3_column_text(stmt, 3);
        if (fecha_modificacion) {
            strncpy(a->fecha_modificacion, fecha_modificacion, TAM_FECHA - 1);
            a->fecha_modificacion[TAM_FECHA - 1] = '\0';
        } else {
            strcpy(a->fecha_modificacion, "0000-00-00");
        }

        const char *cambios = (const char*) sqlite3_column_text(stmt, 4);
        if (cambios) {
            strncpy(a->cambios, cambios, TAM_CAMBIOS - 1);
            a->cambios[TAM_CAMBIOS - 1] = '\0';
        } else {
            strcpy(a->cambios, "");
        }

        lau->numAuditorias++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void loadClientesFromDB(sqlite3 *db, ListaClientes *lc) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM cliente");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    lc->numClient = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (lc->aClient == NULL) {
            lc->aClient = malloc(1 * sizeof(Client));
        } else {
            Client *temp = realloc(lc->aClient,
                    (lc->numClient + 1) * sizeof(Client));
            lc->aClient = temp;
        }

        Client *c = &lc->aClient[lc->numClient];

        // Extraer datos con manejo de posibles NULLs
        c->ID = sqlite3_column_int(stmt, 0);

        // Manejo seguro de strings
        const char *dni = (const char*) sqlite3_column_text(stmt, 1);
        if (dni) {
            strncpy(c->dni, dni, TAM_DNI - 1);
            c->dni[TAM_DNI - 1] = '\0';
        } else {
            strcpy(c->dni, "");
        }

        const char *nombre = (const char*) sqlite3_column_text(stmt, 2);
        if (nombre) {
            strncpy(c->nombre, nombre, TAM_NOMBRE - 1);
            c->nombre[TAM_NOMBRE - 1] = '\0';
        } else {
            strcpy(c->nombre, "");
        }

        const char *apellidos = (const char*) sqlite3_column_text(stmt, 3);
        if (apellidos) {
            strncpy(c->apellidos, apellidos, TAM_APELLIDOS - 1);
            c->apellidos[TAM_APELLIDOS - 1] = '\0';
        } else {
            strcpy(c->apellidos, "");
        }

        const char *direccion = (const char*) sqlite3_column_text(stmt, 4);
        if (direccion) {
            strncpy(c->direccion, direccion, TAM_DIRECCION - 1);
            c->direccion[TAM_DIRECCION - 1] = '\0';
        } else {
            strcpy(c->direccion, "");
        }

        const char *tlf = (const char*) sqlite3_column_text(stmt, 5);
        if (tlf) {
            strncpy(c->tlf, tlf, TAM_TELEFONO - 1);
            c->tlf[TAM_TELEFONO - 1] = '\0';
        } else {
            strcpy(c->tlf, "");
        }

        const char *email = (const char*) sqlite3_column_text(stmt, 6);
        if (email) {
            strncpy(c->email, email, TAM_EMAIL - 1);
            c->email[TAM_EMAIL - 1] = '\0';
        } else {
            strcpy(c->email, "");
        }

        const char *fecha_registro = (const char*) sqlite3_column_text(stmt, 7);
        if (fecha_registro) {
            strncpy(c->fecha_registro, fecha_registro, TAM_FECHA - 1);
            c->fecha_registro[TAM_FECHA - 1] = '\0';
        } else {
            strcpy(c->fecha_registro, "0000-00-00");
        }

        lc->numClient++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void loadConceFromDB(sqlite3 *db, ListaConce *lcon) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM concesionario");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    lcon->numConces = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (lcon->aConce == NULL) {
            lcon->aConce = malloc(1 * sizeof(Conce));
        } else {
            Conce *temp = realloc(lcon->aConce,
                    (lcon->numConces + 1) * sizeof(Conce));
            lcon->aConce = temp;
        }

        Conce *c = &lcon->aConce[lcon->numConces];

        // Extraer datos con manejo de posibles NULLs
        c->ID = sqlite3_column_int(stmt, 0);

        // Manejo seguro de strings
        const char *nombre = (const char*) sqlite3_column_text(stmt, 1);
        if (nombre) {
            strncpy(c->nombre, nombre, TAM_NOMBRE - 1);
            c->nombre[TAM_NOMBRE - 1] = '\0';
        } else {
            strcpy(c->nombre, "");
        }

        const char *direccion = (const char*) sqlite3_column_text(stmt, 2);
        if (direccion) {
            strncpy(c->direccion, direccion, TAM_DIRECCION - 1);
            c->direccion[TAM_DIRECCION - 1] = '\0';
        } else {
            strcpy(c->direccion, "");
        }

        const char *ciudad = (const char*) sqlite3_column_text(stmt, 3);
        if (ciudad) {
            strncpy(c->ciudad, ciudad, TAM_CID_TLF - 1);
            c->ciudad[TAM_CID_TLF - 1] = '\0';
        } else {
            strcpy(c->ciudad, "");
        }

        const char *tlf = (const char*) sqlite3_column_text(stmt, 4);
        if (tlf) {
            strncpy(c->tlf, tlf, TAM_CID_TLF - 1);
            c->tlf[TAM_CID_TLF - 1] = '\0';
        } else {
            strcpy(c->tlf, "");
        }

        const char *email = (const char*) sqlite3_column_text(stmt, 5);
        if (email) {
            strncpy(c->email, email, TAM_EMAIL - 1);
            c->email[TAM_EMAIL - 1] = '\0';
        } else {
            strcpy(c->email, "");
        }

        lcon->numConces++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void loadEmpFromDB(sqlite3 *db, ListaEmp *le) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM empleado");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    le->numEmp = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (le->aEmp == NULL) {
            le->aEmp = malloc(1 * sizeof(Emp));
        } else {
            Emp *temp = realloc(le->aEmp,
                    (le->numEmp + 1) * sizeof(Emp));
            le->aEmp = temp;
        }

        Emp *e = &le->aEmp[le->numEmp];

        // Extraer datos con manejo de posibles NULLs
        e->ID = sqlite3_column_int(stmt, 0);

        // Manejo seguro de strings
        const char *dni = (const char*) sqlite3_column_text(stmt, 1);
        if (dni) {
            strncpy(e->DNI, dni, TAM_DNI - 1);
            e->DNI[TAM_DNI - 1] = '\0';
        } else {
            strcpy(e->DNI, "");
        }

        const char *nombre = (const char*) sqlite3_column_text(stmt, 2);
        if (nombre) {
            strncpy(e->nombre, nombre, TAM_NOMBRE - 1);
            e->nombre[TAM_NOMBRE - 1] = '\0';
        } else {
            strcpy(e->nombre, "");
        }

        const char *cargo = (const char*) sqlite3_column_text(stmt, 3);
        if (cargo) {
            strncpy(e->cargo, cargo, TAM_CARGO - 1);
            e->cargo[TAM_CARGO - 1] = '\0';
        } else {
            strcpy(e->cargo, "");
        }

        e->conce_id = sqlite3_column_int(stmt, 4);

        le->numEmp++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void loadMantenimientosFromDB(sqlite3 *db, ListaMantenimientos *lm) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM mantenimiento");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    lm->numMantenimientos = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (lm->aMantenimiento == NULL) {
            lm->aMantenimiento = malloc(1 * sizeof(Mantenimiento));
        } else {
            Mantenimiento *temp = realloc(lm->aMantenimiento,
                    (lm->numMantenimientos + 1) * sizeof(Mantenimiento));
            lm->aMantenimiento = temp;
        }

        Mantenimiento *m = &lm->aMantenimiento[lm->numMantenimientos];

        // Extraer datos con manejo de posibles NULLs
        m->id = sqlite3_column_int(stmt, 0);
        m->vehiculo_id = sqlite3_column_int(stmt, 1);

        // Manejo seguro de strings
        const char *fecha = (const char*) sqlite3_column_text(stmt, 2);
        if (fecha) {
            strncpy(m->fecha, fecha, TAM_FECHA - 1);
            m->fecha[TAM_FECHA - 1] = '\0';
        } else {
            strcpy(m->fecha, "0000-00-00");
        }

        const char *tipo = (const char*) sqlite3_column_text(stmt, 3);
        if (tipo) {
            strncpy(m->tipo, tipo, TAM_TIPO_MANTENIMIENTO - 1);
            m->tipo[TAM_TIPO_MANTENIMIENTO - 1] = '\0';
        } else {
            strcpy(m->tipo, "");
        }

        m->coste = sqlite3_column_double(stmt, 4);

        const char *descripcion = (const char*) sqlite3_column_text(stmt, 5);
        if (descripcion) {
            strncpy(m->descripcion, descripcion, TAM_DESCRIPCION - 1);
            m->descripcion[TAM_DESCRIPCION - 1] = '\0';
        } else {
            strcpy(m->descripcion, "");
        }

        lm->numMantenimientos++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void loadOperacionesFromDB(sqlite3 *db, ListaOperaciones *lop) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM operaciones");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    lop->numOperaciones = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (lop->aOperaciones == NULL) {
            lop->aOperaciones = malloc(1 * sizeof(Operacion));
        } else {
            Operacion *temp = realloc(lop->aOperaciones,
                    (lop->numOperaciones + 1) * sizeof(Operacion));
            lop->aOperaciones = temp;
        }

        Operacion *o = &lop->aOperaciones[lop->numOperaciones];

        // Extraer datos con manejo de posibles NULLs
        o->ID = sqlite3_column_int(stmt, 0);

        // Manejo seguro de strings
        const char *tipo = (const char*) sqlite3_column_text(stmt, 1);
        if (tipo) {
            strncpy(o->tipo, tipo, TAM_TIPO_OPERACIONES - 1);
            o->tipo[TAM_TIPO_OPERACIONES - 1] = '\0';
        } else {
            strcpy(o->tipo, "");
        }

        o->vehiculo_ID = sqlite3_column_int(stmt, 2);
        o->cliente_ID = sqlite3_column_int(stmt, 3);
        o->empleado_ID = sqlite3_column_int(stmt, 4);

        const char *fecha_operacion = (const char*) sqlite3_column_text(stmt, 5);
        if (fecha_operacion) {
            strncpy(o->fecha_operacion, fecha_operacion, TAM_FECHA - 1);
            o->fecha_operacion[TAM_FECHA - 1] = '\0';
        } else {
            strcpy(o->fecha_operacion, "0000-00-00");
        }

        o->concesionario_ID = sqlite3_column_int(stmt, 6);

        lop->numOperaciones++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void loadRentingFromDB(sqlite3 *db, ListaRenting *lr) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM renting");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    lr->numRenting = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (lr->aRenting == NULL) {
            lr->aRenting = malloc(1 * sizeof(Renting));
        } else {
            Renting *temp = realloc(lr->aRenting,
                    (lr->numRenting + 1) * sizeof(Renting));
            lr->aRenting = temp;
        }

        Renting *r = &lr->aRenting[lr->numRenting];

        // Extraer datos con manejo de posibles NULLs
        r->operacion_id = sqlite3_column_int(stmt, 0);
        r->vehiculo_id = sqlite3_column_int(stmt, 1);
        r->duracion_meses = sqlite3_column_int(stmt, 2);
        r->precio_mensual = sqlite3_column_double(stmt, 3);

        lr->numRenting++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void loadTrasladosFromDB(sqlite3 *db, ListaTraslados *lt) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM translados");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    lt->numTraslados = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (lt->aTraslado == NULL) {
            lt->aTraslado = malloc(1 * sizeof(Traslado));
        } else {
            Traslado *temp = realloc(lt->aTraslado,
                    (lt->numTraslados + 1) * sizeof(Traslado));
            lt->aTraslado = temp;
        }

        Traslado *t = &lt->aTraslado[lt->numTraslados];

        // Extraer datos con manejo de posibles NULLs
        t->id = sqlite3_column_int(stmt, 0);
        t->vehiculo_id = sqlite3_column_int(stmt, 1);
        t->concesionario_origen_id = sqlite3_column_int(stmt, 2);
        t->concesionario_destino_id = sqlite3_column_int(stmt, 3);

        const char *fecha_traslado = (const char*) sqlite3_column_text(stmt, 4);
        if (fecha_traslado) {
            strncpy(t->fecha_traslado, fecha_traslado, TAM_FECHA - 1);
            t->fecha_traslado[TAM_FECHA - 1] = '\0';
        } else {
            strcpy(t->fecha_traslado, "0000-00-00");
        }

        t->responsable_id = sqlite3_column_int(stmt, 5);

        lt->numTraslados++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void loadVehFromDB(sqlite3 *db, ListaVeh *lv) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM vehiculo");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    lv->numVeh = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (lv->aVeh == NULL) {
            lv->aVeh = malloc(1 * sizeof(Veh));
        } else {
            Veh *temp = realloc(lv->aVeh,
                    (lv->numVeh + 1) * sizeof(Veh));
            lv->aVeh = temp;
        }

        Veh *v = &lv->aVeh[lv->numVeh];

        // Extraer datos con manejo de posibles NULLs
        v->ID = sqlite3_column_int(stmt, 0);

        // Manejo seguro de strings
        const char *matricula = (const char*) sqlite3_column_text(stmt, 1);
        if (matricula) {
            strncpy(v->matricula, matricula, TAM_MATRICULA - 1);
            v->matricula[TAM_MATRICULA - 1] = '\0';
        } else {
            strcpy(v->matricula, "");
        }

        const char *marca = (const char*) sqlite3_column_text(stmt, 2);
        if (marca) {
            strncpy(v->marca, marca, TAM_MARCA - 1);
            v->marca[TAM_MARCA - 1] = '\0';
        } else {
            strcpy(v->marca, "");
        }

        const char *modelo = (const char*) sqlite3_column_text(stmt, 3);
        if (modelo) {
            strncpy(v->modelo, modelo, TAM_MODELO - 1);
            v->modelo[TAM_MODELO - 1] = '\0';
        } else {
            strcpy(v->modelo, "");
        }

        v->year = sqlite3_column_int(stmt, 4);

        const char *tipo = (const char*) sqlite3_column_text(stmt, 5);
        if (tipo) {
            strncpy(v->tipo, tipo, TAM_TIPO_VEH - 1);
            v->tipo[TAM_TIPO_VEH - 1] = '\0';
        } else {
            strcpy(v->tipo, "");
        }

        const char *color = (const char*) sqlite3_column_text(stmt, 6);
        if (color) {
            strncpy(v->color, color, TAM_COLOR - 1);
            v->color[TAM_COLOR - 1] = '\0';
        } else {
            strcpy(v->color, "");
        }

        v->precio_compra = sqlite3_column_double(stmt, 7);
        v->precio_venta = sqlite3_column_double(stmt, 8);

        const char *estado = (const char*) sqlite3_column_text(stmt, 9);
        if (estado) {
            strncpy(v->estado, estado, TAM_ESTADO - 1);
            v->estado[TAM_ESTADO - 1] = '\0';
        } else {
            strcpy(v->estado, "");
        }

        const char *fecha_adquisicion = (const char*) sqlite3_column_text(stmt, 10);
        if (fecha_adquisicion) {
            strncpy(v->fecha_adquisicion, fecha_adquisicion, TAM_FECHA - 1);
            v->fecha_adquisicion[TAM_FECHA - 1] = '\0';
        } else {
            strcpy(v->fecha_adquisicion, "0000-00-00");
        }

        v->concesionario_ID = sqlite3_column_int(stmt, 11);
        v->kilometraje = sqlite3_column_double(stmt, 12);

        const char *tipo_combustible = (const char*) sqlite3_column_text(stmt, 13);
        if (tipo_combustible) {
            strncpy(v->tipo_combustible, tipo_combustible, TAM_COMBUSTIBLE - 1);
            v->tipo_combustible[TAM_COMBUSTIBLE - 1] = '\0';
        } else {
            strcpy(v->tipo_combustible, "");
        }

        lv->numVeh++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}

void loadVentasFromDB(sqlite3 *db, ListaVent *lvent) {
    int rc;
    sqlite3_stmt *stmt;
    char sql[1000];

    sprintf(sql, "SELECT * FROM venta");
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    lvent->numVentas = 0;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        if (lvent->aVent == NULL) {
            lvent->aVent = malloc(1 * sizeof(Vent));
        } else {
            Vent *temp = realloc(lvent->aVent,
                    (lvent->numVentas + 1) * sizeof(Vent));
            lvent->aVent = temp;
        }

        Vent *v = &lvent->aVent[lvent->numVentas];

        // Extraer datos con manejo de posibles NULLs
        v->operacion_id = sqlite3_column_int(stmt, 0);
        v->vehiculo_id = sqlite3_column_int(stmt, 1);
        v->precio_final = sqlite3_column_double(stmt, 2);

        const char *metodo_pago = (const char*) sqlite3_column_text(stmt, 3);
        if (metodo_pago) {
            strncpy(v->metodo_pago, metodo_pago, TAM_METODO_PAGO - 1);
            v->metodo_pago[TAM_METODO_PAGO - 1] = '\0';
        } else {
            strcpy(v->metodo_pago, "");
        }

        lvent->numVentas++;
    }

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Error en lectura: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}
