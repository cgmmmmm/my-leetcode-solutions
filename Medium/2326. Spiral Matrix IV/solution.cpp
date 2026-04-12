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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        std::vector<std::vector<int>> res(m, std::vector<int> (n, -1));

        // direction arrays = {East, South, West, North}
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};

        int r = 0, c = 0, cur_d = 0; 
        while (head)
        {
            res[r][c] = head->val;
            head = head->next;

            if (!head) break;

            int nextR = r + dr[cur_d];
            int nextC = c + dc[cur_d];

            if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n || res[nextR][nextC] != -1)
            {
                cur_d = (cur_d + 1) % 4;
            }

            r += dr[cur_d];
            c += dc[cur_d];
        }

        return res;
    }
};
