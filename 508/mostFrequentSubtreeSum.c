class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> counts;
        int maxCount=0;
        subSum(root,counts,maxCount);
        vector<int> result;
        for(auto itr:counts){
            if(itr.second==maxCount)
                result.push_back(itr.first);
        }
        return result;
    }
    
    int subSum(TreeNode*root, unordered_map<int,int>& counts, int& maxCount){
        if(!root)
            return 0;
        int left=subSum(root->left,counts,maxCount);
        int right=subSum(root->right,counts,maxCount);
        int sum=left+right+root->val;
        ++counts[sum];
        maxCount=max(maxCount,counts[sum]);
        return sum; 
    }
};
