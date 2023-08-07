#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data=d;
        this->next = NULL;
    }
};
void Display(Node * head)
{
    Node *temp=head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void Inserttail(Node * &head ,int d)
{
    if(head == NULL)
    {
        head=new Node(d);
        return;
    }
    Node *temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    Node *nn=new Node(d);
    temp->next=nn;
}
Node *Reverselist(Node *head)
{
    Node *curr=head;
    Node *forward=NULL;
    Node *prev= NULL;
    while(curr != NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

int main()
{
    Node*first=NULL;
    Inserttail(first , 10);
    Inserttail(first , 20);
    Inserttail(first , 30);
    Inserttail(first , 40);
    Display(first);
    first=Reverselist(first);
    Display(first);
 return 0;
}