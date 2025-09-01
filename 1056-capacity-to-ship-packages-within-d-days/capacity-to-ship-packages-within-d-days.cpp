class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0, mid;
        for (int i = 0; i < weights.size(); i++) {
            high += weights[i];
        }
        int capacity;
        int requiredDays = 0;
        while (low < high) {
            mid = low + (high - low) / 2;
            capacity = mid;
            for (int i = 0; i < weights.size(); i++) {
                capacity -= weights[i];
                if (capacity <= 0) {
                    requiredDays++;
                    if (capacity < 0) {
                        i--;
                    }
                    capacity = mid;
                }
                if (requiredDays > days) {
                    break;
                }
            }
            if (capacity!=mid)
                requiredDays++;
            if (requiredDays <= days) {
                high = mid;
            } else {
                low = mid + 1;
            }
            requiredDays = 0;
        }
        return high;
    }
};