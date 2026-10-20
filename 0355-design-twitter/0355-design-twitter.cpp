class Twitter {
public:
    int timer=0;
    unordered_map<int,vector<pair<int,int>>>posts;
    unordered_map<int,unordered_set<int>>following;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({++timer,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        using Node=tuple<int,int,int,int>;
          priority_queue<Node> pq;
          vector<int>feed;
          unordered_set<int>users=following[userId];
          users.insert(userId);
          //put in queue
          for(auto user:users){
            if(!posts[user].empty()){
                int i=posts[user].size()-1;
                auto [time,tweetId]=posts[user][i];
                pq.push({time,tweetId,user,i});
            }
          }
          //Retrive 
          while(!pq.empty() && feed.size()<10){
            auto [time,tweetId,user,i]=pq.top();
            pq.pop();
            feed.push_back(tweetId);
            if(i>0){
                auto[prevTime,prevTweetId]=posts[user][i-1];
                pq.push({prevTime,prevTweetId,user,i-1});
            }
          }
          return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
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