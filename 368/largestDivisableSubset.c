class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        unordered_map<int,vector<int>> mymap;//index-->vector<index>
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[i]%nums[j]==0){
                    mymap[j].push_back(i);
                }else if(nums[j]%nums[i]==0){
                    mymap[i].push_back(j);
                }else{
                    continue;
                }
            }
        }
        
        vector<int> tmp;
        vector<vector<int>> matrix(nums.size(),tmp);
        for(int i=0;i<matrix.size();++i){
            computePath(mymap,matrix,nums,i);
        }
        vector<int> result;
        for(int i=0;i<matrix.size();++i){
            if(matrix[i].size()>result.size())
                result=matrix[i];
        }
        return result;
    }
    
    vector<int> computePath(unordered_map<int,vector<int>>&mymap,vector<vector<int>>&matrix,vector<int>& nums,int index){
        if(matrix[index].size()!=0){
            return matrix[index];
        }
        
        if(mymap[index].size()==0){
            matrix[index].push_back(nums[index]);
            return matrix[index];
        }
        
        matrix[index].push_back(nums[index]);
        vector<int> candidate;
        for(int i=0;i<mymap[index].size();++i){
            vector<int> tmp=computePath(mymap,matrix,nums,mymap[index][i]);
            if(tmp.size()>candidate.size()){
                candidate=tmp;
            }
        }
        for(int i=0;i<candidate.size();++i){
            matrix[index].push_back(candidate[i]);
        }
        return matrix[index];
    }
};
