#include <stdio.h>
#include <stdlib.h>

#include "carga.h"
#include "datos.h"
#include "admin.h"

void listar_usuarios (int nUsuarios) {  

	int i;
	printf("\n\nLISTA USUARIOS\n\n");
	printf("ID-NOMBRE-PERFIL-USUARIO-CONTRASENA");
	
	for (i=0;i<nUsuarios;i++) {
		printf("%s-%s-%s-%s-%s",v_usuarios[i].Id_usuario,v_usuarios[i].Nomb_usuario,v_usuarios[i].Perfil_usuario,v_usuarios[i].Usuario,v_usuarios[i].Contrasena);
	}
}

void modificar_usuarios (int nUsuarios) {
	
	int i, op;
	char login[6];
	char cambio[21];
	
	do {
		
		printf("\nIntroduzca un usuario (login) a modificar: ");
		fflush(stdin);
		fgets(login, 6, stdin);	
		
		for (i=0;i<nUsuarios;i++) {
			
			if (login==v_usuarios[i].Usuario) {
				
				goto MODIFICA;
			}
			
		}
		
		printf("\nERROR: No se ha encontrado usuario");
		
		printf("¿Desea continuar? (Pulse 1 para seguir)");
		scanf("%d", &res);
		
		if (res!=1) {
			goto FIN;
		}
		
	}while(v_usuarios[i].Usuario!=login);
	
	MODIFICA:
		
		printf("ID-NOMBRE-PERFIL-USUARIO-CONTRASENA\n");
		printf("%s-%s-%s-%s-%s",v_usuarios[i].Id_usuario,v_usuarios[i].Nomb_usuario,v_usuarios[i].Perfil_usuario,v_usuarios[i].Usuario,v_usuarios[i].Contrasena);

		printf("\t1.ID\n");
		printf("\t2.NOMBRE\n");
		printf("\t3.PERFIL\n");
		printf("\t4.USUARIO\n");
		printf("\t5.CONTRASENA\n");
		printf("\t0.Volver a menu usuario\n");
		
		do {
	
			scanf("%d", &op);
					
			switch (op) {
						
				case 0:
					break;
							
				case 1:	
					
					printf("Introduzca nuevo ID: ");
					fflush(stdin);
					fgets(cambio, 4, stdin);
					v_usuarios[i].Id_usuario=cambio;
					
					goto MODIFICA;
						
				case 2:
					printf("Introduzca nuevo nombre: ");
					fflush(stdin);
					fgets(cambio, 21, stdin);
					v_usuarios[i].Nomb_usuario=cambio;
					
					goto MODIFICA;
								
				case 3:	
					if (v_usuarios[i].Perfil_usuario=='administrador') {
						
						printf("¿Desea cambiar el perfil a profesor? (Pulse 1 para confirmar)");
						scanf("%d", &res);
						
						if (res==1) {
							v_usuarios[i].Perfil_usuario='profesor';
						}
						
					} else {
						
						printf("¿Desea cambiar el perfil a administrador? (Pulse 1 para confirmar)");
						scanf("%d", &res);
						
						if (res==1) {
							v_usuarios[i].Perfil_usuario='administrador';
						}												
					}
					
					goto MODIFICA;
						
				case 4:
					printf("Introduzca nuevo usuario (login): ");
					fflush(stdin);
					fgets(cambio, 6, stdin);
					v_usuarios[i].Usuario=cambio;
					
					goto MODIFICA;
					
				case 5:
					printf("Introduzca nueva contrasena: ");
					fflush(stdin);
					fgets(cambio, 9, stdin);
					v_usuarios[i].Contrasena=cambio;
										
					goto MODIFICA;	
			}
					
		}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3)&&(n!=4)&&(n!=5));
		
		FIN:
}

