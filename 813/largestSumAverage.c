class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        unordered_map<int,double>mymap;
        double result=help(mymap,A,K,0);
        return result;
    }
    
    double help(unordered_map<int,double>&mymap,vector<int>&A,int K,int current){
        int index=K*10000+current;
        if(mymap.count(index)!=0)
            return mymap[index];
        double result=0;
        if(K==A.size()-current){
            double sum=0;
            for(int i=current;i<A.size();++i)
                sum+=A[i];
            return mymap[index]=sum;
        }
        
        if(K==1){
            double sum=0;
            for(int i=current;i<A.size();++i)
                sum+=A[i];
            return mymap[index]=sum/(A.size()-current);
        }
        
        double sum=0.0;
        for(int i=current;i<A.size()-K+1;++i){
            sum+=A[i];
            result=max(result,sum/(i-current+1)+help(mymap,A,K-1,i+1));
        }
        
        return mymap[index]=result;
    }
    
    double max(double a,double b){
        return (a<b)?b:a;
    }
};
