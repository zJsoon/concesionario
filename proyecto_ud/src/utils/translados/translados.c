#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "translados.h"


void iniLT(ListaTraslados *lt) {
    lt->aTraslado = NULL;
    lt->numTraslados = 0;
    writeLog("TRANSLADOS: iniLT Ejecutado.",FICHERO_TRANSLADOS_LOG);
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
    writeLog("TRANSLADOS: addTraslado Ejecutado.",FICHERO_TRANSLADOS_LOG);
}

void printT(Traslado t) {
    printf("%5d%10d%15d%15d%15s%10d\n",
           t.id,
           t.vehiculo_id,
           t.concesionario_origen_id,
           t.concesionario_destino_id,
           t.fecha_traslado,
           t.responsable_id);fflush(stdout);
    writeLog("TRANSLADOS: printT Ejecutado.",FICHERO_TRANSLADOS_LOG);
}

void printLT(ListaTraslados lt) {
    int i;
    printf("%5s%10s%15s%15s%15s%10s\n",
           "ID",
           "VEH_ID",
           "CONC_ORIGEN",
           "CONC_DESTINO",
           "FECHA_TRASLADO",
           "RESP_ID");fflush(stdout);
    for (i = 0; i < lt.numTraslados; i++) {
        printT(lt.aTraslado[i]);
    }
    writeLog("TRANSLADOS: printLT Ejecutado.",FICHERO_TRANSLADOS_LOG);
}

Traslado registrarTranslado(char *matricula, ListaVeh lv, ListaTraslados *lt) {
    int id = obtenerVehiculoID(lv, matricula);
    if (id == -1) {
        printf("Vehículo con matrícula %s no encontrado.\n", matricula);fflush(stdout);
        Traslado vacio = {.id = -1};
        return vacio;
    }

    Traslado t;
    t.id = lt->numTraslados;
    t.vehiculo_id = id;

    printf("Introduce el ID del concesionario de origen: ");fflush(stdout);fflush(stdin);
    scanf("%d", &t.concesionario_origen_id);
    printf("Introduce el ID del concesionario de destino: ");fflush(stdout);fflush(stdin);
    scanf("%d", &t.concesionario_destino_id);
    printf("Introduce la fecha del traslado (YYYY-MM-DD): ");fflush(stdout);fflush(stdin);
    fgets(t.fecha_traslado, TAM_FECHA, stdin);
    t.fecha_traslado[strcspn(t.fecha_traslado, "\n")] = 0;
    printf("Introduce el ID del responsable: ");fflush(stdout);fflush(stdin);
    scanf("%d", &t.responsable_id);
    lv.aVeh[id].concesionario_ID = t.concesionario_destino_id;
    addTraslado(lt, t);
    printf("Traslado registrado correctamente.\n");fflush(stdout);
    return t;
    writeLog("TRANSLADOS: registrarTranslado Ejecutado.",FICHERO_TRANSLADOS_LOG);

}
