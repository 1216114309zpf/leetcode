class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        if(sum%k){
            return false;
        }
        
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        
        vector<vector<int>> partition;
        vector<int> vec;
        for(int i=0;i<k;++i){
            partition.push_back(vec);
        }
        
        if(search(nums,sum/k,0,partition)){
            return true;
        }
        return false;
    }
    
    bool search(vector<int>& nums,int target,int ith,vector<vector<int>>& partition){
        if(ith==nums.size())
            return true;
        for(int i=0;i<partition.size();++i){
            partition[i].push_back(nums[ith]);
            if(sum(partition[i])<=target){
                if(search(nums,target,ith+1,partition)){
                    return true;
                }else{
                    partition[i].pop_back(); 
                }
            }else{
                partition[i].pop_back();
            }
        }
        return false;
    }
    
    int sum(vector<int>& vec){
        int result=0;
        for(int i=0;i<vec.size();++i){
            result+=vec[i];
        }
        return result;
    }
};
