//Este m�dulo es el principal (main) que relaciona los m�dulos de carga y guardado de datos y el menu, adem�s contiene las instrucciones de inicio de sesion

#include "datos.h"
#include "carga.h"
#include "perfil.h"
#include "guarda.h"

//Cabecera: static void inicio_sesion (int nUsuarios, int *i_us)
//Precondici�n: nUsuarios es el n� de usuarios del vector v_usuarios importado de carga
//Postcondici�n: Solicita usuario y contrase�a comprobando la validez de ambos
static void inicio_sesion (int, int *);

//Cabecera: static int profe_o_admin (int i)
//Precondici�n: i es el usuario que se ha introducido
//Postcondici�n: Devuelve 1 si el usuario es admin o 0 si es profesor
static int profe_o_admin (int);

void main () {
	
	carga ();
	
	//Inicio de sesion {
	int i_usuario, tipo_perfil;
	
	inicio_sesion (nUsuarios, &i_usuario);
		
	tipo_perfil=profe_o_admin(i_usuario);
	//}
		
	//Si tipo_perfil=1 abre men� admin, sino men� profe
	perfil (tipo_perfil,i_usuario);

	guardar ();
}

static void inicio_sesion (int nUsuarios, int *i_us) { //nUsuarios es el tama�o de *v_usuarios y i_us va a devolver la "i" del usuario
	
	char usuario[6];
	char contrasena[9];
	char res[3];
	int i;
		
	do { //Solicita un usuario, en caso de no encontrarse lo volver� a pedir
		printf("\nUSUARIO: ");
		fflush(stdin);
		fgets(usuario, 6, stdin);
		
		for (i=0; i<nUsuarios; i++) {  //Devuelve una i, correspondiente a un usuario encontrado con el introducido
			if (strcmp(v_usuarios[i].Usuario,usuario)==0) {
				break;
			}
		}
		if (i==nUsuarios) {  //Este if es solo en caso de que no se encuentre un usuario v�lido
			printf("\nERROR: Usuario no encontrado\n");
			printf("\n�Desea volver a intentarlo? (Introduzca 'Si' para reintentar) \n");
			fflush(stdin);
			fgets(res, 3, stdin);
			
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				exit(1);
			}
		}
	} while (i==nUsuarios);

	do { //Pide la contrase�a que se corresponde al usuario
		printf("\nCONTRASENA: ");
		fflush(stdin);
		fgets(contrasena, 9, stdin);
		
		if (strcmp(v_usuarios[i].Contrasena,contrasena)!=0) {
			printf("\nERROR: La contrasena no se corresponde al usuario\n");
			printf("\n�Desea volver a intentarlo? (Introduzca 'Si' para reintentar) \n");
			fflush(stdin);
			fgets(res, 3, stdin);
			
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				exit(1);
			}
		}
		
	} while (strcmp(v_usuarios[i].Contrasena,contrasena)!=0);
	
	*i_us=i;
}

static int profe_o_admin (int i) {
	
	if (strcmp(v_usuarios[i].Perfil_usuario,"administrador")==0) {
		return(1);
	} else {
		return(0);
	}
}
