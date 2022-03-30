#ifndef _ADMIN_
#define _ADMIN_

void listar_usuarios (int nUsuarios);
void modificar_usuarios (int nUsuarios);
void agregar_usuarios (int *nUsuarios);
void eliminar_usuarios (int *nUsuarios);


void listar_alumnos (int nAlumnos);
void modificar_alumnos (int nAlumnos);
void agregar_alumnos (int *nAlumnos);
void eliminar_alumnos (int *nAlumnos);

void materias_matriculado (int i_alumno, int nMatriculas, int nMaterias);
void modificar_matricula (int i_alumno, int nMatriculas);
void eliminar_matricula (int i_alumno, int *nMatriculas);
void agregar_matricula (int i_alumno, int *nMatriculas);


void listar_materias (int nMaterias);
void modificar_materias (int nMaterias);
void agregar_materias (int *nMaterias);
void eliminar_materias (int *nMaterias);

void listar_horarios (int nUsuarios, int nHorarios);
void modificar_horarios (int nUsuarios, int nHorarios);
//Postcondición: La función devuelve 0 o 1, depende de si los datos recibidos se corresponden a algun i_elemento del vector
int auxiliar_horarios (char [], int nHorarios, int *q);
void agregar_horarios (int *nHorarios);
void eliminar_horarios (int *nHorarios);


#endif
