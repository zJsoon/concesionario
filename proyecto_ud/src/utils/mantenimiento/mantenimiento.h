/*
 * manitenimiento.h
 *
 *  Created on: 6 mar 2025
 *      Author: zJson
 */

#ifndef MANTENIMIENTO_MANTENIMIENTO_H_
#define MANTENIMIENTO_MANTENIMIENTO_H_

#define TAM_FECHA 11
#define TAM_TIPO 30
#define TAM_DESCRIPCION 200

typedef struct {
    int id;
    int vehiculo_id;
    char fecha[TAM_FECHA];
    char tipo[TAM_TIPO];
    double coste;
    char descripcion[TAM_DESCRIPCION];
} Mantenimiento;

typedef struct {
    Mantenimiento* aMantenimiento;
    int numMantenimientos;
} ListaMantenimientos;

#endif /* MANTENIMIENTO_MANTENIMIENTO_H_ */
