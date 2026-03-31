class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2 != 0)
        {
            return false;
        }
        stack<char> entry;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == ')' || s[i]==']' || s[i]=='}')
            {
            if(s[i]==')')
            {
                if(!entry.empty() && entry.top()=='(')
                {
                    entry.pop();
                    continue;
                }
                else
                return false;
            }
            if(s[i]==']')
            {
                if(!entry.empty() && entry.top()=='[')
                {
                    entry.pop();
                    continue;
                }
                else
                return false;
            }
            if(s[i]=='}')
            {
                if(!entry.empty() && entry.top()=='{')
                {
                    entry.pop();
                    continue;
                }
                else
                return false;
            }}
            else entry.push(s[i]);
        }
        return entry.empty();
    }
};
