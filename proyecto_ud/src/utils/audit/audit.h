#ifndef AUDIT_AUDIT_H_
#define AUDIT_AUDIT_H_

#define TAM_USUARIO 50
#define TAM_FECHA 11
#define TAM_CAMBIOS 500

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

#endif /* AUDIT_AUDIT_H_ */
