/**
LINKED LIST - REVERSE A LINKED LIST (RECURSIVE, DATA)
Reverse a linked list by changing the data of its nodes in a recursive manner


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

void InsertNodeAtEnd(node*&head,int data)
{
    node* temp=new node(data);
    node* last_node=head;

    if(head==NULL)
    {
        head=temp;
        return;
    }
    while(last_node->next!=NULL)
    {
        last_node=last_node->next;
    }
    last_node->next=temp;
}
void PrintLL(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
    return;
}

node* ReverseLL(node*head)    /// this function reverses the linked list and returns the head of reversed linked list i.e. tail
{
    if(head->next==NULL||head==NULL)
    {
        return head;
    }
    node* SmallHead=ReverseLL(head->next); /// reverses linked list from head->next to tail
    node* C=head;
    C->next->next=C;                       ///placing head(non reversed) in its correct position on reversed linked list
    C->next=NULL;
    return SmallHead;

}


int main()
{
    node* head=NULL;
    node* temp;
    int N,V;
    cin>>N;
    while(N--)
    {
        cin>>V;
        InsertNodeAtEnd(head,V);

    }
    head=ReverseLL(head);
    PrintLL(head);
    return 0;
}
