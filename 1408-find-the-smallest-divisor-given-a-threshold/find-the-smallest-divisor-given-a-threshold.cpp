class Solution {
public:
    int sum(vector<int>&nums, int divisor){
        int sum=0;
        for(auto it:nums){
            sum+=ceil(it/float(divisor));
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end()), mid;
        while (low < high) {
            mid = low + (high - low) / 2;
            if (sum(nums,mid) <= threshold) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};