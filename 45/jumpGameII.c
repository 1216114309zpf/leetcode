class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int steps=1;
        for(int i=0;i<nums.size();++i){
            int remain=nums[i];
            if(i+remain>=nums.size()-1)
                return steps;
            int position=i;
            for(int j=1;j<=remain;++j){
                if(nums[i+j]>=nums[position]-(i+j-position)){
                     position=i+j;
                }
            }
            if(position==i)
                i=i+remain;
            else
                i=position;
            --i;
            ++steps;
        }
        return steps;
    }

};
