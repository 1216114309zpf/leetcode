class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int **array = new int*[A.size()+1];
        for(int i=0; i<A.size()+1; ++i)
            array[i] = new int[B.size()+1];
        
        for(int i=0; i<A.size()+1; ++i)
            array[i][0] = 0;
        for(int i=0; i<B.size()+1; ++i)
            array[0][i] = 0;
        
        int result = 0;
        for(int i=1; i<A.size()+1; ++i){
            for(int j=1; j<B.size()+1; ++j){
                if(A[i-1] != B[j-1])
                    continue;
                array[i][j] = array[i-1][j-1]+1;
                if(array[i][j] > result)
                    result = array[i][j];
            }
        }
        
        return result;
    }
};
