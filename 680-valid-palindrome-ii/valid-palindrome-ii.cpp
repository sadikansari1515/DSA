class Solution {
public:
    bool palindromeHelper(int i, int j, string s) {
        while(i<j) {
            if(s[i]!=s[j]) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j) {
            if(s[i]!=s[j]) {
                return palindromeHelper(i+1, j, s) || palindromeHelper(i, j-1, s);
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }
};