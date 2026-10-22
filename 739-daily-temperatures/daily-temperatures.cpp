class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> v(temperatures.size(),0);
        int warmest = 1;

        for(int i=temperatures.size()-1; i>=0; i--) {
            int currTemp = temperatures[i];
            if(currTemp >= warmest) {
                warmest = currTemp;
                continue;
            }

            int count = 1;

            while(true) {
                if(temperatures[count+i] > currTemp) {
                    v[i] = count;
                    break;
                }
                else {
                    count = count + v[i+count];
                }
            }
        }
        return v;
    }
};