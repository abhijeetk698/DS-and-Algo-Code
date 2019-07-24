// Problem Statement: 
// Code : https://www.interviewbit.com/problems/excel-column-title/
char titleChar[27]={'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y'};
string Solution::convertToTitle(int A) {
    string ans;
    int num=A;
    while(num>0){
        int rem=(num%26);
        ans.push_back(titleChar[rem]);
        num/=26;
        //Important case : rem=0
        if(rem==0){
            num--;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
