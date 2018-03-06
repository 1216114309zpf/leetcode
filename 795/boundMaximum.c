class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int result=0;
        vector<int> segment;
        for(int i=0;i<A.size();++i){
            if(A[i]>R){
                result+=help(segment,L);
                segment.clear();
            }else{
                segment.push_back(A[i]);
            }
        }
        result+=help(segment,L);
        return result;
    }
    
    int help(vector<int>& segment, int left){
        int result=segment.size()*(segment.size()+1)/2;
        int length=0;
        for(int i=0;i<segment.size();++i){
            if(segment[i]<left){
                ++length;
            }else{
                result-=length*(length+1)/2;
                length=0;
            }
        }
        result-=length*(length+1)/2;
        return result;
    }
};
