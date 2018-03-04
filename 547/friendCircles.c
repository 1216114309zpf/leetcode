
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> vec;
        for(int i=0;i<M.size();++i){
            vec.push_back(false);
        }
        int result=0;
        for(int i=0;i<M.size();++i){
            if(vec[i]){
                continue;
            }else{
                ++result;
                vec[i]=true;
                queue<int> que;
                que.push(i);
                while(!que.empty()){
                    int item=que.front();
                    que.pop();
                    for(int j=0;j<M.size();++j){
                        if(M[item][j]==1 and !vec[j]){
                            vec[j]=true;
                            que.push(j);
                        }
                    }
                }
            }
        }
        return result;
    }
};
