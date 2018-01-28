class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result;
        if(nums.empty())
            return result;
        unordered_map<int,int> myMap;
        stack<int> stk;
        for(int i=0;i<nums.size();++i){
            if(stk.empty()){
                stk.push(nums[i]);
            }else if(nums[i]<stk.top()){
                stk.push(nums[i]);
            }else{
                while(!stk.empty() and nums[i]>stk.top()){
                    myMap[stk.top()]=nums[i];
                    stk.pop();
                }
                stk.push(nums[i]);
            }
        }
        while(!stk.empty()){
            myMap[stk.top()]=-1;
            stk.pop();
        }
        for(int i=0;i<findNums.size();++i){
            result.push_back(myMap[findNums[i]]);
        }
        return result;
    }
};
