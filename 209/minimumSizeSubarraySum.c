class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left=0;
        int right=0;
        int sum=0;
        int result=0;
        while(sum<s and right<nums.size()){
            sum+=nums[right];
            right++;
        }
        
        if(right==nums.size() and sum<s){
            return 0;
        }else{
            result=right-left;
        }
        
        while(true){
            sum-=nums[left];
            left++; 
            while(sum<s and right<nums.size()){
                sum+=nums[right];
                right++;
            }
            
            if(right==nums.size()){
                while(sum>=s){
                    if(right-left<result)
                       result=right-left;
                    sum-=nums[left];
                    ++left;
                }
                break;
            }else{
                if(right-left<result)
                    result=right-left;
            }
        }
        
        return result;
    }
};
