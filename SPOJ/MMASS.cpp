#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int charValue(char ch)
{
    if(ch=='C'){return 12;}
    if(ch=='O'){return 16;}
    return 1;
}

int main()
{
    char str[101];
    cin>>str;
    int N=strlen(str);
    str[N]=')';
    str[N+1]='\0';
    stack<int> S;
    S.push(0);
    N++;
    for(int i=0;i<N;i++)
    {
        if(str[i]=='('){S.push(0);}
        else if(str[i]==')'){
            int sum=0;
            while(S.top()!=0)
            {
                sum+=S.top();
                S.pop();
            }
            S.pop();
            S.push(sum);
        }
        else if(str[i]=='C'){S.push(12);}
        else if(str[i]=='O'){S.push(16);}
        else if(str[i]=='H'){S.push(1);}
        else{
            int V=(int)(str[i])-(int)('0');
            V*=S.top();
            S.pop();
            S.push(V);
        }
    }
    cout<<S.top()<<endl;
    return 0;
}
