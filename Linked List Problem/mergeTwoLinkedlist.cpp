#include "linkedlist.h"
PNODE MergeSortedLinkedList(PNODE first , PNODE second)
{
    PNODE dummy=new Node(-99);
    if(first == NULL)
    {
        return second;
    }
    else if(second == NULL)
    {
        return first;
    }
    
    else 
    {
        
        PNODE temp=dummy;
        while(first != NULL && second!= NULL)
        {
            if((first->data<= second->data))
            {
                temp->next=first;
                temp=temp->next;
                first=first->next;
            }
            else
            {
                temp->next=second;
                temp=temp->next;
                second=second->next;
            }
            
        }
        if(first != NULL)
        {
            temp->next=first;
        }
        else if(second != NULL)
        {
            temp->next=second;
        }
        return dummy->next;
    }
    return dummy->next;
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
    ans->first=MergeSortedLinkedList(Firstobj->first , Secondobj->first);
    ans->Display();
    return 0;
}