class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==NULL)
            return false;
        if(isSame(s,t))
            return true;
        if(isSubtree(s->left,t))
            return true;
        if(isSubtree(s->right,t))
            return true;
        return false;
    }
    
    bool isSame(TreeNode* s,TreeNode* t){
        if(s==NULL and t==NULL)
            return true;
        if(s==NULL and t!=NULL)
            return false;
        if(s!=NULL and t==NULL)
            return false;
        return (s->val==t->val)&&isSame(s->left,t->left)&&isSame(s->right,t->right);
    }
};
