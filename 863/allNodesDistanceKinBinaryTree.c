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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<TreeNode*> current;
        find(root,target,current);
        current.push_back(target);
        vector<int> result;
        for(int i=0;i<current.size();++i){
            //cout<<current[i]->val;
            if(current[i]==target){
                getValue(current[i],K,result);
            }else{
                if(current[i]->left==current[i+1]){
                    current[i]->left=NULL;
                }
                if(current[i]->right==current[i+1]){
                    current[i]->right=NULL;
                }
                getValue(current[i],K-(current.size()-i)+1,result);
            }
        }
        return result;
    }
    void getValue(TreeNode*root,int K,vector<int> &result){
        if(K<0){
            return;
        }
        if(K==0){
            result.push_back(root->val);
            return;
        }
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        while(!que.empty()){
            TreeNode* ptr = que.front();
            que.pop();
            if(ptr==NULL){
                --K;
                if(K==0){
                    while(!que.empty()){
                        TreeNode* node=que.front();
                        que.pop();
                        result.push_back(node->val);
                    }
                    return;
                }
                if(!que.empty()){
                    que.push(NULL);
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
    }
    bool find(TreeNode*root, TreeNode*target, vector<TreeNode*> &current){
        if(!root){
            return false;
        }
        if(target==root){
            return true;
        }
        current.push_back(root);
        if(find(root->left,target,current)){
            return true;
        }
        if(find(root->right,target,current)){
            return true;
        }
        current.pop_back();
        return false;
    }
};
