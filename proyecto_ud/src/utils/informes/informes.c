#include <stdio.h>
#include "informes.h"

void informeVenta(ListaVeh lv, ListaVent lvent, char *mat){
	int id,i;
	printf("INFORMES VENTA\n");
	printf("--------------\n");
	id = obtenerVehiculoID(lv,mat);
	for(i=0;i<lvent.numVentas;i++){
		if(lvent.aVent[i].vehiculo_id == id){
			printVent(lvent.aVent[i]);
		}
	}
}
void informeAlquiler(ListaVeh lv, ListaAlquileres la, char *mat){
	int id,i;
	printf("INFORMES ALQUILER\n");
	printf("------------------\n");
	id = obtenerVehiculoID(lv,mat);
	for(i=0;i<la.numAlquileres;i++){
			if(la.aAlquiler[i].vehiculo_id == id){
				printA(la.aAlquiler[i]);
			}
		}
}
void informeRenting(ListaVeh lv, ListaRenting lr, char *mat){
	int id,i;
	printf("INFORMES RENTING\n");
	printf("----------------\n");
	id = obtenerVehiculoID(lv,mat);
	for(i=0;i<lr.numRenting;i++){
		if(lr.aRenting[i].vehiculo_id == id){
			printR(lr.aRenting[i]);
		}
	}
}
void informeMovimientoCoche(ListaVeh lv, ListaTraslados lt, char *mat){
	int id,i;
	printf("INFORMES MOVIMIENTO COCHE\n");
	printf("-------------------------\n");
	id = obtenerVehiculoID(lv,mat);
	for (i=0;i<lt.numTraslados;i++){
		if(lt.aTraslado[i].vehiculo_id == id){
			printT(lt.aTraslado[i]);
		}
	}
}
void visualizarInformes(ListaVeh lv, ListaVent lvent, ListaAlquileres la, ListaRenting lr, ListaTraslados lt, char *mat){
	printf("TODOS LOS INFORMES\n------------------\n");
	informeVenta( lv,  lvent, mat);
	informeAlquiler( lv,  la, mat);
	informeRenting( lv,  lr, mat);
	informeMovimientoCoche( lv,  lt, mat);
}
