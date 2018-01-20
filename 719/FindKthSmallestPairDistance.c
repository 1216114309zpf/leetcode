class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int *array=new  int[1000000];
        for(int i=0;i<1000000;++i)
            array[i]=0;
        for(int i=0;i<nums.size()-1;++i){
            for(int j=i+1;j<nums.size();++j){
                ++array[abs(nums[i]-nums[j])];
            }
        }
         int count=0;
        for(int i=0;i<1000000;++i){
            if(count+array[i]>=k)
                return i;
            count+=array[i];
        }
    }
};
