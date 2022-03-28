#include <guarda.h>

void guardarUsuario(usuarios *u, size_t *n){
    FILE *fichero;
    int i;

    fichero=fopen("DATA/usuarios.txt","w+");
    i=0;

    if(fichero==NULL){
         printf("\nNo se ha podido editar el fichero");
    }else{
        do{
            fprintf(fichero,"%d-%s-%s-%s-%s", u[i].Id_usuario, u[i].Nomb_usuario, u[i].Perfil_usuario, u[i].Usuario, u[i].Contrasena);
            i++;
        }while(i<n-1);
        fprintf(fichero,"%d-%s-%s-%s-%s", u[i].Id_usuario, u[i].Nomb_usuario, u[i].Perfil_usuario, u[i].Usuario, u[i].Contrasena);
    }
    printf("\nLos usuarios han sido guardados correctamente");
}

void guardarAlumnos(alumnos *a, size_t *n){
    FILE *fichero;
    int i;

    fichero=fopen("DATA/alumnos.txt","w+");

    i=0;

    if(fichero==NULL){
        printf("\nNo se ha podido editar el fichero");
    }else{
        do{
            fprintf(fichero,"%d-%s-%s-%s-%s-%s", a[i].Id_alum, a[i].Nombre_alum, a[i].Direc_alum, a[i].Local_alum, a[i].Curso, a[i].Grupo);
            i++;
        }while(i<n-1);
        fprintf(fichero,"%d-%s-%s-%s-%s-%s", a[i].Id_alum, a[i].Nombre_alum, a[i].Direc_alum, a[i].Local_alum, a[i].Curso, a[i].Grupo);
    }
    printf("\nLos usuarios han sido guardados correctamente");
}

void guardarMaterias(materias *mate, size_t *n){
    FILE *fichero;
    int i;

    fichero=fopen("DATA/materias.txt","w+");

    i=0;

    if(fichero==NULL){
        printf("\nNo se ha podido editar el fichero");
    }else{
        do{
            fprintf(fichero, "%d-%s-%s", mate[i].Id_materia, mate[i].Nombre_materia, mate[i].Abrev_materia);
            i++;
        }while(i<n-1);
        fprintf(fichero, "%d-%s-%s", mate[i].Id_materias, mate[i].Nombre_materia, mate[i].Abrev_materia);
    }
     printf("\nLos usuarios han sido guardados correctamente");
}

void guardarMatriculas(matriculas *matri, size_t *n){
    FILE *fichero;
    int i;

    fichero=fopen("DATA/matriculas.txt","w+");

    i=0;

    if(fichero==NULL){
        printf("\nNo se ha podido editar el fichero");
    }else{
        do{
            fprintf(fichero,"%d-%d", matri[i].Id_materias, matri[i].Id_alum);
            i++;
        }while(i<n-1);
        fprintf(fichero,"%d-%d", matri[i].Id_materias, matri[i].Id_alum);
    }
    printf("\nLos usuarios han sido guardados correctamente");
}

void guardarCalificaciones(calificaciones *c, size_t *n){
    FILE *fichero;
    int i;

    fichero=fopen("DATA/calificaciones.txt","w+");

    i=0;

    if(fichero==NULL){
        ("\nNo se ha podido editar el fichero");
    }else{
        do{
            fprintf(fichero,"%s-%s-%d-%d-%d", c[i].Fecha_calif, c[i].Descrip_calif, c[i].Id_materia, c[i].Id_alum, c[i].Valor_calif);
            i++;
        }while(i<n-1);
        fprintf(fichero,"%s-%s-%d-%d-%d", c[i].Fecha_calif, c[i].Descrip_calif, c[i].Id_materia, c[i].Id_alum, c[i].Valor_calif);
    }
    printf("\nLos usuarios han sido guardados correctamente");
}

void guardarHorarios(horarios *h, int *n){
    FILE *fichero;
    int i;

    fichero=fopen("DATA/horarios.txt", "w+");

    i=0;

    if(fichero==NULL){
        printf("\nNo se ha podido editar el fichero");
    }else{
        do{
            fprintf(fichero, "%d-%d-%d-%d-%s", h[i].Id_profesor, h[i].Dia_clase, h[i].Hora_clase, h[i].Id_materia, h[i].Grupo);
            i++;
        }while(i<n-1);
        fprintf(fichero, "%d-%d-%d-%d-%s", h[i].Id_profesor, h[i].Dia_clase, h[i].Hora_clase, h[i].Id_materia, h[i].Grupo);
    }
    printf("\nLos usuarios han sido guardados correctamente");
}

void guardar(){
    char r=' ';

    while(r!=s && r!=n){
        printf("\nHa seleccionado salir. ¿Desea guardar los cambios realizados? Responda con (s/n)\n");
        fflush(stdin);
        scanf("%c",&r);
    }

    if(r=='s'){
        guardarUsuario(v_usuarios, numUsuarios);
        guardarAlumnos(v_alumnos, numAlumnos);
        guardarMaterias(v_materias, numMaterias);
        guardarMatriculas(v_matriculas, numMatriculas);
        guardarCalificaciones(v_calificaciones, numCalificaciones);
        guardarHorarios(v_horarios, numHorarios);

        exit (0);
    }else{
         printf("\nLos cambios realizados no han sido guardados.\n");
    }
}
