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
    TreeNode* bstToGst(TreeNode* root) 
    {
        int sum = 0;
        
        auto solve = [sum](this auto&& self, TreeNode* curr) -> void
        {
            if (!curr) return;

            self(curr->right);
            curr->val += sum;
            sum = curr->val;
            self(curr->left);
        };

        solve(root);
        return root;
    }
};