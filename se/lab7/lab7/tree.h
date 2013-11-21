#ifndef TREE_H
#define TREE_H

#include "treenode.h"

class Tree
{
    TreeNode *root;

    void inorder(TreeNode *node);
    void preorder(TreeNode *node);
    void postorder(TreeNode *node);
public:

    Tree();
    void insert(TreeNode *node);
    void inorder();
    void preorder();
    void postorder();
};

#endif // TREE_H
