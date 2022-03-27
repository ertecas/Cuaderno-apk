#include <stdio.h>
#include <stdlib.h>

#include "carga.h"
#include "datos.h"
#include "perfil.h"

void perfil (tipo,i_usuario) { //Tipo recibe 1 o 0 | i_usuario es el indice del usuario iniciado
	
	if (tipo==1) {
		
		menu_admin (i_usuario);
		
	} else {
		
		menu_profe (i_usuario);
		
	}
}

void menu_profe (i) {
	
	int n, op;
	
	printf("Bienvenido %s ", v_usuarios[i].Nomb_usuario);
	printf("\nHas accedido como: PROFESOR");
	
	MENU:
		
	do {
		
		printf("\n\nMENU\n\n");
	
		printf("¿A que desea acceder?\n");
	
		printf("\t1.Usuarios\n");
		printf("\t2.Alumnos\n");
		printf("\t3.Materias\n");
		printf("\t4.Horarios\n");
		printf("\t5.Salir del programa\n");
		
		scanf("%d", &n);
			
