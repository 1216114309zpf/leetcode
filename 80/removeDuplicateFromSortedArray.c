class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int current=1;
        int count=1;
        
        for(int i=1;i<nums.size();++i){
            if(nums[i]!=nums[current-1]){
                nums[current]=nums[i];
                ++current;
                count=1;
            }else{
                if(count<2){
                    ++count;
                    nums[current]=nums[i];
                    ++current;
                }else{
                    continue;
                }
            }
        }
        return current;
        
    }
};
