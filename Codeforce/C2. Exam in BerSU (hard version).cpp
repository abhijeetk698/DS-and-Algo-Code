#include <iostream>
#include <vector>

using namespace std;

#define ll long long

ll int answer(vector<ll int>&v,vector<ll int>&count,ll int i,ll int M){
    ll int n=v.size();
    ll int S=M-v[i];
    ll int cnt=0;
    for(ll int i=1;i<=100;i++){
        ll int val=S/i;
        ll int min_val=min(val,count[i]);
        S-=(min_val)*i;
        cnt+=min_val;
    }
    return i-cnt;
}

int main(){
    ll int n,M;
    cin>>n>>M;
    vector<ll int> v(n);
    for(ll int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<ll int> count;
    count.assign(101,0);
    for(ll int i=0;i<n;i++){
        cout<<answer(v,count,i,M)<<" ";
        count[v[i]]++;
    }
    cout<<endl;
}
