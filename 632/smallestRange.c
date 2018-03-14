class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int,vector<pair<int,int>>> myMap;
        int left=100001;
        int right=-100001;
        for(int i=0;i<nums.size();++i){
            if(nums[i][0]<=left){
                left=nums[i][0];
            }
            if(nums[i][0]>=right){
                right=nums[i][0];
            }
        }
        
        int length=right-left;
        vector<int> result;
        result.push_back(left);
        result.push_back(right);
        
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums[i].size();++j){
                pair<int,int> item;
                item.first=i;
                item.second=j;
                myMap[nums[i][j]].push_back(item);
            }
        }
        
        auto itr=myMap.begin();
        ++itr;
            
        for(;itr!=myMap.end();++itr){
            vector<pair<int,int>> itemList=myMap[left];
            left = itr->first;
            for(int i=0;i<itemList.size();++i){
                pair<int,int> item=itemList[i];
                if(item.second==nums[item.first].size()-1){
                    return result;
                }
                if(nums[item.first][item.second+1]>right){
                    right=nums[item.first][item.second+1];
                }
            }
            if(right-left<length){
                result.clear();
                result.push_back(left);
                result.push_back(right);
                length=right-left;
            }
        }
        return result;
    }
};
