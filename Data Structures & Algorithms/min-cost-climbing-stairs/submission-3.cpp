class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int totalCost = 0;
        for (int i = 2; i < n; i++) {
            totalCost = min(cost[i - 2], cost[i - 1]);
            cost[i] = totalCost + cost[i];
        }
        return min(cost[n - 1], cost[n - 2]);
    }
};
