class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string expStr = "+-/*";
        stack<int> s;
        for(int i=0; i<tokens.size(); i++) {
            string token = tokens[i];

            if(expStr.contains(token)) {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();

                int val = 0;

                if (token == "+") {
                    val = op1 + op2;
                }
                else if (token == "-") {
                    val = op1 - op2;
                }
                else if (token == "*") {
                    val = op1 * op2;
                }
                else if (token == "/") {
                    val = op1 / op2;
                }

                s.push(val);

            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};