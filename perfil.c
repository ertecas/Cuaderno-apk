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

void menu_admin (i) {
	
	int n, op;
	
	printf("Bienvenido %s ", v_usuarios[i].Nomb_usuario);
	printf("\nHas accedido como: ADMINISTRADOR");
	
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
			
		switch (n) {
		
			case 1:
				USUARIOS:
				printf("\n\n\USUARIOS\n\n");
				
				do {
		
					printf("\t1.Agregar usuarios\n");
					printf("\t2.Eliminar usuarios\n");
					printf("\t3.Modificar usuarios\n");
					printf("\t4.Listar usuarios\n");		
					printf("\t0.Volver al menu de administrador\n");
				
					scanf("%d", &op);
					
					switch (op) {
						
						case 0:
							goto MENU; //goto salta a la linea marcada por la etiqueta
							
						case 1:	
							agregar_usuarios (&nUsuarios);
							goto USUARIOS;
						
						case 2:
							eliminar_usuarios (&nUsuarios);
							goto USUARIOS;
							
						case 3:	
							modificar_usuarios (nUsuarios);
							goto USUARIOS;
						
						case 4:
							listar_usuarios (nUsuarios);
							goto USUARIOS;
					}
					
				}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3)&&(n!=4));
				
				break;
				
			case 2:
				ALUMNOS:
				printf("\n\nALUMNOS\n\n");
					
				do {
	
					printf("\t1.Agregar alumnos\n");
					printf("\t2.Eliminar alumnos\n");
					printf("\t3.Modificar alumnos\n");
					printf("\t4.Listar alumnos\n");		
					printf("\t0.Volver al menu de administrador\n");
				
					scanf("%d", &op);
					
					switch (op) {
						
						case 0:
							goto MENU; //goto salta a la linea marcada por la etiqueta
							
						case 1:	
							agregar_alumnos (&nAlumnos);
							goto ALUMNOS;
						
						case 2:
							eliminar_alumnos (&nAlumnos);
							goto ALUMNOS;
								
						case 3:	
							modificar_alumnos (nAlumnos);
							goto ALUMNOS;
						
						case 4:
							listar_alumnos (nAlumnos);
							goto ALUMNOS;
					}
					
				}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3)&&(n!=4));
				
				break;
			
			case 3:
				MATERIAS:
				printf("\n\nMATERIAS\n\n");
				do {
	
					printf("\t1.Agregar materias\n");
					printf("\t2.Eliminar materias\n");
					printf("\t3.Modificar materias\n");
					printf("\t4.Listar materias\n");		
					printf("\t0.Volver al menu de administrador\n");
				
					scanf("%d", &op);
					
					switch (op) {
						
						case 0:
							goto MENU; //goto salta a la linea marcada por la etiqueta
							
						case 1:	
							agregar_materias (&nMaterias);
							goto MATERIAS;
						
						case 2:
							eliminar_materias (&nMaterias);
							goto MATERIAS;
								
						case 3:	
							modificar_materias (nMaterias);
							goto MATERIAS;
						
						case 4:
							listar_materias (nMaterias);
							goto MATERIAS;
					}
					
				}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3)&&(n!=4));
				
				break;
				
			case 4:
				HORARIOS:
				printf("\n\nHORARIOS\n\n");
				do {
	
					printf("\t1.Agregar hora a un profesor\n");
					printf("\t2.Eliminar hora de un profesor\n");
					printf("\t3.Modificar hora de un profesor\n");
					printf("\t4.Listar horario de un profesor\n");		
					printf("\t0.Volver al menu de administrador\n");
				
					scanf("%d", &op);
					
					switch (op) {
						
						case 0:
							goto MENU; //goto salta a la linea marcada por la etiqueta
							
						case 1:	
							agregar_horarios (&nHorarios);
							goto HORARIOS;
						
						case 2:
							eliminar_horarios (&nHorarios);
							goto HORARIOS;
								
						case 3:	
							modificar_horarios (nUsuarios,nHorarios);
							goto HORARIOS;
						
						case 4:
							listar_horarios (nUsuarios,nHorarios);
							goto HORARIOS;
					}
					
				}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3)&&(n!=4));
				
				break;
				
			case 5:
				break;		
		}
		
	}while((n!=1)&&(n!=2)&&(n!=3)&&(n!=4)&&(n!=5));
				
}

void menu_profe (i) {
	
	int n, op;
	
	printf("Bienvenido %s ", v_usuarios[i].Nomb_usuario);
	printf("\nHas accedido como: PROFESOR");
	
				
}




