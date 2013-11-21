#include "treenode.h"
#include <iostream>

TreeNode::TreeNode()
{

}

TreeNode::TreeNode(string pname)
{
    word = pname;
    left = NULL;
    right = NULL;
}

