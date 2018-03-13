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
        if(!root){
            return result;
        }
        
        int current;
        int frequency=-1;
        int old=-1;
        
        recursive(root,current,frequency,old,result);
        if(frequency>old){
            result.clear();
            result.push_back(current);
        }else if(frequency==old){
            result.push_back(current);
        }else{
            
        }
        return result;
    }
    
    void recursive(TreeNode*root, int &current, int &frequency, int &old, vector<int>& result){
        if(!root){
            return;
        }
        
        recursive(root->left, current, frequency, old, result);
        if(frequency==-1){
            frequency=1;
            current=root->val;
        }else{
            if(current==root->val){
                ++frequency;
            }else{
                if(frequency>old){
                    result.clear();
                    result.push_back(current);
                    current=root->val;
                    old=frequency;
                    frequency=1;
                }else if(frequency==old){
                    result.push_back(current);
                    current=root->val;
                    frequency=1;
                }else{
                    current=root->val;
                    frequency=1;
                }
            }
        }
        
        recursive(root->right, current, frequency, old, result);
    }
};
