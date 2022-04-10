#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "carga.h"
#include "datos.h"
#include "admin.h"

void listar_usuarios (int nUsuarios) {  

	int i;
	printf("\n\nLISTA USUARIOS\n\n");
	printf("ID-NOMBRE-PERFIL-USUARIO-CONTRASENA\n");
	
	for (i=0;i<nUsuarios;i++) {
		printf("%s-%s-%s-%s-%s\n",v_usuarios[i].Id_usuario,v_usuarios[i].Nomb_usuario,v_usuarios[i].Perfil_usuario,v_usuarios[i].Usuario,v_usuarios[i].Contrasena);
	}
}

void modificar_usuarios (int nUsuarios) {
	
	int i, op, res;
	char login[6];
	char cambio[21];
	
	do {
		
		printf("\nIntroduzca un usuario (login) a modificar: ");
		fflush(stdin);
		fgets(login, 6, stdin);	
		
		for (i=0;i<nUsuarios;i++) {
			
			if (strcmp(login,v_usuarios[i].Usuario)==0) {
				break;
			}
			
		}
		
		if (i==nUsuarios) {
			
			printf("\nERROR: No se ha encontrado usuario");
			printf("\n¿Desea volver a intentarlo? (1.Seguir)");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}
		}
		
		
	}while(i==nUsuarios);
		
	do {
		
		printf("\nID-NOMBRE-PERFIL-USUARIO-CONTRASENA\n");
		printf("%s-%s-%s-%s-%s",v_usuarios[i].Id_usuario,v_usuarios[i].Nomb_usuario,v_usuarios[i].Perfil_usuario,v_usuarios[i].Usuario,v_usuarios[i].Contrasena);

		printf("\t1.ID\n");
		printf("\t2.NOMBRE\n");
		printf("\t3.PERFIL\n");
		printf("\t4.USUARIO\n");
		printf("\t5.CONTRASENA\n");
		printf("\t0.Volver a menu usuario\n");
	
		scanf("%d", &op);
					
		switch (op) {
						
			case 0:
				break;
						
			case 1:	
					
				printf("\nIntroduzca nuevo ID: ");
				fflush(stdin);
				fgets(cambio, 4, stdin);
				strcpy(v_usuarios[i].Id_usuario,cambio);
				break;
						
			case 2:
				printf("\nIntroduzca nuevo nombre: ");
				fflush(stdin);
				fgets(cambio, 21, stdin);
				strcpy(v_usuarios[i].Nomb_usuario,cambio);
				break;
								
			case 3:	
				if (strcmp(v_usuarios[i].Perfil_usuario,'administrador')==0) {
						
					printf("\n¿Desea cambiar el perfil a profesor? (1.Confirmar)\n");
					scanf("%d", &res);
						
					if (res==1) {
						strcpy(v_usuarios[i].Perfil_usuario,'profesor');
					}
						
				} else {
						
					printf("\n¿Desea cambiar el perfil a administrador? (1.Confirmar)\n");
					scanf("%d", &res);
						
					if (res==1) {
						strcpy(v_usuarios[i].Perfil_usuario,'administrador');
					}												
				}
								
			case 4:
				printf("\nIntroduzca nuevo usuario (login): ");
				fflush(stdin);
				fgets(cambio, 6, stdin);
				strcpy(v_usuarios[i].Usuario,cambio);
				break;
					
			case 5:
				printf("\nIntroduzca nueva contrasena: ");
				fflush(stdin);
				fgets(cambio, 9, stdin);
				strcpy(v_usuarios[i].Contrasena,cambio);
				break;	
		}
					
	}while(op!=0);
		
}

