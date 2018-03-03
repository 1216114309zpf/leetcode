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
    int minDiffInBST(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        int diff=-1;
        for(int i=0;i<vec.size()-1;++i){
            if(diff==-1){
                diff=abs(vec[i]-vec[i+1]);
            }else{
                if(diff>abs(vec[i]-vec[i+1])){
                    diff=abs(vec[i]-vec[i+1]);
                }
            }
        }
        return diff;
    }
    void inorder(TreeNode* &root, vector<int> &vec){
        if(root->left)
            inorder(root->left,vec);
        vec.push_back(root->val);
        if(root->right)
            inorder(root->right,vec);
    }

};
