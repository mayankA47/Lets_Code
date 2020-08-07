class Twitter {
public:
    /** Initialize your data structure here. */
    class tweet{
        public:
        int uid, t, tid;
        tweet(int a,int b,int c){
            uid = a;
            t = b;
            tid = c;
        }
    };
    struct compar{
        bool operator()(tweet const&a,tweet const&b){
            return a.t<b.t;
        }
    };
    int time;
    unordered_map<int,vector<tweet>> m; //userid --> [{userId,time,tweetId}] TWEET INFO
    unordered_map<int,unordered_set<int>> f; //userid --> followingsId FOLLOWING INFO
    
    Twitter() {
        time = 0;

    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweet t(userId,time++,tweetId);
        m[userId].push_back(t);
        
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        priority_queue<tweet, vector<tweet>, compar> pq;
        unordered_map<int, int> hash;
        if(m[userId].size()>0)
            hash[userId] = m[userId].size();
        for(int fellow:f[userId]){
            if(m[fellow].size()>0)
                hash[fellow] = m[fellow].size();
        }
        //init pq
        for(auto i:hash){
            pq.push(m[i.first][i.second-1]);
        }
        while(feed.size()<10 and !pq.empty()){
            tweet t = pq.top();
            pq.pop();
            feed.push_back(t.tid);
            hash[t.uid]--;
            if(hash[t.uid]>0)
                pq.push(m[t.uid][hash[t.uid]-1]);
        }
        return feed;
        
        
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            f[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(f[followerId].count(followeeId))
            f[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */