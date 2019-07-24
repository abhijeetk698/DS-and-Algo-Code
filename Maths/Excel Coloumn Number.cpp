//Problem Code: https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string A) {
    int N=A.size();
    int p=0;
    int ans=0;
    for(int i=N-1;i>=0;i--){
        int num=(int)(A[i])-(int)('A')+1;
        ans+=(num*pow(26,p));
        p++;
    }
    return ans;
}
