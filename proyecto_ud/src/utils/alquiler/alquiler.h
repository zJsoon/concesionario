#ifndef ALQUILER_ALQUILER_H_
#define ALQUILER_ALQUILER_H_

#define TAM_FECHA 11

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

#endif /* ALQUILER_ALQUILER_H_ */
