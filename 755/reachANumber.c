class Solution {
public:
    int reachNumber(int target) {
        if(target==0)
            return 0;
        int result;
        if(target<0)
            result=help(-target);
        else
            result=help(target);
        return result;
    }
    
    int help(int target){
        int root =sqrt(target*2);
        int tmp=root*(root+1)/2;
        if(tmp==target)
            return root;
        if(tmp>target){
            root=root-1;
            tmp=root*(root+1)/2;
        }
        int diff=target-tmp;
        if((root+1-diff)%2==0)
            return root+1;
        else{
            if((root+1)%2==1){
                return root+3;
            }else{
                return root+2;
            }
        }
    }
};
