/******************************************
* AUTHOR : ABHIJEET KUMAR JHA *
* INSTITUTION : DELHI TECHNOLOGICAL UNIVERSITY *
******************************************/
// problem link :-https://practice.geeksforgeeks.org/problems/longest-valid-parentheses/0/?track=sp-stack&batchId=152
// problem statement : Given a string S consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.
// complexity : Time Complexity O(N)   :    Space Complexity O(N)

#include <iostream>
#include <string>
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


int longestValidParentheses(string A) {
    // here s acts as a stack and increases its value whenever '(' is encountered in loop 1 
    //and ')' is encountered in loop 2
    int s=0;
    int N=A.length();
    vector<int> dp(N);
    /// dp vector will contain values 1 or 0 if A[i] is a part of a valid substring
    /// eg:- for  ))((())()(  dp will be :- 0001111110
    for(int i=0;i<N;i++){
        dp[i]=0;
    }
    // loop 1 
    /* here whenever I will encountered a '(' i will increment value of s (pushing in stack)
            when i will encounter a ')' then i will decrement value of s if s!=0 (stack is not empty)
            and increment value of dp[i] by 1
            
        here, dp[i]=1 signifies that ith element is closing an open bracket 
        NOTE :- in a valid subsequence every close bracket closes an open bracket present in the 
                same subsequence  (this is the main pricipal i focused on for this problem)
        from above eg we will get dp as 0000011010    
    */
    for(int i=0;i<N;i++){
        if(A[i]=='('){
            s++;
        }
        else{
            if(s!=0){
                s--;
                dp[i]++;
            }
        }
    }
    // LOOP 2
    // Here, we will reverse the string compute what we did on loop 1 Here open brackets will acts as close and vice versa 
    // and we will get dp as 0001111110
    // the continous 1 will represent a a valid substring so the problem reduces to find the max length of continous 1's
    s=0;
    for(int i=(N-1);i>=0;i--){
        if(A[i]==')'){
            s++;
        }
        else{
            if(s!=0){
                s--;
                dp[i]++;
            }
        }
    }
    int ans=0;
    int curr=0;
    for(int i=0;i<N;i++){
        if(dp[i]==0){
            curr=0;
        }
        else{
            curr++;
        }
        ans=max(ans,curr);
    }
    return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<longestValidParentheses(s)<<endl;
    }
    return 0;
}
