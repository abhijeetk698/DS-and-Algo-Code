/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/


#include <bits/stdc++.h>
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

map<int,int> m;
int lhs[1000000];
int LeftmostIndex(int*arr,int s,int e,int K)
{
    if(e-s==1){
        if(arr[s]==K){return s;}
        if(arr[e]==K){return e;}
        return -1;
    }
    if(s==e){
        if(arr[s]==K){return s;}
        return -1;
    }
    if(s>e){return -1;}
    int mid=(s+e)/2;
    if(arr[mid]==K){
        return LeftmostIndex(arr,s,mid,K);
    }
    if(arr[mid]>K){
        return LeftmostIndex(arr,s,mid-1,K);
    }
    return LeftmostIndex(arr,mid+1,e,K);
}

int RightmostIndex(int*arr,int s,int e,int K)
{
    if(e-s==1){
        if(arr[e]==K){return e;}
        if(arr[s]==K){return s;}
        return -1;
    }
    if(s==e){
        if(arr[s]==K){return s;}
        return -1;
    }
    if(s>e){return -1;}
    int mid=(s+e)/2;
    if(arr[mid]==K){
        return RightmostIndex(arr,mid,e,K);
    }
    if(arr[mid]>K){
        return RightmostIndex(arr,s,mid-1,K);
    }
    return RightmostIndex(arr,mid+1,e,K);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,j=0;
    cin>>N;
    int arr[N];
    for(int i=0;i<N;i++)
    {
        int v;
        cin>>v;
        if(m.count(v)==0){
            m[v]=1;
            arr[j++]=v;
        }
    }
    N=j;
    int n=0;
    for(int a=0;a<N;a++)
    {
        for(int b=0;b<N;b++)
        {
            for(int c=0;c<N;c++)
            {
                int v=arr[a]*arr[b]+arr[c];
                lhs[n++]=v;
            }
        }
    }
    int ans=0;
    sort(lhs,lhs+n);
    for(int d=0;d<N;d++)
    {
        if(arr[d]!=0){
        for(int e=0;e<N;e++)
        {
            for(int f=0;f<N;f++)
            {
                int v=(arr[d]*arr[e])+(arr[d]*arr[f]);
                int l=LeftmostIndex(lhs,0,n-1,v);
                int r=RightmostIndex(lhs,0,n-1,v);
                if(l!=-1){
                    ans+=(r-l+1);
                }
            }
        }
    }
    }
    cout<<ans<<endl;
    return 0;
}
