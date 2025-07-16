class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<=1){
            return;
        }
        while(k>n){
            k=k%n;
        }
        if(n>k){
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
        }
    }

    void reverse(vector<int>& nums, int low, int high){
        while(low<high){
            swap(nums[low],nums[high]);
            low++;
            high--;
        }
    }
};