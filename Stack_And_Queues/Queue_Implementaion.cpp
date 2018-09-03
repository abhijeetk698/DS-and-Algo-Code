#include <iostream>

using namespace std;

class Queue
{
private:
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
    node* head;
    node* tail;
public:
    Queue()
    {
        head=NULL;
        tail=NULL;
    }

    bool Empty()
    {
        return (head==NULL);
    }

    void Enqueue(int d)
    {
        node* temp=new node(d);
        if(Empty())
        {
            head=temp;
            tail=head;
        }
        tail->next=temp;
        tail=temp;
    }
    void Dequeue()
    {
        if(Empty())
        {
            return;
        }
        node* temp=head;
        head=head->next;
        delete temp;
    }

    int Front()
    {
        if(Empty())
        {
            return -1;
        }
        return head->data;
    }

};


int main()
{
    Queue Q;
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Enqueue(4);
    cout<<Q.Front();
    return 0;
}
