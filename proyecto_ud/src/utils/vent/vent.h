#ifndef VENT_H_
#define VENT_H_

#include "../veh/veh.h"
#include "../../config/logger/logger.h"


#define TAM_METODO_PAGO 20

typedef struct {
    int operacion_id;
    int vehiculo_id;
    double precio_final;
    char metodo_pago[TAM_METODO_PAGO];
} Vent;

typedef struct {
    Vent* aVent;
    int numVentas;
} ListaVent;

void iniLVent(ListaVent *lvent);
void addVent(ListaVent *lvent, Vent v);
void printVent(Vent v);
void printLVent(ListaVent lvent);
Vent registrarVenta(ListaVent *listaVentas, ListaVeh listaVehiculos, char *matricula);

#endif /* VENT_H_ */
