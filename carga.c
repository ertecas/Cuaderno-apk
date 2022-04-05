//Este módulo se encarga de cargar los datos guardados en los registros y los ejecuta para poder acceder a ellos o modificarlos/
#include "carga.h"

int carga(){
    cargaUsuarios(&v_usuarios,&numUsuarios);
    cargaAlumnos(&v_alumnos,&numAlumnos);
    cargaMaterias(&v_materias,&numMaterias);
    cargaMatriculas(&v_matriculas,&numMatriculas);
    cargaCalificaciones(&v_calificaciones,&numCalificaciones);
    cargaHorarios(&v_horarios,&numHorarios);

    return (0);
}

int cargaUsuarios(usuarios **v_usuarios,int *n){
    FILE *fichero;

    char linea[54];
    char *token;
    *v_usuarios=NULL;
    *n=0;

    fichero=fopen("DATA/usuarios.txt","r");//DATA/usuarios.txt = carpeta DATA, archivo usuarios.txt//

    if (fichero==NULL){
        printf("\nHa ocurrido un error al abrir el fichero DATA/usuarios.txt, compruebe que los datos son correctos.");
    }else{
        do{
            fgets(linea,54,fichero);

            if (strcmp(linea,"\0")){
                *v_usuarios=realloc((usuarios*)(*v_usuarios),((*n)+1)*sizeof(usuarios));

                token=strtok(linea,"-");
                strcpy((*v_usuarios)[*n].Id_usuario,token);

                token=strtok(NULL,"-");
                strcpy((*v_usuarios)[*n].Nomb_usuario,token);

                token=strtok(NULL,"-");
                strcpy((*v_usuarios)[*n].Perfil_usuario,token);

                token=strtok(NULL,"-");
                strcpy((*v_usuarios)[*n].Usuario,token);

                token=strtok(NULL,"\n");
                strcpy((*v_usuarios)[*n].Contrasena,token);

                (*n)++;
            }
        }while(!feof(fichero));
    }
    fclose(fichero);//Siempre cerraremos los ficheros al acabar.//
    return 0;
}

int cargaAlumnos(alumnos **v_alumnos,int *n){
    FILE *fichero;

    char linea[125];
    char *token;

    *v_alumnos=NULL;
    *n=0;

    fichero=fopen("DATA/alumnos.txt","r");

    if(fichero==NULL){
        printf("\nHa ocurrido un error al abrir el fichero DATA/alumnos.txt, compruebe que los datos son correctos.");
    }else{
        do{
            fgets(linea,125,fichero);

            if(strcmp(linea,"\0")){
                *v_alumnos=realloc((alumnos *)(*v_alumnos),((*n)+1)*sizeof(alumnos));

                token=strtok(linea,"-");
                strcpy((*v_alumnos)[*n].Id_alum,token);

                token=strtok(NULL,"-");
                strcpy((*v_alumnos)[*n].Nombre_alum,token);

                token=strtok(NULL,"-");
                strcpy((*v_alumnos)[*n].Direc_alum,token);

                token=strtok(NULL,"-");
                strcpy((*v_alumnos)[*n].Local_alum,token);

                token=strtok(NULL,"-");
                strcpy((*v_alumnos)[*n].Curso,token);

                token=strtok(NULL,"\n");
                strcpy((*v_alumnos)[*n].Grupo,token);

                (*n)++;
            }
        }while(!feof(fichero));
    }

    fclose(fichero);
    return 0;
}

int cargaMaterias(materias **v_materias,int *n){
    FILE *fichero;

    char linea[62];
    char *token;

    *v_materias=NULL;
    *n=0;

    fichero=fopen("DATA/materias.txt","r");

    if(fichero==NULL){
        printf("\nHa ocurrido un error al abrir el fichero DATA/materias.txt, compruebe que los datos son correctos.");
    }else{
        do{
            fgets(linea,62,fichero);

            if(strcmp(linea,"\0")){
                *v_materias=realloc((materias *)(*v_materias),((*n)+1)*sizeof(materias));

                token=strtok(linea,"-");
                strcpy((*v_materias)[*n].Id_materias,token);

                token=strtok(NULL,"-");
                strcpy((*v_materias)[*n].Nombre_materia,token);

                token=strtok(NULL,"\n");
                strcpy((*v_materias)[*n].Abrev_materia,token);

                (*n)++;
            }
        }while(!feof(fichero));
    }
    fclose(fichero);
    return 0;
}

