class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size(),0);
        stack<int> s;
        s.push(0);
        for(int i=1; i<temperatures.size(); i++) {
            int currTemp = temperatures[i];
            while(!s.empty()) {
                int idx = s.top();
                int tempTop = temperatures[idx];
                if(tempTop < currTemp) {
                    answer[idx] = i - idx;
                    s.pop();
                } else {
                    break;
                }
            }
            s.push(i);
        }
        return answer;
    }
};