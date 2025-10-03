/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum=INT_MIN;
        maxPathDown(root,maxSum);
        return maxSum;
    }
    int maxPathDown(TreeNode* root, int &maxSum){
        if(root==NULL){
            return 0;
        }
        int leftSum=maxPathDown(root->left,maxSum);
        int rightSum=maxPathDown(root->right,maxSum);
        if(leftSum<0){
            leftSum=0;
        }
        if(rightSum<0){
            rightSum=0;
        }
        maxSum=max(maxSum,root->val+leftSum+rightSum);
        return root->val+max(leftSum,rightSum);
    }
};