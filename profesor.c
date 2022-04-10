#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "datos.h"
#include "carga.h"
#include "admin.h"

void list_hor_profe (int i_profe, int nHorarios) {
	
	int i, j;
	
	printf("\nHORARIO: ");
	printf("\nDIA-HORA-MATERIA-GRUPO\n");
	
	for (i=0;i<nHorarios;i++) {
		
		if (strcmp(v_horarios[i].Id_profesor, v_usuarios[i_profe].Id_usuario)==0) {
			
			for (j=0;j<nMaterias;j++) {
				
				if (strcmp(v_materias[j].Id_materias, v_horarios[i].Id_materia)==0) {
					break;
				}
			}
			
			printf("%d-%d-%s-%s\n", v_horarios[i].Dia_clase, v_horarios[i].Hora_clase, v_materias[j].Abrev_materia, v_horarios[i].Grupo);
		}
	}	
	
}

void gestor_alumnos (int i_grupo, int nAlumnos) {
	
	int i, res, op;
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
	
			if (strcmp(v_alumnos[i].Id_alum,id)!=0) {
			
				printf("\nERROR: El ID no se corresponde con ningun alumno\n");
				printf("¿Desea volver a intentarlo? (1.Seguir)\n");
				scanf("%d", &res);
				
				if (res!=1) {
					return;
				}
		
			}			
			
		}while(strcmp(v_alumnos[i].Id_alum,id)!=0);
		
	
		do{
			
			printf("\t1.Ficha del alumno\n");
			printf("\t2.Calificaciones\n");
			printf("\t0.Volver al menu de seleccion de alumno\n");
			printf("\t3.Volver al menu de seleccion de grupo\n");
		
			scanf("%d", &op);
		
			switch (op) {
			
				case 0:
					break;
				
				case 1:	
					ficha_alumno (id, nAlumnos);
					break;
				
				case 2:
					calificaciones (id, i_grupo, nAlumnos, nCalificaciones);
					break;
					
				case 3:
					return;	
						
			}
		
		}while(op!=0);
		
	}while(op==0);
	
}

void ficha_alumno (char id[], int nAlumnos) {
	
	int i, op;
	char cambio[31];
	
	for (i=0;i<nAlumnos;i++) {
		
		if (strcmp(v_alumnos[i].Id_alum,id)==0) {
			break;
		}
	}
		
	do {
			
		printf("\nID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO\n");
		printf("%s-%s-%s-%s-%s-%s\n",v_alumnos[i].Id_alum,v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum,v_alumnos[i].Local_alum,v_alumnos[i].Curso,v_alumnos[i].Grupo);
			
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
							
		}
					
	}while(op!=0);
				
	
}

