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
        int candidate;
        queue<TreeNode*> que;
        
        que.push(root);
        que.push(NULL);
        
        bool flag=true;
        while(!que.empty()){
            TreeNode* ptr=que.front();
            if(flag){
                candidate=ptr->val;
                flag=false;
            }
            que.pop();
            if(ptr==NULL){
                if(!que.empty()){
                    que.push(ptr);
                    flag=true;
                }
            }else{
                if(ptr->left){
                    que.push(ptr->left);
                }
                if(ptr->right){
                    que.push(ptr->right);
                }
            }
        }
        
        return candidate;
    }
};
