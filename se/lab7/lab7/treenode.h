#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

/**
 * @class TreeNode
 * @brief TreeNode : Represents a single Tree Node which
 * holds the information about the content of type string
 * and a pointer to the left and right TreeNode.
 * This class is meant to work with the Tree class
 */
class TreeNode
{
    string word;        /** The data of type string */
    TreeNode *left;     /** A pointer to the left node */
    TreeNode *right;    /** A pointer to the right node */

public:
    /**
     * @brief TreeNode Default constructor of the class.
     * Initializes the word to an empty string and the
     * left and right pointers to NULL
     */
    TreeNode();

    /**
     * @brief TreeNode Data constructor which initalizes
     * the word to the parameter given by pname.
     * The left and right pointers are initialized to NULL
     * @param pname The value used to initialize the data of the TreeNode
     */
    TreeNode(string pname);

    /**
     * @brief TreeNode Copy constructor which copies the word data only.
     * The left and right pointers are initialized to NULL
     * @param copy TreeNode from which the data will be copied
     */
    TreeNode(const TreeNode &copy);

    /**
     * Declaration of the class Tree as a friend of the TreeNode
     * to give acess to the private attributes
     */
    friend class Tree;

    /**
     * @brief operator << overloaded to output the relevant information (word)
     * of TreeNoe into the ostream os.
     * @param os ostream class into which will be appended the information of the TreeNode
     * @param tnode The TreeNode object from which the information will be extraced
     * @return a reference of the ostream class
     */
    friend ostream& operator <<(ostream &os, const TreeNode &tnode);
};
#endif // TREENODE_H
