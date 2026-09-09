class Solution {
public:
    bool isAlphanumeric(char c) {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
    }
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j) {
            char c1 = s[i];
            char c2 = s[j];
            if(!isAlphanumeric(c1)) {
                i++;
                continue;
            }
            if(!isAlphanumeric(c2)) {
                j--;
                continue;
            }
            if(tolower(c1) != tolower(c2)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};