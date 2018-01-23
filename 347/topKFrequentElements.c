class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> hashtable;
        for(int i=0;i<nums.size();++i){
            ++hashtable[nums[i]];
        }
        
        vector<vector<int>> bucket(nums.size()+1);
        
        for(auto itr: hashtable){
            bucket[itr.second].push_back(itr.first);
        }
        
        vector<int> result;
        for(int i=bucket.size()-1;i>=0;--i){
            for(int j=0;j<bucket[i].size();++j){
                if(result.size()==k)
                    return result;
                result.push_back(bucket[i][j]);
            }
        }
        return result;
    }
};
