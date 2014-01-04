#include "tree.h"
#include <string.h>
#include <iostream>

using namespace std;

Tree::Tree()
{
    root = NULL;
}

Tree::~Tree()
{
    deleteRec(root);
}

void Tree::deleteRec(TreeNode* curr)
{
    if(curr==NULL)
        return;

    deleteRec(curr->left);
    deleteRec(curr->right);
    cout<<"Deleting "<<*curr<<endl;
    delete curr;
}

void Tree::insert(TreeNode *insertNode)
{
    //If there is no root, then set root to current insert node
    if(root==NULL)
    {
        root = insertNode;
        return;
    }

    TreeNode *curr = root;
    int lexcomp;

    //Otherwise, find the correct place to insert the element
    while(curr!=NULL)
    {
        //Take into account the lexical comparation of
        //the insertNode and the current node of the tree that is being evaluated
        lexcomp = insertNode->word.compare(curr->word);

        if(lexcomp<0)
        {
            if(curr->left == NULL)
            {
                curr->left = insertNode;
                curr = NULL;
            }
            else
                curr = curr->left;
        }
        else if(lexcomp>0)
        {
            if(curr->right == NULL)
            {
                curr->right = insertNode;
                curr = NULL;
            }
            else
                curr = curr->right;
        }
        else
            break;  //If other node is equal, then no insertion is performed!s
    }
}

void Tree::inorder(TreeNode *curr)
{
    if(curr==NULL)
        return;

    inorder(curr->left);
    cout<<*curr<<endl;
    inorder(curr->right);
}

void Tree::preorder(TreeNode *curr)
{
    if(curr==NULL)
        return;

    cout<<*curr<<endl;
    preorder(curr->left);
    preorder(curr->right);
}

void Tree::postorder(TreeNode *curr)
{
    if(curr==NULL)
        return;

    postorder(curr->left);
    postorder(curr->right);
    cout<<*curr<<endl;
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
