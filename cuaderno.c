#include <stdio.h>
#include <stdlib.h>

#include "carga.h"
#include "guarda.h"
#include "datos.h"

//Precondición:
//Postcondicion: Crea el primer usuario del sistema (administrador) y lo guarda en el registro
void primer_inicio ();

//Precondición: N>0
//Postcondición: Solicita usuario y contraseña comprobando la validez de ambos
void inicio_sesion (int, int *);

//Precondición:
//Postcondición: Devuelve 1 si el usuario es admin o 0 si es profesor
int profe_o_admin (int);

void main () {
	
	carga ();
	
	//Inicio de sesion
	int N, i_usuario, tipo_perfil;
	
	if (*v_usuarios==NULL) {  //Si no existe ningun usuario llama a primer_inicio
		
		primer_inicio ();
		
		//Abre directamente menú de admin (1) tras primer inicio
		perfil (1,0);
		
	} else {
		
		inicio_sesion (nUsuarios, &i_usuario);
		
		tipo_perfil=profe_o_admin(i_usuario);
		
		//Si num_perfil=1 abre menú admin, sino menú profe
		perfil (tipo_perfil,i_usuario);
	}

	
	guarda ();
}

void primer_inicio () {
	
	char usuario[6];
	char contrasena [9];
	char nombre[21];
	
	printf("Introduzca un usuario (5 caracteres)");
	fflush(stdin);
	fgets(usuario, 6, stdin);
	
	v_usuarios= (usuarios*) malloc(1*sizeof(usuarios)); //Reserva memoria para el primer usuario (admin)
	
	if (v_usuarios==NULL) {
		
		printf("ERROR: No se ha podido asignar memoria");
		exit(1);
		
	} else {
		
		v_usuarios[].Usuario=usuario;
		
		printf("Introduzca una contraseña (8 caracteres)");
		fflush(stdin);
		fgets(contrasena, 9, stdin);
		
		v_usuarios[].Contrasena=contrasena;
		
		v_usuarios[].Id_usuario=001;
		
		v_usuarios[].Perfil_usuario=administrador;
		
		printf("Introduzca un nombre (maximo 20 caracteres)");
		fflush(stdin);
		fgets(nombre, 21, stdin);
		
		v_usuarios[].Nomb_usuario=nombre;
	}
	
}


void inicio_sesion (int N, int *i_us) { //N es el tamaño de *v_usuarios y i_us va a devolver la "i" del usuario
	
	char usuario[6];
	char contrasena[9];
	int i, encontrado=-1, seguir;
	
	
	do { //Solicita un usuario, en caso de no encontrarse lo volverá a pedir
		printf("Introduzca usuario: ");
		fflush(stdin);
		fgets(usuario, 6, stdin);
		
		for (i=0; i<N; i++) {  //Devuelve una i, correspondiente a un usuario encontrado con el introducido
			if (v_usuarios[i].Usuario==usuario) {
				encontrado=i;
			}
		}
		if (encontrado<0) {  //Este if es solo en caso de que no se encuentre un usuario válido
			printf("ERROR: Usuario no encontrado\n");
			printf("¿Desea salir? (Pulse 1 para seguir o cualquier otro para salir)");
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
		
		if (v_usuarios[encontrado].Contrasena!=contrasena) {
			printf("ERROR: La contrasena no se corresponde al usuario\n");
			printf("¿Desea salir? (Pulse 1 para seguir o cualquier otro para salir)");
			scanf("%d", &seguir);
			
			if (seguir!=1) {
				exit(1);
			}
		}
		
	} while (v_usuarios[encontrado].Contrasena!=contrasena);
	
	*i_us=encontrado;
}


int profe_o_admin (int i) {
	
	if (v_usuarios[i].Perfil_usuario=='administrador') {
		return(1);
	} else {
		return(0);
	}
}



