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
    string tree2str(TreeNode* t) {
        string result=subTree2String(t);
        result.pop_back();
        result.erase(result.begin());
        return result;
    }
    
    string subTree2String(TreeNode* t){
        if(!t)
            return "()";
        string result="(";
        result+=int2string(t->val);
        if(t->right){
            result+=subTree2String(t->left);
            result+=subTree2String(t->right);
        }else{
            if(t->left)
                result+=subTree2String(t->left);
        }
        result+=')';
        return result;
        
        
    }
    
    string int2string(int val){
        string result="";
        int v=val;
        if(val==0)
            return "0";
        if(val<0){
            val=-val;
            result.push_back('-');
        }
        while(val){
            result.push_back('0'+val%10);
            val/=10;
        }
        if(v<0)
            reverse(result.begin()+1,result.end());
        else
            reverse(result.begin(),result.end());
        return result;
    }
};
