#include "Tree.h"
bool IsTreeIdentical(Node *root1, Node *root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return true;
    }
    bool isLeft=IsTreeIdentical(root1->left , root2->left);
    bool isRight=IsTreeIdentical(root1->right,root2->right);
    bool checkdata=(root1->data == root2->data);

    if(isLeft && isRight && checkdata)
    {
        return true;
    }
    return false;
}
int main()
{
    Node *root1 = NULL;
    cout << "Build Tree1" << endl;
    root1 = BuildTree(root1);

    Node *root2 = NULL;
    cout << "Build Tree2" << endl;
    root2 = BuildTree(root2);
    cout << IsTreeIdentical(root1, root2) << endl;
    return 0;
}