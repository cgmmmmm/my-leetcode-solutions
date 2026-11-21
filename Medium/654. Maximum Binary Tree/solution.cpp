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
    TreeNode* solve(const std::vector<int>& nums, int start, int end)
    {
        if (start == end) return nullptr;
        
        int mxe = nums[start];
        int mxi = start;
        for (int i=start; i<end; ++i)
        {
            if (nums[i] > mxe)
            {
                mxe = nums[i];
                mxi = i;
            }
        }

        TreeNode* curr = new TreeNode(mxe);
        curr->left = solve(nums, start, mxi);
        curr->right = solve(nums, mxi+1, end);

        return curr;
    }

    TreeNode* constructMaximumBinaryTree(std::vector<int>& nums) 
    {
        return solve(nums, 0, nums.size());
    }
};

// preorder