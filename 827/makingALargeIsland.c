class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<int>> group=grid;
        int groupId=10;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]!=1)
                    continue;
                findAnIsland(grid,i,j,group,groupId);
                ++groupId;
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
        int result=0;
        bool flag=true;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[i].size();++j){
                if(grid[i][j]!=0)
                    continue;
                flag=false;
                int tmp=1;
                vector<vector<int>> added={{0,1},{0,-1},{1,0},{-1,0}};
                vector<int> vecInt;
                vector<int> another;
                
                for(int t=0;t<4;++t){
                    if(i+added[t][0]>=0 and i+added[t][0]<grid.size() and j+added[t][1]>=0 and j+added[t][1]<grid[0].size()){
                        vecInt.push_back(grid[i+added[t][0]][j+added[t][1]]);
                        another.push_back(group[i+added[t][0]][j+added[t][1]]);
                    }else{
                        vecInt.push_back(0);
                        another.push_back(-1);
                    }
                    tmp+=vecInt[t];
                    for(int k=0;k<t;++k){
                        if(another[k]==another[t]){
                            tmp-=vecInt[t];
                            break;
                        }
                    }
                }
                if(tmp>result)
                    result=tmp;
            }
        }
        
        if(flag)
            return grid.size()*(grid[0].size());
        return result;
    }
    
    void findAnIsland(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& group,int groupId){
        int count=0;
        vector<vector<int>> added={{0,1},{0,-1},{1,0},{-1,0}};
        stack<pair<int,int>> stk;
        stk.push(pair<int,int>(row,col));
        grid[row][col]=-10000;
        while(!stk.empty()){
            pair<int,int> tmp = stk.top();
            stk.pop();
            ++count;
            for(int i=0;i<4;++i){
                int newFirst=tmp.first+added[i][0];
                int newSecond=tmp.second+added[i][1];
                if(newFirst>=0 and newFirst<grid.size() and newSecond>=0 and newSecond<grid[0].size() and grid[newFirst][newSecond]==1){
                    stk.push(pair<int,int>(newFirst,newSecond));
                    grid[newFirst][newSecond]=-10000;
                }
            } 
        }
        
        stk.push(pair<int,int>(row,col));
        while(!stk.empty()){
            pair<int,int> tmp = stk.top();
            stk.pop();
            grid[tmp.first][tmp.second]=count;
            group[tmp.first][tmp.second]=groupId;
            for(int i=0;i<4;++i){
                int newFirst=tmp.first+added[i][0];
                int newSecond=tmp.second+added[i][1];
                if(newFirst>=0 and newFirst<grid.size() and newSecond>=0 and newSecond<grid[0].size() and grid[newFirst][newSecond]==-10000){
                    stk.push(pair<int,int>(newFirst,newSecond));
                }
            } 
        }
    }
};
