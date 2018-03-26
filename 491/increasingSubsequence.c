class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        vector<vector<vector<int>>> mid(nums.size(),result);
        
        unordered_map<int,int> myMap;
        
        for(int i=1;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[i]<nums[j]){
                    continue;
                }else if(nums[i]==nums[j]){
                    mid[i].clear();
                    mid[i]=mid[j];
                    for(int k=0;k<mid[i].size();++k){
                        mid[i][k].push_back(nums[i]);
                    }
                    vector<int> tmp={nums[j],nums[i]};
                    if(myMap.count(nums[j]*1000+nums[i])==0){
                          myMap[nums[j]*1000+nums[i]]=1;
                          mid[i].push_back(tmp);
                    }
                }else{
                    for(int k=0;k<mid[j].size();++k){
                        mid[i].push_back(mid[j][k]);
                        mid[i][mid[i].size()-1].push_back(nums[i]);
                    }
                    vector<int> tmp={nums[j],nums[i]};
                    if(myMap.count(nums[j]*1000+nums[i])==0){
                          myMap[nums[j]*1000+nums[i]]=1;
                          mid[i].push_back(tmp);
                    }
                }
            }
        }
        for(int i=0;i<mid.size();++i){
            for(int j=0;j<mid[i].size();++j){
                result.push_back(mid[i][j]);
            }
        }
        return result;
    }
};
