class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1,mid,index=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]<=target){
                index=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        if(index==-1){
            return 0;
        }
        if(nums[index]==target){
            return index;
        }else{
            return index+1;
        }
    }
};