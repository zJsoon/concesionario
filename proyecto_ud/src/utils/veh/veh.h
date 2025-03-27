#ifndef VEH_H_
#define VEH_H_

#define VEH_CSV "./data/csv/vehiculos.csv"
#define TAM_FECHA 11
#define TAM_TIPO_VEH 30
#define TAM_MATRICULA 10
#define TAM_MARCA 30
#define TAM_MODELO 30
#define TAM_COLOR 20
#define TAM_ESTADO 20
#define TAM_COMBUSTIBLE 15


typedef struct{
    int ID;
    char matricula[TAM_MATRICULA];
    char marca[TAM_MARCA];
    char modelo[TAM_MODELO];
    int year;
    char tipo[TAM_TIPO_VEH];
    char color[TAM_COLOR];
    float precio_compra;
    float precio_venta;
    char estado[TAM_ESTADO];
    char fecha_adquisicion[TAM_FECHA];
    int concesionario_ID;
    float kilometraje;
    char tipo_combustible[TAM_COMBUSTIBLE];
} Veh;

typedef struct{
	Veh *aVeh;
	int numVeh;
} ListaVeh;

void iniLV(ListaVeh *lv);
void loadVehCSV(char *csv, ListaVeh *lv);
void addVeh(ListaVeh *lv, Veh v);
void printV(Veh v);
void printLV(ListaVeh lv);
Veh pedirVeh(ListaVeh lv);
void copyVehCSV(char *csv, ListaVeh lv);
void visualizarVeh(ListaVeh lv);
void visualizarVehConce(ListaVeh lv, int id);
void visualizarVehCiudad(ListaVeh lv, char *ciudad);
void visualizarVehMarca(ListaVeh lv, char *marca);
void visualizarVehTipo(ListaVeh lv, char *tipo);
void visualizarVehEstado(ListaVeh lv, char *estado);
void visualizarVehHistorial(ListaVeh lv, char *matricula);


#endif /* VEH_H_ */
