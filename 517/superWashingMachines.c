class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum=0;
        for(int i=0;i<machines.size();++i)
            sum+=machines[i];
        if(sum%machines.size()!=0)
            return -1;
        
        int average=sum/machines.size();
        
        int result=0;
        
        int current=0;
        for(int i=0;i<machines.size();++i){
            int left=average*i-current;
            current+=machines[i];
            sum-=machines[i];
            int right=average*(machines.size()-i-1)-sum;
            int candidate;
            if(left>0 and right>0)
                candidate=abs(left+right);
            else
                candidate=max(abs(left),abs(right));
            if(candidate>result)
                result=candidate; 
        }
        
        return result;
        
    }
};
