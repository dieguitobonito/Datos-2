#include <iostream>
#include "Lista.h"
#include "Nodo.h"

#include <string>
#include <fstream>

using namespace std;


void escribirArchivo(Lista l){

}

void menu(){
	cout << "--- Lista escolar ---" << endl;
	int opc = 0;
	int valor;
	Lista principal;

	// Necesitas crearla una vez todos los datos estén juntos
	//Alumno niño;
	
	string name;
	int age;
	string gender;
	int posicion;
	bool cambios = false;

	while(opc != 17){
		cout << "\n1. Añadir al inicio" << endl;
		cout << "2. Insertar al final" << endl;
		cout << "3. Insertar en posición" << endl;
		cout << "4. Eliminar" << endl;
		cout << "5. Eliminar toda la lista" << endl;
		cout << "6. Buscar" << endl;
		cout << "7. Inicializar" << endl;
		cout << "8. Verificar si está vacía" << endl;
		cout << "9. Imprimir el primer alumno" << endl;
		cout << "10. Imprimir el último alumno" << endl;
		cout << "11. Tamaño de la lista" << endl;
		cout << "12. Imprimir el siguiente alumno" << endl;
		cout << "13. Imprimir el alumno anterior" << endl;
		cout << "14. Mostrar toda la lista" << endl;
		cout << "15. Escribir a archivo" << endl;
		cout << "16. Leer de archivo" << endl;
		cout << "17. Salir" << endl;
		cout << ": ";
		cin >> opc;
		cout << endl;
	
		switch(opc){
			// Añadir al inicio
			case 1:{
				cout << "¿Cómo se llama el alumno?\n: ";
				cin >> name;
				cout << "¿Cuántos años tiene?\n: ";
				cin >> age;
				cout << "¿Cuál es su género?\n: ";
				cin >> gender;

				// Llamando al constructor a la hora de crear la variable, todo de golpe
				Alumno niño(name, age, gender);	
				// Recibe alumno, no nodo
				principal.insertarInicio(niño);
				break;
			}
			// Añadir al final
			case 2:{	
				cout << "¿Cómo se llama el alumno?\n: ";
				cin >> name;
				cout << "¿Cuántos años tiene?\n: ";
				cin >> age;
				cout << "¿Cuál es su género?\n: ";

				Alumno niño(name, age, gender);
				principal.insertarFinal(niño);
				break;
			}
			case 3:{
				principal.mostrarTodo();
				cout << "¿En qué posición quieres insertar?" << endl;
				cin >> posicion;
				cout << "¿Cómo se llama el alumno?\n: ";
				cin >> name;
				cout << "¿Cuántos años tiene?\n: ";
				cin >> age;
				cout << "¿Cuál es su género?\n: ";

				Alumno niño(name, age, gender);
				principal.insertarPos(niño, posicion);
				break;
			}
			case 4:{
				cout << "¿Cómo se llama el alumno a dar de baja?\n: ";
				cin >> name;
				cout << "¿Cuántos años tiene?\n: ";
				cin >> age;

				Alumno niño(name, age, gender);
				principal.eliminar(niño);
				break;
			}
			case 5:{
				int decision;
				cout << "Esta acción no puede revertirse, ¿continuar?" << endl;
				cout << "1.- Sí\n2.- No\n: ";
				cin >> decision;
				if(decision == 1){
					principal.eliminarTodo();
				}
				else{
					cout << "No se eliminará la lista" << endl;
				}
				break;
			}
			case 6:{
				cout << "¿Cómo se llama el alumno?\n: ";
				cin >> name;
				cout << "¿Cuántos años tiene?\n: ";
				cin >> age;

				Alumno niño(name, age, gender);
				principal.buscar(niño);
				break;
			}
			case 7:{
				principal.inicializa();
				break;
			}
			case 8:{
				principal.vacia();
				break;
			}
			case 9:{
				principal.primero();
				break;
			}
			case 10:{
				principal.ultimo();
				break;
			}
			case 11:{
				principal.tamaño();
				break;
			}
			case 12:{
				cout << "Dame el nombre del alumno que quieras saber quién sigue de él\n: ";
				cin >> name;
				cout << "La edad de dicho\n: ";
				cin >> age;
				Alumno niño(name, age, gender);
				principal.siguiente(niño);
				break;
			}
			case 13:{
				cout << "Dame el nombre del alumno que quieras saber quién sigue antes de él\n: ";
				cin >> name;
				cout << "La edad de dicho\n: ";
				cin >> age;
				Alumno niño(name, age, gender);
				principal.anterior(niño);
				break;
			}

			case 14:{
				principal.mostrarTodo();
				break;
			}
			case 15:{
				principal.escribirArchivo();
				break;
			}
			case 16:{
				principal.leerArchivo();
				break;
			}
			// Salir
			case 17:{
				cout << "¡Ciao!" << endl;
				opc = 17;
			}
				break;
			default:
				cout << "Opción no válida" << endl;
		}
	}
}

int main(){
	menu();
	return 0;
}