void agregar_usuarios (int *nUsuarios) {
	
	int i, res;
	char id[4];
	char nombre[21];
	char perfil[15];
	char login[6];
	char contrasena[9];
	
	do {
		
		printf("\nIntroduzca id (3 digitos) del usuario: ");
		fflush(stdin);
		fgets(id, 4, stdin);		
			
		for (i=0;i<nUsuarios;i++) {
		
			if (strcmp(v_usuarios[i].Id_usuario,id)==0) {
				printf("\nERROR: ID en uso\n");
				printf("¿Desea volver a intentarlo? (1.Seguir)\n");
				scanf("%d", &res);
				
				if (res!=1) {
					return;
				}
				
				break;
			}
		}
	
	} while(strcmp(v_usuarios[i].Id_usuario,id)==0);
			
	do {
		
		printf("\nIntroduzca nombre (20 caracteres) del usuario: ");
		fflush(stdin);
		fgets(nombre, 21, stdin);		
			
		for (i=0;i<nUsuarios;i++) {
		
			if (strcmp(v_usuarios[i].Nomb_usuario,nombre)==0) {
				printf("\nERROR: NOMBRE en uso\n");
				printf("¿Desea volver a intentarlo? (1.Seguir)\n");
				scanf("%d", &res);
				
				if (res!=1) {
					return;
				}
				
				break;
			}
		}
	
	} while(strcmp(v_usuarios[i].Nomb_usuario,nombre)==0);	
			
	printf("\nIntroduzca perfil del usuario (1.Administrador) (Otro.Profesor): ");
	
	scanf("%d", &res);
	
	if (res==1) {
		strcpy(perfil,'administrador');
	} else {
		strcpy(perfil,'profesor');
	}
	
	do {
		
		printf("\nIntroduzca usuario (5 caracteres): ");
		fflush(stdin);
		fgets(usuario, 6, stdin);		
			
		for (i=0;i<nUsuarios;i++) {
		
			if (strcmp(v_usuarios[i].Usuario,usuario)==0) {
				printf("\nERROR: USUARIO en uso\n");
				printf("¿Desea volver a intentarlo? (1.Seguir)\n");
				scanf("%d", &res);
				
				if (res!=1) {
					return;
				}
				
				break;
			}
		}
	
	} while(strcmp(v_usuarios[i].Usuario,usuario)==0);
	
	printf("\nIntroduzca contrasena (8 caracteres): ");
	fflush(stdin);
	fgets(contrasena, 9, stdin);	
	
	printf("\n¿Desea crear este usuario? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_usuarios= (usuarios*) realloc(v_usuarios,(nUsuarios+1)*sizeof(usuarios)); //Añadimos un hueco más al vector
		
		*nUsuarios= *nUsuarios+1;
		
		strcpy(v_usuarios[nUsuarios-1].Id_usuario,id);
		strcpy(v_usuarios[nUsuarios-1].Nomb_usuario,nombre);
		strcpy(v_usuarios[nUsuarios-1].Perfil_usuario,perfil);
		strcpy(v_usuarios[nUsuarios-1].Usuario,usuario);
		strcpy(v_usuarios[nUsuarios-1].Contrasena,contrasena);
		
	}
	
} 