void agregar_usuarios (int *nUsuarios) {
	
	int i, res;
	char id[4];
	char nombre[21];
	char perfil[15];
	char login[6];
	char contrasena[9];
	
	ID:
			
	printf("Introduzca id (3 digitos) del usuario: ");
	fflush(stdin);
	fgets(id, 4, stdin);		
			
	for (i=0;i<nUsuarios;i++) {
		
		if (v_usuarios[i].Id_usuario==id) {
			printf("\nERROR: ID en uso\n");
			goto ID;
		}
	}
	
	NOMBRE:
			
	printf("Introduzca nombre (20 caracteres) del usuario: ");
	fflush(stdin);
	fgets(nombre, 21, stdin);		
			
	for (i=0;i<nUsuarios;i++) {
		
		if (v_usuarios[i].Nomb_usuario==nombre) {
			printf("\nERROR: NOMBRE en uso\n");
			goto NOMBRE;
		}
	}
			
	printf("\nIntroduzca perfil del usuario: ");		
	printf("\tPulse 1 para administrador\n");
	printf("\tPulse cualquier otro para profesor\n");
	
	scanf("%d", &res);
	
	if (res==1) {
		perfil='administrador';
	} else {
		perfil='profesor';
	}
	
	USUARIO:
			
	printf("Introduzca usuario (5 caracteres): ");
	fflush(stdin);
	fgets(usuario, 6, stdin);		
			
	for (i=0;i<nUsuarios;i++) {
		
		if (v_usuarios[i].Usuario==usuario) {
			printf("\nERROR: USUARIO en uso\n");
			goto USUARIO;
		}
	}
	
	printf("Introduzca contrasena (8 caracteres): ");
	fflush(stdin);
	fgets(contrasena, 9, stdin);	
	
	printf("¿Desea crear este usuario? \n(1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_usuarios= (usuarios*) realloc(v_usuarios,(nUsuarios+1)*sizeof(usuarios)); //Añadimos un hueco más al vector
		
		*nUsuarios= *nUsuarios+1;
		
		v_usuarios[nUsuarios-1].Id_usuario=id;
		v_usuarios[nUsuarios-1].Nomb_usuario=nombre;
		v_usuarios[nUsuarios-1].Perfil_usuario=perfil;
		v_usuarios[nUsuarios-1].Usuario=usuario;
		v_usuarios[nUsuarios-1].Contrasena=contrasena;
		
	}
	
} 

void eliminar_usuarios (int *nUsuarios) {
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listar_alumnos (int nAlumnos) { 
	
	int i;
	printf("\n\nLISTA ALUMNOS\n\n");
	printf("ID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO");
	
	for (i=0;i<nAlumnos;i++) {
		printf("%s-%s-%s-%s-%s-%s",v_alumnos[i].Id_alum,v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum,v_alumnos[i].Local_alum,v_alumnos[i].Curso,v_alumnos[i].Grupo);
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
			
			if (id==v_alumnos[i].Id_alum) {
				
				goto MODIFICA;
			}
			
		}
		
		printf("\nERROR: No se ha encontrado alumno");
		
		printf("¿Desea continuar? (Pulse 1 para seguir)");
		scanf("%d", &res);
		
		if (res!=1) {
			goto FIN;
		}
		
	}while(v_alumnos[i].Id_alum!=id);
	
	MODIFICA:
		
		printf("ID-NOMBRE-DIRECCION-LOCALIDAD-CURSO-GRUPO");
		printf("%s-%s-%s-%s-%s-%s",v_alumnos[i].Id_alum,v_alumnos[i].Nombre_alum,v_alumnos[i].Direc_alum,v_alumnos[i].Local_alum,v_alumnos[i].Curso,v_alumnos[i].Grupo);

		printf("\t1.ID\n");
		printf("\t2.NOMBRE\n");
		printf("\t3.DIRECCION\n");
		printf("\t4.LOCALIDAD\n");
		printf("\t5.CURSO\n");
		printf("\t6.GRUPO\n");
		printf("\t7.MATRICULAS\n");
		printf("\t0.Volver a menu alumnos\n");
		
		do {
	
			scanf("%d", &op);
					
			switch (op) {
						
				case 0:
					break;
							
				case 1:	
					
					printf("Introduzca nuevo ID: ");
					fflush(stdin);
					fgets(cambio, 7, stdin);
					v_alumnos[i].Id_alum=cambio;
					
					goto MODIFICA;
						
				case 2:
					printf("Introduzca nuevo nombre: ");
					fflush(stdin);
					fgets(cambio, 21, stdin);
					v_alumnos[i].Nombre_alum=cambio;
					
					goto MODIFICA;
								
				case 3:	
					printf("Introduzca nueva direccion: ");
					fflush(stdin);
					fgets(cambio, 31, stdin);
					v_alumnos[i].Direc_alum=cambio;
					
					goto MODIFICA;
						
				case 4:
					printf("Introduzca nueva localidad: ");
					fflush(stdin);
					fgets(cambio, 31, stdin);
					v_alumnos[i].Local_alum=cambio;
					
					goto MODIFICA;
					
				case 5:
					printf("Introduzca nuevo curso: ");
					fflush(stdin);
					fgets(cambio, 31, stdin);
					v_alumnos[i].Curso=cambio;
										
					goto MODIFICA;	
					
				case 6:
					printf("Introduzca nuevo grupo: ");
					fflush(stdin);
					fgets(cambio, 11, stdin);
					v_alumnos[i].Grupo=cambio;
										
					goto MODIFICA;
					
				case 7:
					MATRICULAS:
						
					printf("\n\nMATRICULAS\n\n")
					materias_matriculado (i,nMatriculas,nMaterias);
					
					do {
						
						printf("\t1.Agregar matricula\n");
						printf("\t2.Eliminar matricula\n");
						printf("\t3.Modificar matricula\n");
						printf("\t0.Volver al menu alumnos\n");
						
						scanf("%d", &op);
						
						switch (op) {
							
							case 0:
								goto ALUMNOS;
								
							case 1:
								agregar_matricula (i);
								goto MATRICULAS;
								
							case 2:
								eliminar_matricula (i);
								goto MATRICULAS;
								
							case 3:
								modificar_matricula (i);
								goto MATRICULAS;																
						}
						
					}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3));
							
			}
					
		}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3)&&(n!=4)&&(n!=5)&&(n!=6)&&(n!=7));
		
		FIN:		
	
	
}

