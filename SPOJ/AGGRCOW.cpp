#include <iostream>
#include <algorithm>
using namespace std;

bool IsValid(int* arr,int C,int K,int N)
{
    int Cows=C-1;
    int index=arr[0];
    for(int i=1;i<N;i++)
    {
        if((arr[i]-index)>=K)
        {
            Cows--;
            index=arr[i];
        }
        if(Cows<=0){return true;}
    }
    return false;
}

int MaxDistance(int* arr,int C,int s,int e,int N)
{
    if((e-s)==1){
        if(IsValid(arr,C,e,N)){return e;}
        else{return s;}
    }
    int mid=(s+e)/2;
    if(IsValid(arr,C,mid,N))
    {
        return MaxDistance(arr,C,mid,e,N);
    }
    else
    {
        return MaxDistance(arr,C,s,mid,N);
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--){
    int N,C;
    cin>>N>>C;
    int arr[N],Max=0;
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
        if(arr[i]>Max){Max=arr[i];}
    }
    sort(arr,arr+N);
    cout<<MaxDistance(arr,C,0,arr[N-1],N)<<endl;
    }
    return 0;
}
