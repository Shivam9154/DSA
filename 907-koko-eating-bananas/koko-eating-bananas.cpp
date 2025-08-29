class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=piles[0],mid;
        int h2=0,count,ans;
        for(int i=1;i<piles.size();i++){
            if(piles[i]>high){
                high=piles[i];
            }
        }
        while(low<=high){
            mid=low+(high-low)/2;
            for(int i=0;i<piles.size();i++){
                count=piles[i];
                // while(count!=0){
                //     h2++;
                //     count=count-mid;
                //     if(count<0){
                //         count=0;
                //     }
                // }
                h2+=count/mid;
                if(count%mid!=0){
                    h2++;
                }
                if(h2>h){
                    break;
                }
            }
            if(h2<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
            h2=0;
        }
        return ans;
    }
};