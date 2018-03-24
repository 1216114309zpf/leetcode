class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size()==0 or nums.size()<4)
            return false;
        int total=0;
        for(int i=0;i<nums.size();++i){
            total+=nums[i];
        }
        
        if(total%4!=0){
            return false;
        }
        
        int average=total/4;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>average){
                return false;
            }
        }
        
        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());
        
        vector<int> sum(4,0);
        return dfs(nums,sum,0, average);
    }
    
    bool dfs(vector<int> &nums, vector<int> &sum, int index, int target){
        if(index==nums.size()-1){
            if(sum[0]==target and sum[1]==target and sum[2]==target){
               return true;
            }else{
                return false;
            }
        }
        
        for(int i=0;i<4;++i){
            if(sum[i]+nums[index]<=target){
                 sum[i]+=nums[index];
                 if(dfs(nums,sum,index+1,target)){
                    return true;
                 }
                 sum[i]-=nums[index];
            }
        }
        return false;
    }
};
