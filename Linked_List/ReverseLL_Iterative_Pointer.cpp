/**
LINKED LIST- REVERSE A LINKED LIST( ITERATIVE , POINTER)
Reverse a linked list by changing the polarity of the pointers in an iterative manner


Input Format:
N -> number of nodes N spaces separated numbers -> content of linked list

Constraints:
None
Output Format:
N space separated numbers -> content of reversed linked list

Sample Input:
5
10 20 30 40 50
Sample Output:
50 40 30 20 10
*/

#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

void InsertAtEnd(node* &head,int d)
{
    node* temp=new node(d);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    node* last_Ptr=head;
    while(last_Ptr->next!=NULL)
    {
        last_Ptr=last_Ptr->next;
    }
    last_Ptr->next=temp;
}

void ReverseLL(node* &head)
{
    node* C=head;
    node* P=NULL;
    node* N=head->next;
    while(N!=NULL)
    {
        C->next=P;
        P=C;
        C=N;
        N=N->next;
    }
    C->next=P;
    head=C;
    return;
}

void PrintLL(node* head)
{
    while(head!=0)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    node* head=NULL;
    int V,N;
    cin>>N;
    while(N--)
    {
     cin>>V;
     InsertAtEnd(head,V);
    }
    ReverseLL(head);
    PrintLL(head);
    return 0;
}
