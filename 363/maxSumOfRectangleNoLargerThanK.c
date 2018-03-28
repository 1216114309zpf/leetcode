class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        vector<int> mid(matrix.size(),0);
        int result=INT_MIN;
        for(int i=0;i<matrix[0].size();++i){
            for(int i=0;i<mid.size();++i){
                mid[i]=0;
            }
            for(int j=i;j<matrix[0].size();++j){
                for(int p=0;p<mid.size();++p){
                    mid[p]+=matrix[p][j];
                }
                help(mid,result,k);
            }
        }
        return result;
    }
    
    void help(vector<int>&mid,int&current,int k){
        set<int> myset;
        int sum=0;
        myset.insert(0);
        for(int i=0;i<mid.size();++i){
            sum+=mid[i];
            auto itr=myset.lower_bound(sum-k);
            if(itr!=myset.end())
                current=max(current,(sum-(*itr)));
            myset.insert(sum);
        }
    }
};
