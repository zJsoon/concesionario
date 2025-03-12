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

	printf("Listas limpiadas.\n");
	fflush(stdout);
}
