class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
         unordered_map<int,vector<int>> mp;
         for(int i=0;i<nums.size();++i){
             mp[nums[i]].push_back(i);
         }
        
        int degree = 0;
        int range = 0;
        
        for(auto it=mp.begin();it!=mp.end();it++){
            int size=it->second.size();
            if(size>degree){
                degree=size;
                range=it->second[size-1] - it->second[0] + 1;
            }else if(size==degree){
                int tmp=it->second[size-1] - it->second[0] + 1;
                if(tmp<range)
                    range=tmp;
            }else{
                
            }
        }
        return range;
    }
};
