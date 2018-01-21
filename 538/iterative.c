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
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        stack<TreeNode*> stk;
        TreeNode* ptr=root;
        while(!stk.empty() or ptr!=NULL){
            while(ptr){
                stk.push(ptr);
                ptr=ptr->right;
            }
            
            ptr=stk.top();
            stk.pop();
            sum+=ptr->val;
            ptr->val=sum;
            
            ptr=ptr->left;
        }
        return root;
    }
};
