class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(nums.empty() or k==0)
            return 0;
        long long int times=1;
        int right=0;
        int result=0;
        for(int left=0;left<nums.size();++left){
            if(nums[left]>=k){
                right=left+1;
                times=1;
                continue;
            }
            while(right<nums.size() and times*nums[right]<k){
                result+=right-left+1;
                times*=nums[right];
                ++right;
            }
            times/=nums[left];
        }
        return result;
    }
};
