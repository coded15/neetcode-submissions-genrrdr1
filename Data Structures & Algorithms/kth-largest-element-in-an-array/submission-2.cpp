class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // instead of max heap we can smartly use min heap, see solution
        priority_queue<int> sortedQueue;
        for(int& num: nums)
        {
            sortedQueue.push(num);
        }
        // if k is 3 then we need the third largest element, hence we are doing pre decrement so that the loop only runs TWO times not thrice
        while(--k)
        {

            sortedQueue.pop();
        }
        return sortedQueue.top();
    }
};
