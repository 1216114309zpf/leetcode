class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<int> tmp(s.size(),0);
        vector<vector<int>> dp(s.size(),tmp);
        
        int result=1;
        
        for(int i=0;i<s.size();++i){
            dp[i][i]=1;
            if(i!=s.size()-1){
                if(s[i]==s[i+1]){
                    dp[i][i+1]=2;
                    result=2;
                }else{
                    dp[i][i+1]=1;
                }
            }
        }
        
        for(int i=2;i<s.size();++i){
            for(int j=0;j<s.size()-i;++j){
                if(s[j]==s[i+j]){
                    dp[j][i+j]=2+dp[j+1][i+j-1];
                }else{
                    dp[j][i+j]=max(dp[j][i+j-1],dp[j+1][i+j]);
                }
                if(dp[j][i+j]>result){
                    result=dp[j][i+j];
                }
            }
        }
        return result;
    }
};
