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

int BinSearch(int*arr,int s,int e,int K)
{
    if(s>e){
        return -1;
    }
    if(s==e){
        if(arr[s]<K){return s;}
        return -1;
    }
    if((e-s)==1)
    {
        if(arr[s]<K){
            return s;
        }
        if(arr[e]<K){
            return e;
        }
        return -1;
    }
    int mid=(s+e)/2;
    if(arr[mid]<K){
        return BinSearch(arr,s,mid,K);
    }
    return BinSearch(arr,mid+1,e,K);
}

int LIS2(int*arr,int N)
{
    int S[N+1];
    int n=1;
    S[n]=arr[0];
    for(int i=1;i<N;i++)
    {
        if(arr[i]<=S[n])
        {
            n++;
            S[n]=arr[i];
        }
        else{
            int index=BinSearch(S,1,n,arr[i]);
            S[index]=arr[i];
        }
    }
    return n;
}

class Mypair{
public:
    int width;
    int height;
};

bool comparator(Mypair a,Mypair b)
{
    if(a.width<b.width){return true;}
    else if(a.width==b.width){
        if(a.height>b.height){return true;}
        else{return false;}
    }
    else{return false;}
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    int N;
    cin>>N;
    Mypair arr[N];
    for(int i=0;i<N;i++){
        cin>>arr[i].width;
        cin>>arr[i].height;
    }
    sort(arr,arr+N,comparator);
    int arr2[N];
    for(int i=0;i<N;i++)
    {
        arr2[i]=arr[i].height;
    }
    cout<<LIS2(arr2,N)<<endl;
    }
    return 0;
}
