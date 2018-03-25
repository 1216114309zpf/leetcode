class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3){
            return 0;
        }
        
        int diff=A[1]-A[0];
        int count=2;
        
        int result=0;
        
        for(int i=2;i<A.size();++i){
            while(i<A.size() and A[i]-A[i-1]==diff){
                ++i;
                ++count;
            }
            if(count>=3){
               result+=(1+count-2)*(count-2)/2; 
            }
            
            if(i!=A.size()-1){
                diff=A[i]-A[i-1];
                count=2;
            }
        }
        
        return result;
    }
};
