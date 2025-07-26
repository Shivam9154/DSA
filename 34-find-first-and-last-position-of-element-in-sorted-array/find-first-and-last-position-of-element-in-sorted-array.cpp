class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1,mid;
        int n=nums.size();
        vector<int>v(2,-1);
        if(n==0){
            return v;
        }   
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target && (mid==0 || nums[mid]!=nums[mid-1])){
                v[0]=mid;
                break;
            }else if(nums[mid]>=target){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        low=mid, high=nums.size()-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target && (mid==n-1 || nums[mid]!=nums[mid+1])){
                v[1]=mid;
                break;
            }else if(nums[mid]<=target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return v;
    }
};