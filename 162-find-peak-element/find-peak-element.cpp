class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid;
        if(low==high){
            return low;
        }
        if(nums[low]>nums[low+1]){
            return low;
        }
        if(nums[high]>nums[high-1]){
            return high;
        }
        low++;
        high--;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1]){
                return mid;
            }
            if(nums[mid]>=nums[mid-1]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return 0;
    }
};