// #include<iostream>
// Reverse level order traversal of a tree
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
Node *BuildTree(Node *root)
{
    cout<<"Enter Data:";
    int d;
    cin>>d;
    root=new Node(d);
    if(d == -1)
    {
        return NULL;
    }
    cout<<"Insert Data for Left Of "<<d<<endl;
    root->left=BuildTree(root->left);
    cout<<"Insert Data for Right Of "<<d<<endl;
    root->right=BuildTree(root->right);
    return root;
}
vector<int>ReverseLevelOrder(Node *root)
{
    queue<Node *>q;
    vector<int>ans;

    q.push(root);
    while(!q.empty())
    {
        Node *t=q.front();
        ans.push_back(t->data);
        q.pop();
        if(t->left)
        {
            q.push(t->left);
        }
        if(t->right)
        {
            q.push(t->right);
        }
    }
    reverse(ans.begin() , ans.end());
    return ans;

}
int main()
{
    Node *root=NULL;
    root=BuildTree(root);
    vector<int>ans;
    ans = ReverseLevelOrder(root);
    for(auto t:ans)
    {
        cout<<t<<" ";
    }
    return 0;
}