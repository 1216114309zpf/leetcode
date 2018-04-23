class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> result(S.size(),-1);
        bool found=false;
        int distance=-1;
        for(int i=0;i<S.size();++i){
            if(S[i]==C){
                found=true;
                result[i]=0;
                distance=1;
                for(int j=i-1;j>=0 and (result[j]==-1 or result[j]>(i-j));--j){
                    result[j]=i-j;
                }
            }else{
                if(found){
                    result[i]=distance++;
                }
            }
        }
        return result;
    }
};
