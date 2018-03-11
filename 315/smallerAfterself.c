class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        vector<vector<int>> vec;
        for(int i=0;i<nums.size();++i){
            result.push_back(0);
            vector<int> tmp;
            tmp.push_back(i);
            tmp.push_back(nums[i]);
            vec.push_back(tmp);
        }
        divide(vec,0,nums.size()-1,result);
        return result;
    }
    
    int divide(vector<vector<int>>& vec,int left,int right,vector<int>& result){
        if(left>=right){
            return 0;
        }
        
        int mid=(left+right)/2;
        divide(vec,left,mid,result);
        divide(vec,mid+1,right,result);
        
        int current=mid+1;
        for(int i=left;i<=mid;++i){
            while(current<=right and vec[i][1]<=vec[current][1]){
                ++current;
            }
            if(current>right){
                break;
            }else{
                result[vec[i][0]]+=(right-current+1);
            }
        }
        sort(vec.begin()+left,vec.begin()+right+1,compare);
        reverse(vec.begin()+left,vec.begin()+right+1);
        return 0;
    }
    
    static bool compare(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
};
