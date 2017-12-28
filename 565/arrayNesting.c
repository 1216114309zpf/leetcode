class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int *searched = new int[nums.size()];
        int result = 0;
        for(int i=0;i<nums.size();++i)
            searched[i]=0;
        for(int i=0; i<nums.size();++i){
            if(searched[i]==0){
                int length = dfs(searched,nums,i);
                if(length>result)
                    result=length;
            }
        }
        return result;
    }
    
    int dfs(int* searched, vector<int>& nums,int index){
        int length=0;
        while(searched[index]==0){
            searched[index]=1;
            index=nums[index];
            ++length;
        }
        return length;
    }
};
