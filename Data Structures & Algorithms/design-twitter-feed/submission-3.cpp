class Twitter {
public:
    unordered_map<int, unordered_set<int>> followees;
    vector<pair<int, int>> posts;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int k = 0;
        for (auto it = posts.rbegin(); it != posts.rend() && k < 10; it++) {
            if (it->first == userId || followees[userId].count(it->first)) {
                feed.push_back(it->second);
                k++;
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};
