/**
LL - DELETE THE DUPLICATES
Eliminate duplicates from a sorted linked list


Input Format:
First line contains T the number of test cases.

For every test case, the first line contains the number of integers N in the linked list.

The next line contains N space separated integers.

Constraints:
1 <= T <= 1000
0 <= N <= 10^7
Elements in LL <= 10^6
Output Format:
T lines each containing linked list with the unique values

Sample Input:
2
8
1 1 2 3 5 6 7 7
2
2 3
Sample Output:
1 2 3 5 6 7
2 3
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

void PrintLL(node* head)
{
    while(head!=0)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

void DeleteNode(node* ptr)
{
    if(ptr->next==NULL)
    {
        return;
    }
    node* temp=ptr->next;
    ptr->next=ptr->next->next;
    delete temp;
}
void DeleteDuplicates(node* head)
{
    if(head==NULL||(head->next)==NULL)
    {
        return;
    }
    node* temp=head;
    while(temp->next!=NULL&&temp!=NULL)
    {
        if(((temp->next)->data)==(head->data))
        {
            DeleteNode(temp);
        }
        if(temp->next==NULL)
        {
            break;
        }
        temp=temp->next;
    }
    DeleteDuplicates(head->next);
}
int main()
{
    int N,V,T;
    cin>>T;
    while(T--)
    {
    node* head=NULL;
    cin>>N;
    while(N--)
    {
        cin>>V;
        InsertAtEnd(head,V);
    }
    DeleteDuplicates(head);
    PrintLL(head);
    while(head->next!=NULL)
    {
        DeleteNode(head);
    }
    delete head;
    }
    return 0;
}
