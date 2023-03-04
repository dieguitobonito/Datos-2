#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>

using namespace std;

class Alumno{
	public:
		string nombre;
		int edad;
		string genero;

		// Constructores
		Alumno();
		Alumno(string, int, string);
};

#endif // ALUMNO_H
