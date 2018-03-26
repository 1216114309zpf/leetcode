class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> myMap;
        int ones=0;
        int zeros=0;
        int result=0;
        myMap[0]=-1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                ones++;
            }else{
                zeros++;
            }
            
            int dif=ones-zeros;
            if(myMap.count(dif)==0){
                myMap[dif]=i;
            }else{
                if(i-myMap[dif]>result){
                    result=i-myMap[dif];
                }
            }
        }
        return result;
    }
};
