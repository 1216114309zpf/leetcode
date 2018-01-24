class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int,int> myMap;
        for(int i=0;i<nums.size();++i){
            myMap[nums[i]]=i;
        }
        vector<string> result(nums.size());
        
        int rank=nums.size();
        for(auto it:myMap){
            if(rank>3){
                result[it.second]=toString(rank);
            }else{
                if(rank==3)
                    result[it.second]="Bronze Medal";
                else if(rank==2)
                    result[it.second]="Silver Medal";
                else
                    result[it.second]="Gold Medal";
            }
            --rank;
        }
        return result;
    }
    
    string toString(int  num){
        string result;
        while(num){
            result.push_back('0'+num%10);
            num/=10;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
