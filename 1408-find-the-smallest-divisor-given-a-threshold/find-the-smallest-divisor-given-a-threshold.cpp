class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 2, high = nums[0], mid;
        int sum = nums[0], ans;
        for (int i = 1; i < nums.size(); i++) {
            if (sum > INT_MAX - nums[i]) {
                break;
            }
            sum += nums[i];
            if (nums[i] > high) {
                high = nums[i];
            }
        }
        if (sum <= threshold) {
            return 1;
        }
        while (low <= high) {
            mid = low + (high - low) / 2, sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                sum += ceil(nums[i] / float(mid));
                if (sum > threshold) {
                    break;
                }
            }
            if (sum <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};