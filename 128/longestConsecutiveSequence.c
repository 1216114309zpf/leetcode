class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        vector<int> vec;
        for(int i=0;i<nums.size();++i){
            vec.push_back(-1);
        }
        
        unordered_map<int,int> myMap;
        for(int i=0;i<nums.size();++i){
            myMap[nums[i]]=i;
        }
        
        for(int i=0;i<nums.size();++i){
            if(myMap.count(nums[i]-1)!=0){
                Union(vec,myMap[nums[i]],myMap[nums[i]-1]);
            }
            // if(myMap.count(nums[i]+1)!=0){
            //     Union(vec,i,myMap[nums[i]+1]);
            // }
        }
        int result=1;
        for(int i=0;i<vec.size();++i){
            if(vec[i]<0 and result<abs(vec[i])){
                result=abs(vec[i]);
            }
        }
        return result;
    }
    
    int find(vector<int>& vec, int index){
        if(vec[index]<0){
            return index;
        }else{
            return vec[index]=find(vec,vec[index]);
        }
    }
    
    void Union(vector<int>& vec, int indexa, int indexb){
        int roota=find(vec,indexa);
        int rootb=find(vec,indexb);
        if(roota==rootb){
            return;
        }
        if(vec[roota]<vec[rootb]){
            vec[roota]+=vec[rootb];
            vec[rootb]=roota;
        }else{
            vec[rootb]+=vec[roota];
            vec[roota]=rootb;
        }
    }
};
