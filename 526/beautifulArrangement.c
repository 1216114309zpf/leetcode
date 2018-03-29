class Solution {
public:
    int countArrangement(int N) {
        vector<bool> arranged(N+1,false);
        int result=0;
        arrange(arranged,result,1,N);
        return result;
    }
    
    void arrange(vector<bool>& arranged, int& result, int position,int N){
        if(position==N+1){
            ++result;
            return;
        }
        
        for(int i=1;i<=N;++i){
            if(!arranged[i] and (i%position==0 or position%i==0)){
                arranged[i]=true;
                arrange(arranged,result,position+1,N);
                arranged[i]=false;
            }
        }
    }
};
