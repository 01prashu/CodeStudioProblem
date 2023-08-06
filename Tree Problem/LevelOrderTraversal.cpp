#include<iostream>
#include <vector>
#include <queue>
using namespace std;
template<typename T>
class Node
{
    public:
    T data;
    Node <T>* left;
    Node <T>* right;
    Node (T d)
    {
        this->data=d;
        this->left = NULL;
        this->right = NULL;
    }
};
template<typename T>
Node<T>* BuiltTree()
{
    cout << "Enter Data: ";
    T d;
    cin >> d;
    if (d == -1)
    {
        return nullptr;
    }

    Node<T>* root = new Node<T>(d);

    cout << "Enter data for left of " << d << endl;
    root->left = BuiltTree<T>();

    cout << "Enter data for right of " << d << endl;
    root->right = BuiltTree<T>();

    return root;
}
vector<int>LevelOrderTraverse(Node <int>*root)
{
    vector<int>ans;
    queue<Node<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        Node <int>*t=q.front();
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
    return ans;
}
int main()
{
    Node<int> *root ;
    root=BuiltTree<int>();
    vector<int>ans;
    ans=LevelOrderTraverse(root);
    for(auto t:ans)
    {
        cout<<(t)<<" ";
    }
    return 0;
}