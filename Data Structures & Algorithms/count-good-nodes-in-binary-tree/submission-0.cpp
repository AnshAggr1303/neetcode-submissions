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
    int dfs(TreeNode* node,int maxval){
        if(node==nullptr) return 0;
        int good=0;
        if(node->val>=maxval) good=1;
        maxval=max(maxval,node->val);
        int left=dfs(node->left,maxval);
        int right=dfs(node->right,maxval);
        return good+left+right;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};