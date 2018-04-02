class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid.size();++j){
                if(grid[i][j]>=grid[grid.size()-1][grid.size()-1] and grid[i][j]>=grid[0][0]){
                    que.push(grid[i][j]);
                }
            }
        }
        
        while(!que.empty()){
            if(help(grid,que.top())){
                return que.top();
            }
            que.pop();
        }
    }
    
    bool help(vector<vector<int>>& grid, int level){
        vector<vector<int>> matrix=grid;
        stack<pair<int,int>> stk;
        stk.push(pair<int,int>(0,0));
        matrix[0][0]=-1;
        while(!stk.empty()){
            pair<int,int> item=stk.top();
            stk.pop();
            //up
            if(item.first!=0 and matrix[item.first-1][item.second]!=-1 and matrix[item.first-1][item.second]<=level){
                stk.push(pair<int,int>(item.first-1,item.second));
                matrix[item.first-1][item.second]=-1;
            }
            
            //down
            if(item.first+1<matrix.size() and matrix[item.first+1][item.second]!=-1 and matrix[item.first+1][item.second]<=level){
                if(item.first+1==matrix.size()-1 and item.second==matrix.size()-1){
                    return true;
                }
                stk.push(pair<int,int>(item.first+1,item.second));
                matrix[item.first+1][item.second]=-1;
            }
            
            //left
            if(item.second!=0 and matrix[item.first][item.second-1]!=-1 and matrix[item.first][item.second-1]<=level){
                stk.push(pair<int,int>(item.first,item.second-1));
                matrix[item.first][item.second-1]=-1;
            }
            
            //right
            if(item.second+1<matrix.size() and matrix[item.first][item.second+1]!=-1 and matrix[item.first][item.second+1]<=level){
                if(item.first==matrix.size()-1 and item.second+1==matrix.size()-1){
                    return true;
                }
                stk.push(pair<int,int>(item.first,item.second+1));
                matrix[item.first][item.second+1]=-1;
            }
        }
        return false;
    }
};
