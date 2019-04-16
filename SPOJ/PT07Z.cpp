// Longest Path in a tree
/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
#include <iostream>
#include <vector>
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

class Graph{
    vector<int>*adjList;
    int V;
public:
    Graph(int N){
        V=N;
        adjList=new vector<int>[V+1];
    }

    void addEdge(int a,int b,bool bidir=true)
    {
        adjList[a].pb(b);
        if(bidir){adjList[b].pb(a);}
        return ;
    }

    pair<int,int> DFSHelper(int src,bool*visited)
    {
        visited[src]=true;
        pair<int,int> pr;
        pr.first=0;
        pr.second=0;
        int m1=0,m2=0;
        int MaxD=0,MaxH=0;
        for(auto x:adjList[src])
        {
            if(!visited[x]){
                pair<int,int> cpr;
                cpr=DFSHelper(x,visited);
                int ch=cpr.second;
                MaxD=max(MaxD,cpr.first);
                if(ch>m2)
                {
                    if(ch>m1){
                        m2=m1;
                        m1=ch;
                    }
                    else{
                        m2=ch;
                    }
                }
            }
        }
        pr.second=1+m1;
        pr.first=max((m1+m2),MaxD);
        return pr;
    }

    int DFS()
    {
        bool visited[V+1];
        for(int i=1;i<=V;i++){
            visited[i]=false;
        }
        int ans=0;
        for(int i=1;i<=V;i++)
        {
            if(!visited[i]){
                pair<int,int> a=DFSHelper(i,visited);
                ans=max(ans,a.first);
            }
        }
        return ans;
    }

    ~Graph()
    {
        delete[] adjList;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V,E;
    cin>>V;
    if(V==0||V==1){
        cout<<1<<endl;
    }
    else{
    E=V-1;
    Graph G(V);
    while(E--)
    {
        int a,b;
        cin>>a>>b;
        G.addEdge(a,b);
    }
    cout<<G.DFS()<<endl;
    }
    return 0;
}
