class Solution {
public:
    int majorityElement(vector<int>& nums)
     {int el;
     int cnt=0;
     //apply algorithm moore's voting
           for (int i = 0; i < nums.size(); i++) {
        if (cnt == 0) {
            cnt = 1;
            el = nums[i];
        }
        else if (el == nums[i]) cnt++;
        else cnt--;
    }
     //checking if the stored element
    // is the majority element:
    int cnt1 = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == el) cnt1++;
    }

    if (cnt1 > (nums.size() / 2)) 
    return el;
    return 0;
    }

};