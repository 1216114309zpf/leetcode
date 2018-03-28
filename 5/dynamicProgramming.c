class Solution {
public:
    string longestPalindrome(string s) {
        string result="";
        vector<bool> tmp(s.size(), false);
        vector<vector<bool>> dp(s.size(),tmp);
        pair<int,int> record(0,0);
        for(int i=0;i<s.size();++i){
            dp[i][i]=true;
            if(i!=s.size()-1){
                dp[i][i+1]=(s[i]==s[i+1]);
                if(dp[i][i+1]){
                    record.first=i;
                    record.second=i+1;
                }
            }
        }
        
        for(int i=2;i<s.size();++i){
            for(int j=0;j<s.size()-i;++j){
                dp[j][i+j]=(dp[j+1][i+j-1] and s[j]==s[i+j]);
                if(dp[j][i+j] and i>record.second-record.first){
                    record.first=j;
                    record.second=i+j;
                }
            }
        }
        
        for(int i=record.first; i<=record.second; ++i){
            result.push_back(s[i]);
        }
        return result;
    }
    
};
