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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<2)
            return head;
        
        int current=0;
        ListNode* ptr=head;
        head=NULL;
        ListNode* khead=ptr;
        ListNode* currentTail=NULL;;
        while(ptr){
            ++current;
            if(current==k){
                ListNode*tmp=ptr;
                ptr=ptr->next;
                tmp->next=NULL;
                ListNode*tail=khead;
                ListNode* node=reverseK(khead);;
                if(currentTail)
                    currentTail->next=node;
                else
                    currentTail=node;
                if(head==NULL){
                    head=currentTail;
                }
                currentTail=tail;
                khead=ptr;
                current=0;
                continue;
            }
            ptr=ptr->next;
        }
        if(khead){
            if(!head)
                head=khead;
            else
                currentTail->next=khead;
        }
        return head;
    }
    
    ListNode* reverseK(ListNode*head){
        ListNode*left=NULL;
        while(head){
            ListNode*tmp=head;
            head=head->next;
            tmp->next=left;
            left=tmp;
        }
        return left;
    }
};
