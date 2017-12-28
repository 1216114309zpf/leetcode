class MyCalendarTwo {
public:
    struct Slice{
        long long start;
        long long end;
        int covers;
        Slice*next;
    };
    Slice*head;
    MyCalendarTwo() {
        head=new Slice();
        head->start=0;
        head->end=1000000000;
        head->covers=0;
        head->next=NULL;
    }
    
    bool book(int start, int end) {
        Slice *ptr=head;
        Slice *list,*listend;
        list=NULL;
        listend=list;
        while(ptr){
            if(ptr->end>start){
                list=ptr;
                listend=list;
                if(list->covers>=2)
                    return false;
                while(listend->next && listend->next->start<end){
                    if(listend->next->covers>=2)
                        return false;
                    listend=listend->next;
                }
                listend=listend->next;
                break;
            }
            ptr=ptr->next;
        }
        
        while(list && list!=listend){
            if(list->start<start && list->end>start &&list->end < end){
                Slice*tmp = new Slice();
                tmp->start=start;
                tmp->end=list->end;
                tmp->covers=list->covers+1;
                list->end=start;
                tmp->next=list->next;
                list->next=tmp;
                list=list->next;
            }else if(list->start>=start && list->end<=end){
                list->covers=list->covers+1;
            }else if(list->start>start && list->start<end && list->end>end){
                Slice*tmp = new Slice();
                tmp->start=end;
                tmp->end = list->end;
                tmp->covers=list->covers;
                tmp->next = list->next;
                list->covers+=1;
                list->end=end;
                list->next=tmp;
                list=list->next;
            }else{
                Slice*mid=new Slice();
                Slice*right=new Slice();
                mid->start=start;
                mid->end=end;
                mid->covers=list->covers+1;
                right->start=end;
                right->end=list->end;
                right->covers=list->covers;
                list->end=start;
                right->next=list->next;
                mid->next=right;
                list->next=mid;
                list=list->next;
                list=list->next;
            }
            list=list->next;
        }
        return true;
    }
};
