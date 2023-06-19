class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int min_day = -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (bouquets_formed(bloomDay, m, k, mid)) {
                min_day = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return min_day;
    }

private:
    bool bouquets_formed(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int flowers = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }

        return bouquets >= m;
    }
};
