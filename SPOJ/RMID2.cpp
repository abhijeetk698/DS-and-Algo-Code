/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

#define ll long long
#define MOD 1000000007
#define dd double
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep1(i,b) for(int i=1;i<=b;i++)
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll int N;
        priority_queue<ll int> MaxHeap;
        priority_queue<ll int,vector<ll int>,greater<ll int> > MinHeap;
        while(1)
        {
            cin>>N;
            if(N==0){
                break;
            }
            if(N==-1)
            {
                if(!MaxHeap.empty()){
                cout<<MaxHeap.top()<<endl;
                MaxHeap.pop();
                while(MinHeap.size()>MaxHeap.size())
                {
                    MaxHeap.push(MinHeap.top());
                    MinHeap.pop();
                }
            }
            }   
            else{
                if(MaxHeap.empty()){
                    MaxHeap.push(N);
                }
                else{
                if(N<=MaxHeap.top())
                {
                    if((MaxHeap.size()-MinHeap.size())==1)
                    {
                        MinHeap.push(MaxHeap.top());
                        MaxHeap.pop();
                    }
                    MaxHeap.push(N);
                }
                else{
                 if((MaxHeap.size()-MinHeap.size())==1)
                    {
                        MinHeap.push(N);
                    }
                    else{
                        if(N<MinHeap.top()){
                        MaxHeap.push(N);}
                        else{
                            MaxHeap.push(MinHeap.top());
                            MinHeap.pop();
                            MinHeap.push(N);
                        }
                    }
                }
            }
            }

        }
        cout<<endl;
    }
    return 0;
}
