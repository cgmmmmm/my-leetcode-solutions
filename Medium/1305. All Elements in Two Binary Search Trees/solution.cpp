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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        std::vector<int> vec1, vec2;
        auto dfs = [](this auto&& self, TreeNode* curr, std::vector<int>& vec) -> void
        {
            if (!curr) return;
            self(curr->left, vec);
            vec.push_back(curr->val);
            self(curr->right, vec);
        };

        dfs(root1, vec1);
        dfs(root2, vec2);

        int m = vec1.size(), n = vec2.size();
        int i=0, j=0;
        
        std::vector<int> res;
        while (i < m && j < n)
        {
            if (vec1[i] <= vec2[j])
                res.push_back(vec1[i++]);
            else
                res.push_back(vec2[j++]);
        }

        while (i < m) res.push_back(vec1[i++]);
        while (j < n) res.push_back(vec2[j++]);

        return res;
    }
};