#include "Alumno.h"
#include <string>

using namespace std;

// Constructor predeterminado
Alumno::Alumno(){
    	nombre = "";
    	edad = 0;
	genero = "";

}

Alumno::Alumno(string nombre, int edad, string genero){
	this->nombre = nombre;
    	this->edad = edad;
	this->genero = genero;
}
