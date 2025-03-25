#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translados.h"

void iniLT(ListaTraslados *lt) {
    lt->aTraslado = NULL;
    lt->numTraslados = 0;
}
void addTraslado(ListaTraslados *lt, Traslado t) {
    int i;

    if (lt->aTraslado == NULL) {
        lt->aTraslado = malloc(1 * sizeof(Traslado));
    } else {
        Traslado *aux = malloc(lt->numTraslados * sizeof(Traslado));
        for (i = 0; i < lt->numTraslados; i++) {
            aux[i] = lt->aTraslado[i];
        }
        free(lt->aTraslado);
        lt->aTraslado = malloc((lt->numTraslados + 1) * sizeof(Traslado));
        for (i = 0; i < lt->numTraslados; i++) {
            lt->aTraslado[i] = aux[i];
        }
        free(aux);
    }
    lt->aTraslado[lt->numTraslados] = t;
    lt->numTraslados++;
}

void printT(Traslado t) {
    printf("%5d%10d%15d%15d%15s%10d\n",
           t.id,
           t.vehiculo_id,
           t.concesionario_origen_id,
           t.concesionario_destino_id,
           t.fecha_traslado,
           t.responsable_id);
}

void printLT(ListaTraslados lt) {
    int i;
    printf("%5s%10s%15s%15s%15s%10s\n",
           "ID",
           "VEH_ID",
           "CONC_ORIGEN",
           "CONC_DESTINO",
           "FECHA_TRASLADO",
           "RESP_ID");
    for (i = 0; i < lt.numTraslados; i++) {
        printT(lt.aTraslado[i]);
    }
}

Traslado registrarTraslado(ListaTraslados lt) {
    Traslado t;

    t.id = lt.numTraslados;
    printf("Introduce el ID del vehículo: ");
    scanf("%d", &t.vehiculo_id);
    printf("Introduce el ID del concesionario de origen: ");
    scanf("%d", &t.concesionario_origen_id);
    printf("Introduce el ID del concesionario de destino: ");
    scanf("%d", &t.concesionario_destino_id);
    getchar(); // Limpiar el buffer
    printf("Introduce la fecha del traslado (YYYY-MM-DD): ");
    fgets(t.fecha_traslado, TAM_FECHA, stdin);
    t.fecha_traslado[strcspn(t.fecha_traslado, "\n")] = 0;
    printf("Introduce el ID del responsable: ");
    scanf("%d", &t.responsable_id);

    return t;
}
