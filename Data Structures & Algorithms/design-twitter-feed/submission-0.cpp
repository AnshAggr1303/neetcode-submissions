class Twitter {
public:

    // Global timestamp to know which tweet is newer
    int timeStamp;

    // follower -> set of followees
    unordered_map<int, unordered_set<int>> followMap;

    // user -> list of {timestamp, tweetId}
    unordered_map<int, vector<pair<int,int>>> tweetMap;

    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {

        // Store tweet with current timestamp
        tweetMap[userId].push_back({timeStamp++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> feed;

        // User should always see their own tweets
        followMap[userId].insert(userId);

        /*
            Heap stores:

            {
                timestamp,
                tweetId,
                userId,
                index in user's tweet list
            }

            Largest timestamp stays on top.
        */
        priority_queue<vector<int>> pq;

        // Push latest tweet of every followed user
        for(int followee : followMap[userId]) {

            // User may not have posted any tweet
            if(tweetMap.count(followee) == 0)
                continue;

            // Latest tweet is at the end of vector
            int index = tweetMap[followee].size() - 1;

            int time = tweetMap[followee][index].first;
            int tweetId = tweetMap[followee][index].second;

            pq.push({time, tweetId, followee, index});
        }

        // Need only 10 most recent tweets
        while(!pq.empty() && feed.size() < 10) {

            // Get newest tweet available
            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int tweetId = curr[1];
            int followee = curr[2];
            int index = curr[3];

            // Add tweet to feed
            feed.push_back(tweetId);

            /*
                We just used one tweet from this user.

                Now move to that user's
                next older tweet.
            */
            index--;

            if(index >= 0) {

                int nextTime =
                    tweetMap[followee][index].first;

                int nextTweet =
                    tweetMap[followee][index].second;

                /*
                    Push next older tweet from
                    the same user into heap.

                    This is exactly like
                    Merge K Sorted Lists.
                */
                pq.push({
                    nextTime,
                    nextTweet,
                    followee,
                    index
                });
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {

        // Add followee to follower's set
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {

        // Don't allow user to unfollow himself
        if(followerId != followeeId) {
            followMap[followerId].erase(followeeId);
        }
    }
};