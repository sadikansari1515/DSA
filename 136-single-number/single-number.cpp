class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> s;
        int sum = 0,
            sumSet = 0;
        for(int num: nums) {
            if(!s.count(num)) {
                sumSet += num; 
                s.insert(num);
            }
            sum += num;
        }

        return 2*sumSet - sum;
    }
};