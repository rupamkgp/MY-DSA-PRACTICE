#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
    struct Tweet {
        int id;
        int time;
    };
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int timestamp;
public:
    Twitter() {
        timestamp = 0;
    }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timestamp++});
    }
    vector<int> getNewsFeed(int userId) {
        auto comp = [](const pair<Tweet, int>& a, const pair<Tweet, int>& b) {
            return a.first.time < b.first.time;
        };
        priority_queue<pair<Tweet, int>, vector<pair<Tweet, int>>, decltype(comp)> maxHeap(comp);
        
        // Add user's own tweets
        if (tweets.count(userId)) {
            for (auto& t : tweets[userId]) maxHeap.push({t, userId});
        }
        
        // Add followees' tweets
        if (following.count(userId)) {
            for (int followee : following[userId]) {
                if (tweets.count(followee)) {
                    for (auto& t : tweets[followee]) maxHeap.push({t, followee});
                }
            }
        }
        
        vector<int> feed;
        int count = 0;
        while (!maxHeap.empty() && count < 10) {
            feed.push_back(maxHeap.top().first.id);
            maxHeap.pop();
            count++;
        }
        return feed;
    }
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    void unfollow(int followerId, int followeeId) {
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};

int main() {
    Twitter tw;
    tw.postTweet(1, 5);
    auto feed = tw.getNewsFeed(1);
    cout << feed[0] << endl; // Expected: 5
    return 0;
}
