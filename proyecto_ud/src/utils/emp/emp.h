#ifndef EMP_H_
#define EMP_H_

#define TAM_DNI 10
#define TAM_NOMBRE 50
#define TAM_CARGO 30

typedef struct{
	int ID;
	char DNI[TAM_DNI];
	char nombre[TAM_NOMBRE];
	char cargo[TAM_CARGO];
	int conce_id;
}Emp;

typedef struct{
	Emp *aEmp;
	int numEmp;
}ListaEmp;


#endif /* EMP_H_ */
