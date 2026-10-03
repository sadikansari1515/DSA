class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> sToT;
        map<char, char> tToS;

        for(int i=0; i<s.size(); i++) {
            char _s = s[i];
            char _t = t[i];
            if(!sToT.count(_s) && !tToS.count(_t)) {
                sToT[_s] =  _t;
                tToS[_t] =  _s;
            }
            else if(!sToT.count(_s)) {
                return false;
            }
            else if(!tToS.count(_t)) {
                return false;
            }
            else if(sToT[_s] != _t && tToS[_t] != _s) {
                return false;
            }
        }
        return true;
    }
};