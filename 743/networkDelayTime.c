struct Node{
    int index;
    Node* next;
    Node(){
        index = -1;
        next = NULL;
    }
};

struct Element{
    int delay;
    Node* node;
    Element(){
        delay = -1;
        node = NULL;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int result = -1;
        Element * array = new Element[N+1];
        array[K].delay = 0;
        
        for(int i=0; i<times.size(); ++i){
            int index = times[i][0];
            if(!array[index].node){
                array[index].node = new Node();
                array[index].node->index = i;
            }
            else{
                Node *ptr = array[index].node;
                while(ptr->next)
                    ptr = ptr->next;
                ptr->next = new Node();
                ptr = ptr->next;
                ptr->index = i;
            }
        }
        
        stack<int> mystack;
        mystack.push(K);
        while(!mystack.empty()){
            int itr = mystack.top();
            mystack.pop();
            Node* ptr=array[itr].node;
            while(ptr){
                int index = ptr->index;
                vector<int> vec = times[index];
                if(array[vec[1]].delay == -1 || array[vec[1]].delay > array[itr].delay + vec[2]){
                    array[vec[1]].delay = array[itr].delay + vec[2];
                    mystack.push(vec[1]);
                }
                ptr=ptr->next;
            }
        }
        
        for(int i=1; i<=N; ++i){
            if(array[i].delay == -1)
                return -1;
            if(array[i].delay > result)
                result = array[i].delay;
        }
        return result;
    }
};
