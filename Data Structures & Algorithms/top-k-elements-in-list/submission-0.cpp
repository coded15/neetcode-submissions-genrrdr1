class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count_num;
        for(int i = 0; i < nums.size();i++)
        {
            count_num[nums[i]]++;
        }
        vector<pair<int, int>> sorted_vec(count_num.begin(), count_num.end());
        sort(sorted_vec.begin(), sorted_vec.end(), [](const auto &p1, const auto &p2){ return p1.second > p2.second; });
        vector <int> result;
        for(int i = 0; i < k; i++)
        {
            result.push_back(sorted_vec[i].first);
        }
        return result;
    }
};