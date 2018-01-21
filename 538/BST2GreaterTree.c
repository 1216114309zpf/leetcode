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
        return rInOrderTraversal(root,sum);
    }
    TreeNode* rInOrderTraversal(TreeNode* root, int &sum){
        if(!root)
            return NULL;
        if(root->right)
            rInOrderTraversal(root->right,sum);
        root->val += sum;
        sum=root->val;
        if(root->left)
            rInOrderTraversal(root->left,sum);
        return root;
    }
};
