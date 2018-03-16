/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Node{
    Interval* interval;
    Node*left;
    Node*right;
    Node(Interval* interval):interval(interval),left(NULL),right(NULL){}
};
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    Node* root;
    SummaryRanges() {
        root=NULL;
    }
    
    void addNum(int val) {
        if(root==NULL){
            Interval *interval=new Interval(val,val);
            root=new Node(interval);
            return;
        }
        Node *ptr=root;
        while(ptr){
            if(val>= ptr->interval->start and val<=ptr->interval->end){
                return;
            }else if(val==ptr->interval->start-1){
                ptr->interval->start--;
                Node*tmp=ptr;
                if(!tmp->left){
                    return;
                }
                if(tmp->left->interval->end+1==ptr->interval->start){
                    ptr->interval->start=tmp->left->interval->start;
                    ptr->left=ptr->left->left;
                    return;
                }
                tmp=tmp->left;
                while(tmp->right and tmp->right->interval->end+1!=ptr->interval->start){
                    tmp=tmp->right;
                } 
                if(tmp->right){
                    ptr->interval->start=tmp->right->interval->start;
                    tmp->right=tmp->right->left;
                    return;
                }
            }else if(val==ptr->interval->end+1){
                ptr->interval->end++;
                Node*tmp=ptr;
                if(!tmp->right){
                    return;
                }
                if(tmp->right->interval->start-1==ptr->interval->end){
                    ptr->interval->end=tmp->right->interval->end;
                    ptr->right=ptr->right->right;
                    return;
                }
                tmp=tmp->right;
                while(tmp->left and tmp->left->interval->start-1!=ptr->interval->end){
                    tmp=tmp->left;
                }
                if(tmp->left){
                    ptr->interval->end=tmp->left->interval->end;
                    tmp->left=tmp->left->right;
                    return;
                }
            }else if(val<ptr->interval->start-1){
                if(!ptr->left){
                    Interval *interval=new Interval(val,val);
                    ptr->left=new Node(interval);
                    return;
                }
                ptr=ptr->left;
            }else{
                if(!ptr->right){
                    Interval *interval=new Interval(val,val);
                    ptr->right=new Node(interval);
                    return;
                }
                ptr=ptr->right;
            }
        }
    }
    
    vector<Interval> getIntervals() {
        Node*ptr=root;
        stack<Node*> stk;
        vector<Interval> result;
        while(ptr or !stk.empty()){
            if(ptr){
                stk.push(ptr);
                ptr=ptr->left;
            }else{
                ptr=stk.top();
                stk.pop();
                result.push_back(*(ptr->interval));
                ptr=ptr->right;
            }
        }
        return result;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