void agregar_alumnos (int *nAlumnos) {
	
	int i, res;
	char id[7];
	char nombre[21];
	char direccion[31];
	char localidad[31];
	char curso[31];
	char grupo[11];
	
	ID:
			
	printf("Introduzca id (6 digitos) del alumno: ");
	fflush(stdin);
	fgets(id, 7, stdin);		
			
	for (i=0;i<nAlumnos;i++) {
		
		if (v_alumnos[i].Id_alum==id) {
			printf("\nERROR: ID en uso\n");
			goto ID;
		}
	}
			
	printf("Introduzca nombre (20 caracteres) del alumno: ");
	fflush(stdin);
	fgets(nombre, 21, stdin);		
			
	printf("Introduzca direccion (30 caracteres) del alumno: ");
	fflush(stdin);
	fgets(direccion, 31, stdin);
	
	printf("Introduzca localidad (30 caracteres) del alumno: ");
	fflush(stdin);
	fgets(localidad, 31, stdin);
	
	printf("Introduzca curso (30 caracteres) del alumno: ");
	fflush(stdin);
	fgets(curso, 31, stdin);
	
	printf("Introduzca grupo (10 caracteres) del alumno: ");
	fflush(stdin);
	fgets(grupo, 11, stdin);	
	
	printf("¿Desea crear este alumno? \n(1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_alumnos= (alumnos*) realloc(v_alumnos,(nAlumnos+1)*sizeof(alumnos)); //Añadimos un hueco más al vector
		
		*nAlumnos= *nAlumnos+1;
		
		v_alumnos[nAlumnos-1].Id_alum=id;
		v_alumnos[nAlumnos-1].Nombre_alum=nombre;
		v_alumnos[nAlumnos-1].Direc_alum=direccion;
		v_alumnos[nAlumnos-1].Local_alum=localidad;
		v_alumnos[nAlumnos-1].Curso=curso;
		v_alumnos[nAlumnos-1].Grupo=grupo;
		
	}	
	
}

void eliminar_alumnos (int *nAlumnos) {
	
}


