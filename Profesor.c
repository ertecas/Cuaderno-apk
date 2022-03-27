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
		switch (n) {
		
			case 1:
				USUARIOS:
				printf("\n\n\USUARIOS\n\n");
				
				do {
		
					printf("Elija una opcion\n");
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
							agregar_usuarios ();
							goto USUARIOS;
						
						case 2:
							eliminar_usuarios ();
							goto USUARIOS;
							
						case 3:	
							modificar_usuarios ();
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
	
					printf("Elija una opcion\n");
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
							agregar_alumnos ();
							goto ALUMNOS;
						
						case 2:
							eliminar_alumnos ();
							goto ALUMNOS;
								
						case 3:	
							modificar_alumnos ();
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
	
					printf("Elija una opcion\n");
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
							agregar_materias ();
							goto MATERIAS;
						
						case 2:
							agregar_materias ();
							goto MATERIAS;
								
						case 3:	
							agregar_materias ();
							goto MATERIAS;
						
						case 4:
							agregar_materias (nMaterias);
							goto MATERIAS;
					}
					
				}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3)&&(n!=4));
				
				break;
				
			case 4:
				printf("");
				break;
				
			case 5:
				exit(1);		
		}
		
	}while((n!=1)&&(n!=2)&&(n!=3)&&(n!=4)&&(n!=5));
	
			
}


void listar_usuarios (int N) {  //N es el número total de usuarios (tamaño de vectores)
	
	int i;
	printf("\n\nLISTA USUARIOS\n\n");
	printf("ID-NOMBRE-PERFIL-USUARIO-CONTRASENA");
	
	for (i=0;i<N;i++) {
		printf("%s-%s-%s-%s-%s",v_usuarios[i].Id_usuario,v_usuarios[i].Nomb_usuario,v_usuarios[i].Perfil_usuario,v_usuarios[i].Usuario,v_usuarios[i].Contrasena);
	}
}

void modificar_usuarios (int N) {
	
	
}

void agregar_usuarios () {
	
} 

void eliminar_usuarios () {
	
}

void listar_alumnos (int N) {  //N es el número total de alumnos (tamaño de vectores)
	
	int i;
	printf("\n\nLISTA ALUMNOS\n\n");
	printf("ID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO");
	
	for (i=0;i<N;i++) {
		printf("%s-%s-%s-%s-%s-%s",v_alumnos[i].Id_alum,v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum,v_alumnos[i].Local_alum,v_alumnos[i].Curso,v_alumnos[i].Grupo);
	}
}

void modificar_materias () {
	
}

void agregar_materias () {
	
}

void eliminar_materias () {
	
}

void listar_materias (int N) {
	
	int i;
	printf("\n\nLISTA MATERIAS\n\n");
	printf("ID-NOMBRE-ABREVIATURA");
	
	for (i=0;i<N;i++) {
		printf("%s-%s-%s-",v_materias[i].Id_materias,v_materias[i].Nombre_materia,v_materias[i].Abrev_materia);
	}	
}

void modificar_materias () {
	
}

void agregar_materias () {
	
}

void eliminar_materias () {
	
}	
