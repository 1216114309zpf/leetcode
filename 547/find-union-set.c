class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> vec;
        for(int i=0;i<M.size();++i){
            vec.push_back(-1);
        }
        int result=0;
        for(int i=0;i<M.size();++i){
            for(int j=0;j<M.size();++j){
                if(M[i][j])
                    Union(vec,i,j);
            }
        }
        for(int i=0;i<M.size();++i){
            if(vec[i]<0){
                ++result;
            }
        }
        return result;
    }
    
    int find(vector<int>& vec, int a){
        if(vec[a]<0){
            return a;
        }else{
            return vec[a]=find(vec,vec[a]);
        }
    }
    void Union(vector<int>& vec,int a,int b){
        int roota=find(vec,a);
        int rootb=find(vec,b);
        if(roota==rootb){
            return;
        }
        if(vec[roota]<vec[rootb]){
            vec[roota]+=vec[rootb];
            vec[rootb]=roota;
        }else{
            vec[rootb]+=vec[roota];
            vec[roota]=rootb;
        }
    }
};
