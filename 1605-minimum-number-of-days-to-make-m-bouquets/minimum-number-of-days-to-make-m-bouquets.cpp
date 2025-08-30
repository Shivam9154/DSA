class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=1,high=bloomDay[0],mid,ans=-1;
        for(int i=1;i<bloomDay.size();i++){
            high=max(high,bloomDay[i]);
        }
        int bouquetsCount=0;
        int adjacentCount=0;
        while(low<=high){
            mid=low+(high-low)/2;
            for(int i=0;i<bloomDay.size();i++){
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