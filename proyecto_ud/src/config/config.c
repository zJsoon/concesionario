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
			if(strncmp(campo,"nombreBD",8)==0){
				strcpy(c.nombreBD, valor);
			}else if(strncmp(campo,"admin",5)==0){
				strcpy(c.admin,valor);
			}else if(strncmp(campo,"con",3)==0){
				strcpy(c.con, valor);
			}
		}
		fclose(pf);
	}
	return c;

}
