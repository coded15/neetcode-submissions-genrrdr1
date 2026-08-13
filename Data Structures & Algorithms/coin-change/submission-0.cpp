class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        unordered_map<int, int> numberOfWaysToMakeAmount;
        int result = dfs(coins, amount, numberOfWaysToMakeAmount);
        return result != INT_MAX ? result : -1;
    }

    int dfs(vector<int>& coins, int target, unordered_map<int, int>& numberOfWaysToMakeAmount) {
        if (target == 0) {
            return 0;
        }
        if (numberOfWaysToMakeAmount.find(target) != numberOfWaysToMakeAmount.end()) {
            return numberOfWaysToMakeAmount[target];
        }
        int result = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (target - coins[i] >= 0) {  // dont forget this condition
                int smallerTarget = dfs(coins, target - coins[i], numberOfWaysToMakeAmount);
                if (smallerTarget != INT_MAX) {
                    result = min(result, 1 + smallerTarget);
                }
            }
        }
        numberOfWaysToMakeAmount[target] = result;
        return result;
    }
};
