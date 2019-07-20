/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
// problem link :-https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0/?track=sp-stack&batchId=152
// problem statement : https://practice.geeksforgeeks.org/problems/decode-the-pattern/0
// complexity : Time Complexity O(Summation of(size of(ans[i])) i=0->N   :    Space Complexity O(max(sizeof(ans[i])) i = 0->N
// ans[i] is the answer string for input i 


#include <iostream>
#include <string>
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

/*
we will compute the i+1 value of the sequence using ith value
So,we will  iterate through the ith element and count every charactes that and same and continous and when we encounter
a different character than the previous one :-
we will push the count and then character in the answer string
*/

string Read(string A){
    A.push_back('X');
    int N=A.size();
    string ans;
    char prev=A[0];
    int count=1;
    for(int i=1;i<N;i++){
        if(A[i]==prev){
            count++;
        }
        else{
            char cnt=(char)(count+'0');
            ans.push_back(cnt);
            ans.push_back(prev);
            count=1;
            prev=A[i];
        }
    }
    return ans;
}


string countAndSay(int A) {
    if(A==1){
        return "1";
    }
    if(A==2){
        return "11";
    }
    string ans="11";
    for(int i=3;i<=A;i++){
        ans=Read(ans);
  }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        cout<<countAndSay(N)<<endl;
    }
    return 0;    
}
