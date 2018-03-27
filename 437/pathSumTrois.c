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
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        unordered_map<int,int> myMap;
        int result=0;
        myMap[0]=1;
        dfs(root,myMap,result,0,sum);
        return result;
    }
    
    void dfs(TreeNode* root,unordered_map<int,int>& myMap,int &result,int current,int sum){
        if(root==NULL)
            return;
        current+=root->val;
        
        if(myMap.count(current)==0){
            myMap[current]=1;
        }else{
            ++myMap[current];
        }
        
        if(myMap.count(current-sum)!=0){
            result+=myMap[current-sum];
            if(sum==0)
                result-=1;
        }
        dfs(root->left,myMap,result,current,sum);
        dfs(root->right,myMap,result,current,sum);
        --myMap[current];
    }
};
