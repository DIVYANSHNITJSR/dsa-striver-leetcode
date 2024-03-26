class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        vector<int> ans(n); // Resize the ans vector to hold 'n' elements
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(st.empty() || ast[i] > 0)
                st.push(ast[i]);
            else {
                while(!st.empty() && st.top() > 0 && st.top() < abs(ast[i]))
                    st.pop();
                    if(!st.empty() && st.top() == abs(ast[i]))
                        st.pop();
                else
                    if(st.empty() || st.top() < 0)
                        st.push(ast[i]);
                
            }
        }
        int i = 0;
        while (!st.empty()) {
            ans[i] = st.top();
            st.pop();
            i++;
        }
        ans.resize(i); // Resize ans to remove any extra uninitialized elements
        reverse(ans.begin(), ans.end()); // Reversing to maintain correct order
        return ans;
    }
};
