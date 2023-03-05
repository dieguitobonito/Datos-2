#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "TreeNode.h"
#include "Student.h"

class Tree{
private:
    TreeNode* root;

public:
    Tree() {
        root = nullptr;
    }

    void insert(Student);
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
};

#endif // TREE_H
