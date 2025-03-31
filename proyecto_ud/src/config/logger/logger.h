#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>
#include <time.h>

#define FICHERO_ALQUILER_LOG "../../../data/logs/alquiler_logs.txt"
#define FICHERO_AUDIT_LOG "../../../data/logs/audit_logs.txt"
#define FICHERO_CLIENT_LOG "../../../data/logs/client_logs.txt"
#define FICHERO_CONCE_LOG "../../../data/logs/conce_logs.txt"
#define FICHERO_DB_LOG "../../../data/logs/db_log.txt"
#define FICHERO_EMP_LOG "../../../data/logs/emp_logs.txt"
#define FICHERO_MANAGEMENU_LOG "../../../data/logs/manageMenu_logs.txt"
#define FICHERO_MANTENIMIENTO_LOG "../../../data/logs/mantenimiento_logs.txt"
#define FICHERO_MENU_LOG "../../../data/logs/menu_logs.txt"
#define FICHERO_OPERACIONES_LOG "../../../data/logs/operaciones_logs.txt"
#define FICHERO_RENTING_LOG "../../../data/logs/renting_logs.txt"
#define FICHERO_TRANSLADOS_LOG "../../../data/logs/translados_logs.txt"
#define FICHERO_VEH_LOG "../../../data/logs/veh_logs.txt"
#define FICHERO_VENT_LOG "../../../data/logs/vent_logs.txt"

void writeLog(char *mensaje, char *txt);
void printLog(char *mensaje);


#endif /* LOGGER_H_ */