void materias_matriculado (int i_alumno, int nMatriculas, int nMaterias) {
	
	int i, j;
	char materia[5];
	
	printf("ALUMNO: %s\n",v_alumnos[i_alumno].Nombre_alum);
	printf("MATRICULADO EN: \n");
	
	for (i=0; i<nMatriculas; i++) {
		
		if (v_alumnos[i_alumno].Id_alum==v_matriculas[i].Id_alum) {
			
			materia=v_matriculas[i].Id_materias;
			
			for (j=0; j<nMaterias; j++) {
				
				if (v_materias[j].Id_materias==materia) {
					
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
		
		printf("Introduzca id (4 digitos) de la matricula que desea modificar");
		fflush(stdin);
		fgets(materia, 5, stdin);
		
		for (i=0;i<nMatriculas;i++) {
			
			if (v_alumnos[i_alumno].Id_alum==v_matriculas[i].Id_alum) {
				
				for (j=0;j<nMatriculas;j++) {
					 
					 if (v_matriculas[j].Id_materias==materia) {
					 	
					 	goto MODIFICA;
					 }
				}
			}
			
		}
		
		printf("\nERROR: No se ha encontrado materia");
		
		printf("¿Desea continuar? (Pulse 1 para seguir)");
		scanf("%d", &res);
		
		if (res!=1) {
			goto FIN;
		}		
		
		
	}while(v_matriculas[j].Id_materias!=materia);
	
	MODIFICA:
		
		printf("Introduzca nueva matricula:");
		fflush(stdin);
		fgets(materia, 5, stdin);
		v_matriculas[j].Id_materias=materia;
		
	FIN:	
	
}

void eliminar_matricula (int i_alumno, int *nMatriculas) {
	
}

void agregar_matricula (int i_alumno, int nMaterias, int *nMatriculas) {
	
	int i, j, res;
	char materia[5];
	
	SEGUIR:
		
	printf("Introduzca la materia (4 digitos) en la que va a matricular: ");
	fflsuh(stdin);
	fgets(materia, 5, stdin);
	
	for (i=0;i<nMaterias;i++) { //Comprueba si la materia existe
		
		if (v_materias[i].Id_materias==materia) {
			break;
		}
	}
	
	if (i=nMaterias) {
		printf("ERROR: La materia introducida no existe\n");
		printf("¿Desea intentarlo de nuevo? (1.Seguir)");
		scanf("%d", res);
		
		if (res==1) {
			goto SEGUIR;
		} else {
			goto FIN;
		}
	}
	
	for (j=0;j<nMatriculas;j++) {  //Comprueba si el alumno esta matriculado en ese momento
		
		if ((v_materias[i].Id_materias==v_matriculas[j].Id_materias)&&(v_alumnos[i_usuario].Id_alum==v_matriculas[j].Id_alum)) {
			
			printf("ERROR: El alumno ya esta matriculado en la materia");
			printf("¿Desea intentarlo de nuevo? (1.Seguir)");
			scanf("%d", &res);
			
			if (res==1) {
				goto SEGUIR;
			} else {
				goto FIN;
			}
					
		}
	}
	
	printf("¿Desea crear la matricula? (1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_matriculas= (matriculas*) realloc(v_matriculas,(nMatrciulas+1)*sizeof(matriculas)); //Añadimos un hueco más al vector
		
		*nMatriculas= *nMatriculas+1;
		
		v_matriculas[nMatriculas-1].Id_alum=v_alumnos[i_usuario].Id_alum;
		v_matriculas[nMatriculas-1].Id_materias=materia;
				
	}
	
	FIN:
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
			
			if (id==v_materias[i].Id_materias) {
				
				goto MODIFICA;
			}
			
		}
		
		printf("\nERROR: No se ha encontrado materia");
		
		printf("¿Desea continuar? (Pulse 1 para seguir)");
		scanf("%d", &res);
		
		if (res!=1) {
			goto FIN;
		}
		
	}while(v_materias[i].Id_materias!=id);
	
	MODIFICA:
		
		printf("ID-NOMBRE-ABREVIATURA");
		printf("%s-%s-%s",v_materias[i].Id_materias,v_materias[i].Nombre_materia,v_materias[i].Abrev_materia);
	
		printf("\t1.ID\n");
		printf("\t2.NOMBRE\n");
		printf("\t3.ABREVIATURA\n");
		printf("\t0.Volver a menu materias\n");
		
		do {
	
			scanf("%d", &op);
					
			switch (op) {
						
				case 0:
					break;
							
				case 1:	
					
					printf("Introduzca nuevo ID: ");
					fflush(stdin);
					fgets(cambio, 5, stdin);
					v_materias[i].Id_materias=cambio;
					
					goto MODIFICA;
						
				case 2:
					printf("Introduzca nuevo nombre: ");
					fflush(stdin);
					fgets(cambio, 51, stdin);
					v_materias[i].Nombre_materia=cambio;
					
					goto MODIFICA;
								
				case 3:	
					printf("Introduzca nuevo abreviatura: ");
					fflush(stdin);
					fgets(cambio, 4, stdin);
					v_materias[i].Abrev_materia=cambio;
					
					goto MODIFICA;	
			}
					
		}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3));
		
		FIN:	
	
}

