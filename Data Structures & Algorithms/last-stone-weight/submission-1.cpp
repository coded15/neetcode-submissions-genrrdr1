class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // sort(stones.begin(), stones.end());
        // int n = stones.size();
        // // n needs to greater that 1 not 0 because inside the loop we are also accessesing the n-2 iterator
        // while(n>1)
        // {
        //     if(stones[n-1]==stones[n-2])
        //     {
        //         stones.pop_back();
        //         stones.pop_back();
        //         n -=2;
        //     }
        //     else
        //     {
        //         stones[n-2] = stones[n-1]-stones[n-2];
        //         stones.pop_back();
        //         --n;
        //         // dont forget to sort this again
        //         sort(stones.begin(), stones.end());
        //     }
        // }
        // return ((n==1)?stones[0]:0);    
        priority_queue<int> maxHeap;
        for(int stoneWeight: stones)
        {
            maxHeap.push(stoneWeight);
        }
        while(maxHeap.size()>1)
        {
            int first = maxHeap.top();
            maxHeap.pop();
            int second = maxHeap.top();
            maxHeap.pop();
            if(first > second)
            {
                maxHeap.push(first - second);
            }
        }
        maxHeap.push(0);
        return maxHeap.top();
    }
};
