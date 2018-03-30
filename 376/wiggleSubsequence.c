class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        
        if(nums.size()==2){
            if(nums[0]==nums[1])
                return 1;
            else
                return 2;
        }
        vector<int> ascend(nums.size(),1);
        vector<int> descend(nums.size(),1);
        ascend[0]=1;
        descend[0]=1;
        int result=1;
        for(int i=1;i<nums.size();++i){
            for(int j=i-1;j>=0;--j){
                if(ascend[j]+1>descend[i] and nums[j]>nums[i]){
                    descend[i]=ascend[j]+1;
                    if(descend[i]>result)
                        result=descend[i];
                    break;
                }
            }
            
            for(int j=i-1;j>=0;--j){
                if(descend[j]+1>ascend[i] and nums[j]<nums[i]){
                    ascend[i]=descend[j]+1;
                    if(ascend[i]>result)
                        result=ascend[i];
                    break;
                }
            }
        }
        
        return result;
    }
};
