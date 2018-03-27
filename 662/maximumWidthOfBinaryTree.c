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
    int widthOfBinaryTree(TreeNode* root) {
        int result=0;
        vector<pair<int,int>> vec;
        int depth=0;
        dfs(root,vec,depth,result,0);
        return result+1;
    }
    
    void dfs(TreeNode*root, vector<pair<int,int>>&vec,int depth,int &result,int position){
        if(!root)
            return ;
        if(vec.size()<=depth){
            vec.push_back(pair<int,int>(position,position));
        }
        
        if(position<vec[depth].first){
            vec[depth].first=position;
        }
        
        if(position>vec[depth].second){
            vec[depth].second=position;
        }
        
        if(vec[depth].second-vec[depth].first>result){
            result=vec[depth].second-vec[depth].first;
        }
        
        dfs(root->left,vec,depth+1,result,2*position);
        dfs(root->right,vec,depth+1,result,2*position+1);
    }
};
