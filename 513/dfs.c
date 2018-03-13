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
    int findBottomLeftValue(TreeNode* root) {
        if(!root->left and !root->right)
            return root->val;
        int leftCandidate,rightCandidate;
        int left=recursive(root->left, leftCandidate);
        int right=recursive(root->right, rightCandidate);
        if(left>=right){
            return leftCandidate;
        }else{
            return rightCandidate;
        }
    }
    
    int recursive(TreeNode* root, int &result){
        if(!root){
            return 0;
        }
        
        if(!root->left and !root->right){
            result=root->val;
            return 1;
        }
        int leftCandidate,rightCandidate;
        int left=recursive(root->left, leftCandidate);
        int right=recursive(root->right, rightCandidate);
        if(left>=right){
            result=leftCandidate;
        }else{
            result=rightCandidate;
        }
        
        return 1+max(left,right);
    }
};
