#include "linkedlist.h"
#include<unordered_map>
Node * findIntersection(Node *firstHead, Node *secondHead)
{
	unordered_map<Node* , bool>mp;
	if(firstHead == NULL)
	{
		return NULL;
	}
	else if(secondHead == NULL)
	{
		return NULL;
	}
	Node *temp1=firstHead;
	Node *temp2=secondHead;
	while(temp1 != NULL)
	{
		if(mp[temp1] == false)
		{
			mp[temp1]=true;
		}
		else
		{
			return temp1;
		}
		temp1=temp1->next; 
	}
	while(temp2 != NULL)
	{
		if(mp[temp2] == false)
		{
			mp[temp2]=true;
		}
		else
		{
			return temp2;
		}
		temp2=temp2->next; 
	}
	return NULL;

}
int main()
{
    SinglyLL *Firstobj=new SinglyLL();
    Firstobj->Inserttail(10);
    Firstobj->Inserttail(20);
    Firstobj->Inserttail(30);
    Firstobj->Inserttail(40);
    Firstobj->Inserttail(50);
    Firstobj->Display();
    cout<<"Size of First Linked list: "<<Firstobj->count()<<endl;;

    SinglyLL *Secondobj=new SinglyLL();
    Secondobj->Inserttail(11);
    Secondobj->Inserttail(15);
    Secondobj->Inserttail(22);
    Secondobj->Inserttail(100);
    Secondobj->Display();
    cout<<"Size Of Second Linked list:"<<Secondobj->count()<<endl;

    cout<<"**************************************************************"<<endl;
    SinglyLL *ans=new SinglyLL();
    ans->first=findIntersection(Firstobj->first , Secondobj->first);
    ans->Display();
    return 0;
}