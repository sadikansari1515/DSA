class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0; i<asteroids.size(); i++) {
            int ast = asteroids[i];
            while(true) {
                if(st.empty()) {
                    st.push(i);
                    break;
                }
                
                if(ast >= 0) {
                    st.push(i);
                    break;
                }

                int idx = st.top();

                if(asteroids[idx] >= 0) {
                    int absAst = abs(ast);

                    if(asteroids[idx] > absAst) {
                        break;
                    } else if(asteroids[idx] == absAst) {
                        st.pop();
                        break;
                    } else {
                        st.pop();
                    }
                } 
                else {
                    st.push(i);
                    break;
                }
            }
        }
        vector<int> res(st.size(),0);
        int i = res.size()-1;
        while(!st.empty()) {
            res[i] = asteroids[st.top()];
            st.pop();
            i--;
        }

        return res;
    }
};