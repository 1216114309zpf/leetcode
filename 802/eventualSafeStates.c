class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> result;
        vector<int> states(graph.size(),0);
        vector<bool> tmpStates(graph.size(),false);
        int label=1;
        for(int i=0;i<graph.size();++i){
            if(states[i]==0){
                vector<int> path;
                dfs(graph,path,states,i,label,tmpStates);
                ++label;
            }
        }
        for(int i=0;i<states.size();++i){
            if(states[i]!=-1){
                result.push_back(i);
            }
        }
        return result;
    }
    
    void dfs(vector<vector<int>>& graph,vector<int> path,vector<int>& states, int current, int label,vector<bool> & tmpStates){
        if(states[current]==-1 ){
            for(int i=0;i<path.size();++i){
                states[path[i]]=-1;
            }
            return;
        }
        
        if(states[current]==label){
            if(tmpStates[current]){
                for(int i=0;i<path.size();++i){
                    states[path[i]]=-1;
                }
                states[current]=-1;
                return; 
            }
        }
        
        if(states[current]>0){
            return;
        }
        
        path.push_back(current);
        states[current]=label;
        tmpStates[current]=true;
        for(int i=0;i<graph[current].size();++i){
            dfs(graph,path,states,graph[current][i],label,tmpStates);
        }
        tmpStates[current]=false;
    }
};
