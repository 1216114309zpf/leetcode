class Solution {
public:
    int minSteps(int n) {
        vector<int> vec(n+1,-1);
        vec[1]=0;
        vec[2]=2;
        return help(n,vec);
    }
    
    int help(int n,vector<int>&vec){
        if(vec[n]!=-1){
            return vec[n];
        }
        int result=1000;
        for(int i=n-1;i>0;--i){
            if(n%i!=0){
                continue;
            }
            int tmp=help(i,vec)+n/i;
            if(tmp<result){
                result=tmp;
            }
        }
        return result;
    }
};
