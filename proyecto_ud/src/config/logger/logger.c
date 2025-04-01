#include <string.h>

#include "logger.h"

void writeLog(char *mensaje, char *txt){
	FILE *pf;
	time_t fechaActual;
	char *sfecha;

	pf=fopen(txt,"a");
	if(pf!=(FILE*)NULL){
		fechaActual = time(NULL);
		sfecha = ctime(&fechaActual);
		fprintf(pf, "%s - %s\n",sfecha,mensaje);
		fclose(pf);
	}
}


void printLog(char *mensaje){
	time_t fechaActual;
	char *sfecha;

	fechaActual = time(NULL);
	sfecha = ctime(&fechaActual);
	printf("%s - %s\n",sfecha,mensaje);

}
