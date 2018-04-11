class Solution {
    struct Node{
        int row;
        int col;
        int value;
        Node(int row,int col,int value):row(row),col(col),value(value){};
        bool operator>(const Node&a) const{
            return value>a.value;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if(heightMap.size()<3 or heightMap[0].size()<3)
            return 0;
        priority_queue<Node,vector<Node>,greater<Node>> que;
        vector<bool> tmp(heightMap[0].size(),false);
        vector<vector<bool>> checked(heightMap.size(),tmp);
        
        for(int i=0;i<heightMap[0].size();++i){
            que.push(Node(0,i,heightMap[0][i]));
            checked[0][i]=true;
            que.push(Node(heightMap.size()-1,i,heightMap[heightMap.size()-1][i]));
            checked[checked.size()-1][i]=true;
        }
        
        for(int j=1;j<heightMap.size()-1;++j){
            que.push(Node(j,0,heightMap[j][0]));
            checked[j][0]=true;
            que.push(Node(j,heightMap[0].size()-1,heightMap[j][heightMap[0].size()-1]));
            checked[j][heightMap[0].size()-1]=true;
        }
        
        int Max=-1;
        int result=0;
        while(!que.empty()){
            Node ptr=que.top();
            que.pop();
            if(ptr.value > Max){
                Max=ptr.value;
            }
            
            vector<Node> neighbors=getNeighbor(heightMap,&ptr);
            for(int i=0;i<neighbors.size();++i){
                if(!checked[neighbors[i].row][neighbors[i].col]){
                    que.push(neighbors[i]);
                    checked[neighbors[i].row][neighbors[i].col]=true;
                    if(neighbors[i].value<Max){
                        result+=(Max-neighbors[i].value);
                    }
                }
            }
        }
        return result;
    }
    
    vector<Node> getNeighbor(vector<vector<int>>&heightMap,Node* ptr){
        vector<Node> result;
        vector<vector<int>> neighbors={{0,1},{0,-1},{-1,0},{1,0}};
        for(int i=0;i<neighbors.size();++i){
            if(ptr->row + neighbors[i][0]>=0 and ptr->row + neighbors[i][0]<heightMap.size()
              and ptr->col+neighbors[i][1]>=0 and ptr->col + neighbors[i][1]<heightMap[0].size()){
                result.push_back(Node(ptr->row + neighbors[i][0],ptr->col+neighbors[i][1],heightMap[ptr->row + neighbors[i][0]][ptr->col+neighbors[i][1]]));
            }
        }
        return result;
    }
};
