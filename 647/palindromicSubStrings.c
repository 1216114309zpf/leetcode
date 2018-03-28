class Solution {
public:
    int countSubstrings(string s) {
        int result=0;
        vector<bool> tmp(s.size(), false);
        vector<vector<bool>> dp(s.size(),tmp);
        for(int i=0;i<s.size();++i){
            dp[i][i]=true;
            if(i!=s.size()-1){
                dp[i][i+1]=(s[i]==s[i+1]);
            }
        }
        
        for(int i=2;i<s.size();++i){
            for(int j=0;j<s.size()-i;++j){
                dp[j][i+j]=(dp[j+1][i+j-1] and s[j]==s[i+j]);
            }
        }
        
        for(int i=0; i<s.size(); ++i){
           for(int j=i;j<s.size();++j){
               result+=dp[i][j];
           }
        }
        return result;
    }
};
