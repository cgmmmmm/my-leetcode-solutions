/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (!head) return nullptr;

        std::vector<int> vec;
        while (head)
        {
            vec.push_back(head->val);
            head = head->next;
        }

        auto buildBalancedBST = [](this auto&& self, int l, int r, const std::vector<int>& vec) -> TreeNode*
        {
            if (l > r) return nullptr;

            int mid = l + (r - l) / 2;

            TreeNode* root = new TreeNode(vec[mid]);
            root->left = self(l, mid-1, vec);
            root->right = self(mid+1, r, vec);

            return root;
        };

        return buildBalancedBST(0, vec.size()-1, vec);
    }
};