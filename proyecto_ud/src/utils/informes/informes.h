#ifndef INFORMES_INFORMES_H_
#define INFORMES_INFORMES_H_
#include "../veh/veh.h"
#include "../vent/vent.h"
#include "../operaciones/operaciones.h"
#include "../alquiler/alquiler.h"
#include "../renting/renting.h"
#include "../translados/translados.h"

void informeVenta(ListaVeh lv, ListaVent lvent, char *mat);
void informeAlquiler(ListaVeh lv, ListaAlquileres la, char *mat);
void informeRenting(ListaVeh lv, ListaRenting lr, char *mat);
void informeMovimientoCoche(ListaVeh lv, ListaTraslados lt, char *mat);
void visualizarInformes(ListaVeh lv, ListaVent lvent, ListaAlquileres la, ListaRenting lr, ListaTraslados lt, char *mat);

#endif /* INFORMES_INFORMES_H_ */
