#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"
#include "Student.h"

class Tree{
public:
    TreeNode* root;
    Tree() {
        root = nullptr;
    }

    void insert(Student);

    // Formas de imprimir el árbol
    void traverseInOrder(TreeNode*);
    // Utilizada para la primer iteración
    void traverseInOrder(){
            traverseInOrder(root);
    }

    void traversePreOrder(TreeNode*);
    void traversePreOrder(){
            traversePreOrder(root);
    }

    void traversePostOrder(TreeNode*);
    void traversePostOrder(){
            traversePostOrder(root);
    }

    bool isTreeEmpty(TreeNode*);

    void search();

    // Leer el archivo de texto
    TreeNode* readFile(const std::string, const char, const char);
    void readFileHelper(TreeNode*&, std::ifstream&, const char, const char);

    // Funciones para guardar archivos
    bool saveFile(TreeNode*, const std::string&, const char, const char);
    void saveFileHelper(TreeNode*, std::ofstream&, const char, const char);

    void deleteAll();
};

#endif // TREE_H
