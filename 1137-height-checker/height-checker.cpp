class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int> v;
        for(int i=0; i<heights.size(); i++) {
            v.push_back(heights[i]);
        }

        // Bubble sort 
        bool flag = true;
        int j = 0;
        while(flag) {
            flag = false;

            for(int i=0; i<v.size()-1-j; i++) {
                if(v[i] > v[i+1]) {
                    int temp = v[i];
                    v[i] = v[i+1];
                    v[i+1] = temp;
                    flag = true;
                }
            }
            j++;
        }

        int count = 0;
        for(int i=0; i<v.size(); i++) {
            if(v[i] != heights[i]) {
                count++;
            }
        }

        return count;
    }
};