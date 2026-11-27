class Solution {
public:
    void reverseStringHelper(vector<char>& s, int start, int end) {
        if(start > end) {
            return;
        }
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        reverseStringHelper(s, start+1, end-1);
    }
    void reverseString(vector<char>& s) {
        reverseStringHelper(s,0 ,s.size()-1);
    }
};