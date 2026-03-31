class Solution
{
public:
    int result(string oper, int firstOperand, int secondOperand)
    {
        if (oper == "+")
        {
            return firstOperand + secondOperand;
        }
        if (oper == "-")
        {
            return firstOperand - secondOperand;
        }
        if (oper == "*")
        {
            return firstOperand * secondOperand;
        }
        if (oper == "/")
        {
            return firstOperand / secondOperand;
        }
        return 0;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> reversePolishNotation;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                int second = reversePolishNotation.top();
                reversePolishNotation.pop();
                reversePolishNotation.top() = result(tokens[i], reversePolishNotation.top(), second);
                cout << reversePolishNotation.top() << endl;
            }
            else
                reversePolishNotation.push(atoi(tokens[i].c_str()));
        }
        return reversePolishNotation.top();
    }
};