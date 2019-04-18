problem title : chef and digits
problem link : https://www.codechef.com/problems/DIGJUMP/
concept used : BFS

/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
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

int Answer(string s)
{
    int N=s.length();
    vector< vector<int> >v(10);
    for(int i=0;i<N;i++)
    {
        int val=(int)(s[i])-(int)('0');
        v[val].pb(i);
    }
    int dist[N];
    for(int i=0;i<N;i++){
        dist[i]=-1;
    }
    queue<int> S;

    S.push(0);
    dist[0]=0;
    while(!S.empty())
    {
        int p=S.front();
        S.pop();
        if((p+1)<N){
            if(dist[p+1]==-1){
                S.push(p+1);
                dist[p+1]=dist[p]+1;
            }
        }
        if((p-1)>=0){
            if(dist[p-1]==-1){
                S.push(p-1);
                dist[p-1]=dist[p]+1;
            }   
        }
        int val=(int)(s[p])-(int)('0');
        for(int x:v[val]){
            if(dist[x]==-1){
                S.push(x);
                dist[x]=dist[p]+1;
            }   
        }
        v[val].clear();
    }
    return dist[N-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    cout<<Answer(s)<<endl;
    return 0;
}
