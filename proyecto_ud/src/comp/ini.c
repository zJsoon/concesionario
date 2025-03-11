#include "ini.h"

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
}
