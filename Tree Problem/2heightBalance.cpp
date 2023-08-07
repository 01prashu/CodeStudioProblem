#include "Tree.h"
pair<bool , int>solve(Node *root)
{
    if(root == NULL)
    {
        pair<bool , int>m=make_pair(true ,0);
        return m;
    }
    pair<bool , int>leftsolve=solve(root->left);
    pair<bool , int>rightsolve=solve(root->right);
    int height=max(leftsolve.second , rightsolve.second)+1;
    bool checkheigth=abs(leftsolve.second - rightsolve.second) <=1;

    bool ans=leftsolve.first && rightsolve.first && checkheigth;
    pair<bool , int>m;
    if(ans)
    {
        m=make_pair(ans , height);
        return m;
    }
    m=make_pair(false , height);
    return m;

}
bool IsheightBT(Node *root)
{
    return solve(root).first;
}
int main()
{
    Node *root=NULL;
    root=BuildTree(root);
    LevelOrderTraversal(root);

    cout<<IsheightBT(root)<<endl;
    return 0;
}