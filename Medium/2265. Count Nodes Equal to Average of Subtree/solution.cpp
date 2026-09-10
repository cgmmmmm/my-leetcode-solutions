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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <vector>

class Solution {
public:
    int res = 0;

    int calcNumOfNodes(TreeNode* curr)
    {
        if (!curr) return 0;
        return 1 + calcNumOfNodes(curr->left) + calcNumOfNodes(curr->right);
    }

    int calcSum(TreeNode* curr)
    {
        if (!curr) return 0;
        int leftSum = calcSum(curr->left);
        int rightSum = calcSum(curr->right);
        return curr->val + leftSum + rightSum;
    }

    void backtrack(TreeNode* curr)
    {
        if (!curr) return;

        backtrack(curr->left);
        backtrack(curr->right);

        int sum = calcSum(curr);
        int nodesNum = calcNumOfNodes(curr);
        if (sum / nodesNum == curr->val) res++;
    }

    int averageOfSubtree(TreeNode* root)
    {
        backtrack(root);
        return res;
    }
};

// store sum at each node
// keep count of number of total child nodes from leaf to root
// calculate average from leaf to root

// depth-first search
// post-order traversal