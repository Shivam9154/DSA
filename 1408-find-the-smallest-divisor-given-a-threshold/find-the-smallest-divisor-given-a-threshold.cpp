class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()), mid, sum;
        while (low < high) {
            mid = low + (high - low) / 2, sum = 0;
            for (auto it : nums) {
                sum += ceil(it / double(mid));
                if (sum > threshold) {
                    break;
                }
            }
            if (sum <= threshold) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};