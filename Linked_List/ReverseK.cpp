/**
REVERSE-K
Implement k Reverse (int k) i.e. you have to reverse first K elements then reverse next K elements and join the linked list and
so on. 3 → 4 → 5 → 2 → 6 → 1 → 9 for k reverse(3) becomes 5 → 4 → 3 → 1 → 6 → 2 → 9 → 1. If k is greater than the size of rest
linked list then reverse the rest part. Ex. For linked list 5 → 4 → 3 → 1 and k =5. Output should be 1 → 3 → 4 → 5


Input Format:
First line contains number of test cases. For each test case there are three lines. First line contains size N , 2nd line contains
N space separated elements and third line contains value of K ( no. of elements to be reversed)

Output Format:
Display the resulting Linked List

Sample Input:
1
8
1 2 3 4 5 6 7 8
3
Sample Output:
3 2 1 6 5 4 8 7
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
    node* LastPtr=head;
    while(LastPtr->next!=NULL)
    {
        LastPtr=LastPtr->next;
    }
    LastPtr->next=temp;
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


void ReverseAtStarting(node*&head,int K)
{
    node* temp1=head;
    node* temp2;
    node* temp3=head;
    int C=K-1;
    while(C--)
    {
        temp1=temp1->next;
    }
    temp2=temp1->next;
    temp1->next=NULL;
    ReverseLL(head);
    temp3->next=temp2;
    return;
}

void ReverseAtMiddle(node* temp,int K)
{
    node* temp1=temp->next;
    node* temp2;
    node* temp3=temp->next;
    int C=K-1;
    while(C--)
    {
        temp1=temp1->next;
    }
    temp2=temp1->next;
    temp1->next=NULL;
    ReverseLL(temp->next);
    temp3->next=temp2;
    temp->next=temp1;
}

void ReverseAtEnd(node* temp)
{
    if(temp==NULL||temp->next==NULL)
    {
        return;
    }
    node* LastNode=temp;
    while(LastNode->next!=NULL)
    {
        LastNode=LastNode->next;
    }
    ReverseLL(temp->next);
    temp->next=LastNode;
}

void ReverseK(node* &head,int K,int N)
{
    if(N==K)
    {
        ReverseLL(head);
        return;
    }
    int C=N/K;
    node*temp1=head;
    node* temp2;
    ReverseAtStarting(head,K);
    C--;
    while(C--)
    {
        temp2=temp1->next;
        ReverseAtMiddle(temp1,K);
        temp1=temp2;
    }
    ReverseAtEnd(temp1);
    return;
}

int main()
{
  int T;
  cin>>T;
  while(T--){
  int N,V,n,K;
  node* head=NULL;
  cin>>N;
  n=N;
  while(N--)
  {
      cin>>V;
      InsertAtEnd(head,V);
  }
  cin>>K;
  ReverseK(head,K,n);
  PrintLL(head);
  }
  return 0;
}
