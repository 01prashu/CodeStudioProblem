/*Diameter Of Tree--Maximum Path between two node
two node may be lies in 1)Right Subtree 2)Left Subtree 3)Right and left subtree..
*/ 
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left= NULL;
        this->right= NULL;
    }
};
Node *BuitTree(Node *root)
{
    cout<<"Enter Data:";
    int d;
    cin>>d;
    root=new Node(d);
    if(d== -1)
    {
        return NULL;
    }
    cout<<"Inserting left of "<<d<<endl;
    root->left=BuitTree(root->left);
    cout<<"Inserting Right Of "<<d<<endl;
    root->right=BuitTree(root->right);
    return root;
}
int height(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int h1=height(root ->left);
    int h2=height(root->right);
    int h3=max(h1 ,h2)+1;
    return h3;
}
int DiameterOfTree(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int op1=DiameterOfTree(root->left);
    int op2=DiameterOfTree(root->right);
    int op3=height(root->left)+height(root->right);

    int ans=max(op1 , max(op2 , op3));
    return ans;
}
int main()
{
    Node * root=NULL;
    root=BuitTree(root);
    cout<<"Diameter Is:"<<DiameterOfTree(root)<<endl;
    return 0;
}

/*Time Complexity : O(n^2) 
DiameterOfTree --takes O(n)
but it calling height another function which takes again O(n)
so , It's Complexity Become O(n^2)
*/