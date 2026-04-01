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
 
// numbers in LL range from 0 to n-1
// there are n nodes in LL
// all values in node are unique

// size of nums range from 1 to n
// values in nums range from 0 to n-1
// all values in nums are unique

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        std::unordered_set<int> st(nums.begin(), nums.end());

        int res = 0;
        ListNode* curr = head;
        while (curr) {
            if ( st.count(curr->val) && (!curr->next || !st.count(curr->next->val)) )
                res++;

            curr = curr->next;
        }

        return res;
    }
};
