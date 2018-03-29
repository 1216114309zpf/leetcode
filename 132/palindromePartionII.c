class Solution {
public:
    int minCut(string s) {
        vector<bool> tmp(s.size(),false);
        vector<vector<bool>> matrix(s.size(),tmp);
        
        for(int i=0;i<s.size();++i){
            matrix[i][i]=true;
            if(i!=s.size()-1){
                if(s[i]==s[i+1]){
                    matrix[i][i+1]=true;
                }else{
                    matrix[i][i+1]=false;
                }
            }
        }
        
        for(int i=2;i<s.size();++i){
            for(int j=0;j+i<s.size();++j){
                if(s[j]==s[i+j] and matrix[j+1][j+i-1]){
                    matrix[j][i+j]=true;
                }else{
                    matrix[j][i+j]=false;
                }
            }
        }
        

        vector<int> vec(s.size(),-1);
        vector<vector<int>> dp(s.size(),vec);
        
        for(int i=0;i<s.size();++i){
            dp[i][i]=0;
            if(i<s.size()-1){
                if(matrix[i][i+1])
                    dp[i][i+1]=0;
                else
                    dp[i][i+1]=1;
            }
        }
        
        return help(dp,matrix,0,s.size()-1);
    }
    
    int  help(vector<vector<int>>&dp, vector<vector<bool>>& matrix,int left, int right){
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        
        if(matrix[left][right]){
            return dp[left][right]=0;
        }
        
        dp[left][right]=INT_MAX;
        for(int i=left;i<right;++i){
            if(matrix[left][i]){
                int tmp=help(dp,matrix,i+1,right)+1;
                if(tmp<dp[left][right])
                    dp[left][right]=tmp;
            }
        }
        
        return dp[left][right];
    }
};
