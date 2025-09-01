class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size() - 1, mid;
        if (arr[low] - 1 >= k) {
            return k;
        }
        int missingNumbers;
        while (low < high) {
            mid = low + (high - low) / 2;
            missingNumbers = arr[mid] - (mid + 1);
            if (missingNumbers < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        missingNumbers = arr[high] - (high + 1);
        if (missingNumbers < k) {
            return arr[high] + k - missingNumbers;
        }
        high--;
        missingNumbers = arr[high] - (high + 1);
        return arr[high] + k - missingNumbers;

    }
};