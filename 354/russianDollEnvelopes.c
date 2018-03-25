class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),compare);
        vector<int> count(envelopes.size(),1);
        for(int i=1;i<envelopes.size();++i){
            for(int j=0;j<i;++j){
                if(canFit(envelopes[j],envelopes[i])){
                    if(count[j]+1>count[i]){
                        count[i]=count[j]+1;
                    }
                }
            }
        }
        int result=0;
        for(int i=0;i<envelopes.size();++i){
            if(count[i]>result){
                result=count[i];
            }
        }
        return result;
    }
    
    static bool compare(pair<int,int>& a, pair<int,int>& b){
        return a.first<b.first;
    }
    
    bool canFit(pair<int,int>& item1, pair<int,int> &item2){
        return item1.first<item2.first and item1.second<item2.second;
    }
};
