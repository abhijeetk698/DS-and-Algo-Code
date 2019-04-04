/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

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
        ll int a,b,c,n;
        cin>>a>>b>>c>>n;
        ll int arr[n+1];
        priority_queue<ll int,vector<ll int>,greater<ll int> > MinHeap;
        priority_queue<ll int> MaxHeap;
        arr[0]=0;
        arr[1]=1;
        MaxHeap.push(1);
        for(int i=2;i<=n;i++)
        {
            ll int V=(MaxHeap.top()*a+b*i+c)%MOD;
            arr[i]=V;
            if(V<=MaxHeap.top()){
                MaxHeap.push(V);
            }
            else{
                MinHeap.push(V);
            }
            while(MinHeap.size()>MaxHeap.size())
            {
                ll int K=MinHeap.top();
                MinHeap.pop();
                MaxHeap.push(K);
            }
            while((MaxHeap.size()-MinHeap.size())>1)
            {
                ll int K=MaxHeap.top();
                MaxHeap.pop();
                MinHeap.push(K);
            }
        }
        ll int sum=0;
        for(int i=0;i<=n;i++)
        {
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
