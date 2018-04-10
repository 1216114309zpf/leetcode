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
    TreeNode* pruneTree(TreeNode* root) {
        if(!deleted(root))
            return root;
        return NULL;
    }
    
    bool deleted(TreeNode*ptr){
        if(!ptr){
            return true;
        }
        
        if(deleted(ptr->left))
            ptr->left=NULL;;
        if(deleted(ptr->right))
            ptr->right=NULL;
        
        return !(ptr->val or ptr->left or ptr->right);
    }
};
