class Solution {
public:
    struct Node{
        Node*next[2];
        Node(){
            next[0]=NULL;
            next[1]=NULL;
        }
    };
    int findMaximumXOR(vector<int>& nums) {
        Node*root=new Node();
        vector<vector<int>> vec;
        for(int i=0;i<nums.size();++i){
            vector<int> num=toString(nums[i]);
            Node*ptr=root;
            for(int j=0;j<32;++j){
                if(!ptr->next[num[j]]){
                    ptr->next[num[j]]=new Node();
                }
                ptr=ptr->next[num[j]];
            }
            vec.push_back(num);
        }
        
        int result=0;
        for(int i=0;i<vec.size();++i){
            int tmp=0;
            vector<int> number=vec[i];
            Node*ptr=root;
            for(int j=0;j<32;++j){
                if(ptr->next[!number[j]]){
                    tmp+=pow(2,31-j);
                    ptr=ptr->next[!number[j]];
                }else{
                    ptr=ptr->next[number[j]];
                }
            }
            if(tmp>result){
                result=tmp;
            }
        }
        return result;
    }
    vector<int> toString(int num){
        vector<int> result;
        while(num){
            result.push_back(num%2);
            num/=2;
        }
        while(result.size()<32)
            result.push_back(0);
        reverse(result.begin(),result.end());
        return result;
    }
};
