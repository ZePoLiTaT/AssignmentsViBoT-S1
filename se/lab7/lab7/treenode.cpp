#include "treenode.h"
#include <iostream>

TreeNode::TreeNode()
{
    word = "";
    left = NULL;
    right = NULL;
}

TreeNode::TreeNode(string pname)
{
    word = pname;
    left = NULL;
    right = NULL;
}

TreeNode::TreeNode(const TreeNode &copy)
{
    word = copy.word;
    left = NULL;
    right = NULL;
}

ostream &operator <<(ostream &os, const TreeNode &tnode)
{
    os<<"word: "<<tnode.word<<" ";
}

