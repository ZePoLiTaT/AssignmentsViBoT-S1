#include <iostream>
#include "tree.h"
#include <string.h>

using namespace std;

int main()
{
    Tree ztree;
    TreeNode* node;
    string word="";

    unsigned short nwords;
    cout << "How many words do you want to add to the dictionary?: " << endl;
    cin>>nwords;

    for(unsigned short i=0; i<nwords; i++)
    {
        cout<<"Enter the word to add to the dictionary: ";
        cin>>word;

        node = new TreeNode(word);
        ztree.insert(node);
    }

    cout<<"************PREORDER"<<endl;
    ztree.preorder();
    cout<<"************POSTORDER"<<endl;
    ztree.postorder();
    cout<<"************INORDER"<<endl;
    ztree.inorder();

    return 0;
}

