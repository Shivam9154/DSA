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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        TreeNode* p = root;
        TreeNode* p2;
        while (p || !s.empty()) {
            while(p){
                v.push_back(p->val);
                s.push(p);
                p=p->right;
            }
            p=s.top();
            p=p->left;
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};