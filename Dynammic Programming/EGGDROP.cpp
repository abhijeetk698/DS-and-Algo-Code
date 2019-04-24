/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/

// Problem Statement =: http://en.wikipedia.org/wiki/Dynamic_programming#Egg_dropping_puzzle
// Concept Used := Dynammic Programming

#include <iostream>
#include <climits>
#include <cstring>
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

int memo[100][100];

int Mindrops(int E,int F){
    if(E==1){
        return F;
    }
    if(F==0||F==1){
        return F;
    }
    if(memo[E][F]!=-1){
        return memo[E][F];
    }
    int ans=INT_MAX;
    for(int i=1;i<=F;i++)
    {
        // if the egg breaks at i th floor from here
        // then we have E-1 eggs remaining and floors to check has been reduced to i-1
        int A=Mindrops(E-1,i-1);
        // if the egg does'nt break here
        // then we are sure that it won't break at any floor below ith floor thus floors to check has been reduced to F-i
        int B=Mindrops(E,F-i);
        // Now we have to consider for the worst case of each floor 
        int AB=max(A,B);
        // Since, we have to minimize number of trials in worst case so, we choose the floor which yeilds min trials/drops
        ans=min(ans,AB);
    }
    memo[E][F]=1+ans;
    return memo[E][F];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int E,F;
        cin>>E>>F;
        memset(memo,-1,sizeof(memo));
        cout<<Mindrops(E,F)<<endl;
    }
    return 0;
}
