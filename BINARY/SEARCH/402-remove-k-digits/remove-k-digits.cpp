class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans = "";
        stack<char> st;
        
        if (k > n)
            return "0";
        if (k == 0)
            return num;
        
        for (int i = 0; i < n; i++) {
            if (st.empty() )
                st.push(num[i]);
            else {
                while (!st.empty() && st.top() > num[i] && k > 0) {
                    st.pop();
                    k--;
                }
                st.push(num[i]);
            }
            
            // Remove leading zeros
            if (st.size() == 1 && num[i] == '0')
                st.pop();
        }
        
        // Remove remaining digits if k > 0
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        // Construct the result string from the stack
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        // Reverse the result string
        reverse(ans.begin(), ans.end());
        
        // If the result is empty, return "0"
        if (ans.empty())
            return "0";
        
        return ans;
    }
};
