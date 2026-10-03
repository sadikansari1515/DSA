class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        vector<string> s;
        for(int i=0; i<list1.size(); i++) {
            m[list1[i]] = i;
        }
        int minIndex = INT_MAX;

        for(int i=0; i<list2.size(); i++) {
            if(m.count(list2[i])) {
                if(i+m[list2[i]] < minIndex) {
                    minIndex = i+m[list2[i]];
                    s.clear();
                    s.push_back(list2[i]);
                }
                else if(i+m[list2[i]] == minIndex) {
                    s.push_back(list2[i]);
                }
            }
        }
        return s;
    }
};