class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int left = 0;
        int right = 0;
        int maxLen = 0;
        while(right < s.length()) {
            char currChar = s[right];
            if(mp.count(currChar)) {
                int currCharIdx = mp[currChar];
                if(currCharIdx >= left) {
                    left = currCharIdx+1;
                }
            }
            maxLen = max(maxLen, right - left +1);
            mp[currChar] = right;
            right++;
        }
        return maxLen;
    }
};