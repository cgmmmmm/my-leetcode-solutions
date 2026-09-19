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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        std::vector<int> res;
        auto dfs = [&](this auto&& self, TreeNode* curr) -> void 
        {
            if (!curr) return;
            res.push_back(curr->val);
            self(curr->left);
            self(curr->right);
        };
        dfs(root);
        return res;
    }
};