void agregar_materias (int *nMaterias) {
	
	int i, res;
	char id[5];
	char nombre[51];
	char abreviatura[4];
	
	ID:
			
	printf("Introduzca id (4 digitos) de la materia: ");
	fflush(stdin);
	fgets(id, 5, stdin);		
			
	for (i=0;i<nMaterias;i++) {
		
		if (v_materias[i].Id_materias==id) {
			printf("\nERROR: ID en uso\n");
			goto ID;
		}
	}
			
	NOMBRE:
			
	printf("Introduzca nombre (50 caracteres) de la materia: ");
	fflush(stdin);
	fgets(nombre, 51, stdin);		
			
	for (i=0;i<nMaterias;i++) {
		
		if (v_materias[i].Nombre_materia==nombre) {
			printf("\nERROR: NOMBRE en uso\n");
			goto NOMBRE;
		}
	}		
			
	ABREVIATURA:
			
	printf("Introduzca abreviatura (3 caracteres) de la materia: ");
	fflush(stdin);
	fgets(abreviatura, 4, stdin);		
			
	for (i=0;i<nMaterias;i++) {
		
		if (v_materias[i].Abrev_materia==abreviatura) {
			printf("\nERROR: ABREVIATURA en uso\n");
			goto ABREVIATURA;
		}
	}
	
	printf("¿Desea crear esta materia? \n(1.Confirmar)\n");
	scanf("%d", &res);
	
	if (res==1) {
		
		v_materias= (materias*) realloc(v_materias,(nMaterias+1)*sizeof(materias)); //Añadimos un hueco más al vector
		
		*nMaterias= *nMaterias+1;
		
		v_materias[nMaterias-1].Id_materias=id;
		v_materias[nMaterias-1].Nombre_materia=nombre;
		v_materias[nMaterias-1].Abrev_materia=abreviatura;
		
	}	
	
}

void eliminar_materias (int *nMaterias) {
	
}

