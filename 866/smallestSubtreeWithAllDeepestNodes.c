/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Result{
    int height;
    TreeNode* candidate;
};
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        Result* result=getHeight(root);
        return result->candidate;
    }
    
    Result* getHeight(TreeNode* root){
        Result * result=new Result;
        if(!root){
            result->height=0;
            result->candidate=NULL;
            return result;
        }
        Result* left=getHeight(root->left);
        Result* right=getHeight(root->right);
        result->height=max(left->height,right->height)+1;
        if(left->height==right->height){
            result->candidate=root;
        }else{
            result->candidate=(left->height > right->height)?left->candidate:right->candidate;
        }
        return result;
    }
};
