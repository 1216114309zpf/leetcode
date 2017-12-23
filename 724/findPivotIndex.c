class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()==0)
            return -1;
        int *left = new int[nums.size()];
        int *right = new int[nums.size()];
        left[0]=nums[0];
        right[nums.size()-1] = nums[nums.size()-1];
        
        for(int i=1;i<nums.size();++i)
            left[i] = left[i-1]+nums[i];
        
        for(int i=nums.size()-2;i>=0;--i)
            right[i]=right[i+1]+nums[i];
        
        if(right[1]==0)
            return 0;
        
        for(int i=1;i<nums.size()-1;++i){
            if(left[i-1]==right[i+1])
                return i;
        }
        
        if(left[nums.size()-2]==0)
            return nums.size()-1;
        
        return -1;
    }
};
