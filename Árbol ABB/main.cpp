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
char rDel = '\n';

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
                << "4. Imprimir preorden (recomendado)\n"
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

// Para imprimir los datos, nada más
void shoutItOut(){
        std::cout << "Nombre (edad, carrera)\n" << std::endl;
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
                                if(oak.isTreeEmpty(oak.root))
                                        std::cout << "No existe" << std::endl;
                                else{
                                        shoutItOut();
                                        oak.traverseInOrder();
                                }
                                break;
                        }
                        // Posorden
                        case '3':{
                                if(oak.isTreeEmpty(oak.root))
                                        std::cout << "No existe" << std::endl;
                                else{
                                        shoutItOut();
                                        oak.traversePostOrder();
                                }
                                break;
                        }
                        // Preorden
                        case '4':{
                                if(oak.isTreeEmpty(oak.root))
                                        std::cout << "No existe" << std::endl;
                                else{
                                        shoutItOut();
                                        oak.traversePreOrder();
                                }
                                break;
                        }
                        // Eliminar nodo
                        case '5':{
                                std::string lookfor;
                                std::cin.ignore();
                                std::cout << "Nombre a eliminar: ";
                                getline(std::cin, lookfor);
                                oak.deleteNode(oak.root, lookfor);
                                break;
                        }
                        // Eliminar árbol
                        case '6':{
                                oak.deleteAll(oak.root);
                                oak.root = nullptr;
                                break;
                        }
                        // Buscar
                        case '7':{
                                std::cin.ignore();
                                std::string lookfor;
                                std::cout << "Nombre a buscar: ";
                                getline(std::cin, lookfor);
                                oak.search(oak.root, lookfor);
                                break;
                        }
                        // Leer archivo
                        case '8':{
                                // Haz que elimine lo que está
                                // anteriormente para así no gastar
                                // memoria
                                oak.root = oak.readFile(filename, fDel, rDel);
                                break;
                        }
                        // Guardar archivo
                        case '9':{
                                char subOption;
                                if(!oak.isFileEmpty(filename)){
                                        std::cout << "El archivo tiene "
                                                << "contenido, "
                                                << "¿sobreescribir?\n"
                                                << "1. Sí 2. No: ";
                                        std::cin >> subOption;
                                        switch(subOption){
                                            case '1':{
                                                    changes = oak.saveFile(oak.root,
                                                                           filename,
                                                                           fDel,
                                                                           rDel);
                                                    break;
                                            }
                                            case '2':{
                                                    std::cout << "Saliendo"
                                                              << std::endl;
                                                    break;
                                            }
                                            default:
                                                    std::cout << "Inválido,"
                                                              << "saliendo"
                                                              << std::endl;
                                            }

                                }else{
                                        changes = oak.saveFile(oak.root,
                                                               filename,
                                                               fDel,
                                                               rDel);
                                }
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
