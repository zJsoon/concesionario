#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#define TAM_TIPO 20
#define TAM_FECHA 11

typedef struct {
    int ID;
    char tipo[TAM_TIPO];
    int vehiculo_ID;
    int cliente_ID;
    int empleado_ID;
    char fecha_operacion[TAM_FECHA];
    int concesionario_ID;
} Operacion;

#define MAX_OPERACIONES 100

typedef struct {
    Operacion *aOperaciones;
    int numOperaciones;
} ListaOperaciones;

void iniLOP(ListaOperaciones *lop);

#endif /* OPERACIONES_H_ */
