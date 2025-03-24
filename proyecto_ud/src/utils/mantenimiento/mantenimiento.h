#ifndef MANTENIMIENTO_MANTENIMIENTO_H_
#define MANTENIMIENTO_MANTENIMIENTO_H_

#define TAM_FECHA 11
#define TAM_TIPO_MANTENIMIENTO 30
#define TAM_DESCRIPCION 200

typedef struct {
    int id;
    int vehiculo_id;
    char fecha[TAM_FECHA];
    char tipo[TAM_TIPO_MANTENIMIENTO];
    double coste;
    char descripcion[TAM_DESCRIPCION];
} Mantenimiento;

typedef struct {
    Mantenimiento* aMantenimiento;
    int numMantenimientos;
} ListaMantenimientos;

void iniLM(ListaMantenimientos *lm);
void addMantenimiento(ListaMantenimientos *lm, Mantenimiento m);
void printM(Mantenimiento m);
void printLM(ListaMantenimientos lm);
Mantenimiento registrarMantenimiento(ListaMantenimientos lm);
#endif /* MANTENIMIENTO_MANTENIMIENTO_H_ */
