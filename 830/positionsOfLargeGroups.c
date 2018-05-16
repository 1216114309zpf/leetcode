class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        if(S.size()==0)
            return result;
        int start=0;
        int end=0;
        char current=S[0];
        for(int i=1;i<S.size();++i){
            if(current==S[i]){
                ++end;
            }else{
                if(end-start>=2){
                    vector<int> tmp={start,end};
                    result.push_back(tmp);
                }
                start=end=i;
                current=S[i];
            }
        }
        if(end-start>=2){
            vector<int> tmp={start,end};
            result.push_back(tmp);
        }
        return result;
    }
};
