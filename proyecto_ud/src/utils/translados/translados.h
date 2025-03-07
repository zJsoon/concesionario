#ifndef TRANSLADOS_TRANSLADOS_H_
#define TRANSLADOS_TRANSLADOS_H_

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

#endif /* TRANSLADOS_TRANSLADOS_H_ */
