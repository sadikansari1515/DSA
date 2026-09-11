class Solution {
public:
    int strStr(string haystack, string needle) {
        // brute force
        if(haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i < haystack.size(); i++) {
            int j = 0;
            while(j < needle.size() && (i + j) < haystack.size()) {
                if(needle[j] != haystack[i+j]) {
                    break;
                }
                j++;
            }
            if(j == needle.size()) {
                return i;
            }
        }
        return -1;
    }
};