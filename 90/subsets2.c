class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> empty;
        result.push_back(empty);
        
        for(int i=0; i<nums.size(); ++i){
            int j=i;
            while(j<nums.size() and nums[j]==nums[i])
                ++j;
            int count=j-i;
            
            int size=result.size();
            for(int itr=1;itr<=count;++itr){
                for(int p=0;p<size;++p){
                    vector<int> tmp= result[p];
                    for(int t=0;t<itr;++t){
                        tmp.push_back(nums[i]);
                    }
                    result.push_back(tmp);
                }
            }
            
            i=j-1;
                
        }
        return result;
    }
};
