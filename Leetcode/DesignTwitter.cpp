//Leetcode 355
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <array>
#include <unordered_set>
using namespace std;

struct smallerThan{
  bool operator()(const array<int,3>& a, const array<int,3>& b)
  {
      return a[0] < b[0];
  }
};

class Twitter {
private:
    int order = 0;
    unordered_map<int,unordered_set<int>> followings;
    priority_queue<array<int,3>, std::vector<std::array<int, 3>>, smallerThan > timeline;
public:
    Twitter() {
        
    }
    void postTweet(int userId, int tweetId) {
        timeline.push({order,userId,tweetId});
        order++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        priority_queue<array<int,3>, std::vector<std::array<int, 3>>, smallerThan > userTimeline(timeline);
        int n = 0;
        while(!userTimeline.empty() and n < 10) {
            array<int,3> topfeed = userTimeline.top();
            if(topfeed[1] == userId || followings[userId].find(topfeed[1])!=followings[userId].end()){
                newsFeed.push_back(topfeed[2]);
                n++;
            }
            userTimeline.pop(); 
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        followings[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};

int main()
{
    return 0;
}
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */