/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> hashtable;
        RandomListNode * root=NULL;
        RandomListNode * newHead=NULL;
        RandomListNode *ptr=head;
        while(ptr){
            if(!root){
                root=new RandomListNode(ptr->label);
                newHead=root;
            }else{
                root->next=new RandomListNode(ptr->label);
                root=root->next;
            }
            hashtable[ptr]=root;
            ptr=ptr->next;
        }
        root=newHead;
        while(root){
            root->random=hashtable[head->random];
            root=root->next;
            head=head->next;
        }
        return newHead;
    }
};