int cargaMatriculas(matriculas **v_matriculas,int *n){
    FILE *fichero;

    char linea[12];
    char *token;

    *v_matriculas=NULL;
    *n=0;

    fichero=fopen("DATA/matriculas.txt","r");

    if(fichero==NULL){
        printf("\nHa ocurrido un error al abrir el fichero DATA/matriculas.txt, compruebe que los datos son correctos.");
    }else{
        do{
            fgets(linea,12,fichero);

            if(strcmp(linea,"\0")){
                *v_matriculas=realloc((matriculas *)(*v_matriculas),((*n)+1)*sizeof(matriculas));

                token=strtok(linea,"-");
                strcpy((*v_matriculas)[*n].Id_materias,token);

                token=strtok(NULL,"\n");
                strcpy((*v_matriculas)[*n].Id_alum,token);

                (*n)++;
            }
        }while(!feof(fichero));
    }
    fclose(fichero);
    return 0;
}

int cargaCalificaciones(calificaciones **v_calificaciones,int *n){
    FILE *fichero;

    char linea[54];
    char *token;

    *v_calificaciones=NULL;
    *n=0;

    fichero=fopen("DATA/calificaciones.txt","r");

    if(fichero==NULL){
        printf("\nHa ocurrido un error al abrir el fichero DATA/calificaciones.txt, compruebe que los datos son correctos.");
    }else{
        do{
            fgets(linea,54,fichero);

            if(strcmp(linea,"\0")){
                *v_calificaciones=realloc((calificaciones *)(*v_calificaciones),((*n)+1)*sizeof(calificaciones));

                token=strtok(linea,"-");
                strcpy((*v_calificaciones)[*n].Fecha_calif,token);

                token=strtok(NULL,"-");
                strcpy((*v_calificaciones)[*n].Descrip_calif,token);

                token=strtok(NULL,"-");
                strcpy((*v_calificaciones)[*n].Id_materia,token);

                token=strtok(NULL,"-");
                strcpy((*v_calificaciones)[*n].Id_alum,token);

                token=strtok(NULL,"\n");
                strcpy((*v_calificaciones)[*n].Valor_calif,token);

                (*n)++;
            }
        }while(!feof(fichero));
    }
    fclose(fichero);
    return 0;
}

int cargaHorarios(horarios **v_horarios,int *n){
    FILE *fichero;

    char linea[23];
    char *token;

    *v_horarios=NULL;
    *n=0;

    fichero=fopen("DATA/horarios.txt","r");
    if(fichero==NULL){
        printf("\nHa ocurrido un error al abrir el fichero DATA/calificaciones.txt, compruebe que los datos son correctos.");
    }else{
        do{
            fgets(linea,23,fichero);

            if(strcmp(linea,"\0")){
                *v_horarios=realloc((horarios *)(*v_horarios),((*n)+1)*sizeof(horarios));

                token=strtok(linea,"\n");
                strcpy((*v_horarios)[*n].Id_profesor,token);

                token=strtok(NULL,"-");
                strcpy((*v_horarios)[*n].Dia_clase,token);

                token=strtok(NULL,"-");
                strcpy((*v_horarios)[*n].Hora_clase,token);

                token=strtok(NULL,"-");
                strcpy((*v_horarios)[*n].Id_materia,token);

                token=strtok(NULL,"\n");
                strcpy((*v_horarios)[*n].Grupo,token);

                (*n)++;
            }
        }while(!feof(fichero));
    }
    fclose(fichero);
    return 0;
}
