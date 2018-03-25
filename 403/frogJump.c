class Solution {
public:
    bool canCross(vector<int>& stones){
        if(stones.size()==1)
            return true;
        if(stones[1]!=1)
            return false;
        vector<int> tmp(stones.size(),-1);
        vector<vector<int>> mid(stones.size(),tmp);
        return help(stones,mid,1,1);
    }
    
    bool help(vector<int>& stones, vector<vector<int>>&mid, int pos,int steps){
        if(mid[pos][steps]!=-1)
            return mid[pos][steps];
        if(pos==stones.size()-1){
            return mid[pos][steps]=true;
        }
        for(int i=pos+1;i<stones.size();++i){
            int gap=stones[i]-stones[pos];
            if(gap<steps-1)
                continue;
            else if(gap>steps+1){
                return mid[pos][steps]=false;
            }else{
                if(help(stones,mid,i,gap)){
                    return mid[pos][steps]=true;
                }
            }
        }
        return mid[pos][steps]=false;
    }
};
