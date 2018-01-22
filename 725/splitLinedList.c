/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> result;
        int count=0;
        ListNode*ptr=root;
        while(ptr){
            ++count;
            ptr=ptr->next;
        }
        int length=count/k;
        int left=count%k;
        for(int i=0;i<left;++i){
            result.push_back(root);
            for(int j=0;j<length;++j){
                root=root->next;
            }
            ListNode*ptr=root;
            root=root->next;
            ptr->next=NULL;
        }
        
        if(length==0){
            for(int i=0;i<k-left;++i)
                result.push_back(NULL);
            return result;
        }
        
        for(int i=0;i<k-left;++i){
            result.push_back(root);
            for(int j=0;j<length-1;++j){
                root=root->next;
            }
            ListNode*ptr=root;
            root=root->next;
            ptr->next=NULL;
        }
        return result;
    }
};
