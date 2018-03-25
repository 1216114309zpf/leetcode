struct Tree{
        int row;
        int col;
        int height;
        Tree(int row,int col,int height):row(row),col(col),height(height){}
        friend bool operator<(const Tree&,const Tree&);
    };
bool operator<(const Tree &a, const Tree &b){
        return a.height>b.height;
    }
class Solution {
public:
    
    int cutOffTree(vector<vector<int>>& forest) {
        priority_queue<Tree> que;
        for(int i=0;i<forest.size();++i){
            for(int j=0;j<forest[i].size();++j){
                if(forest[i][j]>1){
                    Tree tree(i,j,forest[i][j]);
                    que.push(tree);
                }
            }
        }
        
        int result=0;
        
        Tree current(0,0,forest[0][0]);
        while(!que.empty()){
            Tree tree=que.top();
            que.pop();
            int distance=calDistance(forest,current,tree);
            if(distance==-1)
                return -1;
            result+=distance;
            current=tree;
        }
        
        return result;
    }
    
    
    int calDistance(vector<vector<int>> forest, Tree source, Tree target){
        int result=0;
        queue<Tree> que;
        que.push(source);
        que.push(Tree(-1,-1,-1));
        while(!que.empty()){
            Tree current=que.front();
            que.pop();
            if(current.row==-1){
                if(!que.empty()){
                    que.push(Tree(-1,-1,-1));
                    ++result;
                }
            }else{
                forest[current.row][current.col]=0;
                if(current.row==target.row and current.col==target.col){
                    return result;
                }else{
                    if(current.row!=0 and forest[current.row-1][current.col]!=0){
                        que.push(Tree(current.row-1,current.col,forest[current.row-1][current.col]));
                    }
                    
                    if(current.row!=forest.size()-1 and forest[current.row+1][current.col]!=0){
                        que.push(Tree(current.row+1,current.col,forest[current.row+1][current.col]));
                    }
                    
                    if(current.col!=0 and forest[current.row][current.col-1]!=0){
                        que.push(Tree(current.row,current.col-1,forest[current.row][current.col-1]));
                    }
                    
                    if(current.col!=forest[0].size()-1 and forest[current.row][current.col+1]!=0){
                        que.push(Tree(current.row,current.col+1,forest[current.row][current.col+1]));
                    }
                }
            }
            
        }
        return -1;
    }
};
