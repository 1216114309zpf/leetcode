class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> vec(K+1,-1);
        vector<vector<int>> ans(n,vec);
        vector<vector<int>> tmp;
        vector<vector<vector<int>>> newFlights(n,tmp);
        for(int i=0;i<flights.size();++i){
            newFlights[flights[i][0]].push_back(flights[i]);
        }
        
        unordered_map<int,bool> myMap;
        myMap[src]=true;
        
        queue<int> que;
        que.push(src);
        que.push(-1);
        ans[src][0]=0;
        
        int level=0;
        while(!que.empty() and level<K+1){
            int current=que.front();
            que.pop();
            if(current==-1){
                if(que.empty()){
                    break;
                }
                ++level;
                que.push(-1);
                continue;
            }else{
                myMap[current]=false;
                for(int i=0;i<newFlights[current].size();++i){
                    int src=newFlights[current][i][0];
                    int dest=newFlights[current][i][1];
                    int price=newFlights[current][i][2];
                    
                    if(ans[dest][level]==-1){
                        if(level==0)
                            ans[dest][level]=price;
                        else
                            ans[dest][level]=price+ans[src][level-1];
                        for(int p=level;p<K+1;++p){
                            if(ans[dest][p]==-1 or ans[dest][p]>ans[dest][level])
                                ans[dest][p]=ans[dest][level];
                        }
                    }else{
                        if(price+ans[src][level-1]<ans[dest][level]){
                            ans[dest][level]=price+ans[src][level-1];
                        }
                        for(int p=level;p<K+1;++p){
                            if(ans[dest][p]==-1 or ans[dest][p]>ans[dest][level])
                                ans[dest][p]=ans[dest][level];
                        }
                    }
                    if(myMap.count(dest)==0 or myMap[dest]==false){
                        que.push(dest);
                        myMap[dest]=true;
                    }
                }
            }
        }
        int result=-1;
        for(int i=0;i<K+1;++i){
            if(result==-1){
                result=ans[dst][i];
            }else{
                if(result>ans[dst][i] and ans[dst][i]!=-1){
                    result=ans[dst][i];
                }
            }
        }
        
        return result;
    }
};
