class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n,0);
        int pos=0, neg=1;
        for(auto num:nums){
            if(num>0){
                v[pos]=num;
                pos+=2;
            }else{
                v[neg]=num;
                neg+=2;
            }
        }
        return v;
    }
};