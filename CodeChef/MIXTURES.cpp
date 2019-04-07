#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
#define ll long long
int arr[1000];
ll int dp[1000][1000];
int sum(int i,int j)
{
    int ans=0;
    for(int k=i;k<=j;k++){
        ans+=arr[k];
        ans%=100;
    }
    return ans;
}

ll int MinSmoke(int s,int e)
{
    if(dp[s][e]!=-1){return dp[s][e];}
    if(s>=e){return 0;}
    dp[s][e]=INT_MAX;
    for(int k=s;k<e;k++)
    {
        ll int val=MinSmoke(s,k)+MinSmoke(k+1,e)+(sum(s,k)*sum(k+1,e));
        dp[s][e]=min(dp[s][e],val);
    }
    return dp[s][e];
}

int main()
{
    int N;
    while((scanf("%d",&N))!=EOF){
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            cin>>arr[i];
        }
        cout<<MinSmoke(0,N-1)<<endl;
    }
    return 0;
}
