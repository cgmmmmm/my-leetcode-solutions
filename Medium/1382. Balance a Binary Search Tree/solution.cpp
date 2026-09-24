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
    TreeNode* balanceBST(TreeNode* root) 
    {
        std::vector<int> nums;
        auto dfs = [](this auto&& self, TreeNode* curr, std::vector<int>& v) -> void
        {
            if (!curr) return;
            v.push_back(curr->val);
            self(curr->left, v);
            self(curr->right, v);
        };
        dfs(root, nums);
        std::sort(nums.begin(), nums.end());

        auto buildBalancedBST = [](this auto&& self, int l, int r, const std::vector<int>& v) -> TreeNode*
        {
            if (l > r) return nullptr;

            int mid = l + (r - l) / 2;

            TreeNode* root = new TreeNode(v[mid]);

            root->left = self(l, mid-1, v);
            root->right = self(mid+1, r, v);

            return root;
        };

        return buildBalancedBST(0, nums.size()-1, nums);
    }
};