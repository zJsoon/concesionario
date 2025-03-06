/*
 * veh.h
 *
 *  Created on: 6 mar 2025
 *      Author: zJson
 */

#ifndef VEH_H_
#define VEH_H_

#define TAM_FECHA 11
#define TAM_TIPO 30
#define TAM_MATRICULA 10
#define TAM_MARCA 30
#define TAM_MODELO 30
#define TAM_COLOR 20
#define TAM_ESTADO 20
#define TAM_COMBUSTIBLE 15


typedef struct{
    int ID;
    char matricula[TAM_MATRICULA];
    char marca[TAM_MARCA];
    char modelo[TAM_MODELO];
    int year;
    char tipo[TAM_TIPO];
    char color[TAM_COLOR];
    double precio_compra;
    double precio_venta;
    char estado[TAM_ESTADO];
    char fecha_adquisicion[TAM_FECHA];
    int concesionario_ID;
    int kilometraje;
    char tipo_combustible[TAM_COMBUSTIBLE];
} Veh;

typedef struct{
	Veh *aVeh;
	int numVeh;
} ListaVeh;

#endif /* VEH_H_ */
