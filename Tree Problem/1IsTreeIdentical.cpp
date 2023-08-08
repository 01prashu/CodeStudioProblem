#include "Tree.h"
/* Using Iterative Approche
--->Use Any Traversal stored data in array
--->Compare those data
--->If Data are same means Tree Identical
*/

bool IsTreeIdentical(Node *root1, Node *root2)
{
    vector<int> T1 ,T2;
    InorderTraversal(root1 , T1);
    InorderTraversal(root2 , T2);
    int size1 = T1.size();
    int size2 = T2.size();

    if (size1 != size2)
    {
        return false;
    }
    
    else
    {
        int s1 = 0;
        int s2 = 0;
        while (s1 < size1 && s2 < size2)
        {
            if (T1[s1] != T2[s2])
            {
                return false;
            }
            ++s1;
            ++s2;
        }
        return true;
    }
    
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
}