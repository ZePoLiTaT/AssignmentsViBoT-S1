#ifndef TREENODE_H
#define TREENODE_H
#include <iostream>
using namespace std;

class TreeNode
{
    string word;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode();
    TreeNode(string pname);

    friend class Tree;
};
#endif // TREENODE_H
