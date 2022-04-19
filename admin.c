#include "admin.h"

//Postcondicón: Lista todos los usuarios
void listar_usuarios (int nUsuarios) {  

	int i;
	printf("\n\n\tLISTA USUARIOS\n\n");
	printf("\tID-NOMBRE-PERFIL-USUARIO-CONTRASENA\n");
	
	for (i=0;i<nUsuarios;i++) {
		printf("\t%s-%s-%s-%s-%s\n",v_usuarios[i].Id_usuario,v_usuarios[i].Nomb_usuario,v_usuarios[i].Perfil_usuario,v_usuarios[i].Usuario,v_usuarios[i].Contrasena);
	}
}

//Postcondicón: Permite modificar la información de los usuarios existentes
void modificar_usuarios (int nUsuarios) {
	
	int i, op, j;
	char res[3];
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
			printf("\n¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar \n");
			fflush(stdin);
			fgets(res, 3, stdin);
			
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				exit(1);
			}
		}
		
		
	}while(i==nUsuarios);
		
	do {
		
		printf("\n\tID-NOMBRE-PERFIL-USUARIO-CONTRASENA\n");
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

				do {
					
					printf("\nIntroduzca nuevo ID: ");
					fflush(stdin);
					fgets(cambio, 4, stdin);
					
					for (j=0;j<nUsuarios;j++) {
						
						if (strcmp(v_usuarios[j].Id_usuario,cambio)==0) {
							
							printf("\nERROR: ID en uso");
							printf("\n¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)");
							fflush(stdin);
							fgets(res, 3, stdin);
							
							if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
								return;
							}
							break;
						}
					}
												
				}while(strcmp(v_usuarios[j].Id_usuario,cambio)==0);						
				strcpy(v_usuarios[i].Id_usuario,cambio);
				break;
						
			case 2:
				printf("\nIntroduzca nuevo nombre: ");
				fflush(stdin);
				fgets(cambio, 21, stdin);
				strcpy(v_usuarios[i].Nomb_usuario,cambio);
				break;
								
			case 3:	
				if (strcmp(v_usuarios[i].Perfil_usuario,"administrador")==0) {
						
					printf("\n¿Desea cambiar el perfil a profesor? (Introduzca 'Si' para confirmar)\n");
					fflush(stdin);
					fgets(res, 3, stdin);
						
					if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
						strcpy(v_usuarios[i].Perfil_usuario,"profesor");
					}
						
				} else {
						
					printf("\n¿Desea cambiar el perfil a administrador? (Introduzca 'Si' para confirmar)\n");
					fflush(stdin);
					fgets(res, 3, stdin);
					if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
						strcpy(v_usuarios[i].Perfil_usuario,"administrador");
					}												
				}
								
			case 4:
				
				do {
					
					printf("\nIntroduzca nuevo usuario (login): ");
					fflush(stdin);
					fgets(cambio, 6, stdin);
					
					for (j=0;j<nUsuarios;j++) {
						
						if (strcmp(v_usuarios[j].Usuario,cambio)==0) {
							
							printf("\nERROR: USUARIO en uso");
							printf("\n¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)");
							fflush(stdin);
							fgets(res, 3, stdin);
							
							if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
								return;
							}
							break;
						}
					}
												
				}while(strcmp(v_usuarios[j].Usuario,cambio)==0);					
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

