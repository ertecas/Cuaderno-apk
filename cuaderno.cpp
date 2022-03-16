#include <stdio.h>
#include <stdlib.h>

#include <datos.h>

usuarios *vus;
alumnos *val;
materias *vmat;
matriculas *vmatr;
calificaciones *vcal;
horarios *vhor;

static void primer_inicio ();
static void inicio_sesion (int);

void main () {
	
	//Carga los ficheros a los registros
	
	if (*vus==NULL) {  //Si no existe ningun usuario llama a primer_inicio
		
		primer_inicio ();
		//Abre directamente menu de admin tras primer inicio
		
	} else {
		
		//Necesito funcion que devuelva el numero de lineas de usuarios.txt (N)
		inicio_sesion (N);
		
		//Funcion que comprueba si el usuario introducido es administrador o profesor
		
	}
	
	//Copia los registros a los ficheros
}

//Precondición: No hay
//Postcondicion: Crea el primer usuario del sistema (administrador) y lo guarda en el registro
static void primer_inicio () {
	
	char usuario[6];
	char contrasena [9];
	char nombre[21];
	
	printf("Introduzca un usuario (5 caracteres)");
	fflush(stdin);
	fgets(usuario, 6, stdin);
	
	vus= (usuarios*) malloc(1*sizeof(usuarios)); //Reserva memoria para el primer usuario (admin)
	
	if (vus==NULL) {
		
		printf("ERROR: No se ha podido asignar memoria");
		exit(1);
		
	} else {
		
		*vus->Usuario=usuario;
		
		printf("Introduzca una contraseña (8 caracteres)");
		fflush(stdin);
		fgets(contrasena, 9, stdin);
		
		*vus->Contrasena=contrasena;
		
		*vus->Id_usuario=001;
		
		*vus->Perfil_usuario=administrador;
		
		printf("Introduzca un nombre (maximo 20 caracteres)");
		fflush(stdin);
		fgets(nombre, 21, stdin);
		
		*vus->Nomb_usuario=nombre;
	}
	
}

//Precondición: N>0
//Postcondición: Solicita usuario y contraseña comprobando la validez de ambos
static char inicio_sesion (int N) { //N es el tamaño de *vus
	
	char usuario[6];
	char contrasena[9];
	int i, encontrado=-1, seguir;
	
	
	do { //Solicita un usuario, en caso de no encontrarse lo volverá a pedir
		printf("Introduzca usuario: ");
		fflush(stdin);
		fgets(usuario, 6, stdin);
		
		for (i=0; i<N; i++) {  //Devuelve una i, correspondiente a un usuario encontrado con el introducido
			if (*vus->Usuario==usuario) {
				encontrado=i;
			}
		}
		if (encontrado<0) {  //Este if es solo en caso de que no se encuentre un usuario válido
			printf("¿Desea salir? (Pulse 1 para seguir o cualquier otro para salir)")
			scanf("%d", &seguir);
			
			if (seguir!=1) {
				exit(1);
			}
		}
	} while (encontrado<0);

	
	do { //Pide la contraseña que se corresponde al usuario
		printf("Introduzca contrasena: ");
		fflush(stdin);
		fgets(contrasena, 9, stdin);
		
		if (vus[encontrado]->Contrasena!=) {
			printf("ERROR: La contrasena no se corresponde al usuario");
			printf("¿Desea salir? (Pulse 1 para seguir o cualquier otro para salir)");
			scanf("%d", &seguir);
			
			if (seguir!=1) {
				exit(1);
			}
		}
		
	} while (vus[encontrado]->Contrasena!=contrasena);
	
	return (usuario);
}


//Precondición:
//Postcondición: Averigua si el usuario introducico en administrador o profesor
static void profe_o_admin (char usuario) {
	
	
}








