#ifndef _CARGA_H_
#define _CARGA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"

//En primer lugar, hacemos una lista declarando los tipos de datos que usaremos//
//Y luego, declararemos también unos punteros que apuntan hacia vectores de distintos datos//

int numUsuarios;//Número de usuarios en usuarios.txt//
int numAlumnos;//Número de alumnos en alumnos.txt//
int numMaterias;//Número de administradores en administradores.txt//
int numMatriculas;//Número de matriculas en matriculas.txt//
int numCalificaciones;//Número de calificaciones en calificaciones.txt//
int numHorarios;//Número de horarios en horarios.txt//


int carga();
int cargaUsuarios(usuarios **,int *);//usuarios ** significa que apunta al interior del inicio de un vector, y la posición//
// del vector será la que nos dé con el int * para llegar al usuario correspondiente almacenado en dicha posición del vector//
int cargaAlumnos(alumnos **,int *);
int cargaMaterias(materias **,int *);
int cargaMatriculas(matriculas **,int *);
int cargaCalificaciones(calificaciones **,int *);
int cargaHorarios(horarios **,int *);

//También declaramos las funciones que podrán realizar aquellas funciones en las que se deba usar esta cabecera//

void imprimir();
void printCargaUsuarios(usuarios *,int);
void printCargaAlumnos(alumnos *,int);
void printCargaMaterias(materias *,int);
void printCargaMatriculas(matriculas *,int);
void printCargaCalificaciones(calificaciones *,int);
void printCargaHorarios(horarios *,int);

#endif
