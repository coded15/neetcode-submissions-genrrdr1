class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> daysTillWarmer(temperatures.size(),0);
        // for(int i = 0; i < temperatures.size(); i++)
        // {
        //     int j = i + 1;
        //     for(; j < temperatures.size(); j++)
        //     {
        //         if(temperatures[j] > temperatures[i])
        //         {
        //             daysTillWarm.push_back(j - i);
        //             break;
        //         }
        //         else
        //             continue;
        //     }
        //     if(j == temperatures.size())
        //     {
        //         daysTillWarm.push_back(0);
        //     }
        // }
        // So we are popping an element only when we find a temperature greater than the top element
        // it is very possible that the higher temperature 'z' that we found for an element x is also greater than the temperature of the element before y, so we cant just progress after popping x from the stack, we also should pop y since that even though is greater than x but is lesser than z. That is why we are running the loop as long as the stack is not empty and z is greater than the top temperature of the stack
        stack<pair<int, int>> toFindHigherTemperature;
        for(int i = 0; i < temperatures.size(); i++)
        {
            int t = temperatures[i];
            while(!toFindHigherTemperature.empty() && t > toFindHigherTemperature.top().first)
            {
                daysTillWarmer[toFindHigherTemperature.top().second] = i - toFindHigherTemperature.top().second;
                toFindHigherTemperature.pop();
            }
            toFindHigherTemperature.push({t, i});
        }
        return daysTillWarmer;
    }
};
