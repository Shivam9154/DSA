class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number=0;
        for(int element:nums){
            number^=element;
        }
        return number;
    }
};