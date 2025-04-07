#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"

void iniLOP(ListaOperaciones *lop) {
    lop->aOperaciones = NULL;
    lop->numOperaciones = 0;
    writeLog("OPERACIONES: iniLOP Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

void addOperacion(ListaOperaciones *lop, Operacion op) {
    int i;

    if (lop->aOperaciones == NULL) {
        lop->aOperaciones = malloc(1 * sizeof(Operacion));
    } else {
        Operacion *aux = malloc(lop->numOperaciones * sizeof(Operacion));
        for (i = 0; i < lop->numOperaciones; i++) {
            aux[i] = lop->aOperaciones[i];
        }
        free(lop->aOperaciones);
        lop->aOperaciones = malloc((lop->numOperaciones + 1) * sizeof(Operacion));
        for (i = 0; i < lop->numOperaciones; i++) {
            lop->aOperaciones[i] = aux[i];
        }
        free(aux);
    }
    lop->aOperaciones[lop->numOperaciones] = op;
    lop->numOperaciones++;
    writeLog("OPERACIONES: addOperacion Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

void printOP(Operacion op) {
    printf("%5d%20s%10d%10d%10d%15s%10d\n",
           op.ID,
           op.tipo,
           op.vehiculo_ID,
           op.cliente_ID,
           op.empleado_ID,
           op.fecha_operacion,
           op.concesionario_ID);
    writeLog("OPERACIONES: printOP Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

void printLOP(ListaOperaciones lop) {
    int i;
    printf("%5s%20s%10s%10s%10s%15s%10s\n",
           "ID",
           "TIPO_OPERACION",
           "VEH_ID",
           "CLI_ID",
           "EMP_ID",
           "FECHA_OPER",
           "CONS_ID");
    for (i = 0; i < lop.numOperaciones; i++) {
        printOP(lop.aOperaciones[i]);
    }
    writeLog("OPERACIONES: printLOP Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
}

Operacion registrarOperacion(ListaOperaciones lop) {
    Operacion op;

    op.ID = lop.numOperaciones;
    printf("Introduce el tipo de operación: ");
    fgets(op.tipo, TAM_TIPO_OPERACIONES, stdin);
    op.tipo[strcspn(op.tipo, "\n")] = 0;
    printf("Introduce el ID del vehículo: ");
    scanf("%d", &op.vehiculo_ID);
    getchar(); // Limpiar el buffer
    printf("Introduce el ID del cliente: ");
    scanf("%d", &op.cliente_ID);
    getchar(); // Limpiar el buffer
    printf("Introduce el ID del empleado: ");
    scanf("%d", &op.empleado_ID);
    getchar(); // Limpiar el buffer
    printf("Introduce la fecha de la operación (YYYY-MM-DD): ");
    fgets(op.fecha_operacion, TAM_FECHA, stdin);
    op.fecha_operacion[strcspn(op.fecha_operacion, "\n")] = 0;
    printf("Introduce el ID del concesionario: ");
    scanf("%d", &op.concesionario_ID);
    getchar(); // Limpiar el buffer
    writeLog("OPERACIONES: registrarOperacion Ejecutado.",FICHERO_MANTENIMIENTO_LOG);
    return op;
}
