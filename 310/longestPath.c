class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n==1){
            vector<int> result;
            result.push_back(0);
            return result;
        }
        vector<vector<int>> graph(n);
        
        for(int i=0;i<edges.size();++i){
            pair<int, int> edge=edges[i];
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }
        
        vector<int> currentPath;
        vector<int> candidatePath;
        
        dfs(graph,-1,0,currentPath,candidatePath);
        
        int root=candidatePath[candidatePath.size()-1];
        candidatePath.clear();

        dfs(graph,-1,root,currentPath,candidatePath);
        vector<int> result;
        
        int length=candidatePath.size();
        if(length%2){
            result.push_back(candidatePath[length/2]);
        }else{
            result.push_back(candidatePath[length/2]);
            result.push_back(candidatePath[length/2-1]);
        }
        return result;
    }
    
    void dfs(vector<vector<int>>& graph, int parent,int root, vector<int> currentPath, vector<int>& candidatePath){
        currentPath.push_back(root);
        if(parent!=-1 and graph[root].size()==1){
            if(currentPath.size()>candidatePath.size()){
                candidatePath=currentPath;
            }
        }else{
            for(int next=0;next<graph[root].size();++next){
                if(graph[root][next]!=parent){
                    dfs(graph,root,graph[root][next],currentPath,candidatePath);
                }
            }
        }
    }
};
