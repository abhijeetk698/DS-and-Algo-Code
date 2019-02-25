#include <iostream>
#include <algorithm>
using namespace std;

int arr[400];
class Cards{
public:
    int color;
    int value;
};
int LIS(int N)
{
    int dp[N];
    int ans=0;
    for(int i=0;i<N;i++){dp[i]=1;}
    for(int i=1;i<N;i++)
    {
        int m=0;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i]){
                m=max(m,dp[j]);
            }
        }
        dp[i]=m+1;
        ans=max(ans,dp[i]);
    }
    return ans;
}

int main()
{
    int C,N;
    cin>>C>>N;
    Cards Crd[C*N];
    for(int i=0;i<N*C;i++)
    {
        cin>>Crd[i].color>>Crd[i].value;
    }
    int Permutation[C];
    int a[C];
    int ans=10000;
    for(int i=0;i<C;i++){Permutation[i]=i+1;}
    do{
        for(int i=0;i<C;i++){a[Permutation[i]]=i;}
        for(int i=0;i<N*C;i++)
        {
            arr[i]=(a[Crd[i].color]*N)+Crd[i].value;
        }
        int b=(N*C)-LIS(N*C);
        ans=min(ans,b);
    }
    while(next_permutation(Permutation,Permutation+C));
    cout<<ans<<endl;
    return 0;
}
