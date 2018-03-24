class Solution {
public:
    struct Node{
        int row;
        int col;
        int val;
    };
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<int> vec(matrix[0].size(),-1);
        vector<vector<int>> result(matrix.size(),vec);
        queue<Node> que;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                if(matrix[i][j]==0){
                    Node node;
                    node.row=i;
                    node.col=j;
                    node.val=0;
                    que.push(node);
                    result[i][j]=0;
                }
            }
        }
        
        while(!que.empty()){
            Node ptr=que.front();
            que.pop();
            if(ptr.row!=0 and result[ptr.row-1][ptr.col]==-1){
                Node tmp=ptr;
                tmp.row-=1;
                que.push(tmp);
                result[tmp.row][tmp.col]=result[ptr.row][ptr.col]+1;
            }
            
            if(ptr.row!=matrix.size()-1 and result[ptr.row+1][ptr.col]==-1){
                Node tmp=ptr;
                tmp.row+=1;
                que.push(tmp);
                result[tmp.row][tmp.col]=result[ptr.row][ptr.col]+1;
            }
            
            if(ptr.col!=matrix[0].size()-1 and result[ptr.row][ptr.col+1]==-1){
                Node tmp=ptr;
                tmp.col+=1;
                que.push(tmp);
                result[tmp.row][tmp.col]=result[ptr.row][ptr.col]+1;
            }
            
            if(ptr.col!=0 and result[ptr.row][ptr.col-1]==-1){
                Node tmp=ptr;
                tmp.col-=1;
                que.push(tmp);
                result[tmp.row][tmp.col]=result[ptr.row][ptr.col]+1;
            }
        }
        
        return result;
    }
};
