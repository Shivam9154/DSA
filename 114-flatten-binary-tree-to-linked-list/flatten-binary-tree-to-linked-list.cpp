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
    void flatten(TreeNode* root) {
        stack<TreeNode*>s;
        flattenintoLL(root,s);
        TreeNode *p=root;
        while(p && p->right){
            p=p->right;
        }
        if(p==NULL){
            return;
        }
        while(!s.empty()){
            TreeNode* temp=s.top();
            s.pop();
            flattenintoLL(temp,s);
            p->right=temp;
            while(p && p->right){
                p=p->right;
            }
        }
    }
    void flattenintoLL(TreeNode *root, stack<TreeNode*>&s){
        if(root==NULL){
            return;
        }
        TreeNode *p=root->left;
        TreeNode *q=root->right;
        root->right=p;
        root->left=NULL;
        s.push(q);
        flattenintoLL(p,s);
    }
};