class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() <= k) return "0";
        if(k==0) return num;

        stack<char> st;

        for(int i=0; i<num.size(); i++) {
            char c = num[i];

            while(true) {
                if(k==0) {
                    st.push(c);
                    break;
                }
                if(st.empty()) {
                    st.push(c);
                    break;
                }

                char topCh = st.top();

                if(topCh > num[i]) {
                    st.pop();
                    k--;
                }
                else {
                    st.push(c);
                    break;
                }
            }
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        vector<char> v(st.size(),'0');

        for(int i=st.size()-1; i>=0; i--) {
            v[i] = st.top();
            st.pop();
        }

        int i = 0;
        while(i<v.size() && v[i] == '0') {
            i++;
        }
        string res = "";
        while(i<v.size()) {
            res.push_back(v[i]);
            i++;
        }

        return res.size() == 0? "0": res;
    }
};