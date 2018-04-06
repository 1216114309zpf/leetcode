class Twitter {
    struct Message{
        int userId;
        int tweetId;
        int order;
        int localorder;
        Message(int ui,int ti,int order,int localorder):userId(ui),tweetId(ti),order(order),localorder(localorder){};
        bool operator<(const Message &b) const{
            return this->order < b.order;
        }
    };
public:
    /** Initialize your data structure here. */
    unordered_map<int,vector<Message>> mymessage;
    unordered_map<int,set<int>> myfollow;
    int index;
    Twitter() {
        index=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        mymessage[userId].push_back(Message(userId,tweetId,index,mymessage[userId].size()));
        ++index;
        if(myfollow[userId].count(userId)==0){
            myfollow[userId].insert(userId);
        }
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        follow(userId,userId);
        priority_queue<Message,vector<Message>,less<Message>> que;
        for(auto itr=myfollow[userId].begin();itr!=myfollow[userId].end();++itr){
            if(mymessage[*itr].size()!=0){
                que.push(mymessage[*itr][mymessage[*itr].size()-1]);
            }
        }
        vector<int> result;
        for(int i=0;i<10;++i){
            if(!que.empty()){
                Message me=que.top();
                que.pop();
                result.push_back(me.tweetId);
                if(me.localorder-1>=0){
                    que.push(mymessage[me.userId][me.localorder-1]);
                }
            }else{
                break;
            }
        }
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(myfollow[followerId].count(followeeId)==0){
            myfollow[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(myfollow[followerId].count(followeeId)!=0){
            myfollow[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
