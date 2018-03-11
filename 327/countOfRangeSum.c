class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int result=0;
        divide(nums,0,nums.size()-1,lower,upper,result);
        return result;
    }
    
    void divide(vector<int>& nums, int left,int right,int lower,int upper,int &result){
        if(left>right){
            return;
        }
        
        if(left==right){
            if(nums[left]>=lower and nums[left]<=upper){
                ++result;
                cout<<nums[left]<<endl;
            }
            return;
        }
        
        int mid=(left+right)/2;
        divide(nums,left,mid,lower,upper,result);
        divide(nums,mid+1,right,lower,upper,result);
        
        vector<long long int> prefix,suffix;
        long long int sum=0;
        for(int i=mid;i>=left;--i){
            sum+=nums[i];
            suffix.push_back(sum);
        }
        //reverse(suffix.begin(),suffix.end());
        sort(suffix.begin(),suffix.end());
        
        sum=0;
        for(int i=mid+1;i<=right;++i){
            sum+=nums[i];
            prefix.push_back(sum);
        }
        
        for(int i=0;i<prefix.size();++i){
            binarySearch(suffix,lower,upper,prefix[i],result);
        }
    }
    
    void binarySearch(vector<long long int>&suffix, long long int lower, long long int upper, int current, int &result){
        int left=find(suffix,lower-current,true);
        int right=find(suffix,upper-current,false);
        if(left>=suffix.size()){
            return;
        }
        if(right<0){
            return;
        }
        result+=(right-left+1);
    }
    
    int find(vector<long long int>&suffix,long long int target,bool flag){
        int left=0;
        int right=suffix.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(suffix[mid]==target){
                if(flag){
                    while(mid-1>=0 and suffix[mid-1]==target){
                        --mid;
                    }
                }else{
                    while(mid+1<suffix.size() and suffix[mid+1]==target){
                        ++mid;
                    }
                }
                return mid;
            }else if(suffix[mid]<target){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        
        if(flag){
            if(suffix[left]>target){
                return left;
            }else if(suffix[left]==target){
                while(left-1>=0 and suffix[left-1]==target){
                    --left;
                }
                return left;
            }else{
                return left+1;
            }
        }else{
            if(suffix[left]<target){
                return left;
            }else if(suffix[left]==target){
                while(left+1<suffix.size() and suffix[left+1]==target){
                    ++left;
                }
                return left;
            }else{
                return left-1;
            }
        }
    }
};
