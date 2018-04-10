class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        long long result=sum-nums[0]*nums.size();
        long long  value=nums[0];
        int index=1;
        while(index<nums.size()){
            if(nums[index]==value){
                
            }else{
                int added=(nums[index]-value)*index;
                int minus=(nums[index]-value)*(nums.size()-index);
                result=min(result,result+added-minus);
                value=nums[index];
            }
            ++index;
        }
        return result;
    }
};
