class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        int added=1;
        for(int i=0;i<n;++i){
            int size=result.size();
            for(int j=size-1;j>=0;--j){
                result.push_back(result[j]+added);
            }
            added*=2;
        }
        return result;
    }
};
