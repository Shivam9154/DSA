class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0, high=nums.size()-1,mid;
        if(low==high){
            return nums[low];
        }
        if(nums[low]!=nums[low+1]){
            return nums[low];
        }
        if(nums[high-1]!=nums[high]){
            return nums[high];
        }
        low++; high--;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid+1]&&nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if(nums[mid]==nums[mid+1]){
                if((mid+1)%2==0){
                   high=mid-1;
                }else{
                    low=mid+2;
                }
            }else{
                if(mid%2==0){
                    high=mid-2;
                }else{
                    low=mid+1;
                }
            }
        }
        return -1;
    }
};