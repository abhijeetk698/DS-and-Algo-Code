/**
MERGE LINKED LISTS
Merge two sorted linked lists into one.


Input Format:
Enter N and M (Size of List-1 and List-2 respectively) , Enter space separated N elements for list-1 and M space separated
elements for list-2

Constraints:
None
Output Format:
Linked list of size N+M

Sample Input:
5
4
1 4 5 8 9
2 3 6 7
Sample Output:
1 2 3 4 5 6 7 8 9
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
    node* lastNode=head;
    while(lastNode->next!=NULL)
    {
        lastNode=lastNode->next;
    }
    lastNode->next=temp;
}

void PrintLL(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    return;
}

void Merge(node* head1,node* head2,node* &head3)
{
    node* temp;
    while((head1!=NULL)&&(head2!=NULL)){
    if(head1->data<=head2->data)
    {
        InsertAtEnd(head3,head1->data);
        temp=head1;
        head1=head1->next;
        delete temp;
    }
    else
    {
        InsertAtEnd(head3,head2->data);
        temp=head2;
        head2=head2->next;
        delete temp;
    }
    }
    while(head1!=NULL)
    {
        InsertAtEnd(head3,head1->data);
        temp=head1;
        head1=head1->next;
        delete temp;
    }
    while(head2!=NULL)
    {
        InsertAtEnd(head3,head2->data);
        temp=head2;
        head2=head2->next;
        delete temp;
    }
}

int main()
{
    int T;
    node* head1=NULL;
    node* head2=NULL;
    node* head3=NULL;
    int A,B,V;
    cin>>A;
    cin>>B;
    while(A--)
    {
        cin>>V;
        InsertAtEnd(head1,V);
    }
    while(B--)
    {
        cin>>V;
        InsertAtEnd(head2,V);
    }
    Merge(head1,head2,head3);
    PrintLL(head3);
    return 0;
}
