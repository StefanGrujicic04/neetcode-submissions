class Twitter {
    int time;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> posted; // {timestamp, tweetId}

public:
    Twitter() : time(0) {}

    void postTweet(int userId, int tweetId) {
        following[userId].insert(userId); // self-follow
        posted[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // MIN-heap po timestampu — izbacuje najstarije kad preraste 10
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int followed : following[userId]) {
            for (auto& [ts, tid] : posted[followed]) {
                pq.push({ts, tid});
                if (pq.size() > 10)
                    pq.pop();  // izbaci najstariji ✓
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followerId); // self-follow
        following[followerId].insert(followeeId); // nema duplikata
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) return; // ne moze unfollow sebe
        following[followerId].erase(followeeId);
    }
};