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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        auto buildBalancedBST = [&](this auto&& self, int l, int r) -> TreeNode*
        {
            if (l > r) return nullptr;

            int mid = l + (r - l) / 2;

            TreeNode* root = new TreeNode(nums[mid]);
            root->left = self(l, mid-1);
            root->right = self(mid+1, r);

            return root;
        };

        return buildBalancedBST(0, nums.size()-1);
    }
};