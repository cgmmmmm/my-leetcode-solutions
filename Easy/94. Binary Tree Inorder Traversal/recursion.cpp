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
private:
    std::vector<int> res;

    void inorderRecursion(TreeNode* curr)
    {
        // base case
        if (curr == nullptr) return;

        // 1. traverse left
        inorderRecursion(curr->left);

        // 2. process parent
        res.push_back(curr->val);

        // 3. traverse right
        inorderRecursion(curr->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if (!root) return res;
        
        inorderRecursion(root);

        return res;
    }
};
