class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> tail(nums.size(),-1);
        tail[0]=0;
        for(int i=1;i<nums.size();++i){
            for(int j=i-1;j>=0;--j){
                if(tail[j]!=-1 and nums[i]>nums[tail[j]]){
                    if(tail[j+1]==-1){
                        tail[j+1]=i;
                    }else{
                        if(nums[i]<nums[tail[j+1]]){
                            tail[j+1]=i;
                        }
                    }
                }
            }
            if(nums[tail[0]]>nums[i]){
                    tail[0]=i;
            }
        }
        
        int result=0;
        for(int i=0;i<tail.size();++i){
            if(tail[i]!=-1){
                ++result;
            }else{
                break;
            }
        }
        return result;
    }
};
