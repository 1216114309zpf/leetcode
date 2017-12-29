class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        if(n==1)
            return 10;
        if(n>10)
            n=10;
        int result=0;
        for(int i=1;i<=n;++i)
            result+=count(i);
        return result;
    }
    
    int count(int n){
        if(n==1)
            return 10;
        int result=9;
        int current=9;
        while(n!=1){
            result*=current;
            --current;
            --n;
        }
        return result;
    }
};
