#include "profesor.h"

//Postcondición: Lista el horarios del profesor 
void list_hor_profe (int i_profe, int nHorarios, int nMaterias) {
	
	int i, j;
	
	printf("\n\tHORARIO: ");
	printf("\n\tDIA-HORA-MATERIA-GRUPO\n");
	
	for (i=0;i<nHorarios;i++) {
		
		if (strcmp(v_horarios[i].Id_profesor, v_usuarios[i_profe].Id_usuario)==0) {
			
			for (j=0;j<nMaterias;j++) {
				
				if (strcmp(v_materias[j].Id_materias, v_horarios[i].Id_materia)==0) {
					printf("\t%d-%d-%s-%s\n", v_horarios[i].Dia_clase, v_horarios[i].Hora_clase, v_materias[j].Abrev_materia, v_horarios[i].Grupo);
				}
			}
			
		}
	}	
	
}

//Postcondición: Lista todos los alumnos del grupo recibido y permite elegir con el que quiere trabajar
void gestor_alumnos (int i_grupo, int nAlumnos) {
	
	int i, op;
	char res[3];
	char id[7];
	
	do {
		
		for (i=0;i<nAlumnos;i++) { //Lista los alumnos del grupo

			if (strcmp(v_alumnos[i].Grupo, v_horarios[i_grupo].Grupo)==0) {
				printf("\nAlumno:%s ID:%s", v_alumnos[i].Nombre_alum, v_alumnos[i].Id_alum);
			}
		}
		
		do{
			
			printf("\nIntroduzca el ID del alumno con el que desee trabajar: ");
			fflush(stdin),
			fgets(id, 7, stdin);
			
			for (i=0;i<nAlumnos;i++) {
				
				if (strcmp(v_alumnos[i].Id_alum,id)==0) {
					break;
				}
			}
			
			if (i==nAlumnos) {
			
				printf("\nERROR: El ID no se corresponde con ningun alumno\n");
				printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
				fflush(stdin);
				fgets(res, 3, stdin);
				
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
					return;
				}
		
			}			
			
		}while(i==nAlumnos);
		
	
		do{
			
			printf("\n\t1.Ficha del alumno\n");
			printf("\t2.Calificaciones\n");
			printf("\t0.Volver al menu de seleccion de alumno\n");
			printf("\t3.Volver al menu de seleccion de grupo\n");
		
			switch (op) {
			
				case 0:
					break;
				
				case 1:	
					ficha_alumno (id, nAlumnos);
					break;
				
				case 2:
					menu_calificaciones (id, i_grupo, nAlumnos, nCalificaciones);
					break;
					
				case 3:
					return;	
						
			}
		
		}while(op!=0);
		
	}while(op==0);
	
}


//Postcondición: Permite modificar la información personal del alumno
void ficha_alumno (char id[], int nAlumnos) {
	
	int i, op, j;
	char res[3];
	char cambio[31];
	
	for (i=0;i<nAlumnos;i++) {
		
		if (strcmp(v_alumnos[i].Id_alum,id)==0) {
			break;
		}
	}
		
	do {
			
		printf("\n\tID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO\n");
		printf("\t%s-%s-%s-%s-%s-%s\n",v_alumnos[i].Id_alum,v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum,v_alumnos[i].Local_alum,v_alumnos[i].Curso,v_alumnos[i].Grupo);
			
		printf("\t1.ID\n");
		printf("\t2.NOMBRE\n");
		printf("\t3.DIRECCION\n");
		printf("\t4.LOCALIDAD\n");
		printf("\t5.CURSO\n");
		printf("\t6.GRUPO\n");
		printf("\t0.Volver a menu del alumno\n");
	
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
							
		}
					
	}while(op!=0);
				
	
}

//Postcondición: Accede al menú de calificaciones de alumno
void menu_calificaciones (char id[], int i_grupo, int nAlumnos, int nCalificaciones) {
	
	int op;
	
	do {
		
		printf("\n\n\tCALIFICACIONES\n\n");
		
		printf("\t1.Agregar calificaciones\n");
		printf("\t2.Eliminar calificaciones\n");
		printf("\t3.Modificar calificaciones\n");
		printf("\t4.Listar calificaciones\n");
		printf("\t0.Volver a menu del alumno\n");
		
		scanf("%d", &op);
		
		switch (op) {
			
			case 0:
				break;
				
			case 1:
				agregar_calificaciones (id, i_grupo, &nCalificaciones);
				break;
			
			case 2:
				eliminar_calificaciones (&nCalificaciones);
				break;
				
			case 3:
				modificar_calificaciones (id, i_grupo, nCalificaciones);
				break;	
			
			case 4:
				listar_calificaciones (id, i_grupo, nCalificaciones);
				break;		
		}
		
		
	}while(op!=0);
	
}