//Postcondicón: Permite añadir nuevos usuarios
void agregar_usuarios (int *nUsuarios) {
	
	int i;
	char res[3];
	char id[4];
	char nombre[21];
	char perfil[15];
	char usuario[6];
	char contrasena[9];
	
	do {
		
		printf("\nIntroduzca id (3 digitos) del usuario: ");
		fflush(stdin);
		fgets(id, 4, stdin);		
			
		for (i=0;i<*nUsuarios;i++) {
		
			if (strcmp(v_usuarios[i].Id_usuario,id)==0) {
				printf("\nERROR: ID en uso\n");
				printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
				fflush(stdin);
				fgets(res, 3, stdin);
				
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
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
			
		for (i=0;i<*nUsuarios;i++) {
		
			if (strcmp(v_usuarios[i].Nomb_usuario,nombre)==0) {
				printf("\nERROR: NOMBRE en uso\n");
				printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
				fflush(stdin);
				fgets(res, 3, stdin);
				
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
					return;
				}
				
				break;
			}
		}
	
	} while(strcmp(v_usuarios[i].Nomb_usuario,nombre)==0);	
			
	printf("\nIntroduzca perfil del usuario (Introduzca 'A' para administrador o cualquier otro para profesor): ");
	
	fflush(stdin);
	fgets(res, 2, stdin);
	
	if ((strcmp(res,"A")==0)||(strcmp(res,"a")==0)) {
		strcpy(perfil,"administrador");
	} else {
		strcpy(perfil,"profesor");
	}
	
	do {
		
		printf("\nIntroduzca usuario (5 caracteres): ");
		fflush(stdin);
		fgets(usuario, 6, stdin);		
			
		for (i=0;i<*nUsuarios;i++) {
		
			if (strcmp(v_usuarios[i].Usuario,usuario)==0) {
				printf("\nERROR: USUARIO en uso\n");
				printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
				fflush(stdin);
				fgets(res, 3, stdin);
				
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
					return;
				}
				
				break;
			}
		}
	
	} while(strcmp(v_usuarios[i].Usuario,usuario)==0);
	
	printf("\nIntroduzca contrasena (8 caracteres): ");
	fflush(stdin);
	fgets(contrasena, 9, stdin);	
	
	printf("\n¿Desea crear este usuario? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		v_usuarios= (usuarios*) realloc(v_usuarios,((*nUsuarios)+1)*sizeof(usuarios)); //Añadimos un hueco más al vector
		
		*nUsuarios= *nUsuarios+1;
		
		strcpy(v_usuarios[(*nUsuarios)-1].Id_usuario,id);
		strcpy(v_usuarios[(*nUsuarios)-1].Nomb_usuario,nombre);
		strcpy(v_usuarios[(*nUsuarios)-1].Perfil_usuario,perfil);
		strcpy(v_usuarios[(*nUsuarios)-1].Usuario,usuario);
		strcpy(v_usuarios[(*nUsuarios)-1].Contrasena,contrasena);
		
	}
	
} 

//Postcondicón: Permite eliminar usuarios existentes
void eliminar_usuarios (int *nUsuarios) {
	
	int i;
	char res[3];
	char id[4];
	
	do{
		
		printf("\nIntroduzca el id (3 digitos) del usuario a eliminar: ");
		fflush(stdin);
		fgets(id, 4, stdin);
	
		for (i=0;i<*nUsuarios;i++) {
		
			if (strcmp(id,v_usuarios[i].Id_usuario)==0) {
				break;
			}
		}
	
		if (i==*nUsuarios) {
			printf("\nERROR: ID de usuario no encontrado\n");
			printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
				
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}
		}		
		
	}while(i==*nUsuarios);
	
	printf("\n¿Desea eliminar el usuario? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		for (i=i;i<(*nUsuarios-1);i++) {
		
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

//Postcondicón: Lista todos los alumnos
void listar_alumnos (int nAlumnos) { 
	
	int i;
	printf("\n\n\tLISTA ALUMNOS\n\n");
	printf("\tID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO\n");
	
	for (i=0;i<nAlumnos;i++) {
		printf("\t%s-%s-%s-%s-%s-%s\n",v_alumnos[i].Id_alum,v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum,v_alumnos[i].Local_alum,v_alumnos[i].Curso,v_alumnos[i].Grupo);
	}
}

//Postcondicón: Permite modificar la información de los alumnos existentes
void modificar_alumnos (int nAlumnos) {

	int i, j, op, n;
	char res[3];
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
			printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
				
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}			
		}
		
	}while(i==nAlumnos);
			
	do {
		
		printf("\tID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO\n");
		printf("\t%s-%s-%s-%s-%s-%s\n",v_alumnos[i].Id_alum,v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum,v_alumnos[i].Local_alum,v_alumnos[i].Curso,v_alumnos[i].Grupo);

		printf("\n\t1.ID\n");
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
				
				do {
					
					printf("\nIntroduzca nuevo ID: ");
					fflush(stdin);
					fgets(cambio, 7, stdin);
					
					for (j=0;j<nAlumnos;j++) {
						
						if (strcmp(v_alumnos[j].Id_alum,cambio)==0) {
							
							printf("\nERROR: ID en uso");
							printf("\n¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)");
							fflush(stdin);
							fgets(res, 3, stdin);
							
							if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
								return;
							}
							break;
						}
					}
									
					
				}while(strcmp(v_alumnos[j].Id_alum,cambio)==0);	
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
				printf("\n\n\tMATRICULAS\n");
				materias_matriculado (i,nMatriculas,nMaterias);
					
				do {
						
					printf("\n\t1.Agregar matricula\n");
					printf("\t2.Eliminar matricula\n");
					printf("\t3.Modificar matricula\n");
					printf("\t0.Volver al menu de modificacion\n");
						
					scanf("%d", &n);
						
					switch (n) {
							
						case 0:
							break;
								
						case 1:
							agregar_matricula (i, nMaterias, &nMatriculas);
							break;
								
						case 2:
							eliminar_matricula (i, &nMatriculas);
							break;
								
						case 3:
							modificar_matricula (i, nMatriculas);
							break;																
					}
						
				}while(n!=0);
							
		}
					
	}while(op!=0);		
	
}

