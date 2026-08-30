class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> s;
        for(int num : arr) {
            if(s.count(num*2) || s.count(num/2) && num % 2 ==0) {
                return true;
            }
            else s.insert(num);
        }
        return false;
    }
};