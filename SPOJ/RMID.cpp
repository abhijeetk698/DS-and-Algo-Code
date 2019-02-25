#include <bits/stdc++.h>
using namespace std;


int main()
{
    while(!feof(stdin)){
    int n;
    int Median=INT_MAX;
    int Sze1=0,Sze2=0;
    priority_queue<int> Maxheap;
    priority_queue<int,vector<int>,greater<int> > Minheap;
    while(cin>>n)
    {
        if(n==0){break;}
        if(n==-1)
        {
            if(Sze1>=Sze2)
            {
                Maxheap.pop();
                Sze1--;
                cout<<Median<<endl;
            }
            else
            {
                Minheap.pop();
                Sze2--;
                cout<<Median<<endl;
            }
            if(Sze1>=Sze2){Median=Maxheap.top();}
            else{Median=Minheap.top();}
    }
    else{
        if(n<Median){Maxheap.push(n);
        Sze1++;}
        else{Minheap.push(n);
        Sze2++;}
        if((Sze1-Sze2)>1)
        {
            while((Sze1-Sze2)>1)
            {
                int d=Maxheap.top();
                Maxheap.pop();
                Minheap.push(d);
                Sze1--;
                Sze2++;
            }
        }
        if((Sze2-Sze1)>1)
        {
            int d=Minheap.top();
            Minheap.pop();
            Maxheap.push(d);
            Sze2--;
            Sze1++;
        }
        if(Sze1>=Sze2){Median=Maxheap.top();}
        else{Median=Minheap.top();}
    }
    }
    cout<<endl;
    }
    return 0;
}
