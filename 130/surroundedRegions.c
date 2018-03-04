class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return;
        vector<vector<int>> deuxMatrix;
        for(int i=0;i<board[0].size();++i){
            vector<int> vec;
            vec.push_back(0);
            vec.push_back(i);
            deuxMatrix.push_back(vec);
            vec[0]=board.size()-1;
            deuxMatrix.push_back(vec);
        }
        for(int i=0;i<board.size();++i){
            vector<int> vec;
            vec.push_back(i);
            vec.push_back(0);
            deuxMatrix.push_back(vec);
            vec[1]=board[0].size()-1;
            deuxMatrix.push_back(vec);
        }
        
        
        for(int i=0;i<deuxMatrix.size();++i){
            if(board[deuxMatrix[i][0]][deuxMatrix[i][1]]=='O'){
                stack<vector<int>> stk;
                stk.push(deuxMatrix[i]);
                while(!stk.empty()){
                    vector<int> tmp=stk.top();
                    stk.pop();
                    board[tmp[0]][tmp[1]]='C';
                    if(tmp[0]-1>=0 and board[tmp[0]-1][tmp[1]]=='O'){
                        vector<int> up=tmp;
                        up[0]-=1;
                        stk.push(up);
                    }
                    
                    if(tmp[0]+1<board.size() and board[tmp[0]+1][tmp[1]]=='O'){
                        vector<int> down=tmp;
                        down[0]+=1;
                        stk.push(down);
                    }
                    
                    if(tmp[1]-1>=0 and board[tmp[0]][tmp[1]-1]=='O'){
                        vector<int> left=tmp;
                        left[1]-=1;
                        stk.push(left);
                    }
                    
                    if(tmp[1]+1<board[0].size() and board[tmp[0]][tmp[1]+1]=='O'){
                        vector<int> right=tmp;
                        right[1]+=1;
                        stk.push(right);
                    }
                }
            }
        }
        
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='C'){
                    board[i][j]='O';
                }
            }
        }
    }
};
