class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        
        int  positive=0;
        int  negative=0;
        int  result=1;
        
        for(int i=0;i<nums.size();++i){
            if(i==0){
                result=nums[0];
                if(nums[0]<0){
                    negative=nums[0];
                }
                if(nums[0]>0){
                    positive=nums[0];
                }
                continue;
            }
            
            if(nums[i]==0){
                positive=negative=0;
                if(result<0){
                    result=0;
                }
            }else if(nums[i]<0){
                int tmp=positive;
                positive=negative*nums[i];
                if(tmp>0)
                    negative=tmp*nums[i];
                else
                    negative=nums[i];
            }else{
                if(positive>0)
                    positive*=nums[i];
                else
                    positive=nums[i];
                
                negative*=nums[i];
            }
            
            if(positive>result){
                result=positive;
            }
        }
        
        return result;
    }
};
