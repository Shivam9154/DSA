class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=nums[0],mid;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>high){
                high=nums[i];
            }
        }
        int sum=0,ans;
        while(low<=high){
            mid=low+(high-low)/2;
            for(int i=0;i<nums.size();i++){
                sum+=ceil(nums[i]/float(mid));
                if(sum>threshold){
                    break;
                }
            }
            if(sum>threshold){
                low=mid+1;
            }else{
                ans=mid;
                high=mid-1;
            }
            sum=0;
        }
        return ans;
    }
};