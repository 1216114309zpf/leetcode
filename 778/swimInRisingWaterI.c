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
            vector<int> tmp(grid.size(),-1);
            vector<vector<int>> exist(grid.size(),tmp);
            if(help(grid,que.top(),0,0,exist)){
                return que.top();
            }
            que.pop();
        }
    }
    
    bool help(vector<vector<int>> &grid, int level,int row,int col,vector<vector<int>>& exist){
        if(exist[row][col]!=-1)
            return exist[row][col];
        
        if(row==grid.size()-1 and col==grid.size()-1){
            return true;
        }
        
        int old=grid[row][col];
        grid[row][col]=-1;
            //right
            if(col+1<grid.size() and grid[row][col+1]!=-1 and grid[row][col+1]<=level){
                if(help(grid,level,row,col+1,exist))
                    return exist[row][col]=true;
            }
            //down
            if(row+1<grid.size() and grid[row+1][col]!=-1 and grid[row+1][col]<=level){
                if(help(grid,level,row+1,col,exist))
                    return exist[row][col]=true;
            }
            //up
            if(row!=0 and grid[row-1][col]!=-1 and grid[row-1][col]<=level){
                if(help(grid,level,row-1,col,exist))
                    return exist[row][col]=true;
            }
            
            
            //left
            if(col!=0 and grid[row][col-1]!=-1 and grid[row][col-1]<=level){
                if(help(grid,level,row,col-1,exist))
                    return exist[row][col]=true;
            }
        grid[row][col]=old;
        return exist[row][col]=false;
    }
};