//Postcondición: Lista las calificaciones del alumno
void listar_calificaciones (char id[], int i_grupo, int nCalificaciones) {
	
	int i;
	
	printf("\n\tCALIFICACIONES: ");
		
	for (i=0;i<nCalificaciones;i++) {
			
		if ((strcmp(v_calificaciones[i].Id_materia,v_horarios[i_grupo].Id_materia)==0)&&(strcmp(v_calificaciones[i].Id_alum,id)==0)) {
				
			printf("\n\tFECHA-DESCRIPCION-ID MATERIA-ID ALUMNO-CALIFICACION\n");
			printf("\t%s-%s-%s-%s-%s\n", v_calificaciones[i].Fecha_calif, v_calificaciones[i].Descrip_calif, v_calificaciones[i].Id_materia, v_calificaciones[i].Id_alum, v_calificaciones[i].Valor_calif);
		}
	}	
	
}

//Postcondición: Permite modificar las calificaciones del alumno
void modificar_calificaciones (char id[], int i_grupo, int nCalificaciones) {
	
	int i, op;
	char res[3];
	char cambio[31];
	char descripcion[31];
	
	do {
		
		for (i=0;i<nCalificaciones;i++) {
		
			if ((strcmp(v_calificaciones[i].Id_materia,v_horarios[i_grupo].Id_materia)==0)&&(strcmp(v_calificaciones[i].Id_alum,id)==0)) {
			
				printf("\n\tFECHA-DESCRIPCION-ID MATERIA-ID ALUMNO-CALIFICACION\n");
				printf("\t%s-%s-%s-%s-%d\n", v_calificaciones[i].Fecha_calif, v_calificaciones[i].Descrip_calif, v_calificaciones[i].Id_materia, v_calificaciones[i].Id_alum, v_calificaciones[i].Valor_calif);
			}
		}
		
		do {
			
			printf("\nIntroduzca la descripcion (30 caracteres) de la calificacion que desea modificar: ");
			fflush(stdin);
			fgets(descripcion, 31, stdin);
			
			for (i=0;i<nCalificaciones;i++) {
				
				if (strcmp(v_calificaciones[i].Descrip_calif,descripcion)==0) {
					break;
				}
			}
			
			if (i==nCalificaciones) {
				
				printf("\nERROR: DESCRIPCION no encontrada\n");
				printf("¿Desea volver a intentarlo? (Introduzca 'Si' para reintentar)\n");
				fflush(stdin);
				fgets(res, 3, stdin);
				
				if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
					return;
				}
			}
			
		}while(i==nCalificaciones);
		
		do {
			
			printf("\t1.FECHA\n");
			printf("\t2.DESCRIPCION\n");
			printf("\t3.CALIFICACION\n");
			printf("\t0.Volver a menu de calificaciones\n");
			printf("\t4.Volver a elegir calificacion\n");
		
			scanf("%d", &op);
		
			switch (op) {
			
				case 0:
					break;
					
				case 1:
					printf("\nIntroduzca nueva fecha (xx/yy/zzzz): ");
					fflush(stdin);
					fgets(cambio, 11, stdin);
					strcpy(v_calificaciones[i].Fecha_calif, cambio);
					break;
				
				case 2:
					printf("\nIntroduzca nueva descripcion (30 caracteres): ");
					fflush(stdin);
					fgets(cambio, 31, stdin);
					strcpy(v_calificaciones[i].Descrip_calif, cambio);
					break;
				
				case 3:
					do {
						printf("\nIntroduzca nueva calificacion (0-10): ");
						fflush(stdin);
						fgets(cambio, 2, stdin);
													
					}while((strcmp(cambio,"0")!=0)&&(strcmp(cambio,"1")!=0)&&(strcmp(cambio,"2")!=0)&&(strcmp(cambio,"3")!=0)&&(strcmp(cambio,"4")!=0)&&(strcmp(cambio,"5")!=0)&&(strcmp(cambio,"6")!=0)&&(strcmp(cambio,"7")!=0)&&(strcmp(cambio,"8")!=0)&&(strcmp(cambio,"9")!=0)&&(strcmp(cambio,"10")!=0));

					strcpy(v_calificaciones[i].Valor_calif, cambio);
					break;		
			}
			
		}while((op!=0)&&(op!=4));
	
		
	}while(op==4);

}


