#ifndef NODO_H
#define NODO_H

#include "Alumno.h"

class Nodo{
	public:
		Alumno niño;
		Nodo* sig;

		// Constructores
		Nodo();
		Nodo(Alumno, Nodo*);
};

#endif // NODO_H
