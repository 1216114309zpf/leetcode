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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        
        stk1.push(t1);
        stk2.push(t2);
        
        while(!stk1.empty()){
            TreeNode*ptr1=stk1.top();
            TreeNode*ptr2=stk2.top();
            stk1.pop();
            stk2.pop();
            
            ptr1->val+=ptr2->val;
            if(ptr1->left){
                if(ptr2->left){
                    stk1.push(ptr1->left);
                    stk2.push(ptr2->left);
                }
            }else{
                if(ptr2->left){
                    ptr1->left=ptr2->left;
                }
            }
            
            if(ptr1->right){
                if(ptr2->right){
                    stk1.push(ptr1->right);
                    stk2.push(ptr2->right);
                }
            }else{
                if(ptr2->right){
                    ptr1->right=ptr2->right;
                }
            }
        }
        return t1;
    }
};
