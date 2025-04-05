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

void iniLR(ListaRenting *lr);
void addRenting(ListaRenting *lr, Renting r);
void printR(Renting r);
void printLR(ListaRenting lr);
Renting registrarRenting(ListaRenting lr);
Renting startRenting(ListaRenting *lr, int vehiculo_id);
void estadoRenting(ListaRenting lr, int vehiculo_id);
Renting endRenting(ListaRenting *lr, int vehiculo_id);

#endif /* RENTING_RENTING_H_ */
