class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int op = LLONG_MIN;
        for(char ch : s) {
            if(ch == '(') {
                st.push(op);
            } else {
                // ( ( (1) (1) ) )
                int top = st.top();
                if(top == op) {
                    st.pop();
                    st.push(1);
                } else {
                    int val = 0;
                    while(!st.empty() && st.top() != op) {
                        val += st.top();
                        st.pop();
                    }
                    // Here, st.top() will be (
                    st.pop();
                    st.push(2 * val);
                }
            }
        }
        int ans = 0;
        while(!st.empty()) ans += st.top(), st.pop();
        return ans;
    }
};
