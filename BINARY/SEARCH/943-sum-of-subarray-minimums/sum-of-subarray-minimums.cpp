// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         stack <pair<int,int>> st;
//         int n=arr.size();
//         vector<int> NSL_index;
//         for(int i=0;i<n;i++)
//         {
//               while(!st.empty() && st.top().first>=arr[i])
//                 st.pop();
//                 if(st.empty()) NSL_index.push_back(-1);
//                 else
//                   NSL_index.push_back(st.top().second); 
            
//             st.push({arr[i],i});
//         } 
//           while(!st.empty()) st.pop();
//          vector<int> NSR_index;
//         for(int i=0;i<n;i++)
//         {
            
            
//               while(!st.empty() && st.top().first>=arr[i])
//                 st.pop();
//                 if(st.empty()) NSR_index.push_back(n);
//                 else
//                   NSR_index.push_back(st.top().second); 
//             st.push({arr[i],i});
//         } 
//          long long sum = 0;
//         int mod = 1e9 + 7; // modulo value as per the problem
//         for(int i = 0; i < n; i++) {
//             long long left = i - NSL_index[i];
//             long long right = NSR_index[i] - i;
//             sum = (sum + arr[i] * left * right) % mod;
//         }   
//         return sum;
//     }
// };
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<pair<int,int>> st;

        // Finding NSL
        vector<int> NSL_index(n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top().first >= arr[i])
                st.pop();
            NSL_index[i] = st.empty() ? -1 : st.top().second;
            st.push({arr[i], i});
        } 

        // Clear stack for NSR calculation
        while(!st.empty()) st.pop();

        // Finding NSR
        vector<int> NSR_index(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top().first > arr[i])
                st.pop();
            NSR_index[i] = st.empty() ? n : st.top().second;
            st.push({arr[i], i});
        } 

        // Calculate the sum
        long long sum = 0;
        int mod = 1e9 + 7; // modulo value as per the problem
        for(int i = 0; i < n; i++) {
            long long left = i - NSL_index[i];
            long long right = NSR_index[i] - i;
            sum = (sum + arr[i] * left * right) % mod;
        }  

        return sum;
    }
};
