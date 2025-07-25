class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
        int l=0, r=n-1;
        int lmax[n], rmax[n];
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]);
            lmax[i]=maxi;
        }
        maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            rmax[i]=maxi;
        }  
        l=0, r=n-1;
        while(l<r){
            if(height[l]<height[r]){
                total+=lmax[l]-height[l];
                l++;
            }
            else{
                total+=rmax[r]-height[r];
                r--;
            }
        }
        return total;
    }
};