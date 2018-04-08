class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int size=target.size();
        int N=1<<size;
        vector<unsigned int> dp(N,INT_MAX);
        
        dp[0]=0;
        for(unsigned int i=0;i<N;++i){
            if(dp[i]==INT_MAX){
                continue;
            }
        
            for(int j=0;j<stickers.size();++j){
                unsigned int status=i;
                for(int p=0;p<stickers[j].size();++p){
                    for(int r=0;r<size;++r){
                        unsigned int tmp=1<<r;
                        if(target[r]==stickers[j][p] and (tmp&status)==0){
                                status|=tmp;
                                break;
                        }
                    }
                }
                dp[status]=min(dp[status],dp[i]+1);
            }
        }
        if(dp[N-1]!=INT_MAX)
             return dp[N-1];
        return -1;
    }
};
    
    
