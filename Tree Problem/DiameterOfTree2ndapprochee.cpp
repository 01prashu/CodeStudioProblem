/*Diameter Of Tree--Maximum Path between two node
two node may be lies in 1)Right Subtree 2)Left Subtree 3)Right and left subtree..

***************************2nd Approches**********************************
This Opproche Work in O(n) Time Complexity
Insted Of making another function for height we are making pair Of diameter and height
so , In a single recursive call we get height and Diameter
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
pair<int , int>DiameterOfTreeFast(Node *root)
{
    pair<int , int>ans; //pair<Diameter , Height>
    if(root == NULL)
    {
        pair<int ,int>p=make_pair(0,0);
        return p;
    }

    pair<int , int>left=DiameterOfTreeFast(root->left);
    pair<int , int>right=DiameterOfTreeFast(root->right);
    int leftright=left.second + right.second;
    int ans=max(left.first ,max(right.first , leftright));
    return ans;
}
int DiameterOfTree(Node *root)
{    

}
int main()
{
    Node * root=NULL;
    root=BuitTree(root);
    cout<<"Diameter Is:"<<DiameterOfTree(root)<<endl;
    return 0;
}