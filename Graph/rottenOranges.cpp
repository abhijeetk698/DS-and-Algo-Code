// problem statement : https://practice.geeksforgeeks.org/problems/rotten-oranges/0
// time complexity : O(n^2)

#include <iostream>
#include <vector> 
#include <queue> 

using namespace std;

int MinSteps(vector<vector<int> >&v){
    int n=v.size();
    int m=v[0].size();
    queue<pair<int,int> >Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==2){
                Q.push(make_pair(i,j));
            }
        }
    }
    int ans=0;
    Q.push(make_pair(-1,-1));
    while(!Q.empty()){
        pair<int,int> p=Q.front();
        Q.pop();
        if(p.first==-1){
            if(!Q.empty()){
                Q.push(make_pair(-1,-1));
                ans++;
            }
        }
        else{
            int x=p.first;
            int y=p.second;
            if(x!=0&&v[x-1][y]==1){
                v[x-1][y]=2;
                Q.push(make_pair(x-1,y));
            }
            if(x!=(n-1)&&v[x+1][y]==1){
                v[x+1][y]=2;
                Q.push(make_pair(x+1,y));
            }
            if(y!=0&&v[x][y-1]==1){
                v[x][y-1]=2;
                Q.push(make_pair(x,y-1));
            }
            if(y!=(m-1)&&v[x][y+1]==1){
                v[x][y+1]=2;
                Q.push(make_pair(x,y+1));
            }
        }
    }
    int fresh_left=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==1){
                fresh_left=true;
                break;
            }
        }
    }
    if(fresh_left){
        return -1;
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int> > v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        cout<<MinSteps(v)<<endl;   
    }
    return 0;
}
