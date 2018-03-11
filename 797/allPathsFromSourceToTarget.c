class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target=graph.size()-1;
        queue<vector<int>> que;
        vector<int> vec;
        vector<vector<int>> result;
        vec.push_back(0);
        que.push(vec);
        while(!que.empty()){
            vector<int> tmp=que.front();
            que.pop();
            for(int i=0;i<graph[tmp[tmp.size()-1]].size();++i){
                vector<int> v=tmp;
                v.push_back(graph[tmp[tmp.size()-1]][i]);
                if(target==graph[tmp[tmp.size()-1]][i]){
                    result.push_back(v);
                }else{
                    que.push(v);
                }
            }
        }
        return result;
    }
};
