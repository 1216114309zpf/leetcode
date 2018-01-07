class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> vec;
        vec.push_back(1);
        vector<int> index;
        for(int i=0;i<primes.size();++i)
            index.push_back(0);
        while(--n){
            int candidate=-1;
            for(int i=0;i<primes.size();++i){
                int tmp=primes[i]*vec[index[i]];
                if(candidate==-1){
                    candidate=tmp;
                }
                if(tmp<candidate){
                    candidate=tmp;
                }
            }
            vec.push_back(candidate);
            for(int i=0;i<index.size();++i){
                index[i]+=(candidate==vec[index[i]]*primes[i]);
            }
        }
        return vec[vec.size()-1];
    }
};
