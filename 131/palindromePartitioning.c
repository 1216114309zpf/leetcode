class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<bool> tmp(s.size(),false);
        vector<vector<bool>> dp(s.size(),tmp);
        
        for(int i=0;i<s.size();++i){
            dp[i][i]=true;
            if(i!=s.size()-1){
                if(s[i]==s[i+1]){
                    dp[i][i+1]=true;
                }else{
                    dp[i][i+1]=false;
                }
            }
        }
        
        for(int i=2;i<s.size();++i){
            for(int j=0;i+j<s.size();++j){
                if(dp[j+1][j+i-1] and s[j]==s[j+i]){
                    dp[j][j+i]=true;
                }
                else
                    dp[j][j+i]=false;
            }
        }
        
        vector<vector<string>> result=expand(s,dp,0);
        for(int i=0;i<result.size();++i)
            reverse(result[i].begin(),result[i].end());
        return result;
    }
    
    vector<vector<string>> expand(string s, vector<vector<bool>> &dp, int current){
        vector<vector<string>> result;
        if(current==s.size())
            return result;
        string str="";
        for(int i=current;i<s.size();++i){
            str.push_back(s[i]);
            if(dp[current][i]){
                vector<vector<string>> mid=expand(s,dp,i+1);
                if(mid.size()==0){
                    vector<string> vec;
                    vec.push_back(str);
                    mid.push_back(vec);
                }else{
                   for(int j=0;j<mid.size();++j){
                       mid[j].push_back(str);
                   } 
                }
                
                for(int j=0;j<mid.size();++j){
                    result.push_back(mid[j]);
                }
            }
        }
        return result;
    }
};
