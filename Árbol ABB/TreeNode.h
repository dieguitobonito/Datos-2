#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include "Student.h"

class TreeNode{
 public:
        Student data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(Student data) {
                this->data = data;
                left = nullptr;
                right = nullptr;
        }
};


#endif // TREENODE_H
