// class Twitter {
// public:
//     Twitter() {
//         // Variables are local, not class members. hence they get destroyedafter constructor
//         unordered_map<int, priority_queue<int>> userPosts;
//         // also tweetId is not directly proportional to time so we have to maintain count separately
//         unordered_map<int, vector<int>> followerMap;
//     }
    
//     void postTweet(int userId, int tweetId) {
//         userPosts[userId].push_back(tweetId);
//     }
    
//     vector<int> getNewsFeed(int userId) {
//         vector<int> temp;
//         // priority queue is not iterable
//         for(int feed: userPosts[userId])
//         {
//             temp.push_back(feed);
//         }
//         return userPosts[userId];
//     }
    
//     void follow(int followerId, int followeeId) {
//         // vector has no .find()
//         if(!followerMap[followerId].find(followeeId))
//         {
//             followerMap[followerId].push_back(followeeId);
//             vector<int> followeeNewsFeed = getNewsFeed(followeeId);
//             for(int feed: followeeNewsFeed)
//             {
//                 /**
//                 This is very wrong design ❌

//                     👉 Why?

//                     Tweets change dynamically

//                     Follow/unfollow would require massive updates

//                     Leads to duplication + incorrect feeds
//                 */
//                 userPosts[followerId].push(feed);
//             }
//         }
//     }
    
//     void unfollow(int followerId, int followeeId) {
//         if(followerMap[followerId].find(followeeId))
//         {
//             followerMap[followerId].erase(followeeId);
//             for(int feed: followeeNewsFeed)
//             {
//                 userPosts[followerId].erase(feed);
//             }
//         }   
//     }
// };

class Twitter
{
    int time = 0;
    public:
        Twitter()
        {

        }
        unordered_map<int, vector<pair<int, int>>> userPosts;
        unordered_map<int, unordered_set<int>> followees;

        void postTweet(int userId, int tweetId) {
            userPosts[userId].push_back({time++, tweetId});
        }

        vector<int> getNewsFeed(int userId) {
            priority_queue<pair<int,int>> tempFeed;
            for(auto &userFeed: userPosts[userId])
            {
                tempFeed.push(userFeed);
            }
            for(auto followee: followees[userId])
            {
                for(auto &followeeFeed: userPosts[followee])
                {
                    tempFeed.push(followeeFeed);
                }
            }

            vector<int> result;
            while(!tempFeed.empty() && result.size() < 10)
            {
                result.push_back(tempFeed.top().second);
                tempFeed.pop();
            }
            return result;
        }

        void follow(int followerId, int followeeId) {
            // push_back or push? -> none of them unordered set uses insert
            if(followerId != followeeId)
            followees[followerId].insert(followeeId);
        }    

        void unfollow(int followerId, int followeeId) {
            followees[followerId].erase(followeeId);
        }
};
