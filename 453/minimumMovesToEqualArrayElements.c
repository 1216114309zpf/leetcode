class Solution {
public:
    int minMoves(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int minimum=nums[0];
        for(int i=1;i<nums.size();++i){
            if(nums[i]<minimum)
                minimum=nums[i];
        }
        int result=0;
        for(int i=0;i<nums.size();++i){
            result+=(nums[i]-minimum);
        }
        return result;
    }
};