void eliminar_usuarios (int *nUsuarios) {
	
	int i, res;
	char id[4];
	
	do{
		
		printf("\nIntroduzca el id (3 digitos) del usuario a eliminar: ");
		fflush(stdin);
		fgets(id, 4, stdin);
	
		for (i=0;i<nUsuarios;i++) {
		
			if (strcmp(id,v_usuarios[i].Id_usuario)==0) {
				break;
			}
		}
	
		if (i==nUsuarios) {
			printf("\nERROR: ID de usuario no encontrado\n");
			printf("\n¿Desea volver a introducirlo? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}
		}		
		
	}while(i==nUsuarios);
	
	printf("\n¿Desea eliminar el usuario? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		for (i=i;i<(nUsuarios-1);i++) {
		
			strcpy(v_usuarios[i].Id_usuario,v_usuarios[i+1].Id_usuario);
			strcpy(v_usuarios[i].Nomb_usuario,v_usuarios[i+1].Nomb_usuario);
			strcpy(v_usuarios[i].Perfil_usuario,v_usuarios[i+1].Perfil_usuario);
			strcpy(v_usuarios[i].Usuario,v_usuarios[i+1].Usuario);
			strcpy(v_usuarios[i].Contrasena,v_usuarios[i+1].Contrasena);
		}
		
		*nUsuarios= *nUsuarios-1;
	}	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listar_alumnos (int nAlumnos) { 
	
	int i;
	printf("\n\nLISTA ALUMNOS\n\n");
	printf("ID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO\n");
	
	for (i=0;i<nAlumnos;i++) {
		printf("%s-%s-%s-%s-%s-%s\n",v_alumnos[i].Id_alum,v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum,v_alumnos[i].Local_alum,v_alumnos[i].Curso,v_alumnos[i].Grupo);
	}
}

void modificar_alumnos (int nAlumnos) {

	int i, op;
	char id[7];
	char cambio[31];
	
	do {
		
		printf("\nIntroduzca el id (6 digitos) del alumno a modificar: ");
		fflush(stdin);
		fgets(id, 7, stdin);	
		
		for (i=0;i<nAlumnos;i++) {
			
			if (strcmp(id,v_alumnos[i].Id_alum)==0) {
				break;
			}
			
		}
		
		if (i==nAlumnos) {
			
			printf("\nERROR: No se ha encontrado alumno");
			printf("\n¿Desea volver a intentarlo? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}			
		}
		
	}while(i==nAlumnos);
			
	do {
		
		printf("ID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO\n");
		printf("%s-%s-%s-%s-%s-%s\n",v_alumnos[i].Id_alum,v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum,v_alumnos[i].Local_alum,v_alumnos[i].Curso,v_alumnos[i].Grupo);

		printf("\t1.ID\n");
		printf("\t2.NOMBRE\n");
		printf("\t3.DIRECCION\n");
		printf("\t4.LOCALIDAD\n");
		printf("\t5.CURSO\n");
		printf("\t6.GRUPO\n");
		printf("\t7.MATRICULAS\n");
		printf("\t0.Volver a menu alumnos\n");
		
		scanf("%d", &op);
					
		switch (op) {
						
			case 0:
				break;
							
			case 1:	
					
				printf("\nIntroduzca nuevo ID: ");
				fflush(stdin);
				fgets(cambio, 7, stdin);
				strcpy(v_alumnos[i].Id_alum,cambio);				
				break;
						
			case 2:
				printf("\nIntroduzca nuevo nombre: ");
				fflush(stdin);
				fgets(cambio, 21, stdin);
				strcpy(v_alumnos[i].Nombre_alum,cambio);
				break;
								
			case 3:	
				printf("\nIntroduzca nueva direccion: ");
				fflush(stdin);
				fgets(cambio, 31, stdin);
				strcpy(v_alumnos[i].Direc_alum,cambio);
				break;
						
			case 4:
				printf("\nIntroduzca nueva localidad: ");
				fflush(stdin);
				fgets(cambio, 31, stdin);
				strcpy(v_alumnos[i].Local_alum,cambio);
				break;
					
			case 5:
				printf("\nIntroduzca nuevo curso: ");
				fflush(stdin);
				fgets(cambio, 31, stdin);
				strcpy(v_alumnos[i].Curso,cambio);
				break;	
					
			case 6:
				printf("\nIntroduzca nuevo grupo: ");
				fflush(stdin);
				fgets(cambio, 11, stdin);
				strcpy(v_alumnos[i].Grupo,cambio);
				break;
					
			case 7:	
				printf("\n\nMATRICULAS\n\n")
				materias_matriculado (i,nMatriculas,nMaterias);
					
				do {
						
					printf("\t1.Agregar matricula\n");
					printf("\t2.Eliminar matricula\n");
					printf("\t3.Modificar matricula\n");
					printf("\t0.Volver al menu de modificacion\n");
						
					scanf("%d", &n);
						
					switch (n) {
							
						case 0:
							break;
								
						case 1:
							agregar_matricula (i);
							break;
								
						case 2:
							eliminar_matricula (i);
							break;
								
						case 3:
							modificar_matricula (i);
							break;																
					}
						
				}while(n!=0);
							
		}
					
	}while(op!=0);		
	
}

void agregar_alumnos (int *nAlumnos) {
	
	int i, res;
	char id[7];
	char nombre[21];
	char direccion[31];
	char localidad[31];
	char curso[31];
	char grupo[11];
	
	do {
		
		printf("\nIntroduzca id (6 digitos) del alumno: ");
		fflush(stdin);
		fgets(id, 7, stdin);		
			
		for (i=0;i<nAlumnos;i++) {
		
			if (strcmp(v_alumnos[i].Id_alum,id)==0) {
				printf("\nERROR: ID en uso\n");
				printf("¿Desea volver a intentarlo? (1.Seguir)\n");
				scanf("%d", &res);
				
				if (res!=1) {
					return;
				}
				
				break;
			}
		}
	
	} while(strcmp(v_alumnos[i].Id_alum,id)==0);		
		
			
	printf("\nIntroduzca nombre (20 caracteres) del alumno: ");
	fflush(stdin);
	fgets(nombre, 21, stdin);		
			
	printf("\nIntroduzca direccion (30 caracteres) del alumno: ");
	fflush(stdin);
	fgets(direccion, 31, stdin);
	
	printf("\nIntroduzca localidad (30 caracteres) del alumno: ");
	fflush(stdin);
	fgets(localidad, 31, stdin);
	
	printf("\nIntroduzca curso (30 caracteres) del alumno: ");
	fflush(stdin);
	fgets(curso, 31, stdin);
	
	printf("\nIntroduzca grupo (10 caracteres) del alumno: ");
	fflush(stdin);
	fgets(grupo, 11, stdin);	
	
	printf("\n¿Desea crear este alumno? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_alumnos= (alumnos*) realloc(v_alumnos,(nAlumnos+1)*sizeof(alumnos)); //Añadimos un hueco más al vector
		
		*nAlumnos= *nAlumnos+1;
		
		strcpy(v_alumnos[nAlumnos-1].Id_alum,id);
		strcpy(v_alumnos[nAlumnos-1].Nombre_alum,nombre);
		strcpy(v_alumnos[nAlumnos-1].Direc_alum,direccion);
		strcpy(v_alumnos[nAlumnos-1].Local_alum,localidad);
		strcpy(v_alumnos[nAlumnos-1].Curso,curso);
		strcpy(v_alumnos[nAlumnos-1].Grupo,grupo);
		
	}	
	
}

void eliminar_alumnos (int *nAlumnos) {
		
	int i, res;
	char id[7];
	
	do{
		
		printf("\nIntroduzca el id (6 digitos) del alumno a eliminar: ");
		fflush(stdin);
		fgets(id, 7, stdin);
	
		for (i=0;i<nAlumnos;i++) {
		
			if (strcmp(id,v_alumnos[i].Id_alum)==0) {
				break;
			}
		}
	
		if (i==nAlumnos) {
			printf("\nERROR: ID de alumnos no encontrado\n");
			printf("¿Desea volver a introducirlo? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}
		}		
		
	}while(i==nAlumnos);
	
	printf("\n¿Desea eliminar el alumno? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		for (i=i;i<(nAlumnos-1);i++) {
		
			strcpy(v_alumnos[i].Id_alum,v_alumnos[i+1].Id_alum);
			strcpy(v_alumnos[i].Nombre_alum,v_alumnos[i+1].Nombre_alum);
			strcpy(v_alumnos[i].Direc_alum,v_alumnos[i+1].Direc_alum);
			strcpy(v_alumnos[i].Local_alum,v_alumnos[i+1].Local_alum);
			strcpy(v_alumnos[i].Curso,v_alumnos[i+1].Curso);
			strcpy(v_alumnos[i].Grupo,v_alumnos[i+1].Grupo);
			
		}
		
		*nAlumnos= *nAlumnos-1;
	}	
	
}


void materias_matriculado (int i_alumno, int nMatriculas, int nMaterias) {
	
	int i, j;
	
	printf("\nALUMNO: %s\n",v_alumnos[i_alumno].Nombre_alum);
	printf("MATRICULADO EN: \n");
	
	for (i=0; i<nMatriculas; i++) {
		
		if (strcmp(v_alumnos[i_alumno].Id_alum,v_matriculas[i].Id_alum)==0) {
			
			for (j=0; j<nMaterias; j++) {
				
				if (strcmp(v_materias[j].Id_materias,v_matriculas[i].Id_materias)==0) {
					
					printf("-%s \n", v_materias[j].Nombre_materia);
					
				}
			}
			
		}
		
	}
	
}

void modificar_matricula (int i_alumno, int nMatriculas) {
	
	int i, res;
	char materia[5];
	
	do {
		
		printf("\nIntroduzca id (4 digitos) de la matricula que desea modificar");
		fflush(stdin);
		fgets(materia, 5, stdin);
		
		for (i=0;i<nMatriculas;i++) {
			
			if (strcmp(v_alumnos[i_alumno].Id_alum,v_matriculas[i].Id_alum)==0) {
				
				for (j=0;j<nMatriculas;j++) {
					 
					 if (strcmp(v_matriculas[j].Id_materias,materia)==0) {
					 	
					 	break;
					 }
				}
			}
			
			if(strcmp(v_matriculas[j].Id_materias,materia)==0) { //El mismo if de arriba, pero es para salir del primer for y tener la "i"
				break;
			}
			
		}
		
		if (i==nMatriculas) {
			
			printf("\nERROR: No se ha encontrado materia");
			printf("\n¿Desea volver a introducirlo? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}			
		}
		
	}while(i==nMatriculas);
		
	printf("\nIntroduzca nueva matricula:");
	fflush(stdin);
	fgets(materia, 5, stdin);
	strcpy(v_matriculas[j].Id_materias,materia);	
	
}

void eliminar_matricula (int i_alumno, int *nMatriculas) {
	
	int i, res;
	char materia[5];
	
	do{
		
		printf("\nIntroduzca el id (4 digitos) de la materia de la que quiere desmatricular al alumno: ");
		fflush(stdin);
		fgets(materia, 5, stdin);
	
		for (i=0;i<nMatriculas;i++) {
		
			if ((strcmp(materia,v_matriculas[i].Id_materias)==0)&&(strcmp(v_matriculas[i].Id_alum,v_alumnos[i_alumno].Id_alum)==0)) {
				break;
			}
		}
	
		if (i==nMatriculas) {
			printf("\nERROR: MATRICULA no encontrada\n");
			printf("¿Desea volver a introducirla? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}
		}		
		
	}while(i==nMatriculas);
	
	printf("\n¿Desea realizar la desmatriculacion? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		for (i=i;i<(nMatriculas-1);i++) {
		
			strcpy(v_matriculas[i].Id_alum,v_matriculas[i+1].Id_alum);
			strcpy(v_matriculas[i].Id_materias,v_matriculas[i+1].Id_materias);
		}
		
		*nMatriculas= *nMatriculas-1;
	}		
	
}

void agregar_matricula (int i_alumno, int nMaterias, int *nMatriculas) {
	
	int i, j, res;
	char materia[5];
	
	do {
		
		printf("\nIntroduzca el ID MATERIA (4 digitos) en la que va a matricular: ");
		fflsuh(stdin);
		fgets(materia, 5, stdin);		
			
		for (i=0;i<nMaterias;i++) {
		
			if (strcmp(v_materias[i].Id_materias,materia)==0) {
				break;

			}
		}
		
		if (i==nMaterias) {
			
			printf("\nERROR: La MATERIA no existe\n");
			printf("¿Desea volver a intentarlo? (1.Seguir)\n");
			scanf("%d", &res);
				
			if (res!=1) {
				return;
			}				
		}		
	
	} while(i==nMaterias);	
	
	do{
		
		for (j=0;j<nMatriculas;j++) {  //Comprueba si el alumno esta matriculado en ese momento
		
			if ((strcmp(v_materias[i].Id_materias,v_matriculas[j].Id_materias)==0)&&(strcmp(v_alumnos[i_usuario].Id_alum,v_matriculas[j].Id_alum)==0)) {
			
				printf("\nERROR: El alumno ya esta matriculado en la materia");
				printf("\n¿Desea intentarlo de nuevo? (1.Seguir)\n");
				scanf("%d", &res);
			
				if (res!=1) {
					return;
				}
				break;
					
			}
		}		
		
	}while((strcmp(v_materias[i].Id_materias,v_matriculas[j].Id_materias)==0)&&(strcmp(v_alumnos[i_usuario].Id_alum,v_matriculas[j].Id_alum)==0));

	
	printf("\n¿Desea crear la matricula? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_matriculas= (matriculas*) realloc(v_matriculas,(nMatrciulas+1)*sizeof(matriculas)); //Añadimos un hueco más al vector
		
		*nMatriculas= *nMatriculas+1;
		
		strcpy(v_matriculas[nMatriculas-1].Id_alum,v_alumnos[i_usuario].Id_alum);
		strcpy(v_matriculas[nMatriculas-1].Id_materias,materia);
				
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void modificar_materias (int nMaterias) {
	
	int i, op;
	char id[5];
	char cambio[51];
	
	do {
		
		printf("\nIntroduzca el id (4 digitos) de la materia a modificar: ");
		fflush(stdin);
		fgets(id, 5, stdin);	
		
		for (i=0;i<nMaterias;i++) {
			
			if (strcmp(id==v_materias[i].Id_materias)==0) {
				
				break;
			}
			
		}
		
		if (i==nMaterias) {
			
			printf("\nERROR: No se ha encontrado ID MATERIA");
			printf("\n¿Desea volver a introducira? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}			
		}
		
	}while(i==nMaterias);
	
		
	do {
		
		printf("\nID-NOMBRE-ABREVIATURA\n");
		printf("%s-%s-%s\n",v_materias[i].Id_materias,v_materias[i].Nombre_materia,v_materias[i].Abrev_materia);
	
		printf("\t1.ID\n");
		printf("\t2.NOMBRE\n");
		printf("\t3.ABREVIATURA\n");
		printf("\t0.Volver a menu materias\n");		
	
		scanf("%d", &op);
					
		switch (op) {
					
			case 0:
				break;
							
			case 1:	
					
				printf("\nIntroduzca nuevo ID: ");
				fflush(stdin);
				fgets(cambio, 5, stdin);
				strcpy(v_materias[i].Id_materias,cambio);
				break;
						
			case 2:
				printf("\nIntroduzca nuevo nombre: ");
				fflush(stdin);
				fgets(cambio, 51, stdin);
				strcpy(v_materias[i].Nombre_materia,cambio);
				break;
								
			case 3:	
				printf("\nIntroduzca nuevo abreviatura: ");
				fflush(stdin);
				fgets(cambio, 4, stdin);
				strcpy(v_materias[i].Abrev_materia,cambio);
				break;	
		}
					
	}while(op!=0);
		
}

void agregar_materias (int *nMaterias) {
	
	int i, res;
	char id[5];
	char nombre[51];
	char abreviatura[4];
	
	do {
		
		printf("\nIntroduzca el ID MATERIA (4 digitos): ");
		fflsuh(stdin);
		fgets(id, 5, stdin);		
			
		for (i=0;i<nMaterias;i++) {
		
			if (strcmp(v_materias[i].Id_materias,id)==0) {
				printf("\nERROR: ID MATERIA en uso\n");
				printf("¿Desea volver a intentarlo? (1.Seguir)\n");
				scanf("%d", &res);
				
				if (res!=1) {
					return;
				}			
				break;
			}
		}
	
	} while(strcmp(v_materias[i].Id_materias,materia)==0);			
		
	do {
		
		printf("\nIntroduzca nombre (50 caracteres) de la materia: ");
		fflush(stdin);
		fgets(nombre, 51, stdin);		
			
		for (i=0;i<nMaterias;i++) {
		
			if (strcmp(v_materias[i].Nombre_materia,nombre)==0) {
				printf("\nERROR: NOMBRE en uso\n");
				printf("¿Desea volver a intentarlo? (1.Seguir)\n");
				scanf("%d", &res);
				
				if (res!=1) {
					return;
				}			
				break;
			}
		}
	
	} while(strcmp(v_materias[i].Nombre_materia,nombre)==0);
					
	do {
		
		printf("\nIntroduzca abreviatura (3 caracteres) de la materia: ");
		fflush(stdin);
		fgets(abreviatura, 4, stdin);		
			
		for (i=0;i<nMaterias;i++) {
		
			if (strcmp(v_materias[i].Abrev_materia,abreviatura)==0) {
				printf("\nERROR: ABREVIATURA en uso\n");
				printf("¿Desea volver a intentarlo? (1.Seguir)\n");
				scanf("%d", &res);
				
				if (res!=1) {
					return;
				}			
				break;
			}
		}
	
	} while(strcmp(v_materias[i].Abrev_materia,abreviatura)==0);			
	
	printf("\n¿Desea crear esta materia? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_materias= (materias*) realloc(v_materias,(nMaterias+1)*sizeof(materias)); //Añadimos un hueco más al vector
		
		*nMaterias= *nMaterias+1;
		
		strcpy(v_materias[nMaterias-1].Id_materias,id);
		strcpy(v_materias[nMaterias-1].Nombre_materia,nombre);
		strcpy(v_materias[nMaterias-1].Abrev_materia,abreviatura);
		
	}	
	
}

void eliminar_materias (int *nMaterias) {
	
	int i, res;
	char id[5];
	
	do{
		
		printf("\nIntroduzca el id (4 digitos) de la materia a eliminar: ");
		fflush(stdin);
		fgets(id, 5, stdin);
	
		for (i=0;i<nMaterias;i++) {
		
			if (strcmp(id,v_materias[i].Id_materias)==0) {
				break;
			}
		}
	
		if (i==nMaterias) {
			printf("\nERROR: MATERIA no encontrada\n");
			printf("¿Desea volver a introducirla? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}
		}		
		
	}while(i==nMaterias);
	
	printf("\n¿Desea eliminar la materia? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		for (i=i;i<(nMaterias-1);i++) {
		
			strcpy(v_materias[i].Id_materias,v_materias[i+1].Id_materias);
			strcpy(v_materias[i].Nombre_materia,v_materias[i+1].Nombre_materia);
			strcpy(v_materias[i].Abrev_materia,v_materias[i+1].Abrev_materia);
			
		}
		
		*nMaterias= *nMaterias-1;
	}	

}

void listar_materias (int nMaterias) {
	
	int i;
	printf("\n\nLISTA MATERIAS\n\n");
	printf("ID-NOMBRE-ABREVIATURA\n");
	
	for (i=0;i<nMaterias;i++) {
		printf("%s-%s-%s\n",v_materias[i].Id_materias,v_materias[i].Nombre_materia,v_materias[i].Abrev_materia);
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listar_horarios (int nUsuarios, int nHorarios) {
	
	int i, j;
	char id[4];
	
	do { //Comprueba si el id introducido corresponde con uno del registro
		
		printf("\nIntroduzca el id (3 digitos) del profesor para ver su horario: ");
		fflush(stdin);
		fgets(id, 4, stdin);	
		
		for (i=0;i<nHorarios;i++) {
			
			if (strcmp(id,v_horarios[i].Id_profesor)==0) {
				break;
			}
			
		}
		
		if (i==nHorarios) {
			
			printf("\nERROR: Profesor no encontrado");
			printf("\n¿Desea volver a introducirlo? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}			
		}

		
	}while(i==nHorarios);	
	
	for (j=0;j<nUsuarios;j++) {  //Busca la j_usuario del profe en el registro de Usuarios
		
		if (strcmp(id,v_usuarios[j].Id_usuario)==0) {
			break;
		}
		
	}	
	
	printf("\nPROFESOR: %s",v_usuarios[j].Nomb_usuario);
	printf("\nHORARIO: \n");
	printf("DIA-HORA-ID MATERIA-GRUPO\n");
	
	for (i=0;i<nHorarios;i++) {
		
		if (strcmp(v_horarios[i].Id_profesor,id)==0) {
			
			printf("%d-%d-%s-%s\n", v_horarios[i].Dia_clase, v_horarios[i].Hora_clase, v_horarios[i].Id_materia, v_horarios[i].Grupo);
		}
	}
	
}


void modificar_horarios (int nUsuarios, int nHorarios) {
	
	
	int i, j, c, cond, q; //c es para cambio de enteros y cond para guardar la condicion (1/0) para realizar el cambio
	char id[4];
	char cambio[11];
	
	do { //Comprueba si el id introducido corresponde con uno del registro
		
		printf("\nIntroduzca el id (3 digitos) del profesor para modificar horario: ");
		fflush(stdin);
		fgets(id, 4, stdin);	
		
		for (i=0;i<nHorarios;i++) {
			
			if (strcmp(id,v_horarios[i].Id_profesor)==0) {
				break;
			}
			
		}
		
		if (i==nHorarios) {
			
			printf("\nERROR: Profesor no encontrado");
			printf("\n¿Desea volver a introducirlo? (1.Seguir)");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}			
		}

		
	}while(i==nHorarios);	
	
	for (j=0;j<nUsuarios;j++) {  //Busca la i_usuario del profe en el registro de Usuarios
		
		if (strcmp(id,v_usuarios[j].Id_usuario)==0) {
			break;
		}
		
	}	
	
	printf("\nPROFESOR: %s",v_usuarios[j].Nomb_usuario);
	
	do {
		
		printf("\nDIA-HORA-ID MATERIA-GRUPO\n");
	
		for (i=0;i<nHorarios;i++) {
		
			if (strcmp(v_horarios[i].Id_profesor,id)==0) {
				printf("%d-%d-%s-%s\n", v_horarios[i].Dia_clase, v_horarios[i].Hora_clase, v_horarios[i].Id_materia, v_horarios[i].Grupo);
			}
		}				
		
		printf("\t1.DIA\n");
		printf("\t2.HORA\n");
		printf("\t3.GRUPO\n");		
		printf("\t0.Volver a menu horarios\n");
		
		scanf("%d", &op);
				
		switch (op) {
			
			case 0:
				break;
				
			case 1:
				
				cond=auxiliar_horarios(id[4],nHorarios,&q);
				
				if (cond==1) {
					
					do {
						
						printf("\nIntroduzca nuevo dia (1-5): ");
						scanf("%d", &c);
						
					}while((c<1)||(c>5));
					
					v_horarios[q].Dia_clase=c;
					
				} else {
					
					printf("\nERROR: Algun parametro no se corresponde a un horario existente\n");
				}
				break;
			
			case 2:
				
				cond=auxiliar_horarios(id[4],nHorarios,&q);
				
				if (cond==1) {
					
					do {
						
						printf("\nIntroduzca nueva hora (1-6): ");
						scanf("%d", &c);
						
					}while((c<1)||(c>6));
					
					v_horarios[q].Hora_clase=c;
					
				} else {
					
					printf("\nERROR: Algun parametro no se corresponde a un horario existente\n");
				}				
				break;
				
			case 3:
				
				cond=auxiliar_horarios(id[4],nHorarios,&q);
				
				if (cond==1) {
					
					printf("\nIntroduzca nuevo grupo (10 caracteres): ");
					fflush(stdin);
					fgets(cambio, 11, stdin);
					strcpy(v_horarios[q].Grupo,cambio);
					
				} else {
					
					printf("\nERROR: Algun parametro no se corresponde a un horario existente\n");
				}					
				break;		
		}
		
	}while(op!=0);

}

int auxiliar_horarios (char id[4], int nHorarios, int *q) {
	
	char materia[5];
	char grupo[11];
	
	printf("\nIntroduzca materia (4 caracteres) y grupo (10 caracteres) para modificar el horario\n");
	
	printf("\nMATERIA: ");
	fflush(stdin);
	fgets(materia, 5, stdin);
	
	printf("\nGRUPO: ");
	fflush(stdin);
	fgets(grupo, 11, stdin);
	
	for (i=0;i<nHorarios;i++) {
		
		if ((strcmp(v_horarios[i].Id_profesor,id)==0)&&(strcmp(v_horarios[i].Grupo,grupo)==0)&&(strcmp(v_horarios[i].Id_materia,materia)==0)) {
			*q=i;
			return(1);
		}
		
	}
	
	return(0);
}

void agregar_horarios (int *nHorarios, int nUsuarios, int nMaterias, int nAlumnos) {
	
	int i, res, dia, hora;
	char id[4];
	char materia[5];
	char grupo[11];
	
	do {
		
		printf("\nIntroduzca ID (3 digitos) del profesor al que desea crear horario: ");
		fflus(stdin),
		fgets(id, 4, stdin);		
			
		for (i=0;i<nUsuarios;i++) {
		
			if ((strcmp(v_usuarios[i].Id_usuario,id)==0)&&(strcmp(v_usuarios[i].Perfil_usuario,'profesor')==0)) {
				break;

			}
		}
		
		if (i==nUsuarios) {
			
			printf("\nERROR: El ID del profesor no existe\n");
			printf("¿Desea volver a intentarlo? (1.Seguir)\n");
			scanf("%d", &res);
				
			if (res!=1) {
				return;
			}						
			
		}
	
	} while(i==nUsuarios);
	
	do{
		
		do {
		
			printf("\nIntroduzca el dia (1-5) que tiene clase: ");
			scanf("%d", &dia);
		
		}while((dia<1)||(dia>5));

		do {
		
			printf("\nIntroduzca la hora (1-6) a la que tiene clase: ");
			scanf("%d", &hora);
		
		}while((hora<1)||(hora>6));
	
		for (i=0;i<nHorarios;i++) { //Comprueba si ya tiene una clase el mismo dia y hora
		
			if ((dia==v_horarios[i].Dia_clase)&&(hora==v_horarios[i].Hora_clase)) {
				printf("\nERROR: Ya tiene una clase a esa hora el mismo dia\n");
				printf("¿Desea volver a introducir hora? (1.Seguir)\n");
				scanf("%d", &res);
			
				if (res!=1) {
					return;
				}
				break;
			}
		}		
		
	}while((dia==v_horarios[i].Dia_clase)&&(hora==v_horarios[i].Hora_clase));
	
	do {
		
		printf("\nIntroduzca la ID MATERIA (4 digitos) a la que va a dar clase: ");
		fflush(stdin);
		fgets(materia, 5, stdin);		
			
		for (i=0;i<nMaterias;i++) {
		
			if (strcmp(materia,v_materias[i].Id_materias)==0) {
				break;
			}
		}
		
		if (i==nMaterias) {
			
			printf("\nERROR: La ID MATERIA no existe\n");
			printf("¿Desea volver a intentarlo? (1.Seguir)\n");
			scanf("%d", &res);
				
			if (res!=1) {
				return;
			}						
			
		}
	
	} while(i==nMaterias);
			
	do {
		
		printf("\nIntroduzca grupo (10 caracteres) al que va a dar clase: ");
		fflush(stdin);
		fgets(grupo, 11, stdin);		
			
		for (i=0;i<nAlumnos;i++) {
		
			if (strcmp(grupo,v_alumnos[i].Grupo)==0) {
				break;
			}
		}
		
		if (i==nAlumnos) {
			
			printf("\nERROR: El grupo no existe\n");
			printf("¿Desea volver a intentarlo? (1.Seguir)\n");
			scanf("%d", &res);
				
			if (res!=1) {
				return;
			}						
			
		}
	
	} while(i==nAlumnos);
	
	printf("\n¿Desea crear el horarios? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_horarios= (horarios*) realloc(v_horarios,(nHorarios+1)*sizeof(horarios));
		
		*nHorarios = *nHorarios+1;
		
		strcpy(v_horarios[nHorarios-1].Id_profesor,id);
		strcpy(v_horarios[nHorarios-1].Dia_clase,dia);
		strcpy(v_horarios[nHorarios-1].Hora_clase,hora);
		strcpy(v_horarios[nHorarios-1].Id_materia,materia);
		strcpy(v_horarios[nHorarios-1].Grupo,grupo);
		
	}	

}

void eliminar_horarios (int *nHorarios, int nUsuarios) {
	
	int i, res;
	char id[4];
	char grupo[11];
		
	do{
		
		printf("\nIntroduzca ID (3 digitos) del profesor al que desea eliminar horario: ");
		fflush(stdin),
		fgets(id, 4, stdin);
	
		for (i=0;i<nUsuarios;i++) {
		
			if ((strcmp(id,v_usuarios[i].Id_usuario))==0&&(strcmp(v_usuarios[i].Perfil_usuario,'profesor')==0)) {
				break;
			}
		}
	
		if (i==nUsuarios) {
			printf("\nERROR: ID de profesor no encontrado\n");
			printf("¿Desea volver a introducirlo? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}
		}		
		
	}while(i==nUsuarios);
	
	do{
		
		printf("\nIntroduzca el grupo (10 caracteres) que va a eliminar del horario\n");
		fflus(stdin);
		fgets(grupo, 11, stdin);
	
		for (i=0;i<nHorarios;i++) {
		
			if ((strcmp(grupo,v_horarios[i].Grupo))==0&&(strcmp(v_horarios[i].Id_profesor,id)==0)) {
				break;
			}
		}
	
		if (i==nHorarios) {
			
			printf("\nERROR: El grupo no existe o no pertenece al profesor\n");
			printf("¿Desea volver a introducirlo? (1.Seguir)\n");
			scanf("%d", &res);
		
			if (res!=1) {
				return;
			}
		}		
		
	}while(i==nHorarios);	
	
	printf("\n¿Desea eliminar el horario del profesor? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		for (i=i;i<(nHorarios-1);i++) {
		
			strcpy(v_horarios[i].Id_profesor,v_horarios[i+1].Id_profesor);
			strcpy(v_horarios[i].Id_materia,v_horarios[i+1].Id_materia);
			strcpy(v_horarios[i].Grupo,v_horarios[i+1].Grupo);
			strcpy(v_horarios[i].Dia_clase,v_horarios[i+1].Dia_clase);
			strcpy(v_horarios[i].Hora_clase,v_horarios[i+1].Hora_clase);

		}
		
		*nHorarios= *nHorarios-1;
	}	
	
}
