#include <iostream>
#include "tree.h"
#include <string.h>

using namespace std;

int main()
{
    Tree ztree;
    TreeNode* node;

    unsigned short nwords;

    char n[] = "n";
    char z[] = "z";
    char y[] = "y";

    cout<<strcmp(z,n)<<endl;
    cout<<strcmp(z,y)<<endl;

    cout << "Please enter the number of words:" << endl;
    cin>>nwords;

    for(unsigned short i=0; i<nwords; i++)
    {
        string word="";
        cin>>word;

        node = new TreeNode(word);
        ztree.insert(node);
    }

    cout<<"************INORDER"<<endl;
    ztree.inorder();
    cout<<"************PREORDER"<<endl;
    ztree.preorder();
    cout<<"************POSTORDER"<<endl;
    ztree.postorder();

    return 0;
}

