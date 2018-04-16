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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_map<int,bool> mymap;
        for(int i=0;i<G.size();++i)
            mymap[G[i]]=true;
        
        int count=0;
        bool status=false;
        while(head){
            if(status==false){
                if(mymap.count(head->val)==1){
                    status=true;
                    ++count;
                }
            }else{
                if(mymap.count(head->val)==0){
                    status=false;
                }
            }
            head=head->next;
        }
        return count;
    }
};
