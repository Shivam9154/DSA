class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0, high=nums.size()-1, mid;
        if(nums[low]<=nums[high]){
            return nums[low];
        }
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            if(nums[low]<=nums[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        } 
        return -1;  
    }
};