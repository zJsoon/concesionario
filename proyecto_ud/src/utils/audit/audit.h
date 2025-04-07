#ifndef AUDIT_AUDIT_H_
#define AUDIT_AUDIT_H_

#define TAM_USUARIO 50
#define TAM_FECHA 11
#define TAM_CAMBIOS 500
#include "../../config/logger/logger.h"

typedef struct {
    int id;
    int operacion_id;
    char usuario[TAM_USUARIO];
    char fecha_modificacion[TAM_FECHA];
    char cambios[TAM_CAMBIOS];
} Auditoria;

typedef struct {
    Auditoria* aAuditoria;
    int numAuditorias;
} ListaAuditorias;

void iniLAU(ListaAuditorias *lau);
void addAudit(ListaAuditorias *lau, Auditoria a);
void printAU(Auditoria a);
void printLAU(ListaAuditorias lau);
Auditoria realizarAuditoria(ListaAuditorias lau);

#endif /* AUDIT_AUDIT_H_ */