//Postcondicón: Permite añadir un nuevo alumno
void agregar_alumnos (int *nAlumnos) {
	
	int i;
	char res[3];
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
			
		for (i=0;i<*nAlumnos;i++) {
		
			if (strcmp(v_alumnos[i].Id_alum,id)==0) {
				printf("\nERROR: ID en uso\n");
				printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
				fflush(stdin);
				fgets(res, 3, stdin);
				
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
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
	
	printf("\n¿Desea crear este alumno? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		v_alumnos= (alumnos*) realloc(v_alumnos,((*nAlumnos)+1)*sizeof(alumnos)); //Añadimos un hueco más al vector
		
		*nAlumnos= *nAlumnos+1;
		
		strcpy(v_alumnos[(*nAlumnos)-1].Id_alum,id);
		strcpy(v_alumnos[(*nAlumnos)-1].Nombre_alum,nombre);
		strcpy(v_alumnos[(*nAlumnos)-1].Direc_alum,direccion);
		strcpy(v_alumnos[(*nAlumnos)-1].Local_alum,localidad);
		strcpy(v_alumnos[(*nAlumnos)-1].Curso,curso);
		strcpy(v_alumnos[(*nAlumnos)-1].Grupo,grupo);
		
	}	
	
}

//Postcondicón: Permite eliminar un alumno existente
void eliminar_alumnos (int *nAlumnos) {
		
	int i;
	char res[3];
	char id[7];
	
	do{
		
		printf("\nIntroduzca el id (6 digitos) del alumno a eliminar: ");
		fflush(stdin);
		fgets(id, 7, stdin);
	
		for (i=0;i<*nAlumnos;i++) {
		
			if (strcmp(id,v_alumnos[i].Id_alum)==0) {
				break;
			}
		}
	
		if (i==*nAlumnos) {
			printf("\nERROR: ID de alumnos no encontrado\n");
			printf("¿Desea volver a introducirlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
		
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}
		}		
		
	}while(i==*nAlumnos);
	
	printf("\n¿Desea eliminar el alumno? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		for (i=i;i<(*nAlumnos-1);i++) {
		
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


//Postcondicón: Muestra las materias en las que el alumno está matriculado
void materias_matriculado (int i_alumno, int nMatriculas, int nMaterias) {
	
	int i, j;
	
	printf("\n\tALUMNO: %s\n",v_alumnos[i_alumno].Nombre_alum);
	printf("\tMATRICULADO EN: \n");
	
	for (i=0; i<nMatriculas; i++) {
		
		if (strcmp(v_alumnos[i_alumno].Id_alum,v_matriculas[i].Id_alum)==0) {
			
			for (j=0; j<nMaterias; j++) {
				
				if (strcmp(v_materias[j].Id_materias,v_matriculas[i].Id_materias)==0) {
					
					printf("\t-%s \n", v_materias[j].Nombre_materia);
					
				}
			}
			
		}
		
	}
	
}

//Postcondicón: Permite modificar las matrículas de un alumno
void modificar_matricula (int i_alumno, int nMatriculas) {
	
	int i, j;
	char res[3];
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
			printf("\n¿Desea volver a introducirlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
		
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}			
		}
		
	}while(i==nMatriculas);
		
	printf("\nIntroduzca nueva matricula:");
	fflush(stdin);
	fgets(materia, 5, stdin);
	strcpy(v_matriculas[j].Id_materias,materia);	
	
}

//Postcondicón: Permite eliminar una matrícula de un alumno
void eliminar_matricula (int i_alumno, int *nMatriculas) {
	
	int i;
	char res[3];
	char materia[5];
	
	do{
		
		printf("\nIntroduzca el id (4 digitos) de la materia de la que quiere desmatricular al alumno: ");
		fflush(stdin);
		fgets(materia, 5, stdin);
	
		for (i=0;i<*nMatriculas;i++) {
		
			if ((strcmp(materia,v_matriculas[i].Id_materias)==0)&&(strcmp(v_matriculas[i].Id_alum,v_alumnos[i_alumno].Id_alum)==0)) {
				break;
			}
		}
	
		if (i==*nMatriculas) {
			printf("\nERROR: MATRICULA no encontrada\n");
			printf("¿Desea volver a introducirla? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
		
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}
		}		
		
	}while(i==*nMatriculas);
	
	printf("\n¿Desea realizar la desmatriculacion? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		for (i=i;i<(*nMatriculas-1);i++) {
		
			strcpy(v_matriculas[i].Id_alum,v_matriculas[i+1].Id_alum);
			strcpy(v_matriculas[i].Id_materias,v_matriculas[i+1].Id_materias);
		}
		
		*nMatriculas= *nMatriculas-1;
	}		
	
}

//Postcondicón: Permite crear una nueva matrícula a un alumno
void agregar_matricula (int i_alumno, int nMaterias, int *nMatriculas) {
	
	int i, j;
	char res[3];
	char materia[5];
	
	do {
		
		printf("\nIntroduzca el ID MATERIA (4 digitos) en la que va a matricular: ");
		fflush(stdin);
		fgets(materia, 5, stdin);		
			
		for (i=0;i<nMaterias;i++) {
		
			if (strcmp(v_materias[i].Id_materias,materia)==0) {
				break;

			}
		}
		
		if (i==nMaterias) {
			
			printf("\nERROR: La MATERIA no existe\n");
			printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
				
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}				
		}		
	
	} while(i==nMaterias);	
	
	do{
		
		for (j=0;j<*nMatriculas;j++) {  //Comprueba si el alumno esta matriculado en ese momento
		
			if ((strcmp(v_materias[i].Id_materias,v_matriculas[j].Id_materias)==0)&&(strcmp(v_alumnos[i_alumno].Id_alum,v_matriculas[j].Id_alum)==0)) {
			
				printf("\nERROR: El alumno ya esta matriculado en la materia");
				printf("\n¿Desea intentarlo de nuevo? (Introduzca 'Si' para reintentar)\n");
				fflush(stdin);
				fgets(res, 3, stdin);
			
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
					return;
				}
				break;
					
			}
		}		
		
	}while((strcmp(v_materias[i].Id_materias,v_matriculas[j].Id_materias)==0)&&(strcmp(v_alumnos[i_alumno].Id_alum,v_matriculas[j].Id_alum)==0));

	
	printf("\n¿Desea crear la matricula? (1.Confirmar)\n");
	fflush(stdin);
	fgets(res,3,stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		v_matriculas= (matriculas*) realloc(v_matriculas,((*nMatriculas)+1)*sizeof(matriculas)); //Añadimos un hueco más al vector
		
		*nMatriculas= *nMatriculas+1;
		
		strcpy(v_matriculas[(*nMatriculas)-1].Id_alum,v_alumnos[i_alumno].Id_alum);
		strcpy(v_matriculas[(*nMatriculas)-1].Id_materias,materia);
				
	}

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Postcondicón: Permite modifcar la información de las materias existentes
void modificar_materias (int nMaterias) {
	
	int i, op, j;
	char res[3];
	char id[5];
	char cambio[51];
	
	do {
		
		printf("\nIntroduzca el id (4 digitos) de la materia a modificar: ");
		fflush(stdin);
		fgets(id, 5, stdin);	
		
		for (i=0;i<nMaterias;i++) {
			
			if (strcmp(id,v_materias[i].Id_materias)==0) {
				
				break;
			}
			
		}
		
		if (i==nMaterias) {
			
			printf("\nERROR: No se ha encontrado ID MATERIA");
			printf("\n¿Desea volver a introducirla? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
		
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}			
		}
		
	}while(i==nMaterias);
	
		
	do {
		
		printf("\n\tID-NOMBRE-ABREVIATURA\n");
		printf("\t%s-%s-%s\n",v_materias[i].Id_materias,v_materias[i].Nombre_materia,v_materias[i].Abrev_materia);
	
		printf("\t1.ID\n");
		printf("\t2.NOMBRE\n");
		printf("\t3.ABREVIATURA\n");
		printf("\t0.Volver a menu materias\n");		
	
		scanf("%d", &op);
					
		switch (op) {
					
			case 0:
				break;
							
			case 1:	
				
				do {
					
					printf("\nIntroduzca nuevo ID: ");
					fflush(stdin);
					fgets(cambio, 5, stdin);
					
					for (j=0;j<nMaterias;j++) {
						
						if (strcmp(v_materias[j].Id_materias,cambio)==0) {
							
							printf("\nERROR: ID en uso");
							printf("\n¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)");
							fflush(stdin);
							fgets(res, 3, stdin);
							
							if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
								return;
							}
							break;
						}
					}					
					
				}while(strcmp(v_materias[j].Id_materias,cambio)==0);

				strcpy(v_materias[i].Id_materias,cambio);
				break;
						
			case 2:
				
				do {
					
					printf("\nIntroduzca nuevo nombre: ");
					fflush(stdin);
					fgets(cambio, 51, stdin);
					
					for (j=0;j<nMaterias;j++) {
						
						if (strcmp(v_materias[j].Nombre_materia,cambio)==0) {
							
							printf("\nERROR: NOMBRE en uso");
							printf("\n¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)");
							fflush(stdin);
							fgets(res, 3, stdin);
							
							if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
								return;
							}
							break;
						}
					}					
					
				}while(strcmp(v_materias[j].Nombre_materia,cambio)==0);				

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

//Postcondicón: Permite crear nuevas materias
void agregar_materias (int *nMaterias) {
	
	int i;
	char res[3];
	char id[5];
	char nombre[51];
	char abreviatura[4];
	
	do {
		
		printf("\nIntroduzca el ID MATERIA (4 digitos): ");
		fflush(stdin);
		fgets(id, 5, stdin);		
			
		for (i=0;i<*nMaterias;i++) {
		
			if (strcmp(v_materias[i].Id_materias,id)==0) {
				printf("\nERROR: ID MATERIA en uso\n");
				printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
				fflush(stdin);
				fgets(res, 3, stdin);
				
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
					return;
				}			
				break;
			}
		}
	
	} while(strcmp(v_materias[i].Id_materias,id)==0);			
		
	do {
		
		printf("\nIntroduzca nombre (50 caracteres) de la materia: ");
		fflush(stdin);
		fgets(nombre, 51, stdin);		
			
		for (i=0;i<*nMaterias;i++) {
		
			if (strcmp(v_materias[i].Nombre_materia,nombre)==0) {
				printf("\nERROR: NOMBRE en uso\n");
				printf("¿Desea volver a intentarlo? (Introduzca 'Si para reintentar')\n");
				fflush(stdin);
				fgets(res, 3, stdin);
				
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
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
			
		for (i=0;i<*nMaterias;i++) {
		
			if (strcmp(v_materias[i].Abrev_materia,abreviatura)==0) {
				printf("\nERROR: ABREVIATURA en uso\n");
				printf("¿Desea volver a intentarlo? (Introduzca 'Si para reintentar')\n");
				fflush(stdin);
				fgets(res, 3, stdin);
				
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
					return;
				}			
				break;
			}
		}
	
	} while(strcmp(v_materias[i].Abrev_materia,abreviatura)==0);			
	
	printf("\n¿Desea crear esta materia? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		v_materias= (materias*) realloc(v_materias,((*nMaterias)+1)*sizeof(materias)); //Añadimos un hueco más al vector
		
		*nMaterias= *nMaterias+1;
		
		strcpy(v_materias[(*nMaterias)-1].Id_materias,id);
		strcpy(v_materias[(*nMaterias)-1].Nombre_materia,nombre);
		strcpy(v_materias[(*nMaterias)-1].Abrev_materia,abreviatura);
		
	}	
	
}

//Postcondicón: Permite eliminar materias existentes
void eliminar_materias (int *nMaterias) {
	
	int i;
	char res[3];
	char id[5];
	
	do{
		
		printf("\nIntroduzca el id (4 digitos) de la materia a eliminar: ");
		fflush(stdin);
		fgets(id, 5, stdin);
	
		for (i=0;i<*nMaterias;i++) {
		
			if (strcmp(id,v_materias[i].Id_materias)==0) {
				break;
			}
		}
	
		if (i==*nMaterias) {
			printf("\nERROR: MATERIA no encontrada\n");
			printf("¿Desea volver a introducirla? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
		
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}
		}		
		
	}while(i==*nMaterias);
	
	printf("\n¿Desea eliminar la materia? (1.Confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		for (i=i;i<(*nMaterias-1);i++) {
		
			strcpy(v_materias[i].Id_materias,v_materias[i+1].Id_materias);
			strcpy(v_materias[i].Nombre_materia,v_materias[i+1].Nombre_materia);
			strcpy(v_materias[i].Abrev_materia,v_materias[i+1].Abrev_materia);
			
		}
		
		*nMaterias= *nMaterias-1;
	}	

}

