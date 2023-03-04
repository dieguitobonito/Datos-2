#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"
#include "Alumno.h"
#include <iostream>
#include <string>
using namespace std;

class Lista{
    public:
        Nodo* h;

	// Constructores
	Lista();
        Lista(Nodo*);

        // Métodos
        void insertarInicio(Alumno);
	void insertarFinal(Alumno);
	void insertarPos(Alumno, int);
	void eliminar(Alumno);
	void eliminarTodo(void);
	// Comparar ambos datos de alumno
	void buscar(Alumno); 
	// Mandar header
	void inicializa(void);
	void vacia(void);
	void primero(void);
	void ultimo(void);
	void tamaño(void);
	void siguiente(Alumno);
	void anterior(Alumno);
        void mostrarTodo(void);
	void escribirArchivo(void);
	void leerArchivo(void);
};

#endif // LISTA_H
