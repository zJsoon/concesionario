#ifndef TRANSLADOS_TRANSLADOS_H_
#define TRANSLADOS_TRANSLADOS_H_
#include "../veh/veh.h"
#define TAM_FECHA 11

typedef struct {
    int id;
    int vehiculo_id;
    int concesionario_origen_id;
    int concesionario_destino_id;
    char fecha_traslado[TAM_FECHA];
    int responsable_id;
} Traslado;

typedef struct {
    Traslado* aTraslado;
    int numTraslados;
} ListaTraslados;

void iniLT(ListaTraslados *lt);
void addTraslado(ListaTraslados *lt, Traslado t);
void printT(Traslado t);
void printLT(ListaTraslados lt);
Traslado registrarTranslado(char *matricula, ListaVeh lv, ListaTraslados *lt);
#endif /* TRANSLADOS_TRANSLADOS_H_ */
