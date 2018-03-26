class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        vector<int> length(pairs.size(),1);
        for(int i=0;i<pairs.size();++i){
            for(int j=0;j<i;++j){
                if(pairs[i][0]>pairs[j][1] and length[j]+1>length[i]){
                    length[i]=length[j]+1;
                }
            }
        }
        int result=0;
        for(int i=0;i<length.size();++i){
            if(length[i]>result)
                result=length[i];
        }
        return result;
    }
    
    static bool compare(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
};
