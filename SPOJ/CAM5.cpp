//CAM5 = help the Prayatna pr team
// link=https://www.spoj.com/problems/CAM5/
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
        adjList=new vector<int>[V];
    }

    void addEdge(int a,int b,bool bidir=true)
    {
        adjList[a].pb(b);
        if(bidir){adjList[b].pb(a);}
        return ;
    }

    void DFSHelper(int src,bool*visited)
    {
        visited[src]=true;
        for(auto x:adjList[src])
        {
            if(!visited[x]){
                DFSHelper(x,visited);
            }
        }
        return;
    }

    int DFS()
    {
        bool visited[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i]){
                ans++;
                DFSHelper(i,visited);
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
        cout<<G.DFS()<<endl;
    }
    return 0;
}
