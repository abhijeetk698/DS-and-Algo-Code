#include <iostream>
using namespace std;
class Stack{
private:
    class Node{
    public:
        int data;
        Node* next;
    };
    Node* head;
    int sze;
public:
    Stack(){
    head = NULL ;
    sze=0;
    }
    bool Empty()
    {
        return head==NULL;
    }
    void push(int x)
    {
        Node* temp;
        temp=new Node;
        temp->next=head;
        temp->data=x;
        head=temp;
        ++sze;
        return;
    }
    void pop()
    {
        if(Empty())
        {
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
        --sze;
    }

    int top()
    {
        if(Empty())
        {
            return -1;
        }
        return head->data;
    }
    int Size()
    {
        return sze;
    }
    ~Stack()
    {
        while(Empty())
        {
            pop();
        }
    }
};

int main()
{
    Stack s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    return 0;
}
