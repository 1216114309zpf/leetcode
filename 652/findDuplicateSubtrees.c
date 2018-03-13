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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<vector<TreeNode*>> vec;
        recursive(root,vec);
        
        vector<TreeNode*> result;
        
        unordered_map<TreeNode*,TreeNode*> myMap;
        
        for(int i=0;i<vec.size();++i){
            for(int j=0;j<vec[i].size();++j)
                myMap[vec[i][j]]=vec[i][j];
            
            for(int j=0;j<vec[i].size()-1;++j){
                for(int k=j+1;k<vec[i].size();++k){
                    TreeNode* left=vec[i][j];
                    TreeNode* right=vec[i][k];
                    if(left->val==right->val){
                        if(left->left){
                            if(right->left){
                                if(myMap[left->left]!=myMap[right->left]){
                                    continue;
                                }
                            }else{
                                continue;
                            }
                        }else{
                           if(right->left){
                               continue;
                           } 
                        }
                        
                        if(left->right){
                            if(right->right){
                                if(myMap[left->right]!=myMap[right->right]){
                                    continue;
                                }
                            }else{
                                continue;
                            }
                        }else{
                            if(right->right){
                                continue;
                            }
                        }
                        
                        myMap[right]=myMap[left];
                        if(result.size()==0){
                            result.push_back(myMap[right]);
                        }else{
                            bool flag=false;
                            for(int p=0;p<result.size();++p){
                               if(myMap[right]==result[p]){
                                   flag=true;
                                   break;
                               } 
                            }
                            if(!flag)
                            result.push_back(myMap[right]);
                        }
                    }
                }
            }
        }
        return result;
    }
    
    int recursive(TreeNode* root, vector<vector<TreeNode*>>& vec){
        if(!root)
            return 0;
        
        int left=recursive(root->left,vec);
        int right=recursive(root->right,vec);
        
        int height=max(left,right)+1;
        if(vec.size()<height){
            vector<TreeNode*> tmp;
            vec.push_back(tmp);
        }
        vec[height-1].push_back(root);
        return height;
    }
};
