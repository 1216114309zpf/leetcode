/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        TreeNode* ptr=root;
        vector<int> array;
        while(ptr or !stk.empty()){
            if(ptr){
                stk.push(ptr);
                ptr=ptr->left;
            }else{
                ptr=stk.top();
                stk.pop();
                array.push_back(ptr->val);
                ptr=ptr->right;
            }
        }
        
        if(array.size()<2)
            return false;
        
        int left=0;
        int right=array.size()-1;
        while(left!=right){
            if(array[left]+array[right]>k){
                right--;
            }else if(array[left]+array[right]==k){
                return true;
            }else{
                ++left;
            }
        }
        return false;
    }
};
