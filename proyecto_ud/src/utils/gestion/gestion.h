#ifndef GESTION_GESTION_H_
#define GESTION_GESTION_H_

#include "../../config/logger/logger.h"

#include "../alquiler/alquiler.h"
#include "../renting/renting.h"
#include "../mantenimiento/mantenimiento.h"
#include "../veh/veh.h"

void visualizarVehHistorial(ListaVeh lv, ListaAlquileres la, ListaRenting lr, ListaMantenimientos lm, char *matricula);
Alquiler startAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la);
void estadoAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la);
Alquiler endAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la);

#endif /* GESTION_GESTION_H_ */
