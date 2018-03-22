class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> vec(K+1,-1);
        vector<vector<int>> ans(n,vec);
        
        for(int i=0;i<n;++i){
            for(int j=0;j<=K;++j){
                ans[i][j]=1000000;
            }
        }
        
        ans[src][0]=0;
        for(int i=0;i<flights.size();++i){
            if(src==flights[i][0]){
                ans[flights[i][1]][0]=flights[i][2];
            }
        }
        
        for(int i=1;i<=K;++i){
            for(int j=0;j<n;++j){
                ans[j][i]=ans[j][i-1];
            }
            
            for(int p=0;p<flights.size();++p){
                int src=flights[p][0];
                int dest=flights[p][1];
                int price=flights[p][2];
                if(ans[dest][i]>ans[src][i-1]+price){
                    ans[dest][i]=ans[src][i-1]+price;
                }
            }
        }
        
        return ans[dst][K]==1000000?-1:ans[dst][K];
    }
};
