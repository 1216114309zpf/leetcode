class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        vector<int> vec;
        while(N){
            vec.push_back(N%10);
            N/=10;
        }
        vector<int> result = help(vec);
        int res = 0;
        for(int i=0; i<result.size(); ++i){
            res*=10;
            res+=result[i];
        }
        return res;
    }
    
    vector<int> help(vector<int> &vec){
        vector<int> result;
        if(vec.size()==1){
            result.push_back(vec[0]);
            return result;
        }
        
        if(check(vec)){
            result.push_back(vec[vec.size()-1]);
            vec.pop_back();
            vector<int> tmp = help(vec);
            for(int i=0; i<tmp.size(); ++i)
                result.push_back(tmp[i]);
        }
        else{
            if(vec[vec.size()-1] != 1){
                result.push_back(vec[vec.size()-1]-1);
            }
            for(int k=0; k<vec.size()-1; ++k)
                result.push_back(9);
        }
        
        return result;
    }
    
    bool check(vector<int> &vec){
        for(int i=vec.size()-2; i>=0; --i){
            if(vec[i]<vec[vec.size()-1])
                return false;
            if(vec[i]>vec[vec.size()-1])
                return true;
        }
        return true;
    }
};
