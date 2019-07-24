int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
} 
   

int Solution::isPower(int A) {
    if(A==1){
        return 1;
    }
    if(A==2||A==3){
        return 0;
    }
    int num=A;
    int minGCD=INT_MAX;
    int count=0;
    int P=-1;
    if(num%2==0){
        while(num%2==0){
            num/=2;
            count++;
        }
        if(P==-1){
            P=count;
        }
    }
    for(int i=3;i<=sqrt(num);i+=2){
        count=0;
        if(num%i==0){
            while(num%i==0){
                num/=i;
                count++;
            }
            if(P==-1){
                P=count;
            }
            else{
                int g=gcd(P,count);
                if(g==1){
                    return 0;
                }else{
                    minGCD=min(minGCD,g);
                    P=minGCD;
                }
            }
        }
    }
    if(P==0||P==-1||num!=1){
        return 0;
    }
    return 1;
}
