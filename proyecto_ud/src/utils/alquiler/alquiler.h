#ifndef ALQUILER_ALQUILER_H_
#define ALQUILER_ALQUILER_H_

#define TAM_FECHA 11
#include "../veh/veh.h"



typedef struct {
    int operacion_id;
    int vehiculo_id;
    char fecha_inicio[TAM_FECHA];
    char fecha_fin[TAM_FECHA];
    double precio_diario;
} Alquiler;

typedef struct {
    Alquiler* aAlquiler;
    int numAlquileres;
} ListaAlquileres;

void iniLA(ListaAlquileres *la);
void addAlquiler(ListaAlquileres *la, Alquiler a);
void printA(Alquiler a);
void printLA(ListaAlquileres la);
Alquiler realizarAlquiler(ListaAlquileres la);

Alquiler startAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la);
void estadoAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la);
Alquiler endAlquiler(char *matricula, ListaVeh *lv, ListaAlquileres *la);

#endif /* ALQUILER_ALQUILER_H_ */
