class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> daysTillWarm;
        for(int i = 0; i < temperatures.size(); i++)
        {
            int j = i + 1;
            for(; j < temperatures.size(); j++)
            {
                if(temperatures[j] > temperatures[i])
                {
                    daysTillWarm.push_back(j - i);
                    break;
                }
                else
                    continue;
            }
            if(j == temperatures.size())
            {
                daysTillWarm.push_back(0);
            }
        }
        return daysTillWarm;
    }
};
