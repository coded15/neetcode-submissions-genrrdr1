class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> sortedQueue;
        for(int& num: nums)
        {
            sortedQueue.push(num);
        }

        while(--k)
        {

            sortedQueue.pop();
        }
        return sortedQueue.top();
    }
};
