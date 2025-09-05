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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==NULL){
            return ans;
        }
        q.push(root);
        ans.push_back({root->val});
        TreeNode *p;
        while(!q.empty()){
            int size=q.size();
            vector<int>v;
            for(int i=1;i<=size;i++){
                p=q.front();
                if(p->left){
                    q.push(p->left);
                    v.push_back(p->left->val);
                }
                if(p->right){
                    q.push(p->right);
                    v.push_back(p->right->val);
                }
                q.pop();
            }
            if(v.size()>0){
                ans.push_back(v);
            }
        }
        return ans;
    }
};