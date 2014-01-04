#ifndef TREE_H
#define TREE_H

#include "treenode.h"

/**
 * @class Tree
 * @brief Tree used to store a dictionary of words stored
 * according to the lexical order of its TreeNode s.
 */
class Tree
{
    TreeNode *root;     /** Root of the Tree */

    /**
     * @brief Traverses the Tree in INORDER, which means first visits
     * the left node, then the root and finally the right node (LEFT ROOT RIGHT)
     * starting by the TreeNode given by the parameter
     * @param node Starting TreeNode point
     */
    void inorder(TreeNode *node);

    /**
     * @brief Traverses the Tree in PREORDER, which means first visits
     * the root, then the left node and finally the right node (ROOT LEFT RIGHT)
     * starting by the TreeNode given by the parameter.
     * @param node Starting TreeNode point
     */
    void preorder(TreeNode *node);

    /**
     * @brief Traverses the Tree in POSTORDER, which means first visits
     * the left node, the right node and finally the root (LEFT RIGHT ROOT)
     * starting by the TreeNode given by the parameter.
     * @param node Starting TreeNode point
     */
    void postorder(TreeNode *node);

    /**
     * @brief Tree::deleteRec Deletes recursively the TreeNode s of the Tree
     * This is a helper function called by the destructor of the class
     * @param curr Starting point of the deletion
     */
    void deleteRec(TreeNode* curr);
public:

    /**
     * @brief Tree Default constructor of the class which initalizes the
     * root to NULL
     */
    Tree();

    /**
     * @brief Destructor of the class which releases
     * the memory for all the elements in the Tree
     */
    ~Tree();

    /**
     * @brief insert a TreeNode into the Tree in lexical order.
     * If there is no root, the root is set to the TreeNode given by the parameter.
     * Otherwise, it takes into account the lexical comparation of
     * the insertNode and the current node of the tree that is being evaluated.
     * If it is lexically less
     * then the search continues by the left branch. If it is lexically greater
     * then the search continues by the right branch.
     * If another TreeNode with the same word already exists, then no insertion
     * is performed
     * @param node TreeNode to insert into the Tree
     */
    void insert(TreeNode *insertNode);

    /**
     * @brief Traverses the Tree in INORDER, which means first visits
     * the left node, then the root and finally the right node starting by the root:
     * LEFT ROOT RIGHT
     */
    void inorder();

    /**
     * @brief Traverses the Tree in PREORDER, which means first visits
     * the root, then the left node and finally the right node starting by the root:
     * ROOT LEFT RIGHT
     */
    void preorder();

    /**
     * @brief Traverses the Tree in POSTORDER, which means first visits
     * the left node, the right node and finally the root  starting by the root:
     * LEFT RIGHT ROOT
     */
    void postorder();
};

#endif // TREE_H
