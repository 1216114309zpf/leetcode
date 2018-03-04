class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> vec;
        for(int i=0;i<graph.size();++i){
            vec.push_back(-1);
        }
        vec[0]=0;
        
            stack<int> stk;
            stk.push(0);
            while(!stk.empty()){
               int item=stk.top();
               stk.pop();
               for(int i=0;i<graph[item].size();++i){
                   if(vec[graph[item][i]]==-1){
                       vec[graph[item][i]]=!vec[item];
                       stk.push(graph[item][i]);
                   }else if(vec[graph[item][i]]==(!vec[item])){
                       continue;
                   }else{
                       return false;
                   }
               }
            }
        
        for(int i=0;i<graph.size();++i){
            if(vec[i]!=-1 or graph[i].size()==0){
                continue;
            }
            vec[i]=!vec[graph[i][0]];
            for(int j=0;j<graph[i].size();++j){
                if(vec[i]!=(!vec[graph[i][j]])){
                    return false;
                }
            }
        }
        return true;
    }
};
