#ifndef RENTING_RENTING_H_
#define RENTING_RENTING_H_

typedef struct {
    int operacion_id;
    int vehiculo_id;
    int duracion_meses;
    double precio_mensual;
} Renting;

typedef struct {
    Renting* aRenting;
    int numRenting;
} ListaRenting;

#endif /* RENTING_RENTING_H_ */
