class Twitter {
private:
    // Global incremental timestamp to track the chronological order of tweets
    int timestampCount;

    // Maps a userId to their personal timeline vector: {timestamp, tweetId}
    // Newer tweets are naturally appended to the back of the vector
    unordered_map<int, vector<pair<int, int>>> tweetMap;

    // Maps a userId to the set of unique userIds they are currently following
    unordered_map<int, unordered_set<int>> followMap;

public:
    Twitter() {
        timestampCount = 0;
    }

    void postTweet(int userId, int tweetId) {
        // Append the tweet metadata to the user's local timeline vector
        tweetMap[userId].push_back({timestampCount++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        
        // Max-Heap tracking elements layout: {timestamp, tweetId, followeeId, arrayIndex}
        // Since timestamp is placed at index 0, the priority_queue automatically
        // sorts and extracts the newest global tweets first.
        priority_queue<vector<int>> maxHeap;

        // Rule: A user must always be able to see their own tweets in their news feed
        followMap[userId].insert(userId);

        // Step 1: Seed the heap with the single newest tweet from the user and each followee
        for (int followeeId : followMap[userId]) {
            // Check if the followee has actually posted any tweets
            if (tweetMap.count(followeeId) && !tweetMap[followeeId].empty()) {
                // The absolute newest tweet lives at the very back of their timeline vector
                int index = tweetMap[followeeId].size() - 1;
                auto newestTweet = tweetMap[followeeId][index];
                
                // Push array layout: {timestamp, tweetId, followeeId, index}
                maxHeap.push({newestTweet.first, newestTweet.second, followeeId, index});
            }
        }

        // Step 2: Extract the top 10 most recent tweets using Multi-way Merge
        while (!maxHeap.empty() && res.size() < 10) {
            vector<int> topNode = maxHeap.top();
            maxHeap.pop();

            int tweetId = topNode[1];
            int followeeId = topNode[2];
            int index = topNode[3];

            // Add the most recent valid tweet ID to our final result array
            res.push_back(tweetId);

            // If the author stream still contains older tweets, pull the next one into the heap
            if (index > 0) {
                auto olderTweet = tweetMap[followeeId][index - 1];
                maxHeap.push({olderTweet.first, olderTweet.second, followeeId, index - 1});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        // A user shouldn't be allowed to unfollow themselves, and the relationship must exist
        if (followerId != followeeId && followMap[followerId].count(followeeId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};
