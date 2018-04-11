class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        if(A.size()<2){
            return false;
        }
        
        int sum=0;
        for(int i=0;i<A.size();++i){
            sum+=A[i];
        }
        return canSplit(A,0,sum,0,0);
    }
    
    bool canSplit(vector<int>&A,int index,int sum,int count,int total){
        if(index==A.size()){
            return false;
        }

        if(count!=0 and sum*count==total*A.size()){
            return true;
        }
        
        
        if(canSplit(A,index+1,sum,count+1,total+A[index])){
            return true;
        }
        
        if(count==0){
            if(canSplit(A,index+1,sum,count,total))
                return true;
        }else{
            if(total*A.size()%count==0 and canSplit(A,index+1,sum,count,total))
                return true;
        }
        
        return false;
    }
};
