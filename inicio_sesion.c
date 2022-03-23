#include <stdio.h>
#include <stdlib.h>

#include "datos.h"
#include "inicio_sesion.h"
#include "carga.h"
#include "perfil.h"

void inicio_sesion () {
	
	int N, i_usuario, tipo_perfil;
	
	if (*v_usuarios==NULL) {  //Si no existe ningun usuario llama a primer_inicio
		
		primer_inicio ();
		
		//Abre directamente menú de admin (1) tras primer inicio
		perfil (1,0);
		
	} else {
		
		//Necesito funcion que devuelva el numero de lineas (N) de usuarios.txt para recorrer el registro
		inicio_sesion (nUsuarios, &i_usuario);
		
		tipo_perfil=profe_o_admin(i_usuario);
		
		//Si num_perfil=1 abre menú admin, sino menú profe
		perfil (tipo_perfil,i_usuario);
	}
	
}


static void primer_inicio () {
	
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


static void inicio_sesion (int N, int *num_us) { //N es el tamaño de *v_usuarios y num_us va a devolver la "i" del usuario
	
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
		
		if (v_usuarios[encontrado].Contrasena!=) {
			printf("ERROR: La contrasena no se corresponde al usuario\n");
			printf("¿Desea salir? (Pulse 1 para seguir o cualquier otro para salir)");
			scanf("%d", &seguir);
			
			if (seguir!=1) {
				exit(1);
			}
		}
		
	} while (v_usuarios[encontrado].Contrasena!=contrasena);
	
	*num_us=encontrado;
}


static int profe_o_admin (int i) {
	
	if (v_usuarios[i].Perfil_usuario=='administrador') {
		return(1);
	} else {
		return(0);
	}
}

