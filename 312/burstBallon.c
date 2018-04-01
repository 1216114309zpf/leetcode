class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> nb(1,1);
        for(int i=0;i<nums.size();++i)
            nb.push_back(nums[i]);
        nb.push_back(1);
        
        vector<int> tmp(nums.size()+1,-1);
        vector<vector<int>> dp(nums.size()+1,tmp);
        
        return help(dp,nb,1,nums.size());
    }
    
    int help(vector<vector<int>>&dp, vector<int>&nums, int start,int end){
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(start==end){
            return dp[start][end]=nums[start-1]*nums[start]*nums[start+1];
        }
        
        dp[start][end]=0;
        for(int i=start;i<=end;++i){
            int tmp=nums[start-1]*nums[i]*nums[end+1];
            if(i!=start){
                tmp+=help(dp,nums,start,i-1);
            }
            
            if(i!=end){
                tmp+=help(dp,nums,i+1,end);
            }
            
            dp[start][end]=(tmp>dp[start][end])?tmp:dp[start][end];
        }
        return dp[start][end];
    }
};
