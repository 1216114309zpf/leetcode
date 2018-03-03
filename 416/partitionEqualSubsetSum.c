class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
        }
        if(sum%2){
            return false;
        }
        
        int target = sum/2;
        bool **array = new bool*[nums.size()+1];
        for(int i=0;i<nums.size()+1;++i){
            array[i]=new bool[target+1];
        }
        
        array[0][0]=true;
        for(int i=1;i<target+1;++i){
            array[0][i]=false;
        }
        for(int i=1;i<nums.size()+1;++i){
            array[i][0]=true;
        }
        
        for(int i=1;i<nums.size()+1;++i){
            for(int j=1;j<target+1;++j){
                array[i][j]=(array[i-1][j] or array[i-1][j-nums[i-1]]);
            }
        }
        return array[nums.size()][target];
    }
};
