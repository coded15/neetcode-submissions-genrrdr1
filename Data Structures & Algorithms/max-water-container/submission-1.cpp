class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            int current_volm = 0;
            for(int j = i + 1; j < heights.size();j++)
            {
                current_volm = (j-i)*min(heights[i], heights[j]);
                res = max(res, current_volm);
            }

        }
        return res;
    }
};
