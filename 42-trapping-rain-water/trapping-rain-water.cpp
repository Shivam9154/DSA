class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int total =0, lmax=0,rmax=0,l=0,r=n-1;
        while(l<r){
            if(height[l]>lmax){
                lmax=height[l];
            }
            if(height[r]>rmax){
                rmax=height[r];
            }
            if(height[l]<height[r]){
                total+= lmax-height[l];
                l++;
            }else{
                total+=rmax-height[r];
                r--;
            }
        }
        return total;
    }
};