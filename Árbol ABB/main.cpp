#include <iostream>
#include <string>
#include <fstream>
#include "Tree.h"

Tree oak;
bool changes;
struct data{
        std::string name;
        int age;
        std::string major;
}student;

// Nombre del archivo
const std::string filename = "file01.txt";

// Delimitador de campo y de registro
char fDel = ',';
char rDel = '|';

void readInput(){
        std::cin.ignore();
        std::cout << "Nombre: ";
        std::getline(std::cin, student.name);

        std::cout << "Edad: ";
        std::cin >> student.age;
        std::cin.ignore();

        std::cout << "Carrera: ";
        std::getline(std::cin, student.major);
        changes = true;
}

char choose(){
        char option;
        if(changes){
                std::cout << "\n(El árbol ha sido modificado"
                        << ", recomendable guardar)";
        }
        std::cout << "\n1. Insertar\n"
                << "2. Imprimir inorden\n"
                << "3. Imprimir posorden\n"
                << "4. Imprimir preorden\n"
                << "5. Eliminar nodo\n"
                << "6. Eliminar árbol\n"
                << "7. Buscar\n"
                << "8. Leer archivo\n"
                << "9. Guardar archivo\n"
                << "S. Salir\n"
                << ": ";
        std::cin >> option;

        std::cout << "\n";

        return option;
}

void menu(){
        char option;
        std::cout << "Árbol ABB" << std::endl;
        do{
                option = choose();
                switch(option){
                        // Insertar
                        case '1':{
                                readInput();
                                oak.insert(Student(student.name,
                                                   student.age,
                                                   student.major));
                                break;
                        }
                        // Inorden
                        case '2':{
                                oak.traverseInOrder();
                                break;
                        }
                        // Posorden
                        case '3':{
                                oak.traversePostOrder();
                                break;
                        }
                        // Preorden
                        case '4':{
                                oak.traversePreOrder();
                                break;
                        }
                        // Eliminar nodo
                        case '5':{
                                std::string buscar;
                                std::getline(std::cin, buscar);
                                oak.deleteNode(oak.root,
                                               buscar);
                                break;
                        }
                        // Eliminar árbol
                        case '6':{
                                oak.deleteAll();
                                break;
                        }
                        // Buscar
                        case '7':{
                                oak.search();
                                break;
                        }
                        // Leer archivo
                        case '8':{
                                oak.readFile();
                                break;
                        }
                        // Guardar archivo
                        case '9':{
                                changes = oak.saveFile(oak.root,
                                                       filename,
                                                       fDel,
                                                       rDel);
                                break;
                        }
                        case 'S':{
                                std::cout << "Adiós" << std::endl;
                                break;
                        }
                        case 's':{
                                std::cout << "Adiós" << std::endl;
                                break;
                        }
                        default:
                                std::cout << "Opción incorrecta" << std::endl;
                }

        }while(option != 's' && option != 'S');
}

int main(){
        menu();
        return 0;
}
