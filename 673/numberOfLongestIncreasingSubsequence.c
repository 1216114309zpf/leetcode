class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int result=0;
        pair<int,int> item(1,1);
        vector<pair<int,int>> dp;
        for(int i=0;i<nums.size();++i){
            dp.push_back(item);
        }
        
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[i]>nums[j]){
                    if(dp[i].first==dp[j].first+1)  dp[i].second+=dp[j].second;
                    if(dp[i].first<dp[j].first+1){ 
                        dp[i].first=dp[j].first+1;
                        dp[i].second=dp[j].second;
                    }
                }
            }
        }
        int max_len=0;
        for(int i=0;i<dp.size();++i){
            if(dp[i].first>max_len){
                max_len=dp[i].first;
                result=dp[i].second;
            }else if(dp[i].first==max_len){
                result+=dp[i].second;
            }else{
                
            }
        }
        return result;
    }
};
