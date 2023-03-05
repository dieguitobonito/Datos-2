#include "Tree.h"
#include <fstream>

void Tree::insert(Student data){
    if(root == nullptr){
        root = new TreeNode(data);
    }else{
        TreeNode* current = root;
        while(true){
            if(data.name < current->data.name){
                if(current->left == nullptr){
                    current->left = new TreeNode(data);
                    break;
                }else{
                    current = current->left;
                }
            }else{
                if(current->right == nullptr){
                    current->right = new TreeNode(data);
                    break;
                }else{
                    current = current->right;
                }
            }
        }
    }
}

void Tree::traverseInOrder(TreeNode* node){
    if(node != nullptr){
        traverseInOrder(node->left);
        std::cout << node->data.name
                  << " ("
                  << node->data.age
                  << ", "
                  << node->data.major
                  << ")" << std::endl;
        traverseInOrder(node->right);
    }
}

void Tree::traversePreOrder(TreeNode* node){
    if(node != nullptr){
            std::cout << node->data.name
                      << " ("
                      << node->data.age
                      << ", "
                      << node->data.major
                      << ")" << std::endl;
            traversePreOrder(node->left);
            traversePreOrder(node->right);
    }
}

void Tree::traversePostOrder(TreeNode* node){
       if(node != nullptr){
               traversePostOrder(node->left);
               traversePostOrder(node->right);
               std::cout << node->data.name
                         << " ("
                         << node->data.age
                         << ", "
                         << node->data.major
                         << ")" << std::endl;
       }
}

void Tree::search(){
        std::cout << "Impleméntame" << std::endl;
}

TreeNode* Tree::readFile(const std::string filename,
                         const char fDel, const char rDel){

        std::ifstream file;
        file.open(filename);

        TreeNode* root = nullptr;

        readFileHelper(root, file, fDel, rDel);
        std::cout << "Hola" << std::endl;

        return root;
}

void Tree::readFileHelper(TreeNode*& node,
                    std::ifstream& file,
                    const char fDel,
                    const char rDel){

        std::string name;
        // Necesario para leerlo del archivo,
        // de ahí lo convertimos a int
        std::string ageStr;
        std::string major;

        getline(file, name, fDel);
        getline(file, ageStr, fDel);
        getline(file, major, rDel);

        if(name.empty() || ageStr.empty() || major.empty())
                node = nullptr;
        else{
                int age = stoi(ageStr);

                // Leemos de la misma manera en que leemos
                // el archivo
                node = new TreeNode(Student(name, age, major));
                std::cout << "Haciendo magia" << std::endl;
                readFileHelper(node->left, file, fDel, rDel);
                readFileHelper(node->right, file, fDel, rDel);
        }
}

bool Tree::saveFile(TreeNode* root, const std::string& filename,
                    const char fDel, const char rDel){

        std::ofstream file;
        file.open(filename);

        saveFileHelper(root, file, fDel, rDel);

        file.close();
        // Para changes, false para saber que no hay
        // changes, jeje, ¿entiendes?
        return false;
}

void Tree::saveFileHelper(TreeNode* node, std::ofstream& file,
                          const char fDel, const char rDel){

        if(node == nullptr){
                return;
        }

        // Recorrido preorden PREORDEN
        // Guarda el nodo
        // Se va al izquierdo y derecho
        file << node->data.name << fDel
                << node->data.age << fDel
                << node->data.major << rDel;

        saveFileHelper(node->left, file, fDel, rDel);
        saveFileHelper(node->right, file, fDel, rDel);
}

void Tree::deleteAll(){
        std::cout << "Impleméntame" << std::endl;
}

bool Tree::isTreeEmpty(TreeNode* root){
        return (root == nullptr);
}
