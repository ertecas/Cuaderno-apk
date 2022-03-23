#ifndef _INICIO_
#define _INICIO_

//Precondición: No hay
//Postcondicion: Crea el primer usuario del sistema (administrador) y lo guarda en el registro
void primer_inicio ();

//Precondición: N>0
//Postcondición: Solicita usuario y contraseña comprobando la validez de ambos
void inicio_sesion (int, int *);

//Precondición:
//Postcondición: Devuelve 1 si el usuario es admin o 0 si es profesor
int profe_o_admin (int);

#endif
