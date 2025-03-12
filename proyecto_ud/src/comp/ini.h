#ifndef INI_H_
#define INI_H_

#include "../utils/alquiler/alquiler.h"
#include "../utils/audit/audit.h"
#include "../utils/client/client.h"
#include "../utils/concesionario/concesionario.h"
#include "../utils/emp/emp.h"
#include "../utils/mantenimiento/mantenimiento.h"
#include "../utils/operaciones/operaciones.h"
#include "../utils/renting/renting.h"
#include "../utils/translados/translados.h"
#include "../utils/veh/veh.h"
#include "../utils/vent/vent.h"

void iniListas(ListaAlquileres *la, ListaAuditorias *lau, ListaClientes *lc,
		ListaConce *lcon, ListaEmp *le, ListaMantenimientos *lm,
		ListaOperaciones *lop, ListaRenting *lr, ListaTraslados *lt,
		ListaVeh *lv, ListaVent *lvent);

void freeListas(ListaAlquileres *la, ListaAuditorias *lau, ListaClientes *lc,
		ListaConce *lcon, ListaEmp *le, ListaMantenimientos *lm,
		ListaOperaciones *lop, ListaRenting *lr, ListaTraslados *lt,
		ListaVeh *lv, ListaVent *lvent);

#endif /* INI_H_ */
