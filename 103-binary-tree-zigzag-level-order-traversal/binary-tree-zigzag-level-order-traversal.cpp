/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode*>q;
        int level=0;
        q.push(root);
        bool rev=false;
        while(!q.empty()){
            int level_size=q.size();
            vector<int>level(level_size);
            for(int i=0;i<level_size;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                level[i]=node->val;
            }
            if(rev) reverse(level.begin(),level.end());
            result.push_back(level);
            rev=!rev;
        }
        return result;
    }
};