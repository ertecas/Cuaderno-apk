#ifndef _PROFE_
#define _PROFE_

void list_hor_profe (int i_profe, int nHorarios);
void gestor_alumnos (int i_grupo, int nAlumnos);
void ficha_alumno (char [], int nAlumnos);
void calificaciones (char [], int i_grupo, int nAlumnos, int nCalificaciones);

void listar_calificaciones (char id[], int i_grupo, int nCalificaciones);
void modificar_calificaciones (char id[], int i_grupo, int nCalificaciones);
void agregar_calificaciones (char id[], int i_grupo, int *nCalificaciones);
void eliminar_calificaciones (int *nCalificaciones);


#endif