//Postcondicón: Lista todas las materias
void listar_materias (int nMaterias) {
	
	int i;
	printf("\n\n\tLISTA MATERIAS\n\n");
	printf("\tID-NOMBRE-ABREVIATURA\n");
	
	for (i=0;i<nMaterias;i++) {
		printf("\t%s-%s-%s\n",v_materias[i].Id_materias,v_materias[i].Nombre_materia,v_materias[i].Abrev_materia);
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Postcondicón: Lista el horario de un profesor
void listar_horarios (int nUsuarios, int nHorarios) {
	
	int i, j;
	char res[3];
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
			printf("\n¿Desea volver a introducirlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
		
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}			
		}

		
	}while(i==nHorarios);	
	
	for (j=0;j<nUsuarios;j++) {  //Busca la j_usuario del profe en el registro de Usuarios
		
		if (strcmp(id,v_usuarios[j].Id_usuario)==0) {
			break;
		}
		
	}	
	
	printf("\n\tPROFESOR: %s",v_usuarios[j].Nomb_usuario);
	printf("\n\tHORARIO: \n");
	printf("\tDIA-HORA-ID MATERIA-GRUPO\n");
	
	for (i=0;i<nHorarios;i++) {
		
		if (strcmp(v_horarios[i].Id_profesor,id)==0) {
			
			printf("\t%d-%d-%s-%s\n", v_horarios[i].Dia_clase, v_horarios[i].Hora_clase, v_horarios[i].Id_materia, v_horarios[i].Grupo);
		}
	}
	
}

