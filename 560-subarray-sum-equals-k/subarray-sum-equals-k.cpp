class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int count=0;
        unordered_map<int,int>prefixMap;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                count++;
            } 
            if(prefixMap.find(sum-k)!=prefixMap.end()){
                count+=prefixMap[sum-k];
            }
            prefixMap[sum]++;
        }
        return count;
    }
};