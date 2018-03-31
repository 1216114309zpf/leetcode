class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                que.push(matrix[i][j]);
            }
        }
        
        while(k-1){
            que.pop();
            --k;
        }
        
        return que.top();
    }
};
