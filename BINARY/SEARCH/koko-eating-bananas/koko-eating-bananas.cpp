class Solution {
public:
    bool isValid(int mid, vector<int> piles, int h) {
        int hours = 0;
        for(int i=0;i<piles.size();i++) {
            hours += (piles[i]/mid);
            piles[i] %=mid;
            if(piles[i] > 0) hours++;
            if(hours > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = 0, res = -1;
        for(int i=0;i<piles.size();i++) {
            end = max(end, piles[i]);
        }
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(isValid(mid, piles, h)) {
                res = mid;
                end = mid - 1;
            } else start = mid + 1;
        }

        return res;
    }
};