void calificaciones (char id[], int i_grupo, int nAlumnos, int nCalificaciones) {
	
	int op;
	
	do {
		
		printf("\n\nCALIFICACIONES\n\n");
		
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

void listar_calificaciones (char id[], int i_grupo, int nCalificaciones) {
	
	int i;
	
	printf("\nCALIFICACIONES: ");
		
	for (i=0;i<nCalificaciones;i++) {
			
		if ((strcmp(v_calificaciones[i].Id_materia,v_horarios[i_grupo].Id_materia)==0)&&(strcmp(v_calificaciones[i].Id_alum,id)==0)) {
				
			printf("\nFECHA-DESCRIPCION-ID MATERIA-ID ALUMNO-CALIFICACION\n");
			printf("%s-%s-%s-%s-%d\n", v_calificaciones[i].Fecha_calif, v_calificaciones[i].Descrip_calif, v_calificaciones[i].Id_materia, v_calificaciones[i].Id_alum, v_calificaciones[i].Valor_calif);
		}
	}	
	
}

void modificar_calificaciones (char id[], int i_grupo, int nCalificaciones) {
	
	int i, op, res, c;
	char cambio[31];
	char descripcion[31];
	
	do {
		
		for (i=0;i<nCalificaciones;i++) {
		
			if ((strcmp(v_calificaciones[i].Id_materia,v_horarios[i_grupo].Id_materia)==0)&&(strcmp(v_calificaciones[i].Id_alum,id)==0)) {
			
				printf("\nFECHA-DESCRIPCION-ID MATERIA-ID ALUMNO-CALIFICACION\n");
				printf("%s-%s-%s-%s-%d\n", v_calificaciones[i].Fecha_calif, v_calificaciones[i].Descrip_calif, v_calificaciones[i].Id_materia, v_calificaciones[i].Id_alum, v_calificaciones[i].Valor_calif);
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
				printf("¿Desea volver a intentarlo? (1.Seguir)\n");
				
				scanf("%d", &res);
				
				if (res!=1) {
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
						scanf("%d", &c);							
					}while((c<0)||(c>10));

					v_calificaciones[i].Valor_calif=c;
					break;		
			}
			
		}while((op!=0)&&(op!=4));
	
		
	}while(op==4);

}

void agregar_calificaciones (char id[], int i_grupo, int *nCalificaciones) {
	
	char fecha[11];
	char descripcion[31];
	int nota, res;
	
	printf("\nIntroduzca la FECHA de la calificacion (xx/yy/zzzz):");
	fflush(stdin);
	fgets(fecha, 11, stdin);
	
	printf("\nIntroduzca la DESCRIPCION (31 caracteres): ");
	fflush(stdin),
	fgets(descripcion, 31, stdin);
	
	do {
		
		printf("\nIntroduzca la CALIFICACION (0-10): ");
		scanf("%d", &nota);
		
		if((nota<0)||(nota>10)) {
			printf("\nERROR: La nota debe estar comprendida entre 0 y 10");
		}
		
	}while((nota<0)||(nota>10));
	
	printf("\n¿Desea crear la calificacion? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_calificaciones= (calificaciones*) realloc(v_calificaciones,(nCalificaciones+1)*sizeof(calificaciones); //Añadimos un hueco más al vector
		
		*nCalificaciones= *nCalificaciones+1;
		
		strcpy(v_calificaciones[nCalificaciones-1].Fecha_calif, fecha);
		strcpy(v_calificaciones[nCalificaciones-1].Descrip_calif, descripcion);
		strcpy(v_calificaciones[nCalificaciones-1].Id_materia, v_horarios[i_grupo].Id_materia);
		strcpy(v_calificaciones[nCalificaciones-1].Id_alum, id);
		v_calificaciones[nCalificaciones-1].Valor_calif=nota;
	}
	
	
}

void eliminar_calificaciones (int *nCalificaciones) {
	
	int i, res;
	char descripcion[31];
	
	do {
		
		printf("\nIntroduzca la DESCRIPCION (30 caracteres) de la calificacion que desea eliminar");;
		fflush(stdin);
		fgets(descripcion, 31, stdin);
	
		for (i=0;i<nCalificaciones;i++) {
		
			if(strcmp(v_calificaciones[i].Descrip_calif,descripcion)==0) {
				break;
			}
		}
		
		if(i==nCalificaciones) {
			
			printf("\nERROR: La DESCRIPCION introducida no existe\n");
			printf("¿Desea volver a introducirla? (1.Seguir)\n");
			scanf("%d", &res);
			
			if (res!=1) {
				return;
			}
		}
		
	}while(i==nCalificaciones);
	
	printf("\n¿Desea eliminar la calificacion? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		for (i=i;i<(nCalificaciones-1);i++) {
			
			strcpy(v_calificaciones[i].Fecha_calif, v_calificaciones[i+1].Fecha_calif)
			strcpy(v_calificaciones[i].Descrip_calif, v_calificaciones[i+1].Descrip_calif)
			strcpy(v_calificaciones[i].Id_materia, v_calificaciones[i+1].Id_materia)
			strcpy(v_calificaciones[i].Id_alum, v_calificaciones[i+1].Id_alum)
			v_calificaciones[i].Valor_calif=v_calificaciones[i+1].Valor_calif;
		}
		
		*nCalificaciones= *nCalificaciones-1;		
	}
		
}
