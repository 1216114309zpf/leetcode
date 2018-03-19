class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        vector<int> distance;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                distance.push_back(abs(nums[i]-nums[j]));
            } 
        }
        
        int index=findKthSmallest(distance,k,0,distance.size()-1);
        return distance[index];
    }
    
    int findKthSmallest(vector<int>&distance, int k, int start,int end){
        if(start==end){
            return start;
        }
        
        int tmp=distance[start];
        
        int left=start;
        int right=end;
        while(left<right){
            while(left<right and distance[right]>=tmp){
                --right;
            }
            
            if(left<right){
                distance[left]=distance[right];
                ++left;
            }
            
            while(left<right and distance[left]<=tmp){
                ++left;
            }
            
            if(left<right){
                distance[right]=distance[left];
                --right;
            }
        }
        
        distance[left]=tmp;
        if(k==left-start+1){
            return left;
        }else if(k<left-start+1){
            return findKthSmallest(distance,k,start,left-1);
        }else{
            return findKthSmallest(distance,k-(left-start+1),left+1,end);
        }
    }
};
