class Solution {
public:
    bool split(vector<int>&nums,int maxSum,int k){
        int sum=0;
        int count=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxSum){
                count++;
                sum=nums[i];
            }
        }
        if(count>k){
            return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=nums[0];
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++){
            sum+=nums[i];
            if(nums[i]>maxi){
                maxi=nums[i];
            }
        }
        if(k==nums.size()){
            return maxi;
        }
        if(maxi==0){
            return 0;
        }
        int low=maxi, high=sum,mid,ans=-1;
        while(low<=high){
            mid=low+(high-low)/2;
            if(split(nums,mid,k)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};