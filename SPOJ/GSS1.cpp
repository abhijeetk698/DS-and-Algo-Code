#include <iostream>

using namespace std;
#define MaxN 50010
class Mypair{
public:
    int sum;
    int maxSum;
    int SS;
    int PS;
};



void Merge(Mypair&node,Mypair&lhs,Mypair&rhs)
{
    node.sum=lhs.sum+rhs.sum;
    node.PS=max(lhs.PS,(lhs.sum+rhs.PS));
    node.SS=max((rhs.sum+lhs.SS),rhs.SS);
    node.maxSum=max(lhs.maxSum,max(rhs.maxSum,(lhs.SS+rhs.PS)));
}

void Build(int*arr,Mypair*SegTree,int start,int end,int node)
{
    if(start==end){
        SegTree[node].sum=arr[start];
        SegTree[node].maxSum=arr[start];
        SegTree[node].SS=arr[start];
        SegTree[node].PS=arr[start];
        return;
    }
    int mid=(start+end)/2;
    Build(arr,SegTree,start,mid,2*node);
    Build(arr,SegTree,mid+1,end,2*node+1);
    Mypair lhs=SegTree[2*node];
    Mypair rhs=SegTree[2*node+1];
    Merge(SegTree[node],lhs,rhs);
    return;
}

Mypair Query(int*arr,Mypair*SegTree,int start,int end,int l,int r,int node)
{
    if(start==l&&end==r)
    {
        return SegTree[node];
    }
    else{
        int cl=2*node;
        int cr=cl+1;
        int mid=(start+end)/2;
        if(r<=mid)
        {
            return Query(arr,SegTree,start,mid,l,r,cl);
        }
        else if(l>mid)
        {
            return Query(arr,SegTree,mid+1,end,l,r,cr);
        }
        else{
            Mypair leftnode=Query(arr,SegTree,start,mid,l,mid,cl);
            Mypair rightnode=Query(arr,SegTree,mid+1,end,mid+1,r,cr);
            Mypair m;
            Merge(m,leftnode,rightnode);
            return m;
        }
    }
}

int main()
{
    unsigned int N;
    cin>>N;
    int arr[MaxN];
    Mypair SegTree[4*MaxN];
    arr[0]=0;
    for(int i=1;i<=N;i++)
    {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    Build(arr,SegTree,1,N,1);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        Mypair m=Query(arr,SegTree,1,N,l,r,1);
        cout<<m.maxSum<<endl;
    }
    return 0;
}
