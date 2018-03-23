class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<double> vec(N*N,-1.0);
        vector<vector<double>> dp(K+1,vec);
        for(int i=0;i<N*N;++i){
            dp[0][i]=1;
        }
        
        return recursive(dp,K,r,c,N);
    }
    
    double recursive(vector<vector<double>>&dp, int K, int r, int c, int N){
        if(dp[K][r*N+c]!=-1.0){
            return dp[K][r*N+c];
        }
        
        dp[K][r*N+c]=0;
        
        if(r+2<N and c+1<N){
            dp[K][r*N+c]+=0.125*recursive(dp,K-1,r+2,c+1,N);
        }
        
        if(r+1<N and c+2<N){
            dp[K][r*N+c]+=0.125*recursive(dp,K-1,r+1,c+2,N);
        }
        
        if(r-1>=0 and c-2>=0){
            dp[K][r*N+c]+=0.125*recursive(dp,K-1,r-1,c-2,N);
        }
        
        if(r-2>=0 and c-1>=0){
            dp[K][r*N+c]+=0.125*recursive(dp,K-1,r-2,c-1,N);
        }
        
        if(r+2<N and c-1>=0){
            dp[K][r*N+c]+=0.125*recursive(dp,K-1,r+2,c-1,N);
        }
        
        if(r+1<N and c-2>=0){
            dp[K][r*N+c]+=0.125*recursive(dp,K-1,r+1,c-2,N);
        }
        
        if(r-1>=0 and c+2<N){
            dp[K][r*N+c]+=0.125*recursive(dp,K-1,r-1,c+2,N);
        }
        
        if(r-2>=0 and c+1<N){
            dp[K][r*N+c]+=0.125*recursive(dp,K-1,r-2,c+1,N);
        }
        
        return dp[K][r*N+c];
    }
};
