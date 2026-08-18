class Solution {
   public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<pair<bool, int>> roomStatus(n, {false, 0});  // <roomNo., <inUse, count>>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
            meetingQueue;
        // {endTime, roomNo.}
        // sort meeting based on their starting time
        sort(meetings.begin(), meetings.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
        pair<int, int> mostUsed = {0, INT_MIN};  // {roomNo, count}
        for (int j = 0; j < meetings.size(); j++) {
            while (!meetingQueue.empty() && meetingQueue.top().first <= meetings[j][0]) {
                pair<int, int> meetingToEnd = meetingQueue.top();  //{endTime, roomNo.}
                roomStatus[meetingToEnd.second].first = false;
                meetingQueue.pop();
            }
            if (meetingQueue.size() == n) {
                int roomNo = meetingQueue.top().second;
                int toWaitTill = meetingQueue.top().first;
                roomStatus[roomNo].second++;
                meetingQueue.pop();
                meetingQueue.push({toWaitTill - meetings[j][0] + meetings[j][1], roomNo});
                if (roomStatus[roomNo].second == mostUsed.second) {
                    mostUsed.first = min(mostUsed.first, roomNo);
                } else if (roomStatus[roomNo].second > mostUsed.second) {
                    mostUsed = {roomNo, roomStatus[roomNo].second};
                }

            } else {
                for (int i = 0; i < n; i++) {
                    if (!roomStatus[i].first) {
                        meetingQueue.push({meetings[j][1], i});
                        roomStatus[i].second++;
                        roomStatus[i].first = true;
                        if (roomStatus[i].second == mostUsed.second) {
                            if (i < mostUsed.first) {
                                mostUsed.first = i;
                            }
                        } else if (roomStatus[i].second > mostUsed.second) {
                            mostUsed = {i, roomStatus[i].second};
                        }
                        break;
                    }
                }
            }
            cout << mostUsed.first << " " << mostUsed.second << endl;
        }
        return mostUsed.first;
    }
};