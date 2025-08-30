class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1,high=bloomDay[0],mid,ans=-1;
        int n=bloomDay.size();
        if((long long)m*k>n){
            return -1;
        }
        for(int i=1;i<bloomDay.size();i++){
            high=max(high,bloomDay[i]);
        }
        if((m==1 && k==n)||(m==n && k==1)){
            return high;
        }
        int bouquetsCount=0;
        int adjacentCount=0;
        while(low<=high){
            mid=low+(high-low)/2;
            for(int i=0;i<n;i++){
                if(bloomDay[i]<=mid){
                    adjacentCount++;
                    if(adjacentCount%k==0){
                        bouquetsCount++;
                    }
                }else{
                    adjacentCount=0;
                }
                if(bouquetsCount==m){
                    break;
                }
            }
            if(bouquetsCount==m){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            bouquetsCount=0;
            adjacentCount=0;
        }
    return ans;
    }
};