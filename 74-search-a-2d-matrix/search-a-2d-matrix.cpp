class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int row=0;row<m;row++)
        {
            if(matrix[row][n-1]<target)
            {
                continue;
            }
            int start=0,end=n-1;
            int mid;
            if(matrix[row][start]>target)
            {
                return 0;
            }
            while(start<=end) //Binary search on row
            {
                mid=start+(end-start)/2;
                if(matrix[row][mid]==target)
                {
                    return 1;
                }
                else if(matrix[row][mid]>target)
                {
                    end=mid-1;
                }
                else
                {
                    start=mid+1;
                }
            }
        }
        return 0;
    }
};