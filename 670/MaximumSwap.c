class Solution {
public:
    int maximumSwap(int num) {
        vector<int> inter;
        int tmp=num;
        while(tmp){
            inter.push_back(tmp%10);
            tmp/=10;
        }
        
        reverse(inter.begin(),inter.end());
        for(int i=0;i<inter.size()-1;++i){
            int index=i+1;
            for(int j=i+2;j<inter.size();++j){
                if(inter[j]>=inter[index]){
                    index=j;
                }
            }
            if(inter[index]<=inter[i])
                continue;
            else{
                int tmp=inter[index];
                inter[index]=inter[i];
                inter[i]=tmp;
                
                int result=0;
                for(int k=0;k<inter.size();++k){
                    result*=10;
                    result+=inter[k];
                }
                return result;
            }
        }
        return num;
    }
};
