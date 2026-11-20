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
    int res = 0;
    int max_depth = 0;

    void solve(TreeNode* root, int depth)
    {
        if (!root) return;

        solve(root->left, depth+1);
        if (depth > max_depth)
        {
            res = root->val;
            max_depth = depth;
        }
        else if (depth == max_depth)
        {
            res += root->val;
        }
        solve(root->right, depth+1);
    }

    int deepestLeavesSum(TreeNode* root) 
    {
        solve(root, 1);
        return res;
    }
};