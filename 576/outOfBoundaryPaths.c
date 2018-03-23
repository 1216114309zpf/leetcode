class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<int> vec(m*n,-1);
        vector<vector<int>> dp(N+1,vec);
        
        for(int i=0;i<m*n;++i){
            dp[0][i]=0;
        }
        
        return recursive(dp,N,i*n+j,n,m);
    }
    
    int recursive(vector<vector<int>>& dp, int row, int col, int cols,int rows){
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        
        int r=col/cols;
        int c=col%cols;
        
        dp[row][col]=0;
        if(r==0){
            dp[row][col]+=1;
        }else{
            int tmp=col-cols;
            dp[row][col]+=recursive(dp,row-1,tmp,cols,rows);
        }
        
         if(dp[row][col]>=1000000007)
            dp[row][col]%=1000000007;
        
        if(r==rows-1){
            dp[row][col]+=1;
        }else{
            int tmp=col+cols;
            dp[row][col]+=recursive(dp,row-1,tmp,cols,rows);
        }
        
         if(dp[row][col]>=1000000007)
            dp[row][col]%=1000000007;
        
        if(c==0){
            dp[row][col]+=1;
        }else{
            int tmp=col-1;
            dp[row][col]+=recursive(dp,row-1,tmp,cols,rows);
        }
        
         if(dp[row][col]>=1000000007)
            dp[row][col]%=1000000007;
        
        if(c==cols-1){
            dp[row][col]+=1;
        }else{
            int tmp=col+1;
            dp[row][col]+=recursive(dp,row-1,tmp,cols,rows);
        }
        
        if(dp[row][col]>=1000000007)
            dp[row][col]%=1000000007;
        return dp[row][col];
    }
};
