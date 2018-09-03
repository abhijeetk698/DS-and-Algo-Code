/**
SORT LINKED LIST USING MERGE SORT
Given a linked list with n nodes. Sort the linked list using merge sort.


Input Format:
First line contains the number of nodes in the linked list n and then next line contains n space separated integers representing
the node values of the linked list.

Constraints:
n < 10^4
Output Format:
Print the linked list after sorting it using merge sort.

Sample Input:
5
2 3 4 1 5
Sample Output:
1 2 3 4 5
Explanation:
None

Time Limit: 1 sec
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

void Merge(node* Head1,node* Head2)
{
    node* head1=Head1;
    node* head2=Head2;
    node* temp;
    node* head3=NULL;
    while((head1!=NULL)&&(head2!=NULL)){
    if(head1->data<=head2->data)
    {
        InsertAtEnd(head3,head1->data);
//        temp=head1;
        head1=head1->next;
//        delete temp;
    }
    else
    {
        InsertAtEnd(head3,head2->data);
//        temp=head2;
        head2=head2->next;
//        delete temp;
    }
    }
    while(head1!=NULL)
    {
        InsertAtEnd(head3,head1->data);
//        temp=head1;
        head1=head1->next;
  //      delete temp;
    }
    while(head2!=NULL)
    {
        InsertAtEnd(head3,head2->data);
      //  temp=head2;
        head2=head2->next;
    //    delete temp;
    }
    head1=Head1;
    head2=Head2;
    while(head1->next!=NULL)
    {
        head1->data=head3->data;
        head1=head1->next;
        head3=head3->next;
    }
    head1->data=head3->data;
    head1->next=head2;
    head1=head1->next;
    head3=head3->next;
    while(head1!=NULL)
    {
        head1->data=head3->data;
        head1=head1->next;
        head3=head3->next;
    }
}

void MergeSort(node* &head,int N)
{
    if(N<=1)
    {
        return;
    }
    int n;
    n=(N%2==0)?(N/2):(N/2)+1;
    node* mid=head;
    node* head1;
    int C=n-1;
    while(C--)
    {
        mid=mid->next;
    }
    head1=mid->next;
    mid->next=NULL;
    MergeSort(head,n);
    MergeSort(head1,N-n);
    Merge(head,head1);
}

int main()
{
    int T;
    node* head1=NULL;
    node* head2=NULL;
    node* head3=NULL;
    int A,B,V;
    cin>>A;
    T=A;
//    cin>>B;
    while(A--)
    {
        cin>>V;
        InsertAtEnd(head1,V);
    }
 /*   while(B--)
    {
        cin>>V;
        InsertAtEnd(head2,V);
    }
   */

    MergeSort(head1,T);
    PrintLL(head1);
    return 0;
}
