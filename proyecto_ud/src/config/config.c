#include <stdio.h>
#include <string.h>

#include "config.h"

Config leerConfiguracion(char *nomfich){
	Config c;
	FILE *pf;
	char linea[100], campo[TAM], valor[TAM];

	pf = fopen(nomfich, "r");
	if(pf != (FILE*)NULL){
		while(fgets(linea,100,pf) != NULL){
			sscanf(linea, "%s = %s", campo, valor);
			if(strcmp(campo,"nombreBD")==0){
				strcpy(c.nombreBD, valor);
			}
		}
		fclose(pf);
	}
	return c;

}
