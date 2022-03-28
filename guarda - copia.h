#ifndef _GUARDAR_H_
#define _GUARDAR_H_

#include <carga.h>
#include <datos.h>

//Precondición: Un vector usuario existente y una dimensión de vector//
//Postcondición: Guarda en el fichero los datos de los usuarios//

void guardar();
void guardarUsuarios(usuarios *u, size_t *n);
void guardarAlumnos(alumnos *a, size_t *n);
void guardarMaterias(materias *mate, size_t *n);
void guardarMatriculas(matriculas *matri, size_t *n);
void guardarCalificaciones(calificaciones *c, size_t *n);
void guardarHorarios(horarios *h, size_t *n);

#endif
