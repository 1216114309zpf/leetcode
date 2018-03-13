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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        stack<TreeNode*> stk;
        
        int current;
        int frequency=-1;
        int old=-1;
        
        TreeNode* ptr=root;
        while(!stk.empty() or ptr){
            if(ptr){
                stk.push(ptr);
                ptr=ptr->left;
            }else{
                ptr=stk.top();
                stk.pop();
                
                if(frequency==-1){
                    frequency=1;
                    current=ptr->val;
                }else{
                    if(current==ptr->val){
                        ++frequency;
                    }else{
                        if(frequency>old){
                            result.clear();
                            result.push_back(current);
                            old=frequency;
                            frequency=1;
                            current=ptr->val;
                        }else if(frequency==old){
                            result.push_back(current);
                            frequency=1;
                            current=ptr->val;
                        }else{
                            current=ptr->val;
                            frequency=1;
                        }
                    }
                }
                
                ptr=ptr->right;
            }
        }
        
        if(frequency>old){
            result.clear();
            result.push_back(current);
        }else if(frequency==old){
            result.push_back(current);
        }
        
        return result;
    }
};
