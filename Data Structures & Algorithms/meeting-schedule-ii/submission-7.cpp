/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& intervals) {
        // answer will be equal to max conflict at one point
        if(intervals.size()==0)
        {
            return 0;
        }
        if(intervals.size() == 1)
        {
            return 1;
        }
        int currentResult = 0;
        int result = 0;
        // sort(intervals.begin(), intervals.end(),
        //      [](Interval& a, Interval& b) { return (a.start > b.start); });
        // for(int i = 0; i < intervals.size() - 1; i++)
        // {
        //     int j = i + 1;
        //     int currentRooms = 1;
        //     while(intervals[j].start < intervals[i].end && j < intervals.size())
        //     {
        //         if(j - i > 1)
        //         {
        //             if(intervals[j].start >= intervals[j - 1].end)
        //             {
        //                 j++;
        //                 continue;
        //             }
        //         }
        //         currentRooms++;
        //         j++;
        //     }
        //     result = max(result, currentRooms);
        // }
        vector<int> startTimes;
        vector<int> endTimes;
        for(auto it: intervals)
        {
            startTimes.push_back(it.start);
            endTimes.push_back(it.end);
        }
        sort(startTimes.begin(), startTimes.end(), [](int &a, int& b){return(a>b);});
        sort(endTimes.begin(), endTimes.end(), [](int &a, int& b){return(a>b);});

        while(startTimes.size() != 0 && endTimes.size() != 0)
        {
            if(startTimes.back()< endTimes.back())
            {
                currentResult++;
                startTimes.pop_back();
            }
            else
            {
                currentResult--;
                endTimes.pop_back();                            
            }
                result = max(result, currentResult);
        }
        return result;
    }
};
