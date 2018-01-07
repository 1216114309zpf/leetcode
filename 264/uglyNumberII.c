class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vec;
        int id2=0,id3=0,id5=0;
        vec.push_back(1);
        while(--n){
            int candidate=min(2*vec[id2],min(3*vec[id3],5*vec[id5]));
            vec.push_back(candidate);
            id2+=(candidate==2*vec[id2]);
            id3+=(candidate==3*vec[id3]);
            id5+=(candidate==5*vec[id5]);
        }
        return vec[vec.size()-1];
    }
    
};
