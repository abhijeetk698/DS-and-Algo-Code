// A Bug Life
// link: https://www.spoj.com/problems/BUGLIFE/
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

    bool DFSHelper(int src,int*color,bool*visited,int pc)
    {
        visited[src]=true;
        if(color[src]==-1)
        {
            if(pc==-1){color[src]=1;}
            else if(pc==0){color[src]=1;}
            else{color[src]=0;}
        }
        else if(color[src]==1){
            if(pc==1){return false;}
        }
        else{
            if(pc==0){return false;}
        }
        bool ans=true;
        for(auto x:adjList[src])
        {
            if(color[x]==color[src]){return false;}
            if(!visited[x]){
                bool a=DFSHelper(x,color,visited,color[src]);
                ans&=a;
            }
        }
        return ans;
    }

    bool IsBipartite()
    {
        bool visited[V+1];
        for(int i=1;i<=V;i++){
            visited[i]=false;
        }
        int color[V+1];
        for(int i=1;i<=V;i++)
        {
            color[i]=-1;
        }
        bool ans=true;
        for(int i=1;i<=V;i++)
        {
            if(!visited[i]){
                bool a=DFSHelper(i,color,visited,-1);
                ans&=a;
            }
        }
        return ans;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    int count=1;
    cin>>t;
    while(t--)
    {
        int V,E;
        cin>>V>>E;
        Graph G(V);
        while(E--)
        {
            int a,b;
            cin>>a>>b;
            G.addEdge(a,b);
        }
        cout<<"Scenario #"<<count<<":"<<endl;
        count++;
        if(G.IsBipartite()){
            cout<<"No suspicious bugs found!"<<endl;
        }
        else{
            cout<<"Suspicious bugs found!"<<endl;
        }
    }
    return 0;
}
