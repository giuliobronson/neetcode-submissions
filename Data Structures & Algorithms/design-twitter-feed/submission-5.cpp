class Twitter {
public:
    struct Post {
        int t;
        int tweetId;
    };

    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<Post>> posts;
    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Post, vector<Post>, decltype([](Post& p1, Post& p2) {
            return p1.t < p2.t;
        })> pq(posts[userId].rbegin(), posts[userId].rbegin() + min((int) posts[userId].size(), 10));
        vector<int> feed;
        
        for (int followee : followees[userId]) {
            for (auto it = posts[followee].rbegin(); it != posts[followee].rbegin() + min((int) posts[followee].size(), 10); it++) {
                pq.push(*it);
            }
        }
        
        while (!pq.empty()) {
            Post p = pq.top(); pq.pop();

            feed.push_back(p.tweetId);

            if (feed.size() == 10) return feed;
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