//POstcondición: Permite añadir nuevas calificaciones a un alumno
void agregar_calificaciones (char id[], int i_grupo, int *nCalificaciones) {
	
	char res[3];
	char fecha[11];
	char descripcion[31];
	char nota[2];
	
	printf("\nIntroduzca la FECHA de la calificacion (xx/yy/zzzz):");
	fflush(stdin);
	fgets(fecha, 11, stdin);
	
	printf("\nIntroduzca la DESCRIPCION (30 caracteres maximo): ");
	fflush(stdin),
	fgets(descripcion, 31, stdin);
	
	do {
		
		printf("\nIntroduzca la CALIFICACION (0-10): ");
		fflush(stdin);
		fgets(nota, 2, stdin);
		
		if((strcmp(nota,"0")!=0)&&(strcmp(nota,"1")!=0)&&(strcmp(nota,"2")!=0)&&(strcmp(nota,"3")!=0)&&(strcmp(nota,"4")!=0)&&(strcmp(nota,"5")!=0)&&(strcmp(nota,"6")!=0)&&(strcmp(nota,"7")!=0)&&(strcmp(nota,"8")!=0)&&(strcmp(nota,"9")!=0)&&(strcmp(nota,"10")!=0)) {
			printf("\nERROR: La nota debe estar comprendida entre 0 y 10");
		}
		
	}while((strcmp(nota,"0")!=0)&&(strcmp(nota,"1")!=0)&&(strcmp(nota,"2")!=0)&&(strcmp(nota,"3")!=0)&&(strcmp(nota,"4")!=0)&&(strcmp(nota,"5")!=0)&&(strcmp(nota,"6")!=0)&&(strcmp(nota,"7")!=0)&&(strcmp(nota,"8")!=0)&&(strcmp(nota,"9")!=0)&&(strcmp(nota,"10")!=0));
	
	printf("\n¿Desea crear la calificacion? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		v_calificaciones= (calificaciones*) realloc(v_calificaciones,((*nCalificaciones)+1)*sizeof(calificaciones)); //Añadimos un hueco más al vector
		
		*nCalificaciones= *nCalificaciones+1;
		
		strcpy(v_calificaciones[(*nCalificaciones)-1].Fecha_calif, fecha);
		strcpy(v_calificaciones[(*nCalificaciones)-1].Descrip_calif, descripcion);
		strcpy(v_calificaciones[(*nCalificaciones)-1].Id_materia, v_horarios[i_grupo].Id_materia);
		strcpy(v_calificaciones[(*nCalificaciones)-1].Id_alum, id);
		strcpy(v_calificaciones[(*nCalificaciones)-1].Valor_calif,nota);
	}
	
	
}


//Postcondición: Permite eliminar una calificación de un alumno
void eliminar_calificaciones (int *nCalificaciones) {
	
	int i;
	char res[3];
	char descripcion[31];
	
	do {
		
		printf("\nIntroduzca la DESCRIPCION (30 caracteres) de la calificacion que desea eliminar");;
		fflush(stdin);
		fgets(descripcion, 31, stdin);
	
		for (i=0;i<(*nCalificaciones);i++) {
		
			if(strcmp(v_calificaciones[i].Descrip_calif,descripcion)==0) {
				break;
			}
		}
		
		if(i==(*nCalificaciones)) {
			
			printf("\nERROR: La DESCRIPCION introducida no existe\n");
			printf("¿Desea volver a introducirla? (Introduzca 'Si' para reintentar)\n");
			fflush(stdin);
			fgets(res, 3, stdin);
			
			if ((strcmp(res,"si")!=0)&&(strcmp(res,"SI")!=0)&&(strcmp(res,"Si")!=0)&&(strcmp(res,"sI")!=0)) {
				return;
			}
		}
		
	}while(i==(*nCalificaciones));
	
	printf("\n¿Desea eliminar la calificacion? (Introduzca 'Si' para confirmar)\n");
	fflush(stdin);
	fgets(res, 3, stdin);
	
	if ((strcmp(res,"si")==0)||(strcmp(res,"SI")==0)||(strcmp(res,"Si")==0)||(strcmp(res,"sI")==0)) {
		
		for (i=i;i<(*nCalificaciones-1);i++) {
			
			strcpy(v_calificaciones[i].Fecha_calif, v_calificaciones[i+1].Fecha_calif);
			strcpy(v_calificaciones[i].Descrip_calif, v_calificaciones[i+1].Descrip_calif);
			strcpy(v_calificaciones[i].Id_materia, v_calificaciones[i+1].Id_materia);
			strcpy(v_calificaciones[i].Id_alum, v_calificaciones[i+1].Id_alum);
			strcpy(v_calificaciones[i].Valor_calif,v_calificaciones[i+1].Valor_calif);
		}
		
		*nCalificaciones= *nCalificaciones-1;		
	}
		
}
