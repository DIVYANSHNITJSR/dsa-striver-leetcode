#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // Handle the case when height is empty to avoid out-of-range access

        int ans = 0;
        vector<int> maxl(n);
        vector<int> maxr(n);

        // Initialize the first element of maxr and the last element of maxl
        maxr[0] = height[0];
        maxl[n - 1] = height[n - 1];

        // Fill in the maxl and maxr vectors
        for (int i = 1; i < n; i++) {
            maxr[i] = max(maxr[i - 1], height[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            maxl[i] = max(maxl[i + 1], height[i]);
        }

        // Calculate the trapped water
        for (int i = 0; i < n; i++) {
            ans += min(maxl[i], maxr[i]) - height[i];
        }

        return ans;
    }
};
