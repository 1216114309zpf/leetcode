class Solution {
public:
    
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int result=0;
        result+=divide(nums,0,nums.size()-1);
        return result;
    }
    
    int divide(vector<int>&nums,int left,int right){
        if(left==right){
            return 0;
        }
        int result=0;
        int mid=(left+right)/2;
        result+=divide(nums,left,mid);
        result+=divide(nums,mid+1,right);
        
        int current=mid+1;
        for(int i=left;i<=mid;++i){
            while(current<=right and double(nums[i])/2<=double(nums[current])){
                ++current;
            }
            if(current<=right){
                result+=(right-current+1);
            }else{
                break;
            }
        }
        
        //sort
        sort(nums.begin()+left,nums.begin()+right+1);
        reverse(nums.begin()+left,nums.begin()+right+1);
        return result;
    }
};
