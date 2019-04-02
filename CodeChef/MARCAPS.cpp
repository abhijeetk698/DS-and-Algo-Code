//question code:= MARCAPS (Markers and Caps)
//question link:= https://www.codechef.com/problems/MARCAPS
//concept used : ad-hoc
//time complexity :O(N)
/*************************CODE*****************************/

/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>
#include <algorithm>

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

bool comparator(pair<ll int,int> a,pair<ll int,int> b)
{
    return a.first<b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        ll int N;
        cin>>N;
        pair<ll int,int> arr[N];
        for(int i=0;i<N;i++)
        {
            ll int V;
            cin>>V;
            arr[i].first=V;
            arr[i].second=i;
        }
        sort(arr,arr+N,comparator);
        ll int h=N/2;
        ll int C=0;
        ll int j=arr[0].first;
        bool ans=true;
        for(int i=0;i<N;i++)
        {
            if(arr[i].first==j){
                C++;
            }
            else{
                j=arr[i].first;
                C=1;
            }
            if(C>h){
                ans=false;
                break;
            }
        }
        ll int temp[N];
        for(int i=0;i<N;i++)
        {
            int ind=(i+h)%N;
            temp[arr[i].second]=arr[ind].first;
        }
        if(ans){
            cout<<"Yes"<<endl;
            for(int i=0;i<N;i++)
            {
                cout<<temp[i]<<" ";
            }
            cout<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
