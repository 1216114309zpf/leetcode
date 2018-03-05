class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<set<int>> graph(n);
        vector<bool> vec;
        for(int i=0;i<n;++i){
            vec.push_back(true);
        }
        for(int i=0;i<edges.size();++i){
            pair<int, int> edge=edges[i];
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
        
        int count=n;
        while(count>2){
            vector<int> leaves;
            for(int i=0;i<n;++i){
                if(graph[i].size()==1){
                    vec[i]=false;
                    leaves.push_back(i);
                }
            }
            for(int i=0;i<leaves.size();++i){
                for(auto itr=graph[leaves[i]].begin();itr!=graph[leaves[i]].end();++itr){
                    graph[*itr].erase(leaves[i]);
                }
                graph[leaves[i]].clear();
            }
            count-=leaves.size();
            leaves.clear();
        }
        
        vector<int> result;
        for(int i=0;i<graph.size();++i){
            if(vec[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};
