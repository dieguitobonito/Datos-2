#include "Tree.h"

void Tree::insert(Student data){
    if(root == nullptr){
        root = new TreeNode(data);
    }else{
        TreeNode* current = root;
        while(true){
            if(data.name < current->data.name){
                if (current->left == nullptr){
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
