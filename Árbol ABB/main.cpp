#include <iostream>
#include "Tree.h"

Tree oak;

void menu(){
        char option = ' ';
        do{
                // Leer árbol
                // imprimir árbol
                // // inorden, posorden, preorden
                // Guardar árbol
                // Eliminar nodo
                //
                switch(option){
                        case '1':{

                        }
                        default:
                                std::cout << "Incorrecto" << std::endl;
                }

        }while(option != 's');
        std::cout << "Adiós" << std::endl;
}

int main(){

        oak.insert(Student("Alice", 21, "Computer Science"));
        oak.insert(Student("Bob", 22, "Mathematics"));
        oak.insert(Student("Charlie", 20, "English"));
        oak.insert(Student("David", 23, "Biology"));
        oak.insert(Student("Emily", 19, "Chemistry"));

        oak.traverseInOrder();
        return 0;
}
