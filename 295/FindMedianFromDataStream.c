class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> great;
    priority_queue<int,vector<int>,greater<int>> little;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(little.empty()){
            little.push(num);
            return;
        }
        if(num>little.top()){
            little.push(num);
            if(little.size()-great.size()>1){
                great.push(little.top());
                little.pop();
            }
        }else{
            great.push(num);
            if(great.size()-little.size()>1){
                little.push(great.top());
                great.pop();
            }
        }
    }
    
    double findMedian() {
        if(great.size()>little.size())
            return great.top();
        else if(great.size()==little.size())
            return (great.top()+little.top())/2.0;
        else
            return little.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
