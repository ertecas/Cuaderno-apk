#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carga.h"
#include "guarda.h"
#include "datos.h"

//Precondición:
//Postcondicion: Crea el primer usuario del sistema (administrador) y lo guarda en el registro
static void primer_inicio ();

//Precondición:
//Postcondición: Solicita usuario y contraseña comprobando la validez de ambos
static void inicio_sesion (int, int *);

//Precondición:
//Postcondición: Devuelve 1 si el usuario es admin o 0 si es profesor
static int profe_o_admin (int);

void main () {
	
	carga ();
	
	//Inicio de sesion
	int i_usuario, tipo_perfil;
	
	if (*v_usuarios==NULL) {  //Si no existe ningun usuario llama a primer_inicio
		
		primer_inicio ();
		
		//Abre directamente menú de admin (1) tras primer inicio
		perfil (1,0);
		
	} else {
		
		inicio_sesion (nUsuarios, &i_usuario);
		
		tipo_perfil=profe_o_admin(i_usuario);
		
		//Si tipo_perfil=1 abre menú admin, sino menú profe
		perfil (tipo_perfil,i_usuario);
	}
	//
		
	guarda ();
}

static void primer_inicio () {
	
	char usuario[6];
	char contrasena [9];
	char nombre[21];
	
	printf("\nIntroduzca un usuario (5 caracteres)");
	fflush(stdin);
	fgets(usuario, 6, stdin);
	
	v_usuarios= (usuarios*) malloc(1*sizeof(usuarios)); //Reserva memoria para el primer usuario (admin)
	
	if (v_usuarios==NULL) {
		
		printf("\nERROR: No se ha podido asignar memoria");
		exit(1);
		
	} else {
		
		strcpy(v_usuarios[].Usuario,usuario);
		
		printf("\nIntroduzca una contrasena (8 caracteres): ");
		fflush(stdin);
		fgets(contrasena, 9, stdin);
		
		strcpy(v_usuarios[].Contrasena,contrasena);
		
		strcpy(v_usuarios[].Id_usuario,'001');
		
		strcpy(v_usuarios[].Perfil_usuario,'administrador');
		
		printf("\nIntroduzca un nombre (maximo 20 caracteres): ");
		fflush(stdin);
		fgets(nombre, 21, stdin);
		
		strcpy(v_usuarios[].Nomb_usuario,nombre);
	}
	
}

static void inicio_sesion (int nUsuarios, int *i_us) { //N es el tamaño de *v_usuarios y i_us va a devolver la "i" del usuario
	
	char usuario[6];
	char contrasena[9];
	int i, res;
		
	do { //Solicita un usuario, en caso de no encontrarse lo volverá a pedir
		printf("\nUSUARIO: ");
		fflush(stdin);
		fgets(usuario, 6, stdin);
		
		for (i=0; i<nUsuarios; i++) {  //Devuelve una i, correspondiente a un usuario encontrado con el introducido
			if (strcmp(v_usuarios[i].Usuario,usuario)==0) {
				break;
			}
		}
		if (i==nUsuarios) {  //Este if es solo en caso de que no se encuentre un usuario válido
			printf("\nERROR: Usuario no encontrado\n");
			printf("\n¿Desea volver a intentarlo? (1.Seguir)\n");
			scanf("%d", &res);
			
			if (res!=1) {
				exit(1);
			}
		}
	} while (i==nUsuarios);

	do { //Pide la contraseña que se corresponde al usuario
		printf("\nCONTRASENA: ");
		fflush(stdin);
		fgets(contrasena, 9, stdin);
		
		if (strcpy(v_usuarios[i].Contrasena,contrasena)!=0) {
			printf("\nERROR: La contrasena no se corresponde al usuario\n");
			printf("\n¿Desea volver a intentarlo? (1.Seguir)\n");
			scanf("%d", &sres);
			
			if (res!=1) {
				exit(1);
			}
		}
		
	} while (strcpy(v_usuarios[i].Contrasena,contrasena)!=0);
	
	*i_us=i;
}

static int profe_o_admin (int i) {
	
	if (strcmp(v_usuarios[i].Perfil_usuario,'administrador')==0) {
		return(1);
	} else {
		return(0);
	}
}
