class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front(), ans = right;
        int n = nums.size();

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            int count = 0, i = 1;

            while (i < n) {
                if (nums[i] - nums[i - 1] <= mid) {
                    ++count;
                    i += 2;
                } else {
                    ++i;
                }
                if (count >= p) break;  
            }

            if (count >= p) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
