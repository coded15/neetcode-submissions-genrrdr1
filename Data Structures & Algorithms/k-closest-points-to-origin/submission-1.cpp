class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // read the question properly, you need min distance not the max distance.
        priority_queue<pair<int, vector<int>>> minDistance;
        // how to ensure that we insert value in the max heap based on the second element of the pair, do we have to right our custom comparator function?
        // Answer: Ok so it sorted based on the first entry of pair, hence I had the logic and convert the pair as {distance, point} not {point, distance}
        for(auto point: points)
        {
            // actually I dont even need square root here, I just need to know the order of how how much a point is farther from origin becuase I have to return the points not the distance
            int distance = (point[0]*point[0])+ (point[1]*point[1]);
            // push after converting into a pair by enclosing them in curly braces not directly
            // have to return the closest, hence we need the min heap not a max heap
            minDistance.push({-1*(distance), point});
        }
        vector<vector<int>> result;
        while(k--)
        {
            result.push_back(minDistance.top().second);
            minDistance.pop();
        }
        return result;
    }
};
