class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> maxDistance;
        // how to ensure that we insert value in the max heap based on the second element of the pair, do we have to right our custom comparator function?
        for(auto point: points)
        {
            // actually I dont even need square root here, I just need to know the order of how how much a point is farther from origin becuase I have to return the points not the distance
            int distance = (point[0]*point[0])+ (point[1]*point[1]);
            maxDistance.push({-1*(distance), point});
        }
        vector<vector<int>> result;
        while(k--)
        {
            result.push_back(maxDistance.top().second);
            maxDistance.pop();
        }
        return result;
    }
};
