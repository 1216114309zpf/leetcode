class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>> mymap;
        for(int i=0;i<nums.size();++i){
            if(mymap.count(nums[i]-1)==0 or mymap[nums[i]-1].empty()){
                if(mymap.count(nums[i])==0){
                    priority_queue<int,vector<int>,greater<int>> que;
                    que.push(1);
                    mymap[nums[i]]=que;
                }else{
                    mymap[nums[i]].push(1);
                }
            }else{
                int tmp=mymap[nums[i]-1].top();
                mymap[nums[i]-1].pop();
                mymap[nums[i]].push(tmp+1);
            }
        }
        
        for(auto itr=mymap.begin();itr!=mymap.end();++itr){
            if(!itr->second.empty() and itr->second.top()<3)
                return false;
        }
        
        return true;
    }
};
