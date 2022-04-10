#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carga.h"
#include "datos.h"
#include "perfil.h"
#include "admin.h"
#include "profesor.h"

void perfil (tipo,i_usuario) { //Tipo recibe 1 o 0 | i_usuario es el indice del usuario iniciado
	
	if (tipo==1) {
		
		menu_admin (i_usuario);
		
	} else {
		
		menu_profe (i_usuario);
		
	}
}

static void menu_admin (i) {
	
	int n, op;
	
	printf("\nBienvenido %s ", v_usuarios[i].Nomb_usuario);
	printf("\nHas accedido como: ADMINISTRADOR");
		
	do {
		
		printf("\n\nMENU\n\n");
	
		printf("\t1.Usuarios\n");
		printf("\t2.Alumnos\n");
		printf("\t3.Materias\n");
		printf("\t4.Horarios\n");
		printf("\t0.Salir del programa\n");
		
		scanf("%d", &n);
			
		switch (n) {
		
			case 1:

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
							break;
							
						case 1:	
							agregar_usuarios (&nUsuarios);
							break;
						
						case 2:
							eliminar_usuarios (&nUsuarios);
							break;
							
						case 3:	
							modificar_usuarios (nUsuarios);
							break;
						
						case 4:
							listar_usuarios (nUsuarios);
							break;
					}
					
				}while(op!=0);
				
				break;
				
			case 2:
				
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
							break;
							
						case 1:	
							agregar_alumnos (&nAlumnos);
							break;
						
						case 2:
							eliminar_alumnos (&nAlumnos);
							break;
								
						case 3:	
							modificar_alumnos (nAlumnos);
							break;
						
						case 4:
							listar_alumnos (nAlumnos);
							break;
					}
					
				}while(op!=0);
				
				break;
			
			case 3:
				
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
							break;
							
						case 1:	
							agregar_materias (&nMaterias);
							break;
						
						case 2:
							eliminar_materias (&nMaterias);
							break;
							
						case 3:	
							modificar_materias (nMaterias);
							break;
						
						case 4:
							listar_materias (nMaterias);
							break;
					}
					
				}while(op!=0);
				
				break;
				
			case 4:
				
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
							break;
							
						case 1:	
							agregar_horarios (&nHorarios, nUsuarios, nMaterias, nAlumnos);
							break;
						
						case 2:
							eliminar_horarios (&nHorarios, nUsuarios);
							break;
								
						case 3:	
							modificar_horarios (nUsuarios,nHorarios);
							break;
						
						case 4:
							listar_horarios (nUsuarios,nHorarios);
							break;
					}
					
				}while(op!=0);
				
				break;
				
			case 0:
				break;		
		}
		
	}while(n!=0);
				
}

static void menu_profe (i_profe) {
	
	int n, i, j, hora, dia, res;
	char grupo[11];
	
	printf("\nBienvenido %s ", v_usuarios[i_profe].Nomb_usuario);
	printf("\nHas accedido como: PROFESOR");
	
	do {
		
		list_hor_profe (i_profe, nHorarios);
	
		do {
		
			printf("\nIntroduzca el grupo con el que quiere trabajar: ");
			fflush(stdin);
			fgets(grupo, 11, stdin);
		
			printf("\nIntroduzca la hora (1-6) del grupo con el que quiere trabajar: ");
			scanf("%d", &hora);
		
			printf("\nIntroduzca el dia (1-5) del grupo con el que quiere trabajar: ");
			scanf("%d", &dia);				
		
			for (i=0;i<nHorarios;i++) {
			
				if ((strcmp(v_usuarios[i_profe].Id_usuario,v_horarios[i].Id_profesor)==0)&&(strcmp(v_horarios[i].Grupo,grupo)==0)&&(strcmp(v_horarios[i].Dia_clase,dia)==0)&&(strcmp(v_horarios[i].Dia_clase,dia)==0)){
					
					for (j=0;j<nMaterias;j++) {  //Busca indice (j) en v_materias (para poner la abreviatura mas adelante)
				
						if (strcmp(v_materias[j].Id_materias,v_horarios[i].Id_materia)==0) {
							break;
						}
					}	
					break;
				}
			}
		
			if (i==nHorarios) {
				printf("\nERROR: Algun dato no se corresponde al grupo/profesor");
				printf("\n¿Desea volver a intentarlo? (1.Seguir)\n");
				scanf("%d", &res);
			
				if (res!=1) {
					exit (1);
				}
			}
		
		
		}while(i==nHorarios);
	
		printf("\n\nMENU\n\n");
	
		do {
			
			printf("GRUPO: %s  MATERIA: %s ", v_horarios[i].Grupo, v_materias[j].Abrev_materia);
		
			printf("\t1.Lista de alumnos\n");
			printf("\t2.Cambiar de grupo\n");
			printf("\t0.Salir del programa\n");
		
			scanf("%d", &n);
		
			switch (n) {
			
				case 0:
					break;
				
				case 1:
					gestor_alumnos (i,nAlumnos);
					break;
			
				case 2:
					break;
					
			}		
		
		
		}while((n!=0)&&(n!=2));		
		
	}while(n!=0);
		
}
