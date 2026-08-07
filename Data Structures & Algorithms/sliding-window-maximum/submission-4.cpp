class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> decreasingWindow;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            while (!decreasingWindow.empty() && decreasingWindow.front() <= i - k) {
                decreasingWindow.pop_front();  // will there be a need of this if I only run the
                                               // loop till nums.size() - k
            }
            while (!decreasingWindow.empty() &&
                   nums[decreasingWindow.back()] <
                       nums[i])  // AHA!  notice that we are comparing the back value for magnitude
            {
                decreasingWindow.pop_back();
            }
            decreasingWindow.push_back(i);
            // AHA!    this condition is only for pushing the first window result. the later window
            // are maintained by the conditionin first if statement
            if (i >= k - 1) {
                result.push_back(nums[decreasingWindow.front()]);
            }
        }
        return result;
    }
};
