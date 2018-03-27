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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d==1){
            TreeNode* node=new TreeNode(v);
            node->left=root;
            root=node;
            return root;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        int depth=1;
        while(depth!=d-1){
            TreeNode*ptr=que.front();
            que.pop();
            if(ptr==NULL){
                que.push(NULL);
                ++depth;
                continue;
            }else{
                if(ptr->left){
                    que.push(ptr->left);
                }
                if(ptr->right){
                    que.push(ptr->right);
                }
            }
        }
        
        while(!que.empty()){
            TreeNode*ptr=que.front();
            que.pop();
            if(ptr){
                TreeNode*left=new TreeNode(v);
                TreeNode*right=new TreeNode(v);
                left->left=ptr->left;
                right->right=ptr->right;
                ptr->left=left;
                ptr->right=right;
            }
        }
        return root;
    }
};
