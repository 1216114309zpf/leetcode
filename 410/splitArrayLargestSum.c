class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        
        
        double average=double(sum)/m;
        vector<int> tmp(m+1,-1);
        vector<vector<int>> dp(nums.size(),tmp);
        
        help(dp,nums,average,0,m);
        return dp[0][m];
    }
    
    int help(vector<vector<int>>&dp,vector<int>&nums,double average, int current, int sets){
        if(dp[current][sets]!=-1){
            return dp[current][sets];
        }
        
        if(sets==1){
            int result=0;
            for(int i=current;i<nums.size();++i){
                result+=nums[i];
            }
            return dp[current][sets]=result;
        }
        if(sets==nums.size()-current){
            int result=0;
            for(int i=current;i<nums.size();++i){
                if(nums[i]>result){
                    result=nums[i];
                }
            }
            return dp[current][sets]=result;
        }
        
        int sum=0;
        int ptr=current;
        while(ptr<nums.size() and sum+nums[ptr]<average){
            sum+=nums[ptr];
            ptr++;
        }
        
        int largest=INT_MAX;
        while(sum<largest){
            if(sets>1 and sets-1<=nums.size()-ptr){
                largest=max(sum,help(dp,nums,average,ptr,sets-1));
                sum+=nums[ptr];
                ++ptr;
            }else{
                break;
            }
        }
        
        return dp[current][sets]=largest;
    }
};
