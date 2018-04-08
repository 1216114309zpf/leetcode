class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        recursive(result,current,1,k,n);
        return result;
    }
    
    void recursive(vector<vector<int>>&result,vector<int> current,int now, int remain,int target){
        int summ=sum(current);
        if(remain==0){
            if(summ==target){
                result.push_back(current);
            }
            return;
        }
        
        if(now==10)
            return;
        
        if(summ+now>target)
            return;
        
        recursive(result,current,now+1,remain,target);
        current.push_back(now);
        recursive(result,current,now+1,remain-1,target);
    }
    
    int sum(vector<int>&array){
        int result=0;
        for(int i=0;i<array.size();++i)
            result+=array[i];
        return result;
    }
};
