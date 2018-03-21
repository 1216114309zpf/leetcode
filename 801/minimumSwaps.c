class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp;
        vector<int> tmp;
        tmp.push_back(0);
        tmp.push_back(0);
        for(int i=0;i<A.size();++i){
            dp.push_back(tmp);
        }
        
        dp[0][0]=0;
        dp[0][1]=1;
        
        for(int i=1;i<A.size();++i){
            if(A[i-1]>=A[i] or B[i-1]>=B[i]){
                dp[i][0]=dp[i-1][1];
            }else{
                if(A[i-1]<B[i] and B[i-1]<A[i]){
                    dp[i][0]=min(dp[i-1][0],dp[i-1][1]);
                }else{
                    dp[i][0]=dp[i-1][0];
                }
            }
            
            if(A[i-1]>=B[i] or B[i-1]>=A[i]){
                dp[i][1]=dp[i-1][1]+1;
            }else{
                if(A[i-1]<A[i] and B[i-1]<B[i]){
                    dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1;
                }else{
                    dp[i][1]=dp[i-1][0]+1;
                }
            }
        }
        
        return min(dp[A.size()-1][0],dp[A.size()-1][1]);
    }
};
