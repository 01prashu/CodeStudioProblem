#include <iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};
typedef class Node* PNODE;
class SinglyLL
{
    public:
    int size;
    PNODE first;
    SinglyLL()
    {
        this->size=0;
        first=NULL;
    }
    void Inserthead(int d);
    void Inserttail(int d);
    int count();
    void Display();
};
void SinglyLL::Inserthead(int d)
{
    PNODE nn = new Node(d);
    nn->next=first;
    first=nn;
    size++;
}
void SinglyLL::Inserttail(int d)
{
    PNODE nn=new Node(d);
    if(first == NULL)
    {
        first=nn;
        size++;
    }
    else
    {
        PNODE temp=first;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
        temp=nn;
        size++;
    }
    
}
int SinglyLL::count()
{
    return size;
}
void SinglyLL::Display()
{
    PNODE temp=first;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}