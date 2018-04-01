class Solution {
    struct Node{
        int first;
        int second;
        int indexf;
        int indexs;
        Node(int first,int second,int indexf,int indexs){
            this->first=first;
            this->second=second;
            this->indexf=indexf;
            this->indexs=indexs;
        }
        
        Node(const Node& a){
            first=a.first;
            second=a.second;
            indexf=a.indexf;
            indexs=a.indexs;
        }
        
        bool operator<(const Node& a) const{
            return first+second<a.first+a.second;
        }
        
        bool operator>(const Node& a) const{
            return first+second>a.first+a.second;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        if(nums1.empty() or nums2.empty())
            return result;
        priority_queue<Node,vector<Node>,greater<Node>> que;
        for(int i=0;i<nums1.size();++i){
            que.push(Node(nums1[i],nums2[0],i,0));
        }
        
        while(k){
            if(!que.empty()){
                Node node=que.top();
                result.push_back(pair<int,int>(node.first,node.second));
                int i=node.indexf;
                int j=node.indexs;
                que.pop();
                if(j<nums2.size()-1){
                    que.push(Node(nums1[i],nums2[j+1],i,j+1));
                }
            }else{
                break;
            }
            --k;
        }
        
        return result;
    }
};
