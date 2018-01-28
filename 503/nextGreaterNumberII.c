class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<pair<int,int>> stk;
        vector<int> result(nums.size());
        for(int i=0;i<nums.size();++i){
            while(!stk.empty() and nums[i]>stk.top().second){
                result[stk.top().first]=nums[i];
                stk.pop();
            }
            pair<int,int> tmp;
            tmp.first=i;
            tmp.second=nums[i];
            stk.push(tmp);
        }
        for(int i=0;i<nums.size();++i){
            while(!stk.empty() and nums[i]>stk.top().second){
                result[stk.top().first]=nums[i];
                stk.pop();
            }
        }
        while(!stk.empty()){
            result[stk.top().first]=-1;
            stk.pop();
        }
        return result;
    }
};
