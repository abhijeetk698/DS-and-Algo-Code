/**
SORT LINKED LIST USING BUBBLE SORT
Given a linked list with n nodes. Sort the linked list using bubble sort.


Input Format:
First line contains the number of nodes in the linked list n and then next line contains n space separated integers representing the node values of the linked list.

Constraints:
n < 30
Output Format:
Print the linked list after sorting it using bubble sort.

Sample Input:
5
2 3 4 1 5
Sample Output:
1 2 3 4 5
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

void Swap(node* &head,int i)
{
    node* temp=head;
    node* temp2;
    if(i==0)
    {
        temp=head->next->next;
        temp2=head->next;
        head->next->next=head;
        head->next=temp;
        head=temp2;
        return;
    }
    i=i-1;
    while(i--)
    {
     temp=temp->next;
    }
    temp2=((temp->next)->next)->next;
    node* temp3=(temp->next)->next;
    ((temp->next)->next)->next=temp->next;
    temp->next->next=temp2;
    temp->next=temp3;
}

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

void BubbleSort(node* &head,int N)
{
    node* temp=head;
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<N-1-i;j++)
        {
            if(temp->data>temp->next->data)
            {
                Swap(head,j);
            }
            else
            {
                temp=temp->next;
            }
        }
        temp=head;
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
    BubbleSort(head,n);
    PrintLL(head);
    return 0;
}
