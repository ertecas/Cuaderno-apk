#ifndef _INICIO_
#define _INICIO_

//Precondici�n: No hay
//Postcondicion: Crea el primer usuario del sistema (administrador) y lo guarda en el registro
void primer_inicio ();

//Precondici�n: N>0
//Postcondici�n: Solicita usuario y contrase�a comprobando la validez de ambos
void inicio_sesion (int, int *);

//Precondici�n:
//Postcondici�n: Devuelve 1 si el usuario es admin o 0 si es profesor
int profe_o_admin (int);

#endif
