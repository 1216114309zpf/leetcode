class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int result=0;
        int i=0;
        long miss=1;
        while(miss<=n){
            if(i<nums.size() and nums[i]<=miss){
                miss+=nums[i++];
            }else{
                miss+=miss;
                ++result;
            }
        }
        return result;
    }
};
