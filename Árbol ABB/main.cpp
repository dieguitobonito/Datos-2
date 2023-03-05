#include <iostream>
#include <string>
#include "Tree.h"

Tree oak;
struct data{
        std::string name;
        int age;
        std::string major;
}student;

void readInput(){
        std::cin.ignore();
        std::cout << "Nombre: ";
        std::getline(std::cin, student.name);

        std::cout << "Edad: ";
        std::cin >> student.age;
        std::cin.ignore();

        std::cout << "Carrera: ";
        std::getline(std::cin, student.major);

}

char choose(){
        char option;
        std::cout << "1. Insertar\n"
                << "2. Imprimir inorden\n"
                << "3. Imprimir posorden\n"
                << "4. Imprimir preorden\n"
                << "5. Eliminar nodo\n"
                << "6. Buscar\n"
                << "7. Leer archivo\n"
                << "8. Guardar archivo\n"
                << "9. Salir\n"
                << ": ";
        std::cin >> option;
        return option;
}

void menu(){
        char option;
        std::cout << "Árbol ABB" << std::endl;
        do{
                option = choose();
                switch(option){
                        case '1':{
                                readInput();
                                oak.insert(Student(student.name,
                                                   student.age,
                                                   student.major));
                                break;
                        }
                        case '2':{
                                oak.traverseInOrder();
                                break;
                        }

                        case '3':{
                                oak.traversePostOrder();
                                break;
                        }

                        case '4':{
                                oak.traversePreOrder();
                                break;
                        }

                        default:
                                std::cout << "Opción incorrecta" << std::endl;
                }

        }while(option != 's' && option != '9' && option != 'S');
}

int main(){
        menu();
        return 0;
}
