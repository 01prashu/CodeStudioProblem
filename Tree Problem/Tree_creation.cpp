#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
Node *builtTree(Node *root)
{
    int data;
    cout<<"Enter Data for Node: ";
    cin>>data;
    root=new Node(data);
    if(data == -1)
    {
        return NULL;
    }
    cout<<"Enter Data For Inserting Left Of "<<data<<endl;
    root->left=builtTree(root->left);
    cout<<"Enter Data For Inserting Right Of "<<data<<endl;
    root->right=builtTree(root->right);
    return root;
}
void levelOrderTraversal(Node *root)
{
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
        Node *temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left != NULL)
        {
            q.push(temp->left);
        }
        if(temp->right != NULL)
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    Node *root=NULL;
    //Built Tree
    root=builtTree(root);
    levelOrderTraversal(root);
    return 0;
}
