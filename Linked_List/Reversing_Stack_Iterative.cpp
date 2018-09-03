/**
LINKED LIST - REVERSE A LINKED LIST (ITERATIVE, DATA)
Reverse a linked list by changing the data of its nodes in an iterative manner


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
    node* LastNode=head;
    while(LastNode->next!=NULL)
    {
        LastNode=LastNode->next;
    }
    LastNode->next=temp;
    return;
}

void PrintLL(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void Reverse(node* Head,int N)
{
    node* head=Head;
    node* tail=NULL;
    int n=N/2;
    int V;
    while(n--)
    {
        while(head->next!=tail)
        {
            head=head->next;
        }
        tail=head;
        head=Head;
        V=head->data;
        head->data=tail->data;
        tail->data=V;
        Head=Head->next;
    }
}

int main()
{
    node* head=NULL;
    int N,V,n;
    cin>>N;
    n=N;
    while(N--)
    {
        cin>>V;
        InsertAtEnd(head,V);
    }
    Reverse(head,n);
    PrintLL(head);
    return 0;
}
