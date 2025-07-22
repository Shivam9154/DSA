class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> umap;
        unordered_map<int, int> visited;
        int n = nums.size();
        if(n==0){
            return 0;
        }
        for (int i = 0; i < n; i++) {
            umap[nums[i]] = 1;
        }
        int length = 1, maxLength = 1, i=0,j=1;
        while (i<n) {
            while(i<n && visited[nums[i]]){
                i++;
            }
            if(i==n){
                break;
            }
            visited[nums[i]]=1;
            while(umap[nums[i]-j]) {
                length++;
                visited[nums[i]-j] = 1;
                j++;
            }
            j=1;
            while(umap[nums[i]+j]){
                length++;
                visited[nums[i]+j]=1;
                j++;
            }
            j=1;
            if(length>maxLength){
                maxLength=length;
            }
            length=1;
        }
        return maxLength;
    }
};