//Postcondicón: Permite modificar los horarios de un profesor
void modificar_horarios (int nUsuarios, int nHorarios) {
	
	
	int i, j, c, cond, q, op; //c es para cambio de enteros y cond para guardar la condicion (1/0) para realizar el cambio
	char res[3];
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
			printf("\n¿Desea volver a introducirlo? (Introduzca 'Si' para reintentar)");
			fflush(stdin);
			fgets(res, 3, stdin);
		
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}			
		}

		
	}while(i==nHorarios);	
	
	for (j=0;j<nUsuarios;j++) {  //Busca la i_usuario del profe en el registro de Usuarios
		
		if (strcmp(id,v_usuarios[j].Id_usuario)==0) {
			break;
		}
		
	}	
	
	printf("\n\tPROFESOR: %s",v_usuarios[j].Nomb_usuario);
	
	do {
		
		printf("\n\tDIA-HORA-ID MATERIA-GRUPO\n");
	
		for (i=0;i<nHorarios;i++) {
		
			if (strcmp(v_horarios[i].Id_profesor,id)==0) {
				printf("\t%d-%d-%s-%s\n", v_horarios[i].Dia_clase, v_horarios[i].Hora_clase, v_horarios[i].Id_materia, v_horarios[i].Grupo);
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
				
				cond=auxiliar_horarios(id,nHorarios,&q);
				
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
				
				cond=auxiliar_horarios(id,nHorarios,&q);
				
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
				
				cond=auxiliar_horarios(id,nHorarios,&q);
				
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

//Postcondicón: Permite saber si el profesor imparte una materia a un grupo, devuelve 1 si es cierto, sino 0
//La función es para no escribir lo mismo varias veces
int auxiliar_horarios (char id[4], int nHorarios, int *q) {
	
	int i;
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

//Postcondicón: Permite crear un nuevo horarios a un profesor
void agregar_horarios (int *nHorarios, int nUsuarios, int nMaterias, int nAlumnos) {
	
	int i, dia, hora;
	char res[3];
	char id[4];
	char materia[5];
	char grupo[11];
	
	do {
		
		printf("\nIntroduzca ID (3 digitos) del profesor al que desea crear horario: ");
		fflush(stdin),
		fgets(id, 4, stdin);		
			
		for (i=0;i<nUsuarios;i++) {
		
			if ((strcmp(v_usuarios[i].Id_usuario,id)==0)&&(strcmp(v_usuarios[i].Perfil_usuario,"profesor")==0)) {
				break;

			}
		}
		
		if (i==nUsuarios) {
			
			printf("\nERROR: El ID del profesor no existe\n");
			printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
				
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
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
	
		for (i=0;i<*nHorarios;i++) { //Comprueba si ya tiene una clase el mismo dia y hora
		
			if ((dia==v_horarios[i].Dia_clase)&&(hora==v_horarios[i].Hora_clase)) {
				printf("\nERROR: Ya tiene una clase a esa hora el mismo dia\n");
				printf("¿Desea volver a introducir hora? (Introduzca 'Si' para reintentar)\n");
				fflush(stdin);
				fgets(res, 3, stdin);
			
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
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
			printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
				
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
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
			printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
				
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}						
			
		}
	
	} while(i==nAlumnos);
	
	printf("\n¿Desea crear el horarios? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		v_horarios= (horarios*) realloc(v_horarios,((*nHorarios)+1)*sizeof(horarios));
		
		*nHorarios = *nHorarios+1;
		
		strcpy(v_horarios[(*nHorarios)-1].Id_profesor,id);
		v_horarios[(*nHorarios)-1].Dia_clase=dia;
		v_horarios[(*nHorarios)-1].Hora_clase=hora;
		strcpy(v_horarios[(*nHorarios)-1].Id_materia,materia);
		strcpy(v_horarios[(*nHorarios)-1].Grupo,grupo);
		
	}	

}

//Postcondicón: Permite eliminar un horarios existente de un profesor
void eliminar_horarios (int *nHorarios, int nUsuarios) {
	
	int i, dia, hora;
	char res[3];
	char id[4];
	char grupo[11];
		
	do{
		
		printf("\nIntroduzca ID (3 digitos) del profesor al que desea eliminar horario: ");
		fflush(stdin),
		fgets(id, 4, stdin);
	
		for (i=0;i<nUsuarios;i++) {
		
			if ((strcmp(id,v_usuarios[i].Id_usuario)==0)&&(strcmp(v_usuarios[i].Perfil_usuario,"profesor")==0)) {
				break;
			}
		}
	
		if (i==nUsuarios) {
			printf("\nERROR: ID de profesor no encontrado\n");
			printf("¿Desea volver a introducirlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
		
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}
		}		
		
	}while(i==nUsuarios);
	
	do {
		
		printf("\nIntroduzca el grupo (10 caracteres maximo) que quiere eliminar: ");
		fflush(stdin);
		fgets(grupo, 11, stdin);
		
		printf("\nIntroduzca la hora (1-6) del grupo que quiere eliminar: ");
		scanf("%d", &hora);
		
		printf("\nIntroduzca el dia (1-5) del grupo que quiere eliminar: ");
		scanf("%d", &dia);				
		
		for (i=0;i<*nHorarios;i++) {
			
			if ((strcmp(id,v_horarios[i].Id_profesor)==0)&&(strcmp(v_horarios[i].Grupo,grupo)==0)&&(v_horarios[i].Hora_clase==hora)&&(v_horarios[i].Dia_clase==dia)){
					
				break;
			}
		}
		
		if (i==*nHorarios) {
			
			printf("\nERROR: Algun dato no se corresponde al grupo/profesor");
			printf("\n¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
			
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}
		}
		
	}while(i==*nHorarios);
	
	printf("\n¿Desea eliminar el horario del profesor? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		for (i=i;i<(*nHorarios-1);i++) {
		
			strcpy(v_horarios[i].Id_profesor,v_horarios[i+1].Id_profesor);
			strcpy(v_horarios[i].Id_materia,v_horarios[i+1].Id_materia);
			strcpy(v_horarios[i].Grupo,v_horarios[i+1].Grupo);
			v_horarios[i].Dia_clase=v_horarios[i+1].Dia_clase;
			v_horarios[i].Hora_clase=v_horarios[i+1].Hora_clase;

		}
		
		*nHorarios= *nHorarios-1;
	}	
	
}
