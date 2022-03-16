#ifndef _DATOS_
#define _DATOS_

//Definicion de los tipos de registros para cada fichero

typedef struct {
	char Id_usuario[4];      //3 digitos
	char Nomb_usuario[21];
	char Perfil_usuario[15];
	char Usuario[6];
	char Contrasena[9];
}usuarios;

typedef struct {
	char Id_alum[7];      //6 digitos
	char Nombre_alum[21];
	char Direc_alum[31];
	char Local_alum[31];
	char Curso[31];
	char Grupo[11];
}alumnos;

typedef struct {
	char Id_materias[5];   //4 digitos
	char Nombre_materia[51];
	char Abrev_materia[4];
}materias;

typedef struct {
	char Id_materias[5];  //4 digitos
	char Id_alum[7];      //6 digitos
}matriculas;

typedef struct {
	int dia;
	int mes;
	int a�o;
}fecha;

typedef struct {
	fecha Fecha_calif;   //Formato fecha
	char Descrip_calif[31];
	char Id_materia[5];     //4 digitos, debe coincidir con materias.txt
	char Id_alum[7];        //6 digitos, debe coincidir con alumnos.txt
	int Valor_calif;    //Entre 0 y 10
}calificaciones;

typedef struct {
	char Id_profesor[4];   //3 digitos, debe coincidir con usuarios.txt
	int Dia_clase;     //De 1 a 5
	int Hora_clase;    //De 1 a 6
	char Id_materia[5];    //4 digitos, debe coincidir con materias.txt
	char Grupo[11];    //Debe coincidir con alumnos.txt
}horarios;


//Precondici�n: Los registros deben estar inicializados
//Postcondici�n: Permite modificar los datos de los registros
void modifica_datos ();

#endif














