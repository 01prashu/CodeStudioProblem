#include "Tree.h"
/* we have to check whether tree is heigth balanced or not
If tree is height balanced then (heigth of left subtree - heigth of right subtree <=1 )


***Approche******
check leftsubtree , rightSubtree are balanced and subtraction of there height
must be less than or equal to 1
*/
int height(Node * root)
{
    if(root == NULL)
    {
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);

    int ans=max(h1 , h2)+1;
    return ans;
}
bool isBalancedBT(Node * root){
    if(root == NULL)
    {
        return true;
    }
    bool leftBalance=isBalancedBT(root->left);
    bool rightBalance=isBalancedBT(root->right);
    bool checkheight=abs(height(root->left)-height(root->right))<=1;

    if(leftBalance && rightBalance && checkheight)
    {
        return true;
    }
    return false;
}
int main()
{
    Node *root=NULL;
    root=BuildTree(root);
    LevelOrderTraversal(root);
    cout<<endl;
    bool ans =isBalancedBT(root);
    
    if(ans)
    {
        cout<<"Tree is Height Balanced: ";
        cout<<"Subtraction of there Left and right subtree is less than or equal to 1"<<endl;

    }
    else
    {
        cout<<"Tree is Not Heigth Balanced"<<endl;
    }
    
    return 0;
}