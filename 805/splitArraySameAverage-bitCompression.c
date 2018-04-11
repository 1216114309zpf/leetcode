class Solution {
    struct Node{
        int sum;
        int count;
        Node(){
            sum=0;
            count=0;
        }
        Node(int sum,int count):sum(sum),count(count){};
    };
public:
    bool splitArraySameAverage(vector<int>& A) {
        if(A.size()<2){
            return false;
        }
        
        unordered_map<int,Node> mymap;
        int sum=0;
        for(int i=0;i<A.size();++i)
            sum+=A[i];
        
        unsigned int n=(1<<A.size());
        Node*node=new Node();
        mymap[0]=*node;
        for(unsigned int i=0;i<n;++i){ 
            for(int j=0;j<A.size();++j){
                unsigned int com=(1<<j);
                if((i&com)==0){ //current doesn't contain A[j];
                    int index=i+com;
                    if(mymap.count(index)!=0)
                        continue;
                    Node*node=new Node(mymap[i].sum+A[j],mymap[i].count+1);
                    mymap[index]=*node;
                    if(mymap[index].count!=A.size() and sum*mymap[index].count==mymap[index].sum * A.size()){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