void listar_materias (int nMaterias) {
	
	int i;
	printf("\n\nLISTA MATERIAS\n\n");
	printf("ID-NOMBRE-ABREVIATURA");
	
	for (i=0;i<nMaterias;i++) {
		printf("%s-%s-%s",v_materias[i].Id_materias,v_materias[i].Nombre_materia,v_materias[i].Abrev_materia);
	}	
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void listar_horarios (int nUsuarios, int nHorarios) {
	
	int i, j, k;
	char id[4];
	
	do { //Comprueba si el id introducido corresponde con uno del registro
		
		printf("\nIntroduzca el id (3 digitos) del profesor para ver su horario: ");
		fflush(stdin);
		fgets(id, 4, stdin);	
		
		for (i=0;i<nHorarios;i++) {
			
			if (id==v_horarios[i].Id_profesor) {
				
				goto LISTA;
			}
			
		}
		
		printf("\nERROR: No se ha encontrado profesor");
		
		printf("¿Desea continuar? (Pulse 1 para seguir)");
		scanf("%d", &res);
		
		if (res!=1) {
			goto FIN;
		}
		
	}while(v_horarios[i].Id_profesor!=id);	
	
	LISTA:
	
	for (j=0;j<nUsuarios;j++) {  //Busca la i_usuario del profe en el registro de Usuarios
		
		if (id==v_usuarios[j].Id_usuario) {
			break;
		}
		
	}	
	
	printf("PROFESOR: %s\n",v_usuarios[j].Nomb_usuario);
	printf("HORARIO: \n");
	printf("\nDIA-HORA-ID MATERIA-GRUPO\n");
	
	for (k=0;k<nHorarios;k++) {
		
		if (v_horarios[k].Id_profesor==id) {
			
			printf("%d-%d-%s-%s", v_horarios[k].Dia_clase, v_horarios[k].Hora_clase, v_horarios[k].Id_materia, v_horarios[k].Grupo);
		}
	}
	
}


void modificar_horarios (int nUsuarios, int nHorarios) {
	
	
	int i, j, k, c, cond; //c es para cambio de enteros y cond para guardar la condicion (1/0) para realizar el cambio
	char id[4];
	char cambio[11];
	
	do { //Comprueba si el id introducido corresponde con uno del registro
		
		printf("\nIntroduzca el id (3 digitos) del profesor para modificar horario: ");
		fflush(stdin);
		fgets(id, 4, stdin);	
		
		for (i=0;i<nHorarios;i++) {
			
			if (id==v_horarios[i].Id_profesor) {
				
				goto LISTA;
			}
			
		}
		
		printf("\nERROR: No se ha encontrado profesor");
		
		printf("¿Desea continuar? (Pulse 1 para seguir)");
		scanf("%d", &res);
		
		if (res!=1) {
			goto FIN;
		}
		
	}while(v_horarios[i].Id_profesor!=id);	
	
	LISTA:
	
	for (j=0;j<nUsuarios;j++) {  //Busca la i_usuario del profe en el registro de Usuarios
		
		if (id==v_usuarios[j].Id_usuario) {
			break;
		}
		
	}	
	
	printf("PROFESOR: %s\n",v_usuarios[j].Nomb_usuario);
	
	HORARIOS:
	
	printf("\nDIA-HORA-ID MATERIA-GRUPO\n");
	
	for (k=0;k<nHorarios;k++) {
		
		if (v_horarios[k].Id_profesor==id) {
		
			printf("%d-%d-%s-%s", v_horarios[k].Dia_clase, v_horarios[k].Hora_clase, v_horarios[k].Id_materia, v_horarios[k].Grupo);
		}
	}	
	
	do {
		
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
						
						printf("\nIntroduzca nuevo dia (1-5)\n");
						scanf("%d", &c);
						
					}while((c!=1)&&(c!=2)&&(c!=3)&&(c!=4)&&(c!=5));
					
					v_horarios[q].Dia_clase=c;
					
				} else {
					
					printf("ERROR: Algun parametro no se corresponde a un horarios existente\n");
				}

				goto HORARIOS;
			
			case 2:
				
				cond=auxiliar_horarios(id[4],nHorarios,&q);
				
				if (cond==1) {
					
					do {
						
						printf("\nIntroduzca nueva hora (1-6)\n");
						scanf("%d", &c);
						
					}while((c!=1)&&(c!=2)&&(c!=3)&&(c!=4)&&(c!=5)&&(c!=6));
					
					v_horarios[q].Hora_clase=c;
					
				} else {
					
					printf("ERROR: Algun parametro no se corresponde a un horarios existente\n");
				}				
				
				
				goto HORARIOS;
				
			case 3:
				
				cond=auxiliar_horarios(id[4],nHorarios,&q);
				
				if (cond==1) {
					
					printf("Introduzca nuevo grupo (10 caracteres)\n");
					fflush(stdin);
					fgets(cambio, 11, stdin);
					v_horarios[q].Grupo=cambio;
					
				} else {
					
					printf("ERROR: Algun parametro no se corresponde a un horarios existente\n");
				}					

				
				goto HORARIOS;		
		}
		
	}while((n!=0)&&(n!=1)&&(n!=2)&&(n!=3));
	
	FIN:
	
}

int auxiliar_horarios (char id[4], int nHorarios, int *q) {
	
	char materia[5];
	char grupo[11];
	
	printf("Introduzca materia (4 caracteres) y grupo (10 caracteres) para modificar el horario\n");
	
	printf("MATERIA:");
	fflush(stdin);
	fgets(materia, 5, stdin);
	
	printf("GRUPO: ");
	fflush(stdin);
	fgets(grupo, 11, stdin);
	
	for (i=0;i<nHorarios;i++) {
		
		if ((v_horarios[i].Id_profesor==id)&&(v_horarios[i].Grupo==grupo)&&(v_horarios[i].Id_materia==materia)) {
			*q=i;
			return(1);
		}
		
	}
	
	return(0);
}

void agregar_horarios (int *nHorarios) {
	
}

void eliminar_horarios (int *nHorarios) {
	
	
}








