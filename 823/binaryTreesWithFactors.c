class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(),A.end());
        unordered_map<int,long long int> mymap;
        long long int count=0;
        for(int i=0;i<A.size();++i){
            long long int result=1;
            for(int j=0;j<i and A[j]<=sqrt(A[i]);++j){
                if(A[i]%A[j]==0 and mymap.count(A[i]/A[j])!=0){
                    if(A[i]!=A[j]*A[j])
                        result+=(mymap[A[i]/A[j]]*mymap[A[j]]*2%1000000007);
                    else
                        result+=(mymap[A[i]/A[j]]*mymap[A[j]]%1000000007);
                }
            }
            mymap[A[i]]=result;
            count+=result;
            count%=1000000007;
        }
        return count;
    }
};
