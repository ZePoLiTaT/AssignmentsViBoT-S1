#include "tree.h"
#include <string.h>
#include <iostream>

using namespace std;

Tree::Tree()
{
    root = NULL;
}

void Tree::insert(TreeNode *node)
{
    int lexcomp;
    if(root==NULL)
    {
        root = node;
        return;
    }

    TreeNode *curr = root;


    while(curr!=NULL)
    {
        lexcomp = node->word.compare(curr->word);
        if(lexcomp<0)
        {
            if(curr->left == NULL)
            {
                curr->left = node;
                curr = NULL;
            }
            else
                curr = curr->left;
        }
        else if(lexcomp>0)
        {
            if(curr->right == NULL)
            {
                curr->right = node;
                curr = NULL;
            }
            else
                curr = curr->right;
        }
    }
}

void Tree::inorder(TreeNode *curr)
{
    if(curr==NULL)
        return;

    cout<<(curr->word)<<endl;
    inorder(curr->left);
    inorder(curr->right);
}

void Tree::preorder(TreeNode *curr)
{
    if(curr==NULL)
        return;

    inorder(curr->left);
    cout<<(curr->word)<<endl;
    inorder(curr->right);
}

void Tree::postorder(TreeNode *curr)
{
    if(curr==NULL)
        return;

    inorder(curr->left);
    inorder(curr->right);
    cout<<(curr->word)<<endl;
}

void Tree::inorder()
{
    inorder(root);
}

void Tree::preorder()
{
    preorder(root);
}

void Tree::postorder()
{
    postorder(root);
}
