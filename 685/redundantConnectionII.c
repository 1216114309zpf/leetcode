class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<vector<int>> from, to;
        for(int i=0;i<edges.size()+1;++i){
            vector<int> tmp;
            from.push_back(tmp);
            to.push_back(tmp);
        }
        
        for(int i=0;i<edges.size();++i){
            vector<int> edge=edges[i];
            from[edge[0]].push_back(edge[1]);
            to[edge[1]].push_back(edge[0]);
        }
        
        vector<int> candidate;
        vector<int> another;
        for(int i=1;i<edges.size()+1;++i){
            if(to[i].size()==2){
                candidate.push_back(to[i][1]);
                candidate.push_back(i);
                another.push_back(to[i][0]);
                another.push_back(i);
            }
        }
        
        if(candidate.size()!=0){
            vector<int> vect;
            for(int i=0;i<edges.size()+1;++i){
                 vect.push_back(-1);
            }
            
            for(int i=0;i<edges.size();++i){
                if(edges[i][0]==candidate[0] and edges[i][1]==candidate[1]){
                    continue;
                }
                int a=find(vect,edges[i][0]);
                int b=find(vect,edges[i][1]);
                if(a==b){
                    return another;
                }
            
                 Union(vect,a,b);
            }
            
            return candidate;
        }
        
        vector<int> vec;
        for(int i=0;i<edges.size()+1;++i){
            vec.push_back(-1);
        }
        
        for(int i=0;i<edges.size();++i){
            int a=find(vec,edges[i][0]);
            int b=find(vec,edges[i][1]);
            if(a==b){
                return edges[i];
            }
            
            Union(vec,a,b);
        }
    }
    
    
    int find(vector<int>&vec, int index){
        if(vec[index]<0){
            return index;
        }else{
            return vec[index]=find(vec,vec[index]);
        }
    }
    
    void Union(vector<int>&vec, int indexa,int indexb){
        if(vec[indexa]<vec[indexb]){
            vec[indexa]+=vec[indexb];
            vec[indexb]=indexa;
        }else{
            vec[indexb]+=vec[indexa];
            vec[indexa]=indexb;
        }
    }

};
